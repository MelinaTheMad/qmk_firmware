// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define HOME_C LGUI_T(KC_C)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)

#define HOME_N LCTL_T(KC_N)
#define HOME_E LSFT_T(KC_E)
#define HOME_A LALT_T(KC_A)
#define HOME_I LGUI_T(KC_I)

#define LT3_Q LT(3, KC_Q)

#define LTHMB_1 LALT_T(KC_ESC)
#define LTHMB_2 KC_BSPC
#define LTHMB_3 LT(1, KC_SPC)

#define RTHMB_1 QK_AREP
#define RTHMB_2 QK_REP
#define RTHMB_3 LT(2, KC_ENT)

#define HOME_0 LGUI_T(KC_P0)
#define HOME_4 LALT_T(KC_P4)
#define HOME_5 LSFT_T(KC_P5)
#define HOME_6 LCTL_T(KC_P6)

#define HOME_DWN LCTL_T(KC_DOWN)
#define HOME_UP  LSFT_T(KC_UP)
#define HOME_RHT LALT_T(KC_DOWN)
#define HOME_END LGUI_T(KC_END)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
      CW_TOGG,    KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,                         KC_Z,    KC_F,    KC_O,    KC_U, KC_QUOT,  KC_DEL,
       KC_TAB,  HOME_C,  HOME_R,  HOME_S,  HOME_T,    KC_G,                         KC_M,  HOME_N,  HOME_E,  HOME_I,  HOME_A, KC_SCLN,
      KC_LSFT,   LT3_Q,    KC_J,    KC_V,    KC_D,    KC_K,                         KC_X,    KC_H, KC_SLSH, KC_COMM,  KC_DOT, KC_BSLS,
                                 LTHMB_1, LTHMB_2, LTHMB_3,                      RTHMB_1, RTHMB_2, RTHMB_3
  ),
    [1] = LAYOUT_split_3x6_3(
      _______, _______,   KC_P7,   KC_P8,   KC_P9, _______,                      _______, KC_PGUP, KC_PGDN, KC_HOME, _______, _______,
      _______,  HOME_0,  HOME_4,  HOME_5,  HOME_6, _______,                      KC_DOWN,HOME_DWN, HOME_UP,HOME_RHT,HOME_END, _______,
      _______, _______,   KC_P1,   KC_P2,   KC_P3, _______,                      _______, KC_MINS,  KC_EQL,  KC_GRV, _______, _______,
                                 _______, _______, _______,                      _______, _______, _______
  ),
    [2] = LAYOUT_split_3x6_3(
      _______, _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      _______, _______, _______, _______, _______, _______,
      _______, _______,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                      _______, _______, _______, _______, _______, _______,
      _______, _______,   KC_F1,   KC_F2,   KC_F3,  KC_F12,                      _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______,                      _______, _______, _______
  ),
    [3] = LAYOUT_split_3x6_3(
      QK_BOOT, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______,                      _______, _______, _______
  )
// clang-format on
};

/*const uint16_t PROGMEM combo_caps_word[] = {LTHMB_3, RTHMB_1, COMBO_END};*/

const uint16_t PROGMEM combo_1[] = {KC_W, HOME_C, COMBO_END};
const uint16_t PROGMEM combo_2[] = {KC_L, HOME_R, COMBO_END};
const uint16_t PROGMEM combo_3[] = {KC_Y, HOME_S, COMBO_END};
const uint16_t PROGMEM combo_4[] = {KC_P, HOME_T, COMBO_END};
const uint16_t PROGMEM combo_5[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM combo_6[] = {KC_Z, KC_P, COMBO_END};
const uint16_t PROGMEM combo_7[] = {KC_F, HOME_N, COMBO_END};
const uint16_t PROGMEM combo_8[] = {KC_O, HOME_E, COMBO_END};
const uint16_t PROGMEM combo_9[] = {KC_U, HOME_I, COMBO_END};
const uint16_t PROGMEM combo_0[] = {KC_SLSH, HOME_A, COMBO_END};

const uint16_t PROGMEM combo_parenth_open[] = {KC_L, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_parenth_close[] = {KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM combo_bracket_open[] = {KC_Y, KC_P, COMBO_END};
const uint16_t PROGMEM combo_bracket_close[] = {KC_F, KC_O, COMBO_END};
const uint16_t PROGMEM combo_curly_open[] = {KC_L, KC_Y, KC_P, COMBO_END};
const uint16_t PROGMEM combo_curly_close[] = {KC_F, KC_O, KC_U, COMBO_END};

combo_t key_combos[] = {
    /*COMBO(combo_caps_word, CW_TOGG)*/

    COMBO(combo_1, KC_1),
    COMBO(combo_2, KC_2),
    COMBO(combo_3, KC_3),
    COMBO(combo_4, KC_4),
    COMBO(combo_5, KC_5),
    COMBO(combo_6, KC_6),
    COMBO(combo_7, KC_7),
    COMBO(combo_8, KC_8),
    COMBO(combo_9, KC_9),
    COMBO(combo_0, KC_0),

    COMBO(combo_parenth_open, LSFT(KC_9)),
    COMBO(combo_parenth_close, LSFT(KC_0)),
    COMBO(combo_bracket_open, KC_LBRC),
    COMBO(combo_bracket_close, KC_RBRC),
    COMBO(combo_curly_open, LSFT(KC_LBRC)),
    COMBO(combo_curly_close, LSFT(KC_RBRC)),
};
