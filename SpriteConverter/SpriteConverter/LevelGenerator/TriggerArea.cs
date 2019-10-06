namespace PogoDataConverter.LevelGenerator
{
    internal class TriggerArea
    : IMarker
    {
        public string Trigger { get; set; }
        public int Left { get; set; }
        public int Top { get; set; }
        public int Right { get; set; }
        public int Bottom { get; set; }

        // set by linking phase to id of Trigger name
        public int TriggerId { get; set; }
    }
}
