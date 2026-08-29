# QMK Source Snapshot

This directory contains the custom keymap source used to build the firmware in `../firmware/`:

```text
keyboards/crkbd/keymaps/chocofi_miryoku_qmk/
```

It bakes the layout directly into `keymap.c`, including the three editing macros as custom keycodes. There is no dynamic keymap and no EEPROM-stored settings, so this source fully describes what the keyboard does.

To rebuild, copy the keymap folder into a QMK checkout and compile:

```sh
qmk compile -kb crkbd/rev1 -km chocofi_miryoku_qmk -e CONVERT_TO=rp2040_ce
```

The keymap needs a QMK tree that provides `CHORDAL_HOLD` and `FLOW_TAP_TERM`. It has no Vial dependencies, so it builds equally well in a Vial-QMK checkout.

The source is stored here rather than only keeping the UF2 so the tap-hold tuning stays reviewable and diffable. See `../docs/qmk-settings.md` for the reasoning behind the settings.
