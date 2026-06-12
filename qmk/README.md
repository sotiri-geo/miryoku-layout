# QMK Source Snapshot

This directory contains the custom Vial-QMK keymap source used to build the firmware in `../firmware/`.

To rebuild from a Vial-QMK checkout, copy the keymap folder into the checkout:

```text
keyboards/crkbd/keymaps/chocofi_miryoku_vial/
```

Then compile:

```sh
qmk compile -kb crkbd/rev1 -km chocofi_miryoku_vial -e CONVERT_TO=rp2040_ce
```

The source is intentionally stored here rather than only keeping the UF2, because the Vial saved layout depends on the firmware's Vial UID, matrix layout, layer count, and enabled feature slots.

The keymap also enforces the intended QMK Settings values at boot. This is needed because Vial-QMK stores tap-hold settings in EEPROM; without the guard, Chordal Hold can be compiled in but left disabled at runtime after a flash or reset.
