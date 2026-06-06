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
