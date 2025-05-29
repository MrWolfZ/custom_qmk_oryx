#!/usr/bin/env bash

set -euo pipefail

# Save working directory

PWD=$(pwd)

SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

oryx_json_file_path="$SCRIPT_DIR/../oryx.json"
existing_layout_id=''

cd $SCRIPT_DIR/..

if [ -f "$oryx_json_file_path" ]; then
  existing_layout_id=$(cat "$oryx_json_file_path" | jq -r '.layoutId')
  echo "found existing oryx info with layout ID '$existing_layout_id'"
fi

layout_id=$(jq -r .'layout' $SCRIPT_DIR/../config.json)
geometry=$(jq -r .'geometry' $SCRIPT_DIR/../config.json)

if [ "$layout_id" = "$existing_layout_id" ]; then
  echo "configured layout '$layout_id' ID is same as existing oryx info; skipping..."
  exit 0
fi

echo "found different layout ID '$layout_id'; updating..."

response=$(curl --location 'https://oryx.zsa.io/graphql' --header 'Content-Type: application/json' --data '{"query":"query getLayout($hashId: String!, $revisionId: String!, $geometry: String) { layout(hashId: $hashId, geometry: $geometry, revisionId: $revisionId) { revision { hashId, qmkVersion, title } } }","variables":{"hashId":"'$layout_id'","geometry":"'$geometry'","revisionId":"latest"}}')

echo "${response}"

response=$(echo $response | jq '.data.layout.revision' | jq ". += {\"layoutId\":\"$layout_id\"}")

hash_id=$(echo "${response}" | jq -r '.hashId')
firmware_version=$(printf "%.0f" $(echo "${response}" | jq -r '.qmkVersion'))
change_description=$(echo "${response}" | jq -r '.title')

# on the oryx branch the keymap will always be the original from oryx, but by using a
# stable dir name like this, we can merge changes from oryx into our modified version
# on the main branch; this approach also lets us see the diff between the keymaps from
# oryx
keymap_dir="oryx.modified"

if [ "$firmware_version" -ge 24 ]; then
  keyboard_directory="zsa"
else
  keyboard_directory=""
fi

if [[ -z "${change_description}" ]]; then
  change_description="latest layout modification made with Oryx"
fi

echo "${response}" >"$oryx_json_file_path"

git fetch origin --prune
git worktree add .oryx oryx

cd .oryx

curl -L "https://oryx.zsa.io/source/${hash_id}" -o source.zip

# no need to keep old keymaps around, they are in the git history
rm -rf userspace/keyboards/$keyboard_directory/$geometry/keymaps

mkdir -p userspace/keyboards/$keyboard_directory/$geometry/keymaps/$keymap_dir

unzip -oj source.zip '*_source/*' -d userspace/keyboards/$keyboard_directory/$geometry/keymaps/$keymap_dir

sed -i 's/[[:space:]]*$//' userspace/keyboards/$keyboard_directory/$geometry/keymaps/$keymap_dir/*

rm source.zip

git add userspace/keyboards/$keyboard_directory/$geometry/keymaps

cp $SCRIPT_DIR/../config.json config.json
cp $SCRIPT_DIR/../oryx.json oryx.json
git add config.json oryx.json

git commit -m "✨(oryx/${layout_id}/${hash_id}): ${change_description}" || echo "No layout change"

git push

cd $SCRIPT_DIR/..

git worktree remove .oryx

git stash
git rebase oryx
git stash pop

cd $PWD
