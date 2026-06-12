# Miryoku Layout for My 36-Key Chocofi

This repo captures the Miryoku-inspired layout I use on my 36-key split Chocofi. It keeps the flashed Vial-QMK firmware, the importable Vial save file, a QMK-only diagnostic firmware, and the matching QMK keymap sources together so another Chocofi can be updated from the same known-good setup.

## Setup At A Glance

- Board: 36-key split Chocofi
- Layout style: Miryoku-inspired
- Base layer: Colemak-DH
- Mods: home-row mods
- Firmware tooling: Vial-QMK on `crkbd/rev1`; QMK-only keymap also kept for tap-hold testing
- Controller target: RP2040 Pro Micro-compatible controller, built with `CONVERT_TO=rp2040_ce`
- QMK behavior tuning: `TAPPING_TERM 180`, `QUICK_TAP_TERM 120`, `FLOW_TAP_TERM 150`, `CHORDAL_HOLD`, `HOLD_ON_OTHER_KEY_PRESS`

## Repo Contents

- `firmware/crkbd_rev1_chocofi_miryoku_vial_rp2040_ce.uf2` is the Vial-compatible UF2 flashed to both halves.
- `firmware/crkbd_rev1_chocofi_miryoku_qmk_rp2040_ce.uf2` is the QMK-only UF2 with the layout compiled directly into C.
- `exports/chocofi-miryoku-colemakdh.vil` is the canonical Vial save file to import after flashing.
- `exports/miryoku-colemakdh.vil` preserves the earlier source layout save used for the conversion.
- `qmk/keyboards/crkbd/keymaps/chocofi_miryoku_vial/` contains the Vial-QMK keymap source used to build the UF2.
- `qmk/keyboards/crkbd/keymaps/chocofi_miryoku_qmk/` contains the QMK-only source used to build the diagnostic UF2.
- `docs/layers-overview.svg` renders the active layers directly on GitHub.
- `docs/layout-notes.md` summarizes the base layer and the main layer roles.
- `docs/qmk-settings.md` documents the QMK behavior settings paired with this layout.

## Layer Diagram

![Layer overview](docs/layers-overview.svg)

Empty caps in the diagram inherit from the base layer. Omitted matrix slots are not physical keys on the 36-key Chocofi.

## Updating Another Chocofi

1. Flash `firmware/crkbd_rev1_chocofi_miryoku_vial_rp2040_ce.uf2` to the left half.
2. Flash the same UF2 to the right half.
3. Open Vial.
4. Back up the keyboard's current layout.
5. Import `exports/chocofi-miryoku-colemakdh.vil`.

Use the same UF2 for both halves. Put only one half into bootloader at a time, copy the UF2 to the `RPI-RP2` drive, wait for it to reboot, then repeat for the other half.

## Rebuilding The Firmware

Copy the target keymap folder into a Vial-QMK checkout under `keyboards/crkbd/keymaps/`.

For the Vial-compatible firmware, compile:

```sh
qmk compile -kb crkbd/rev1 -km chocofi_miryoku_vial -e CONVERT_TO=rp2040_ce
```

For the QMK-only firmware, compile:

```sh
qmk compile -kb crkbd/rev1 -km chocofi_miryoku_qmk -e CONVERT_TO=rp2040_ce
```

The expected output names are:

```text
crkbd_rev1_chocofi_miryoku_vial_rp2040_ce.uf2
crkbd_rev1_chocofi_miryoku_qmk_rp2040_ce.uf2
```

## Highlights

- Colemak-DH base layer with home-row mods on `A R S T` and `O I E N`
- Miryoku-style layer usage centered around thumb keys
- Vial save preserves navigation/edit, mouse, media/system, symbols, and numbers
- QMK-only source bakes navigation/edit, media/system, symbols, and numbers into `keymap.c`, including C replacements for the three Vial macro slots
- Vial-compatible saved layout with 10 layers, 32 tap-dance slots, 32 combo slots, 32 key-override slots, and 32 alt-repeat slots
- Caps Word, Layer Lock, Repeat Key, and media keys compiled into both firmware paths
- Mouse keys stay available only in the Vial firmware path; the QMK-only test firmware omits the mouse layer
- Tap dance, combos, and key overrides stay enabled in the Vial firmware path for future Vial edits

## References

- [QMK Tap-Hold configuration](https://docs.qmk.fm/tap_hold)
- [QMK Caps Word](https://develop-docs.qmk.fm/features/caps_word)
- [Vial porting guide](https://get.vial.today/docs/porting-to-vial.html)
