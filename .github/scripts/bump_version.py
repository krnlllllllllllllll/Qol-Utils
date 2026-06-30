import json
import sys

path = sys.argv[1]

with open(path, "r") as f:
    data = json.load(f)

version = data.get("version", "1.0.0")
parts = version.split(".")

parts[-1] = str(int(parts[-1]) + 1)
new_version = ".".join(parts)

data["version"] = new_version

with open(path, "w") as f:
    json.dump(data, f, indent=2)

print(f"Bumped version to {new_version}")
