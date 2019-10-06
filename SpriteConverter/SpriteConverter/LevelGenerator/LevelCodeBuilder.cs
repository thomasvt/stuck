using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PogoDataConverter.LevelGenerator
{
    internal class LevelCodeBuilder
    {
        public static string Build(IList<Level> levels, byte newgameSpawnpoint)
        {
            var sb = new StringBuilder();
            sb.AppendLine("#include <Levels.h>");
            sb.AppendLine();
            sb.AppendLine("namespace levels {");
            sb.AppendLine();
            AppendGlobalInfo(levels, newgameSpawnpoint, sb);
            sb.AppendLine();
            AppendLevelNames(levels, sb);
            sb.AppendLine();
            AppendLevelData(levels, sb);
            sb.AppendLine();
            AppendLevelDefinitions(levels, sb);
            sb.AppendLine();
            sb.AppendLine("}");
            sb.AppendLine();
            return sb.ToString();
        }

        private static void AppendGlobalInfo(IList<Level> levels, byte newgameSpawnpoint, StringBuilder sb)
        {
            sb.AppendLine($"\t// copy these to the levels.h file:");
            sb.AppendLine($"\tconstexpr uint8_t newgame_spawnpoint = {newgameSpawnpoint};");
            sb.AppendLine($"\tconstexpr uint8_t level_count = { levels.Count };");
            sb.AppendLine($"\tconstexpr uint8_t trigger_count = { levels.SelectMany(l => l.TriggerAreas.Select(ta => ta.Trigger.ToLower())).Distinct().Count() };");
            sb.AppendLine($"\t// -- end");
        }

        private static void AppendLevelData(IList<Level> levels, StringBuilder sb)
        {
            for (var i = 0; i < levels.Count; i++)
            {
                var level = levels[i];
                sb.AppendLine($"\tconst uint8_t level{i}_data[] PROGMEM = {{ // {level.Name}");
                sb.AppendLine($"\t\t{level.Width}, {level.Height}, // width, height");
                AppendSpawnpoints(level, sb);
                AppendPortals(level, sb);
                AppendTriggerAreas(level, sb);
                AppendTerrain(level, sb);
                sb.AppendLine($"\t}};");
            }
        }

        private static void AppendSpawnpoints(Level level, StringBuilder sb)
        {
            sb.AppendLine($"{level.Spawnpoints.Count}, // spawnpoints");
            foreach (var spawnpoint in level.Spawnpoints)
            {
                sb.AppendLine($"{spawnpoint.Point.X}, {spawnpoint.Point.Y},");
            }
        }

        private static void AppendPortals(Level level, StringBuilder sb)
        {
            sb.AppendLine($"{level.Portals.Count}, // portals");
            foreach (var portal in level.Portals)
            {
                var targetLevel = portal.LevelId == -1 ? 0 : portal.LevelId;
                var targetSpawnpoint = portal.SpawnpointId == -1 ? 0 : portal.SpawnpointId;
                sb.AppendLine($"{portal.Point.X}, {portal.Point.Y}, {targetLevel}, {targetSpawnpoint}, ");
            }
        }

        private static void AppendTriggerAreas(Level level, StringBuilder sb)
        {
            sb.AppendLine($"{level.TriggerAreas.Count}, // trigger areas");
            foreach (var triggerArea in level.TriggerAreas)
            {
                sb.AppendLine($"{triggerArea.TriggerId}, {triggerArea.Left}, {triggerArea.Top}, {triggerArea.Right}, {triggerArea.Bottom}, ");
            }
        }

        private static void AppendTerrain(Level level, StringBuilder sb)
        {
            var gameTerrain = TranslateGameTerrain(level);
            for (var y = 0; y < level.Height; y++)
            {
                for (var x = 0; x < level.Width; x++)
                {
                    sb.Append(gameTerrain[x, y]);
                    sb.Append(", ");
                }

                sb.AppendLine();
            }
        }

        /// <summary>
        /// Forms the raw terrain data directly usable by the game engine.
        /// </summary>
        private static byte[,] TranslateGameTerrain(Level level)
        {
            var gameTerrain = new byte[level.Width, level.Height];
            for (var y = 0; y < level.Height; y++)
            {
                for (var x = 0; x < level.Width; x++)
                {
                    var tile = level.Terrain[x, y];
                    gameTerrain[x, y] = IsGameTerrainTile(tile) ? (byte) tile : (byte)0;
                }
            }
            // add pressureplates: they are a special case to save some game resources by including the triggerId into the tile's index (64+ = pressure plates where triggerid = value - 64)
            foreach (var pressurePlate in level.PressurePlates)
            {
                gameTerrain[pressurePlate.Point.X, pressurePlate.Point.Y] = (byte)(64 + pressurePlate.TriggerId);
            }

            return gameTerrain;
        }

        private static bool IsGameTerrainTile(Tile tile)
        {
            return tile != Tile.Spawnpoint && tile != Tile.Portal && tile != Tile.PressurePlate;
        }

        private static void AppendLevelDefinitions(IList<Level> levels, StringBuilder sb)
        {
            sb.AppendLine("\tconst Level levels[] PROGMEM = {");
            for (var i = 0; i < levels.Count; i++)
            {
                sb.AppendLine($"\t\tLevel(level{i}_name_data, level{i}_data),");
            }
            sb.AppendLine($"\t}};");
        }

        private static void AppendLevelNames(IList<Level> levels, StringBuilder sb)
        {
            for (var i = 0; i < levels.Count; i++)
            {
                sb.AppendLine($"\tconst uint16_t level{i}_name_data[] PROGMEM = {{ // {levels[i].Name}");
                sb.AppendLine("\t0, 0, 0, 0, 0, 0, 0,");
                sb.AppendLine("\t0");
                sb.AppendLine("};");
            }
        }
    }
}