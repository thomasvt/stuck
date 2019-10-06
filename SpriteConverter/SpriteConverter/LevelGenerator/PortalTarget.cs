using System;
using System.Text.RegularExpressions;

namespace PogoDataConverter.LevelGenerator
{
    public class PortalTarget
    {
        public string Level { get; }
        public string Spawnpoint { get; }

        private PortalTarget(string level, string spawnpoint)
        {
            Level = level;
            Spawnpoint = spawnpoint;
        }

        private static readonly Regex TargetIdRegex = new Regex("(?<level>.*?)\\.(?<spawnpoint>.*)");

        public static PortalTarget FromTargetId(string targetId, string levelName)
        {
            if (targetId is null)
                return null;
            var match = TargetIdRegex.Match(targetId);
            return match.Success ? new PortalTarget(match.Groups["level"].Value, match.Groups["spawnpoint"].Value) : new PortalTarget(levelName, targetId);
        }

        public override string ToString()
        {
            return $"{Level}.{Spawnpoint}";
        }
    }
}
