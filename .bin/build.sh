#!/usr/bin/env bash

set -euo pipefail

# Save working directory

PWD=$(pwd)

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

BRANCH="$(git rev-parse --abbrev-ref HEAD)"
if [[ "$BRANCH" != "main" ]]; then
  echo "build must only be executed from main branch, currently on branch '$BRANCH'"
  exit 1
fi

oryx_json_file_path="$SCRIPT_DIR/../oryx.json"

"$SCRIPT_DIR/download_and_commit_oryx.sh"

cd $SCRIPT_DIR/..

# Compile the firmware

layout_id=$(jq -r .'layout' $SCRIPT_DIR/../config.json)
geometry=$(jq -r .'geometry' $SCRIPT_DIR/../config.json)
firmware_prefix=$(jq -r .'firmwarePrefix' $SCRIPT_DIR/../config.json)
hash_id=$(cat "$oryx_json_file_path" | jq -r '.hashId')
firmware_version=$(printf "%.0f" $(cat "$oryx_json_file_path" | jq -r '.qmkVersion'))

if [ "$firmware_version" -ge 24 ]; then
  keyboard_directory="zsa"
else
  keyboard_directory=""
fi

keymap_dir="oryx.modified"

cd qmk_firmware

qmk config user.overlay_dir="$(realpath $SCRIPT_DIR/../userspace)"
qmk compile -kb "$keyboard_directory/$geometry" -km "$keymap_dir"

mkdir -p "$SCRIPT_DIR/../firmwares"

firmware_file_name="$firmware_prefix$(date '+%Y-%m-%dT%H%M%S')_${layout_id}_${hash_id}.bin"
echo "created firmware $firmware_file_name"

for file in "$SCRIPT_DIR"/../qmk_firmware/.build/*.bin; do
  cp "$file" "$SCRIPT_DIR/../firmwares/$firmware_file_name"
done

cd $PWD
