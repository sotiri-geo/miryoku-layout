# Firmware Artifact

This folder stores the working UF2 artifacts for the Chocofi RP2040 build:

```text
crkbd_rev1_chocofi_miryoku_vial_rp2040_ce.uf2
crkbd_rev1_chocofi_miryoku_qmk_rp2040_ce.uf2
```

Flash the same chosen UF2 to both halves.

1. Disconnect the halves from each other.
2. Put one half into bootloader mode.
3. Copy the UF2 to the `RPI-RP2` drive.
4. Wait for the drive to disappear.
5. Repeat for the other half.

Use `crkbd_rev1_chocofi_miryoku_vial_rp2040_ce.uf2` when you want to edit the layout in Vial. After both halves are flashed, reconnect the split cable, open Vial, and import:

```text
exports/chocofi-miryoku-colemakdh.vil
```

Use `crkbd_rev1_chocofi_miryoku_qmk_rp2040_ce.uf2` when you want to test the layout compiled directly into QMK. Vial will not be able to edit or import a `.vil` file for this firmware.

The firmware files were built from the keymap sources in:

```text
qmk/keyboards/crkbd/keymaps/chocofi_miryoku_vial/
qmk/keyboards/crkbd/keymaps/chocofi_miryoku_qmk/
```

The Vial build includes a runtime guard that keeps Chordal Hold, Hold-on-other-key, Flow Tap, and the tap timing settings aligned with the saved Vial layout after flashing or EEPROM reset. The QMK-only build does not use Vial or QMK Settings, so those tap-hold settings come directly from `config.h`.
