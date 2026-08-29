#pragma once

#ifndef TAPPING_TERM
#    define TAPPING_TERM 350
#endif
#ifndef QUICK_TAP_TERM
#    define QUICK_TAP_TERM 0
#endif
#ifndef FLOW_TAP_TERM
#    define FLOW_TAP_TERM 150
#endif
#ifndef CHORDAL_HOLD
#    define CHORDAL_HOLD
#endif
#ifndef HOLD_ON_OTHER_KEY_PRESS
#    define HOLD_ON_OTHER_KEY_PRESS
#endif

#ifndef CAPS_WORD_IDLE_TIMEOUT
#    define CAPS_WORD_IDLE_TIMEOUT 3000
#endif
#ifndef CAPS_WORD_INVERT_ON_SHIFT
#    define CAPS_WORD_INVERT_ON_SHIFT
#endif

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2

#ifdef RGBLIGHT_ENABLE
#    undef RGBLIGHT_LED_COUNT
#    define RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_LED_COUNT 54
#    undef RGBLED_SPLIT
#    define RGBLED_SPLIT \
        { 27, 27 }
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_HUE_STEP  10
#    define RGBLIGHT_SAT_STEP  17
#    define RGBLIGHT_VAL_STEP  17
#endif
