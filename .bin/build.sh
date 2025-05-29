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

# workaround for missing call to pre_process_record_user in oryx firmware
line_number=314
oryx_file="keyboards/zsa/common/oryx.c"
content=$(sed -n "${line_number}p" "$oryx_file")
expected_content="    return true;"
replacement="    return pre_process_record_user(keycode, record);"

if [[ "$content" != "$expected_content" ]]; then
  echo "pre_process_record_kb fix: line $line_number did not match expected content '$expected_content', was '$content'. Aborting..."
  exit 1
fi

mv "$oryx_file" "${oryx_file}.tmp"

revert_oryx_file() {
  mv "${oryx_file}.tmp" "$oryx_file"
}

trap revert_oryx_file EXIT

awk -v n="$line_number" -v r="$replacement" 'NR == n {$0 = r} {print}' "${oryx_file}.tmp" >"$oryx_file"
# end workaround

qmk config user.overlay_dir="$(realpath $SCRIPT_DIR/../userspace)"
qmk compile -kb "$keyboard_directory/$geometry" -km "$keymap_dir"

mkdir -p "$SCRIPT_DIR/../firmwares"

firmware_file_name="$firmware_prefix$(date '+%Y-%m-%dT%H%M%S')_${layout_id}_${hash_id}.bin"
echo "created firmware $firmware_file_name"

for file in "$SCRIPT_DIR"/../qmk_firmware/.build/*.bin; do
  cp "$file" "$SCRIPT_DIR/../firmwares/$firmware_file_name"
done

cd $PWD
