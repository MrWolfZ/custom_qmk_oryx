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

git submodule update --init --remote --depth=1
cd qmk_firmware
git checkout -B firmware$firmware_version origin/firmware$firmware_version
git submodule update --init --recursive
cd ..
git add qmk_firmware
git commit -m "✨(qmk): Update firmware" && git push || echo "No QMK change"

cd qmk_firmware

# the 'echo "3"' answers a prompt that ask for whether the selected firmware is correct
echo "3" | qmk setup zsa/qmk_firmware -b firmware$firmware_version -y

qmk config user.overlay_dir="$(realpath $SCRIPT_DIR/../userspace)"
qmk compile -kb "$keyboard_directory/$geometry" -km "$keymap_dir"

mkdir -p "$SCRIPT_DIR/../firmwares"

firmware_file_name="$firmware_prefix$(date '+%Y-%m-%dT%H%M%S')_${layout_id}_${hash_id}.bin"
echo "created firmware $firmware_file_name"

for file in "$SCRIPT_DIR"/../qmk_firmware/.build/*.bin; do
  cp "$file" "$SCRIPT_DIR/../firmwares/$firmware_file_name"
done

cd $PWD
