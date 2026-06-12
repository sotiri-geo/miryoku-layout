# Firmware Artifact

This folder stores the working UF2 for the Chocofi RP2040 build:

```text
crkbd_rev1_chocofi_miryoku_vial_rp2040_ce.uf2
```

Flash the same UF2 to both halves.

1. Disconnect the halves from each other.
2. Put one half into bootloader mode.
3. Copy the UF2 to the `RPI-RP2` drive.
4. Wait for the drive to disappear.
5. Repeat for the other half.

After both halves are flashed, reconnect the split cable, open Vial, and import:

```text
exports/chocofi-miryoku-colemakdh.vil
```

The firmware was built from the keymap source in:

```text
qmk/keyboards/crkbd/keymaps/chocofi_miryoku_vial/
```

This build includes a runtime guard that keeps Chordal Hold, Hold-on-other-key, Flow Tap, and the tap timing settings aligned with the saved Vial layout after flashing or EEPROM reset.
