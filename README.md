# Miryoku Layout for My 36-Key Chocofi

This repo captures the Miryoku-inspired layout I use on my 36-key split Chocofi. It keeps the flashed QMK firmware and the matching keymap source together so another Chocofi can be updated from the same known-good setup.

The layout is compiled directly into `keymap.c`. There is no dynamic keymap and no EEPROM-stored layout, so the source in this repo is the single source of truth for what the keyboard does.

## Setup At A Glance

- Board: 36-key split Chocofi
- Layout style: Miryoku-inspired
- Base layer: Colemak-DH
- Mods: home-row mods
- Firmware tooling: QMK on `crkbd/rev1`
- Controller target: RP2040 Pro Micro-compatible controller, built with `CONVERT_TO=rp2040_ce`
- QMK behavior tuning: `TAPPING_TERM 350`, `QUICK_TAP_TERM 0`, `FLOW_TAP_TERM 150`, `CHORDAL_HOLD`, `HOLD_ON_OTHER_KEY_PRESS`

## Repo Contents

- `firmware/crkbd_rev1_chocofi_miryoku_qmk_rp2040_ce.uf2` is the UF2 flashed to both halves.
- `qmk/keyboards/crkbd/keymaps/chocofi_miryoku_qmk/` contains the keymap source used to build it.
- `docs/layers-overview.svg` renders the active layers directly on GitHub.
- `docs/layout-notes.md` summarizes the base layer and the main layer roles.
- `docs/qmk-settings.md` documents the QMK behavior settings paired with this layout.

## Layer Diagram

![Layer overview](docs/layers-overview.svg)

Empty caps in the diagram inherit from the base layer. Omitted matrix slots are not physical keys on the 36-key Chocofi.

## Updating Another Chocofi

1. Flash `firmware/crkbd_rev1_chocofi_miryoku_qmk_rp2040_ce.uf2` to the left half.
2. Flash the same UF2 to the right half.
3. Reconnect the split cable.

Use the same UF2 for both halves. Put only one half into bootloader at a time, copy the UF2 to the `RPI-RP2` drive, wait for it to reboot, then repeat for the other half.

The layout is baked into the firmware, so there is nothing to import afterwards.

## Rebuilding The Firmware

Copy the keymap folder into a QMK checkout under `keyboards/crkbd/keymaps/`, then compile:

```sh
qmk compile -kb crkbd/rev1 -km chocofi_miryoku_qmk -e CONVERT_TO=rp2040_ce
```

The expected output name is:

```text
crkbd_rev1_chocofi_miryoku_qmk_rp2040_ce.uf2
```

The keymap needs a QMK tree that provides `CHORDAL_HOLD` and `FLOW_TAP_TERM`. It has no Vial dependencies, so it builds equally well in a Vial-QMK checkout.

## Highlights

- Colemak-DH base layer with home-row mods on `A R S T` and `O I E N`
- Miryoku-style layer usage centered around thumb keys
- Navigation/edit, media/system, symbols, and numbers layers baked into `keymap.c`
- Three editing macros implemented as custom keycodes in C
- Caps Word, Layer Lock, and Repeat Key compiled in
- Quick tap disabled outright, so re-pressing a home-row mod never repeats the letter instead of engaging the mod
- `is_flow_tap_key()` extended to cover the apostrophe, which QMK's default set omits

## References

- [QMK Tap-Hold configuration](https://docs.qmk.fm/tap_hold)
- [QMK Caps Word](https://develop-docs.qmk.fm/features/caps_word)
