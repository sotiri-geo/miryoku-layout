# Layout Notes

## Base Layer

The base layer is Colemak-DH with home-row mods.

The rows below are written in display order, left to right as the keyboard appears in front of me.

Left hand:

- `Q W F P B`
- `LGUI_T(A) LALT_T(R) LCTL_T(S) LSFT_T(T) G`
- `Z X C D V`

Right hand:

- `J L U Y '`
- `M RSFT_T(N) RCTL_T(E) RALT_T(I) RGUI_T(O)`
- `K H , . /`

Thumb keys:

- Left: `LT3(Escape)`, `LT1(Space)`, `Tab`
- Right: `LT5(Enter)`, `LT4(Backspace)`, `=`

## Layer Sketch

- Layer 1 is the main navigation and edit layer.
- Layer 2 is the mouse layer with pointer, wheel, and buttons.
- Layer 3 holds media, RGB, and system controls.
- Layer 4 is the shifted symbol layer.
- Layer 5 is the number and unshifted symbol layer.

## Saved Export

The canonical Chocofi-compatible Vial save file in this repo is `exports/chocofi-miryoku-colemakdh.vil`.

It is formatted for the firmware in `firmware/crkbd_rev1_chocofi_miryoku_vial_rp2040_ce.uf2`, including 10 layers and the Vial feature arrays required by the compiled firmware.

The earlier source save is kept at `exports/miryoku-colemakdh.vil` for reference.

## Firmware Source

The matching Vial-QMK keymap source is stored under `qmk/keyboards/crkbd/keymaps/chocofi_miryoku_vial/`.

The keymap uses `LAYOUT_split_3x5_3`, and `keymap.c` defines a `chordal_hold_layout` where alpha keys are left/right handed and thumb keys are `*`. The `*` handedness means thumb layer-taps can chord naturally with either hand.

## Preserved Macros

The settled Vial export includes three custom macros (`M0`, `M1`, and `M2`). They are kept as-is so this repo matches the layout snapshot I am actually using.
