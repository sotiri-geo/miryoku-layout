# QMK Source Snapshot

This directory contains the custom keymap sources used to build the firmware in `../firmware/`.

The Vial-compatible source is:

```text
keyboards/crkbd/keymaps/chocofi_miryoku_vial/
```

It keeps the layout editable through Vial, so the actual layout is imported from `../exports/chocofi-miryoku-colemakdh.vil` after flashing.

The QMK-only source is:

```text
keyboards/crkbd/keymaps/chocofi_miryoku_qmk/
```

It bakes the layout directly into `keymap.c`, including C replacements for the three Vial macro slots. Use this build when testing whether Vial runtime settings or EEPROM state are interfering with tap-hold behavior.

To rebuild from a Vial-QMK checkout, copy the relevant keymap folder into the checkout, then compile one of:

```sh
qmk compile -kb crkbd/rev1 -km chocofi_miryoku_vial -e CONVERT_TO=rp2040_ce
qmk compile -kb crkbd/rev1 -km chocofi_miryoku_qmk -e CONVERT_TO=rp2040_ce
```

The sources are intentionally stored here rather than only keeping UF2 files. The Vial saved layout depends on the firmware's Vial UID, matrix layout, layer count, and enabled feature slots; the QMK-only source gives a simpler compiled layout for debugging home-row-mod behavior.

The Vial keymap also enforces the intended QMK Settings values at boot. This is needed because Vial-QMK stores tap-hold settings in EEPROM; without the guard, Chordal Hold can be compiled in but left disabled at runtime after a flash or reset.
