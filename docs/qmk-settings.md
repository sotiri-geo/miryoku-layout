# QMK Settings

These are the QMK behavior settings paired with this layout to make home-row mods on Colemak-DH feel predictable on a small split board.

## `config.h`

```c
#pragma once

#define TAPPING_TERM 180
#define QUICK_TAP_TERM 120
#define FLOW_TAP_TERM 150
#define CHORDAL_HOLD
#define HOLD_ON_OTHER_KEY_PRESS

#define CAPS_WORD_IDLE_TIMEOUT 3000
#define CAPS_WORD_INVERT_ON_SHIFT
```

## Vial Feature Capacity

The firmware and save file are intentionally sized for the current Vial export:

```c
#define DYNAMIC_KEYMAP_LAYER_COUNT 10
#define VIAL_TAP_DANCE_ENTRIES 32
#define VIAL_COMBO_ENTRIES 32
#define VIAL_KEY_OVERRIDE_ENTRIES 32
```

Because `REPEAT_KEY_ENABLE = yes`, Vial also exposes 32 alt-repeat entries. The canonical export fills unused slots with neutral values so Vial can import it cleanly.

## `rules.mk`

```make
VIA_ENABLE          = yes
VIAL_ENABLE         = yes
LTO_ENABLE          = yes

RGBLIGHT_ENABLE     = yes
RGB_MATRIX_ENABLE   = no
MOUSEKEY_ENABLE     = yes
EXTRAKEY_ENABLE     = yes
TAP_DANCE_ENABLE    = yes
KEY_OVERRIDE_ENABLE = yes
COMBO_ENABLE        = yes
QMK_SETTINGS        = yes

CAPS_WORD_ENABLE    = yes
LAYER_LOCK_ENABLE   = yes
REPEAT_KEY_ENABLE   = yes
```

## Why These Settings

- `CHORDAL_HOLD` applies an opposite-hands rule: same-hand rolls resolve as taps, which helps avoid accidental home-row-mod activation while typing.
- `HOLD_ON_OTHER_KEY_PRESS` lets opposite-hand chords resolve as holds immediately, which makes shortcuts like `Ctrl+C` or `Shift+letter` feel responsive.
- `FLOW_TAP_TERM 150` protects fast typing by forcing tap behavior when another tap-hold key is pressed soon after a previous normal typing key.
- `TAPPING_TERM 180` is the main tap-vs-hold window.
- `QUICK_TAP_TERM 120` keeps quick repeated taps usable without making home-row mods too eager.
- Caps Word is enabled so `CW_TOGG` can be placed in Vial; it turns itself off at word boundaries such as Space.

## Vial Saved Settings

The canonical export includes QMK Settings values matching the firmware:

```json
{
  "7": 180,
  "22": 0,
  "23": 1,
  "24": 0,
  "25": 120,
  "26": 1,
  "27": 150
}
```

For this Vial-QMK tree, these map to tapping term, permissive hold, hold-on-other-key, retro tapping, quick tap term, chordal hold, and flow tap term.

## Runtime Guard

Because `QMK_SETTINGS = yes` stores these tap-hold options in EEPROM, a fresh flash, EEPROM reset, or partial Vial import can leave Chordal Hold off even though `CHORDAL_HOLD` is compiled. When that happens, same-hand rolls such as holding `T` and pressing `V` incorrectly resolve as `Shift+V`.

The keymap's `keyboard_post_init_user()` reasserts the intended runtime settings at boot:

```c
set_qmk_setting_u16(QSID_TAPPING_TERM, 180);
set_qmk_setting_u8(QSID_PERMISSIVE_HOLD, 0);
set_qmk_setting_u8(QSID_HOLD_ON_OTHER_KEY_PRESS, 1);
set_qmk_setting_u8(QSID_RETRO_TAPPING, 0);
set_qmk_setting_u16(QSID_QUICK_TAP_TERM, 120);
set_qmk_setting_u8(QSID_CHORDAL_HOLD, 1);
set_qmk_setting_u16(QSID_FLOW_TAP_TERM, 150);
```

It reads first and only writes when a value differs, avoiding repeated EEPROM writes during normal boots.

## Notes

- `PERMISSIVE_HOLD` is intentionally off. It is useful as a softer alternative to `HOLD_ON_OTHER_KEY_PRESS`, but enabling both adds little for this layout because hold-on-other-key resolves first.
- `IGNORE_MOD_TAP_INTERRUPT` is not used. In newer QMK it was removed in favor of hold-on-other-key behavior.
- References: [QMK Tap-Hold configuration](https://docs.qmk.fm/tap_hold), [QMK Caps Word](https://develop-docs.qmk.fm/features/caps_word).
