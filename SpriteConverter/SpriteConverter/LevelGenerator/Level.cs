using System.Collections.Generic;

namespace PogoDataConverter.LevelGenerator
{
    internal class Level
    {
        public string Name { get; set; }
        public int Width { get; set; }
        public int Height { get; set; }
        public Tile[,] Terrain { get; set; }
        public List<Spawnpoint> Spawnpoints { get; set; }
        public List<Portal> Portals { get; set; }
        public List<TriggerArea> TriggerAreas { get; set; }
        public List<PressurePlate> PressurePlates { get; set; }
        public string Error { get; set; }
    }
}
