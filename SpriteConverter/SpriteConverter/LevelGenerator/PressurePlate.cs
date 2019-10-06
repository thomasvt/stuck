using System.Drawing;

namespace PogoDataConverter.LevelGenerator
{
    public class PressurePlate
    : IMarker
    {
        public string Trigger { get; set; }
        public Point Point { get; set; }

        // set during linking
        public int TriggerId { get; set; }
    }
}
