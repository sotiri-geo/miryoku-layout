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

- Left: `LT2(Escape)`, `LT1(Space)`, `Tab`
- Right: `LT4(Enter)`, `LT3(Backspace)`, `=`

## Layers

- Layer 1 is the main navigation and edit layer.
- Layer 2 holds media, RGB, and system controls.
- Layer 3 is the shifted symbol layer.
- Layer 4 is the number and unshifted symbol layer.

There is no mouse layer. Mouse keys are not compiled in.

## Firmware Source

The keymap source is stored under `qmk/keyboards/crkbd/keymaps/chocofi_miryoku_qmk/`. It compiles the layout directly into `keymap.c`, so the firmware behaves the same on a fresh flash as it does after an EEPROM reset — there is no dynamic keymap to import or lose.

The keymap uses `LAYOUT_split_3x5_3`, and `keymap.c` defines a `chordal_hold_layout` where alpha keys are left/right handed and thumb keys are `*`. The `*` handedness exempts thumbs from the opposite-hands rule, which lets thumb layer-taps chord naturally with either hand.

`keymap.c` also overrides `is_flow_tap_key()` to add `KC_QUOT` to Flow Tap's key set. See `qmk-settings.md` for why.

## Macros

Three editing macros are implemented as custom keycodes in C:

- `M_3W` types `3w`
- `M_3B` types `3b`
- `M_GD` types `gd`
