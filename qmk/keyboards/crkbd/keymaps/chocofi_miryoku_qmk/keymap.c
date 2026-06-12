// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NAV,
    _MEDIA,
    _SYM,
    _NUM,
};

enum custom_keycodes {
    M_3W = SAFE_RANGE,
    M_3B,
    M_GD,
};

#define KC_XXXXX KC_NO
#define KC_____ KC_TRNS

#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LCTL_T(KC_S)
#define HOME_T LSFT_T(KC_T)
#define HOME_O RGUI_T(KC_O)
#define HOME_I RALT_T(KC_I)
#define HOME_E RCTL_T(KC_E)
#define HOME_N RSFT_T(KC_N)

#define NAV_SPC LT(_NAV, KC_SPC)
#define MED_ESC LT(_MEDIA, KC_ESC)
#define SYM_BSP LT(_SYM, KC_BSPC)
#define NUM_ENT LT(_NUM, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                             KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,                             KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                             KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
                                   MED_ESC, NAV_SPC, KC_TAB,         NUM_ENT, SYM_BSP, KC_EQL
    ),

    [_NAV] = LAYOUT_split_3x5_3(
        KC_____, KC_____, KC_____, KC_____, KC_____,                          CW_TOGG, M_GD,    KC_COPY, KC_CUT,  KC_UNDO,
        KC_____, KC_____, KC_____, KC_____, KC_____,                          RCTL(KC_GRV), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
        KC_____, KC_____, KC_____, KC_____, KC_____,                          KC_INS,  M_3B,    LCTL(KC_D), RCTL(KC_U), M_3W,
                                   KC_____, KC_____, KC_____,        KC_ENT,  KC_BSPC, KC_TAB
    ),

    [_MEDIA] = LAYOUT_split_3x5_3(
        KC_____, KC_____, KC_____, KC_____, KC_____,                          RGB_TOG, RGB_MOD, KC_VOLD, KC_VOLU, RGB_VAI,
        KC_____, KC_____, KC_____, KC_____, KC_____,                          KC_XXXXX, HYPR(KC_LEFT), HYPR(KC_DOWN), HYPR(KC_UP), HYPR(KC_RGHT),
        KC_____, KC_____, KC_____, KC_____, KC_____,                          KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX, KC_XXXXX,
                                   KC_____, KC_____, KC_____,        KC_MPLY, KC_MSTP, KC_MUTE
    ),

    [_SYM] = LAYOUT_split_3x5_3(
        LSFT(KC_LBRC), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_RBRC),      KC_____, KC_____, KC_____, KC_____, KC_____,
        LSFT(KC_SCLN), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_EQL),       KC_____, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
        LSFT(KC_GRV),  LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_BSLS),      KC_____, KC_____, KC_____, KC_____, KC_____,
                                                LSFT(KC_9), LSFT(KC_0), LSFT(KC_MINS), KC_____, KC_____, KC_____
    ),

    [_NUM] = LAYOUT_split_3x5_3(
        KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                          KC_____, KC_____, KC_____, KC_____, KC_____,
        KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                           KC_____, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,                          KC_____, KC_____, KC_____, KC_____, KC_____,
                                   KC_DOT,  KC_0,    KC_MINS,        KC_____, KC_____, KC_____
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case M_3W:
            tap_code16(KC_3);
            tap_code16(KC_W);
            return false;
        case M_3B:
            tap_code16(KC_3);
            tap_code16(KC_B);
            return false;
        case M_GD:
            tap_code16(KC_G);
            tap_code16(KC_D);
            return false;
    }

    return true;
}

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_split_3x5_3(
    'L', 'L', 'L', 'L', 'L',                         'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',                         'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L',                         'R', 'R', 'R', 'R', 'R',
                   '*', '*', '*',               '*', '*', '*'
);
