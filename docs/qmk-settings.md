# QMK Settings

These are the QMK behavior settings I pair with this layout to make homerow mods on Colemak-DH feel predictable.

## `config.h`

```c
#pragma once

#define TAPPING_TERM 240
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
```

## Why These Settings

- `TAPPING_TERM 240` gives taps a bit more room before a homerow mod turns into a hold.
- `PERMISSIVE_HOLD` makes rolling into shortcuts and layer holds feel more reliable.
- `IGNORE_MOD_TAP_INTERRUPT` helps avoid accidental holds when another key lands during a tap.
