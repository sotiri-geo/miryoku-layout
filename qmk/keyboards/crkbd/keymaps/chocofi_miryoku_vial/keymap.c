// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#ifdef QMK_SETTINGS
#    include "qmk_settings.h"

enum qmk_setting_id {
    QSID_TAPPING_TERM            = 7,
    QSID_PERMISSIVE_HOLD         = 22,
    QSID_HOLD_ON_OTHER_KEY_PRESS = 23,
    QSID_RETRO_TAPPING           = 24,
    QSID_QUICK_TAP_TERM          = 25,
    QSID_CHORDAL_HOLD            = 26,
    QSID_FLOW_TAP_TERM           = 27,
};

static void set_qmk_setting_u8(uint16_t id, uint8_t value) {
    uint8_t current = 0;
    if (qmk_settings_get(id, &current, sizeof(current)) != 0 || current != value) {
        qmk_settings_set(id, &value, sizeof(value));
    }
}

static void set_qmk_setting_u16(uint16_t id, uint16_t value) {
    uint16_t current = 0;
    if (qmk_settings_get(id, &current, sizeof(current)) != 0 || current != value) {
        qmk_settings_set(id, &value, sizeof(value));
    }
}

void keyboard_post_init_user(void) {
    set_qmk_setting_u16(QSID_TAPPING_TERM, 180);
    set_qmk_setting_u8(QSID_PERMISSIVE_HOLD, 0);
    set_qmk_setting_u8(QSID_HOLD_ON_OTHER_KEY_PRESS, 1);
    set_qmk_setting_u8(QSID_RETRO_TAPPING, 0);
    set_qmk_setting_u16(QSID_QUICK_TAP_TERM, 120);
    set_qmk_setting_u8(QSID_CHORDAL_HOLD, 1);
    set_qmk_setting_u16(QSID_FLOW_TAP_TERM, 150);
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   KC_LGUI, KC_BSPC, KC_SPC,           KC_SPC,  KC_ENT,  KC_RALT
    )
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_split_3x5_3(
    'L', 'L', 'L', 'L', 'L',                         'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',                         'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',                         'R', 'R', 'R', 'R', 'R',
                   '*', '*', '*',               '*', '*', '*'
);
