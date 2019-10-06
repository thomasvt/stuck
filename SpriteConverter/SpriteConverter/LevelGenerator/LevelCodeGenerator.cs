using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Xml.Serialization;
using Exception = System.Exception;

namespace PogoDataConverter.LevelGenerator
{
    internal class LevelCodeGenerator
    {
        public string CurrentLevelName { get; set; }

        public string Generate(string folder)
        {
            if (!CheckFolderExists(folder))
                return "Folder does not exist";
            var levels = ReadLevels(folder);
            if (!ValidateLevels(levels)) return "Cannot generate code.\nSee output log.";

            var newgameSpawnpoint = GetNewgameSpawnpoint(levels);
            LinkTriggers(levels);
            LinkPortals(levels);

            return LevelCodeBuilder.Build(levels, newgameSpawnpoint);
        }

        private byte GetNewgameSpawnpoint(List<Level> levels)
        {
            // newgame spawnpoint has to be level 0, spawnpoint 0, so we move that to the top of the list.
            Level startLevel = null;
            Spawnpoint startSpawnpoint = null;
            foreach (var level in levels.ToList())
            {
                var newgameSpawnpoints = level.Spawnpoints.Where(s => s.SpawnpointId?.ToLower() == "newgame");
                if (newgameSpawnpoints.Count() > 1)
                {
                    Error($"More than one 'newgame' spawnpoint detected in level {level.Name}.");
                }
                if (newgameSpawnpoints.Any())
                {
                    if (startLevel != null)
                    {
                        Error($"More than one 'newgame' spawnpoint detected! ({startLevel.Name}, {level.Name})");
                        break;
                    }
                    startLevel = level;
                    startSpawnpoint = newgameSpawnpoints.First();
                }
            }

            if (startSpawnpoint == null)
            {
                Error($"No 'newgame' spawnpoint detected in any level. Game has no starting point.");
                return 0;
            }

            var startLevelIndex = levels.Select(l => l.Name.ToLower()).ToList().IndexOf(startLevel.Name.ToLower());
            var spawnpointIndex = startLevel.Spawnpoints.Select(s => s.SpawnpointId.ToLower()).ToList()
                .IndexOf(startSpawnpoint.SpawnpointId.ToLower());
            return (byte)((startLevelIndex << 3) | spawnpointIndex);
        }

        private bool ValidateLevels(List<Level> levels)
        {
            var isValid = true;
            foreach (var level in levels)
            {
                CurrentLevelName = level.Name;
                if (level.Error == null)
                {
                    if (level.Portals.Count > 7)
                    {
                        isValid = false;
                        Error($"Too many portals ({level.Portals.Count}/7)");
                    }

                    if (level.Spawnpoints.Count > 8)
                    {
                        isValid = false;
                        Error($"Too many spawnpoints ({level.Spawnpoints.Count}/8)");
                    }
                    var collectibleCount = CountCollectibles(level);
                    if (collectibleCount > 64)
                    {
                        isValid = false;
                        Error($"Too many collectibles ({collectibleCount}/64)");
                    }
                }
                else
                {
                    Error("Level is unreadable: " + level.Error);
                }
            }
            CurrentLevelName = null;

            if (levels.Any(l => l.Error != null))
            {
                Error("There are unreadable levels.");
                isValid = false;
            }

            return isValid;
        }

        private readonly Tile[] collectibleTiles = {Tile.Coin, Tile.GemBlue, Tile.GemGreen, Tile.GemOrange, Tile.GemRed, Tile.Potion};

        private int CountCollectibles(Level level)
        {
            var count = 0;
            for (var y = 0; y < level.Terrain.GetLength(1); y++)
            {
                for (var x = 0; x < level.Terrain.GetLength(0); x++)
                {
                    var tile = level.Terrain[x, y];
                    if (collectibleTiles.Contains(tile))
                        count++;
                }
            }

            return count;
        }

        private void LinkTriggers(List<Level> levels)
        {
            var triggerNames = levels.SelectMany(l => l.TriggerAreas).Select(p => p.Trigger.ToLower()).Distinct().ToList();
            var plateTriggerNames = levels.SelectMany(l => l.PressurePlates).Select(p => p.Trigger.ToLower()).Distinct().ToList();
            var uncontrolledTriggers = triggerNames.Except(plateTriggerNames);
            foreach (var t in uncontrolledTriggers)
            {
                Warn($"There is no PressurePlate controlling trigger \"{t}\".");
            }
            foreach (var level in levels)
            {
                foreach (var pressurePlate in level.PressurePlates)
                {
                    var triggerId = triggerNames.IndexOf(pressurePlate.Trigger.ToLower());
                    if (triggerId == -1)
                        Warn($"TriggerPlate at ({pressurePlate.Point}) addresses trigger \"{pressurePlate.Trigger}\" which is not used by any TriggerArea.");
                    pressurePlate.TriggerId = triggerId == -1 ? 255 : triggerId;
                }

                foreach (var triggerArea in level.TriggerAreas)
                {
                    var triggerId = triggerNames.IndexOf(triggerArea.Trigger.ToLower());
                    triggerArea.TriggerId = triggerId;
                }
            }
        }

        /// <summary>
        /// Replaces the textual Portal target reference by numerical ones for the game engine.
        /// </summary>
        private void LinkPortals(List<Level> levels)
        {
            var levelNames = levels.Select(l => l.Name.ToLower()).ToList();
            foreach (var level in levels)
            {
                CurrentLevelName = level.Name;
                foreach (var portal in level.Portals)
                {
                    if (portal.Target == null)
                    {
                        continue;
                    }
                    portal.LevelId = levelNames.IndexOf(portal.Target.Level.ToLower());
                    if (portal.LevelId == -1)
                    {
                        Warn($"Cannot link Portal target \"{portal.Target}\": level \"{portal.Target.Level}\" not found.");
                    }
                    else
                    {
                        var targetLevel = levels[portal.LevelId];
                        var spawnpointNames = targetLevel.Spawnpoints.Select(s => s.SpawnpointId.ToLower()).ToList(); // inefficient to do this every time, but we wont notice :)
                        portal.SpawnpointId = spawnpointNames.IndexOf(portal.Target.Spawnpoint.ToLower());
                        if (portal.SpawnpointId == -1)
                        {
                            Warn($"Cannot link Portal target \"{portal.Target}\": spawnpoint \"{portal.Target.Spawnpoint}\" not found in level \"{portal.Target.Level}\".");
                        }
                    }
                }
            }

            CurrentLevelName = null;
        }

        private List<Level> ReadLevels(string folder)
        {
            var levels = Directory.GetFiles(folder, "*.tmx").Select(f =>
            {
                CurrentLevelName = Path.GetFileNameWithoutExtension(f);
                try
                {
                    return ReadLevel(f);
                }
                catch (Exception e)
                {
                    Error(e.Message);
                    return new Level
                    {
                        Name = CurrentLevelName,
                        Error = e.Message
                    };
                }
            }).ToList();
            CurrentLevelName = null;
            return levels;
        }

        private bool CheckFolderExists(string folder)
        {
            if (Directory.Exists(folder)) return true;
            Error("Folder doesn't exist.");
            return false;
        }

        private void Error(string message)
        {
            OnLog?.Invoke(this, string.IsNullOrWhiteSpace(CurrentLevelName) ? $"ERROR: {message}" : $"({CurrentLevelName}) ERROR: {message}");
        }

        private void Warn(string message)
        {
            OnLog?.Invoke(this, string.IsNullOrWhiteSpace(CurrentLevelName) ? $"WARNING: {message}" : $"({CurrentLevelName}) ERROR: {message}");
        }

        private void Info(string message)
        {
            OnLog?.Invoke(this, string.IsNullOrWhiteSpace(CurrentLevelName) ? $"INFO: {message}" : $"({CurrentLevelName}) INFO: {message}");
        }

        public Level ReadLevel(string file)
        {
            var map = ReadMap(file);
            var tileLookup = GetTileLookup(GetFullPath(file, map.tileset.Single(t => t.source != null && t.source.Contains("Pogo")).source));
            var tiles = ConvertTiles(map, tileLookup);
            var levelName = Path.GetFileNameWithoutExtension(file).ToLower();
            var markers = GetMarkers(map, tiles, levelName);
            var level = new Level
            {
                Name = levelName,
                Width = tiles.GetLength(0),
                Height = tiles.GetLength(1),
                Terrain = tiles,
                Spawnpoints = BuildSpawnpointList(markers),
                Portals = BuildPortalList(markers),
                PressurePlates = markers.OfType<PressurePlate>().ToList(),
                TriggerAreas = markers.OfType<TriggerArea>().ToList()
            };
            return level;
        }

        private static List<Portal> BuildPortalList(List<IMarker> markers)
        {
            return markers.OfType<Portal>().ToList();
        }

        private static List<Spawnpoint> BuildSpawnpointList(List<IMarker> markers)
        {
            var spawnpoints = markers.OfType<Spawnpoint>();
            var ids = spawnpoints.Select(s => s.SpawnpointId?.ToLower());
            if (ids.Any(string.IsNullOrWhiteSpace))
                throw new Exception("Spawnpoints must have a non empty name; unique in the level. (case insensitive)");
            if (ids.Distinct().Count() < ids.Count())
                throw new Exception("There are Spawnpoints with duplicate names: " + string.Join(", ", ids.GroupBy(id => id).Where(g => g.Count() > 1).Select(g => g.Key)));
            return spawnpoints.ToList();
        }

        private List<IMarker> GetMarkers(map map, Tile[,] tiles, string levelName)
        {
            var list = new List<IMarker>();
            if (map.objectgroup == null)
                return list; // no annotations
            foreach (var o in map.objectgroup[0].@object)
            {
                list.Add(o.width == null ? GetSingleTileMarker(tiles, o, levelName) : GetRectangularMarker(o));
            }
            return list.Where(m => m != null).ToList(); // filter out the annotations that didn't yield an IMarker.
        }

        private IMarker GetSingleTileMarker(Tile[,] tiles, mapObjectgroupObject o, string levelName)
        {
            var point = new Point((int)double.Parse(o.x) / 16, (int)double.Parse(o.y) / 16);
            var tile = GetTile(tiles, point);
            switch (tile)
            {
                case Tile.Portal:
                    {
                        var target = PortalTarget.FromTargetId(o.name, levelName);
                        if (target?.Spawnpoint == null)
                            Warn($"Invalid Portal Target \"{o.name}\" at {point}. (syntax: [LEVEL.]SPAWNPOINT )");
                        return new Portal
                        {
                            Target = target,
                            Point = point
                        };
                    }
                case Tile.Spawnpoint:
                    return new Spawnpoint
                    {
                        SpawnpointId = o.name,
                        Point = point
                    };
                case Tile.PressurePlate:
                    return new PressurePlate
                    {
                        Trigger = o.name,
                        Point = point
                    };
                case Tile.FlameThrowerOffset:
                    if (!int.TryParse(o.name, out var shoot_offset))
                    {
                        shoot_offset = 0;
                        Warn($"Invalid flamethrower offset \"{o.name}\" at {point}: should be 0, 1, 2 or 3.");
                    }

                    tiles[point.X, point.Y] = Tile.FlameThrowerOffset + shoot_offset;
                    return null;

                default:
                    throw new Exception(
                        $"Illegal Point object found at {point}. Only allowed on tiles of type Portal, Spawnpoint, PressurePlate.");
            }
        }

        private static Tile GetTile(Tile[,] tiles, Point point)
        {
            try
            {
                return tiles[point.X, point.Y];
            }
            catch (IndexOutOfRangeException)
            {
                throw new Exception($"Found a tile marker outside level bounds: {point}");
            }
        }

        private static IMarker GetRectangularMarker(mapObjectgroupObject o)
        {
            var x0 = (int)double.Parse(o.x) / 16;
            var y0 = (int)double.Parse(o.y) / 16;
            var x1 = (int)(double.Parse(o.x) + double.Parse(o.width)) / 16;
            var y1 = (int)(double.Parse(o.y) + double.Parse(o.height)) / 16;
            return new TriggerArea
            {
                Trigger = o.name,
                Left = x0,
                Top = y0,
                Right = x1,
                Bottom = y1
            };
        }

        private static Tile[,] ConvertTiles(map map, Dictionary<int, Tile> tileLookup)
        {
            var width = int.Parse(map.width);
            var height = int.Parse(map.height);
            if (width * height > 2000)
                throw new Exception($"Level dimensions too big: {width} x {height} = {width * height} (max 2000)");

            var rawTiles = map.layer[0].data[0].Value.Split(new[] { '\n' }, StringSplitOptions.RemoveEmptyEntries)
                .Select(row => row.Split(new[] { ',' }, StringSplitOptions.RemoveEmptyEntries)
                    .Select(id => tileLookup[int.Parse(id) - 1]).ToArray()) // tile ids are 1-based, because 0 is used for "empty"
                .ToArray();
            var tiles = new Tile[width, height];
            for (var y = 0; y < height; y++)
            {
                for (var x = 0; x < width; x++)
                {
                    var tile = rawTiles[y][x];
                    if (tile >= Tile.DoorBlue && tile <= Tile.DoorRed) // doors must be stored 1 cell above the ground
                    {
                        tiles[x, y - 1] = tile;
                    }
                    else
                    {
                        tiles[x, y] = tile;
                    }
                }
            }

            return tiles;
        }

        private static Dictionary<int, Tile> GetTileLookup(string filename)
        {
            var tileset = ReadTileset(filename);
            var lookup = tileset.tile.ToDictionary(t => int.Parse(t.id), t => TileMapper.GetTileFromFilename(t.image[0].source));
            lookup.Add(-1, Tile.None);
            return lookup;
        }

        private static tileset ReadTileset(string file)
        {
            using (var stream = File.OpenRead(file))
            {
                var serializer = new XmlSerializer(typeof(tileset));
                return (tileset)serializer.Deserialize(stream);
            }
        }

        private static map ReadMap(string file)
        {
            using (var stream = File.OpenRead(file))
            {
                var serializer = new XmlSerializer(typeof(map));
                return (map)serializer.Deserialize(stream);
            }
        }

        private static string GetFullPath(string mainFile, string relativePath)
        {
            if (Path.IsPathRooted(relativePath))
                return relativePath;
            return Path.Combine(Path.GetDirectoryName(mainFile), relativePath.Replace('/', '\\'));
        }

        public event EventHandler<string> OnLog;
    }
}
