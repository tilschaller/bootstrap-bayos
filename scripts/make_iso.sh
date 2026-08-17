#!/usr/bin/env bash
set -ex

BUILD_ROOT="$1"
cd "$BUILD_ROOT"

xorriso -as mkisofs -R -r -J -b boot/limine/limine-bios-cd.bin \
	-no-emul-boot -boot-load-size 4 -boot-info-table -hfsplus \
	-apm-block-size 2048 --efi-boot boot/limine/limine-uefi-cd.bin \
	-efi-boot-part --efi-boot-image --protective-msdos-label \
	iso -o bayos.iso

tools/host-limine/bin/limine bios-install bayos.iso
