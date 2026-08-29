# Firmware Artifact

This folder stores the working UF2 artifact for the Chocofi RP2040 build:

```text
crkbd_rev1_chocofi_miryoku_qmk_rp2040_ce.uf2
```

Flash the same UF2 to both halves.

1. Disconnect the halves from each other.
2. Put one half into bootloader mode.
3. Copy the UF2 to the `RPI-RP2` drive.
4. Wait for the drive to disappear.
5. Repeat for the other half.

The layout is compiled into the firmware, so there is nothing to import once both halves are flashed. Reconnect the split cable and the board is ready.

The firmware was built from the keymap source in:

```text
qmk/keyboards/crkbd/keymaps/chocofi_miryoku_qmk/
```

Tap-hold behavior comes entirely from `config.h` and the callbacks in `keymap.c`. There is no EEPROM-stored settings state, so flashing or resetting cannot leave the board with different tap-hold behavior than the source describes.
