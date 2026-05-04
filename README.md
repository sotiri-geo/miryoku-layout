# Miryoku Layout for My 36-Key Chocofi

This repo captures the Miryoku-inspired layout I have settled on for the 36-key split Chocofi I use as my daily driver. It keeps the importable Vial export alongside the QMK notes I want handy whenever I revisit the firmware.

## Setup At A Glance

- Board: 36-key split Chocofi
- Layout style: Miryoku-inspired
- Base layer: Colemak-DH
- Mods: homerow mods
- Firmware tooling: Vial / QMK
- QMK behavior tuning: `TAPPING_TERM 240`, `PERMISSIVE_HOLD`, `IGNORE_MOD_TAP_INTERRUPT`

## Repo Contents

- `exports/final-miryoku-corne-v4-vial-fixed.json` contains the settled Vial export.
- `docs/layout-notes.md` summarizes the base layer and the main layer roles.
- `docs/qmk-settings.md` documents the QMK behavior settings paired with this layout.

## Importing The Layout

1. Open Vial.
2. Back up your current layout.
3. Import `exports/final-miryoku-corne-v4-vial-fixed.json`.
4. If you compile your own firmware, apply the QMK settings from `docs/qmk-settings.md`.

## Highlights

- Colemak-DH base layer with homerow mods on `A R S T` and `O I E N`
- Miryoku-style layer usage centered around thumb keys
- Navigation/edit, mouse, media/system, symbols, and numbers preserved in the export
- The Vial snapshot keeps the custom macros already present in the settled layout

## Note On Naming

The export file name includes `corne-v4` because that is the name of the settled Vial export I am preserving here. The physical board I use daily is a 36-key Chocofi.
