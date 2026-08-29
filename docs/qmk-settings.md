# QMK Settings

These are the QMK behavior settings paired with this layout to make home-row mods on Colemak-DH feel predictable on a small split board.

## `config.h`

```c
#pragma once

#define TAPPING_TERM 350
#define QUICK_TAP_TERM 0
#define FLOW_TAP_TERM 150
#define CHORDAL_HOLD
#define HOLD_ON_OTHER_KEY_PRESS

#define CAPS_WORD_IDLE_TIMEOUT 3000
#define CAPS_WORD_INVERT_ON_SHIFT
```

## `rules.mk`

```make
LTO_ENABLE          = yes

RGBLIGHT_ENABLE     = no
RGB_MATRIX_ENABLE   = no
MOUSEKEY_ENABLE     = no
EXTRAKEY_ENABLE     = yes

OLED_ENABLE         = no
OLED_DRIVER         = SSD1306

CAPS_WORD_ENABLE    = yes
LAYER_LOCK_ENABLE   = yes
REPEAT_KEY_ENABLE   = yes
```

Mouse keys are disabled because the keymap has no mouse layer. RGB is disabled because the board has no LEDs driven by this firmware.

## Why These Settings

The three tap-hold options work as a set, and QMK's documentation treats them that way: Chordal Hold is intended to be used together with either Permissive Hold or Hold On Other Key Press.

- `CHORDAL_HOLD` applies an opposite-hands rule: same-hand rolls resolve as taps, which avoids accidental home-row-mod activation while typing.
- `HOLD_ON_OTHER_KEY_PRESS` lets opposite-hand chords resolve as holds the instant the other key goes down, which makes cross-hand shortcuts feel immediate.
- `FLOW_TAP_TERM 150` protects fast typing by forcing tap behavior when a tap-hold key is pressed soon after a previous normal typing key.

### `TAPPING_TERM 350`

Chordal Hold has no effect after the tapping term. Its same-hand-settles-as-tap rule only applies *within* `TAPPING_TERM`, so the long term is deliberate: it widens the window in which same-hand rolls are protected from firing a mod.

The long term costs very little in practice. Because `HOLD_ON_OTHER_KEY_PRESS` settles opposite-hand chords immediately, the primary cross-hand workflow never waits on the tapping term at all. The term is only felt in two cases:

- A lone hold, where a mod is held with no other key pressed.
- A deliberate same-hand chord, such as `Ctrl`+`C` with Ctrl on left-home `S` and `C` on the same hand. Using the mirrored right-hand mod instead makes the chord cross-hand and immediate.

### `QUICK_TAP_TERM 0`

Quick tap is the behavior where re-pressing a key within a short window of tapping it sends the tap keycode with auto-repeat instead of the hold. On home-row mods this shows up as `ttttt` where Shift was intended.

Chordal Hold cannot help here. Its opposite-hands rule compares two *different* keys, so it has nothing to say about the same key being pressed twice. Quick tap is the one gap in the guard, which makes disabling it more important the higher `TAPPING_TERM` is.

The value must be defined explicitly as `0`. Deleting the define does not disable the feature — QMK falls back to `QUICK_TAP_TERM = TAPPING_TERM`, which here would mean a 350 ms window.

### `is_flow_tap_key()`

Flow Tap's default key set is `KC_SPC`, `KC_A`–`KC_Z`, `KC_DOT`, `KC_COMM`, `KC_SCLN` and `KC_SLSH`. It omits `KC_QUOT`, which on this layout sits on the right pinky.

That leaves a gap: after an apostrophe, the next tap-hold key gets no Flow Tap protection, and Chordal Hold does not cover it either, because `'` is right-handed while `S` and `T` are left-hand mod-taps. Words like `don't`, `it's` and `can't` are the exposed cases. `keymap.c` overrides the callback to add `KC_QUOT`.

The callback's mod guard is kept as-is, so Flow Tap still disables itself while GUI, Ctrl or Alt is held and cannot interfere with shortcuts.

## Notes

- `PERMISSIVE_HOLD` is intentionally off. It is the alternative to `HOLD_ON_OTHER_KEY_PRESS` for the opposite-hands case, but it requires the other key to be pressed *and released* first, which is less responsive for a cross-hand workflow.
- `IGNORE_MOD_TAP_INTERRUPT` is not used. In newer QMK it was removed in favor of hold-on-other-key behavior.
- Flow Tap disables itself while a tap-hold key is still undecided, so chording two home-row mods together does not require waiting out the flow term.
- To observe the decisions rather than infer them, build once with `CONSOLE_ENABLE = yes` and run `qmk console`. Chordal Hold logs `Tapping: End. Chord considered a tap` each time the same-hand rule fires.
- References: [QMK Tap-Hold configuration](https://docs.qmk.fm/tap_hold), [QMK Caps Word](https://develop-docs.qmk.fm/features/caps_word).
