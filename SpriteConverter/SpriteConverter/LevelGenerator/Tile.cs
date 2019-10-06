namespace PogoDataConverter.LevelGenerator
{
    // tiles as they are numbered in the Pogo game code
    public enum Tile
    {
        None = 0,

        WallSecret = 3,
        Ladder = 4,
        Spikes = 5,

        DoorBlue = 6,
        DoorGreen,
        DoorOrange,
        DoorRed,

        GemBlue = 10,
        GemGreen,
        GemOrange,
        GemRed,
        PowerUpDoubleJump,
        PowerUpTripleJump,
        PowerUpArrowClimb,

        Potion = 17,
        Coin = 18,

        Goblin = 19,
        Imp = 20,
        Boss = 21, // reserved

        ClueSign = 22,
        Catapult = 23,

        Pillar = 27,
        StairsAdd = 28,
        StairsRemove,

        Wall = 30,
        WallGrass,
        WoodJunction,
        WoodHorizontal,
        WoodVertical,

        // 64+ triggers with trigger id = x - 64

        FlameThrowerOffset = 240,
        // 240+ = flamethrowers (where timing schedule = x - 240)

        // following are temporarily for code generator, they dont end up in the game engines data
        Portal = 60, 
        Spawnpoint = 70,
        PressurePlate = 80,



        //GemSecret = 128, // the ominous skull key to the secret level
    }
}
