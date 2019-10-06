
using System.Drawing;

namespace PogoDataConverter.LevelGenerator
{
    internal class Portal
    : IMarker
    {
        public PortalTarget Target { get; set; }
        public Point Point { get; set; }

        // properties set during link phase (where PortalTarget is translated into indexes)
        public int LevelId { get; set; }
        public int SpawnpointId { get; set; }
    }
}
