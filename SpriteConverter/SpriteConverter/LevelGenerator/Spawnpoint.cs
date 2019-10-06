
using System.Drawing;

namespace PogoDataConverter.LevelGenerator
{
    internal class Spawnpoint
    : IMarker
    {
        public string SpawnpointId { get; set; }
        public Point Point { get; set; }
    }
}
