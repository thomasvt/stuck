using System;

namespace PogoDataConverter.LevelGenerator
{
    class TileMapper
    {
        public static Tile GetTileFromFilename(string filename)
        {
            if (filename.Contains("walltiles1"))
                return Tile.Wall;

            if (filename.Contains("grass"))
                return Tile.WallGrass;

            if (filename.Contains("wood1"))
                return Tile.WoodJunction;

            if (filename.Contains("wood2"))
                return Tile.WoodHorizontal;

            if (filename.Contains("wood3"))
                return Tile.WoodVertical;

            if (filename.Contains("secret_wall"))
                return Tile.WallSecret;

            if (filename.Contains("ladder"))
                return Tile.Ladder;

            if (filename.Contains("door_blue"))
                return Tile.DoorBlue;

            if (filename.Contains("door_green"))
                return Tile.DoorGreen;

            if (filename.Contains("door_orange"))
                return Tile.DoorOrange;

            if (filename.Contains("door_red"))
                return Tile.DoorRed;

            if (filename.Contains("gem_blue"))
                return Tile.GemBlue;

            if (filename.Contains("gem_green"))
                return Tile.GemGreen;

            if (filename.Contains("gem_orange"))
                return Tile.GemOrange;

            if (filename.Contains("gem_red"))
                return Tile.GemRed;

            if (filename.Contains("double_jump"))
                return Tile.PowerUpDoubleJump;

            if (filename.Contains("triple_jump"))
                return Tile.PowerUpTripleJump;

            if (filename.Contains("arrow_climb"))
                return Tile.PowerUpArrowClimb;

            if (filename.Contains("clue"))
                return Tile.ClueSign;

            if (filename.Contains("catapult"))
                return Tile.Catapult;

            if (filename.Contains("pillar"))
                return Tile.Pillar;

            if (filename.Contains("spikes"))
                return Tile.Spikes;

            if (filename.Contains("portal"))
                return Tile.Portal;

            if (filename.Contains("princess"))
                return Tile.Spawnpoint;

            if (filename.Contains("plate"))
                return Tile.PressurePlate;

            if (filename.Contains("goblin"))
                return Tile.Goblin;
            if (filename.Contains("imp-idle"))
                return Tile.Imp;

            if (filename.Contains("potion"))
                return Tile.Potion;

            if (filename.Contains("coin"))
                return Tile.Coin;

            //if (filename.Contains("gem5"))
            //    return Tile.GemSecret;

            if (filename.Contains("stairs_add"))
                return Tile.StairsAdd;

            if (filename.Contains("stairs_remove"))
                return Tile.StairsRemove;

            if (filename.Contains("firecanon"))
                return Tile.FlameThrowerOffset;

            throw new NotSupportedException("Unknown tile filename: " + filename);
        }
    }
}