#!/bin/bash
# Build this keymap in QMK's Docker image and flash it to the half plugged into USB.
# Usage: ./flash.sh            build, then flash
#        ./flash.sh --no-build flash the existing .uf2
# Enter the bootloader with Space + Enter + top-left key, or double-tap reset.
set -euo pipefail

ROOT=$(git -C "$(dirname "$0")" rev-parse --show-toplevel)
UF2="$ROOT/beekeeb_piantor_pro_blez.uf2"

if [ "${1:-}" != "--no-build" ]; then
  git -C "$ROOT" submodule update --init --recursive --depth 50 -q
  docker run --rm --user "$(id -u):$(id -g)" -w /qmk_firmware -v "$ROOT":/qmk_firmware \
    -e SKIP_GIT=true ghcr.io/qmk/qmk_cli make beekeeb/piantor_pro:blez
fi

echo "Waiting for the keyboard in bootloader mode (RPI-RP2)..."
for _ in $(seq 1 600); do
  dev=$(readlink -f /dev/disk/by-label/RPI-RP2 2>/dev/null || true)
  [ -b "$dev" ] && break
  sleep 1
done
[ -b "$dev" ] || { echo "Timed out after 10 minutes"; exit 1; }
sleep 1

# The drive isn't auto-mounted on this machine, so mount it if needed.
mnt=$(lsblk -no MOUNTPOINTS "$dev" | head -1)
[ -n "$mnt" ] || mnt=$(udisksctl mount -b "$dev" | sed -n 's/.* at \(.*\)$/\1/p')
cp "$UF2" "$mnt/" && sync
echo "Firmware copied to $mnt"

while [ -e /dev/disk/by-label/RPI-RP2 ]; do sleep 1; done
echo "Keyboard rebooted with the new firmware."
