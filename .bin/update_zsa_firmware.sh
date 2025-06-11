#!/usr/bin/env bash

set -euo pipefail

# Save working directory

PWD=$(pwd)

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

BRANCH="$(git rev-parse --abbrev-ref HEAD)"
if [[ "$BRANCH" != "main" ]]; then
  echo "firmware update must only be executed from main branch, currently on branch '$BRANCH'"
  exit 1
fi

oryx_json_file_path="$SCRIPT_DIR/../oryx.json"

firmware_version=$(printf "%.0f" $(cat "$oryx_json_file_path" | jq -r '.qmkVersion'))

cd $SCRIPT_DIR/..

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

cd $PWD
