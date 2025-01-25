// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/achordion.h"

enum custom_keycodes {
    LPAREN = SAFE_RANGE,
    RPAREN,
    LBRC,
    RBRC,
    LSBRC,
    RSBRC,
    OCTO,
    DOLLAR,
    AMPER,
    PERCEN,
    PIPE,
    LABRC,
    RABRC,
    ATSGN,
    MINUS,
    EQUAL,
    PLUS,
    BANG,
    COLON,
    TILDE,
    STAR,
    CARET,
    UNDRSCR,
    QSTNMRK,
    DQUOT,
};

/* --- Repeat keys --- */
#define REPEAT QK_REP
#define ALT_REPEAT QK_AREP

/* --- Thumb keys --- */
// Left.
#define LTHMB_0 LT(2, KC_MINS)
#define LTHMB_1 LT(2, UNDRSCR)
#define LTHMB_2 LT(3, KC_SPC)
// Right.
#define RTHMB_0 REPEAT
#define RTHMB_1 LT(2, KC_ESC)
#define RTHMB_2 LT(4, KC_ENT)

/* --- Homerow mods --- */
#define HM_0(x) LT(1, x)
#define HM_1(x) LALT_T(x)
#define HM_2(x) LCTL_T(x)
#define HM_3(x) LSFT_T(x)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
       KC_TAB,      KC_F,      KC_D,      KC_H,      KC_W,      KC_P,              KC_Q,      KC_J,      KC_U,      KC_O,      KC_Y,   KC_SLSH,
      KC_BSPC,HM_0(KC_S),HM_1(KC_T),HM_2(KC_N),HM_3(KC_C),      KC_B,              KC_Z, HM_3(KC_R),HM_2(KC_E),HM_1(KC_A),HM_0(KC_I),    COLON,
      CW_TOGG,LGUI_T(KC_V),    KC_K,      KC_M,      KC_G,   KC_QUOT,              KC_X,      KC_L,   KC_SCLN,   KC_COMM,LGUI_T(KC_DOT),KC_BSLS,
                                       LTHMB_0,   LTHMB_1,   LTHMB_2,           RTHMB_0,   RTHMB_1,   RTHMB_2
  ),
    [1] = LAYOUT_split_3x6_3(
      _______,     ATSGN,     LABRC,     RABRC,   KC_BSLS,    KC_GRV,             AMPER,      OCTO,      LBRC,      RBRC,    PERCEN,   _______,
      _______,HM_0(BANG),HM_1(MINUS),HM_2(PLUS),HM_3(EQUAL), QSTNMRK,              PIPE,HM_3(LPAREN),HM_2(LSBRC),HM_1(RSBRC),HM_0(RPAREN),_______,
      _______,     TILDE,   KC_SLSH,      STAR,     CARET,     DQUOT,             TILDE,    DOLLAR,   _______,   _______,   _______,   _______,
                                       _______,   _______,   _______,           _______,   _______,   _______
  ),
    [2] = LAYOUT_split_3x6_3(
      _______,   _______,      KC_6,      KC_5,      KC_4,   _______,           _______,      KC_4,      KC_5,      KC_6,   _______,   _______,
      _______,HM_0(KC_0),HM_1(KC_3),HM_2(KC_2),HM_3(KC_1),   _______,           _______,HM_3(KC_1),HM_2(KC_2),HM_1(KC_3),HM_0(KC_0),   _______,
      _______,   _______,      KC_9,      KC_8,      KC_7,   _______,           _______,      KC_7,      KC_8,      KC_9,   _______,   _______,
                                       _______,   _______,   _______,           _______,   _______,   _______
    ),
    [3] = LAYOUT_split_3x6_3(
      _______,   _______,     KC_P7,     KC_P8,     KC_P9,   _______,           _______,   KC_PGDN,   KC_PGUP,   KC_HOME,   _______,   _______,
      _______,HM_0(KC_P0),HM_1(KC_P4),HM_2(KC_P5),HM_3(KC_P6),_______,          KC_LEFT,HM_3(KC_DOWN),HM_2(KC_UP),HM_1(KC_RIGHT),HM_0(KC_END),_______,
      _______,   _______,     KC_P1,     KC_P2,     KC_P3,   _______,           _______,   KC_MINS,    KC_EQL,    KC_GRV,   _______,   _______,
                                       _______,   _______,   _______,           _______,   _______,   _______
  ),
    [4] = LAYOUT_split_3x6_3(
      QK_BOOT,   _______,     KC_F7,     KC_F8,     KC_F9,    KC_F10,           _______,   _______,   _______,   _______,   _______,   _______,
      _______,   _______,     KC_F4,     KC_F5,     KC_F6,    KC_F11,           _______,   _______,   _______,   _______,   _______,   _______,
      _______,   _______,     KC_F1,     KC_F2,     KC_F3,    KC_F12,           _______,   _______,   _______,   _______,   _______,   _______,
                                       _______,   _______,   _______,           _______,   _______,   _______
  ),
    [5] = LAYOUT_split_3x6_3(
      QK_BOOT,   _______,   _______,   _______,   _______,   _______,           _______,   _______,   _______,   _______,   _______,   _______,
      _______,   _______,   _______,   _______,   _______,   _______,           _______,   _______,   _______,   _______,   _______,   _______,
      _______,   _______,   _______,   _______,   _______,   _______,           _______,   _______,   _______,   _______,   _______,   _______,
                                       _______,   _______,   _______,           _______,   _______,   _______
  )
};
// clang-format on

bool remember_last_key_user(uint16_t keycode, keyrecord_t *record, uint8_t *remembered_mods) {
    switch (keycode) {
        case REPEAT:
        case ALT_REPEAT:
            return false;
            /*
            case LTHMB_2:
            case LTHMB_0:
            case KC_ENTER:
            case RTHMB_2:
            case KC_ESC:
                set_last_record(OSM(MOD_RSFT), record);
                return false;
            */
    }
    return true;
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_Y:
            return KC_I;
        case HM_0(KC_I):
            return KC_W;
        case HM_0(KC_S):
            return KC_F;
        case LGUI_T(KC_V):
            return KC_F;
        case HM_2(KC_E):
            return KC_U;
        case HM_1(KC_A):
            return KC_O;
        case KC_O:
            return KC_A;
        case KC_U:
            return KC_E;
        case KC_M:
            return KC_N;
        case KC_D:
            return KC_T;
    }
    return KC_TRNS;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_BOOT:
            return true;
        case LTHMB_1:
            if (record->event.pressed && record->tap.count) {
                tap_code16(LSFT(KC_MINUS));
                return false;
            }
            return true;
        case RTHMB_1:
            if (record->event.pressed && record->tap.count) {
                tap_code16(KC_ESC);
                return false;
            }
            return true;
        case HM_0(BANG):
            if (record->event.pressed && record->tap.count) {
                tap_code16(LSFT(KC_1));
                return false;
            }
            return true;
        case HM_1(MINUS):
            if (record->event.pressed && record->tap.count) {
                tap_code16(KC_MINUS);
                return false;
            }
            return true;
        case HM_2(PLUS):
            if (record->event.pressed && record->tap.count) {
                tap_code16(LSFT(KC_EQL));
                return false;
            }
            return true;
        case HM_3(EQUAL):
            if (record->event.pressed && record->tap.count) {
                tap_code16(KC_EQL);
                return false;
            }
            return true;
        case HM_3(LPAREN):
            if (record->event.pressed && record->tap.count) {
                tap_code16(LSFT(KC_9));
                return false;
            }
            return true;
        case HM_2(LSBRC):
            if (record->event.pressed && record->tap.count) {
                tap_code16(LSFT(KC_LBRC));
                return false;
            }
            return true;
        case HM_1(RSBRC):
            if (record->event.pressed && record->tap.count) {
                tap_code16(LSFT(KC_RBRC));
                return false;
            }
            return true;
        case HM_0(RPAREN):
            if (record->event.pressed && record->tap.count) {
                tap_code16(LSFT(KC_0));
                return false;
            }
            return true;
        case LBRC:
            if (record->event.pressed) {
                tap_code16(KC_LBRC);
                return false;
            }
        case RBRC:
            if (record->event.pressed) {
                tap_code16(KC_RBRC);
                return false;
            }
        case OCTO:
            if (record->event.pressed) {
                tap_code16(LSFT(KC_3));
                return false;
            }
        case DOLLAR:
            if (record->event.pressed) {
                tap_code16(LSFT(KC_4));
                return false;
            }
        case AMPER:
            if (record->event.pressed) {
                tap_code16(LSFT(KC_7));
                return false;
            }
        case PERCEN:
            if (record->event.pressed) {
                tap_code16(LSFT(KC_5));
                return false;
            }
        case PIPE:
            if (record->event.pressed) {
                tap_code16(LSFT(KC_BSLS));
                return false;
            }
        case COLON:
            if (record->event.pressed) {
                tap_code16(LSFT(KC_SCLN));
                return false;
            }
        case TILDE:
            if (record->event.pressed) {
                tap_code16(LSFT(KC_GRV));
                return false;
            }
        case LABRC:
            if (record->event.pressed) {
                tap_code16(LSFT(KC_COMM));
                return false;
            }
        case RABRC:
            if (record->event.pressed) {
                tap_code16(LSFT(KC_DOT));
                return false;
            }
        case ATSGN:
            if (record->event.pressed) {
                tap_code16(LSFT(KC_2));
                return false;
            }
        case STAR:
            if (record->event.pressed) {
                tap_code16(LSFT(KC_8));
                return false;
            }
        case CARET:
            if (record->event.pressed) {
                tap_code16(LSFT(KC_6));
                return false;
            }
        case UNDRSCR:
            if (record->event.pressed) {
                tap_code16(LSFT(KC_MINUS));
                return false;
            }
        case QSTNMRK:
            if (record->event.pressed) {
                tap_code16(LSFT(KC_SLSH));
                return false;
            }
        case DQUOT:
            if (record->event.pressed) {
                tap_code16(LSFT(KC_QUOT));
                return false;
            }
            /*case REPEAT: if (record->event.pressed && record->tap.count) { repeat_key_invoke(&record->event); record->event.pressed = false; repeat_key_invoke(&record->event); return false; } return true; case ALT_REPEAT: if (record->event.pressed && record->tap.count) { alt_repeat_key_invoke(&record->event); record->event.pressed = false; alt_repeat_key_invoke(&record->event); return false; } return true;*/
    }
    if (!process_achordion(keycode, record)) {
        return false;
    }
    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    switch (tap_hold_keycode) {
        case LTHMB_0:
        case LTHMB_1:
        case LTHMB_2:
            return (other_record->event.key.row != 7);
        case RTHMB_0:
        case RTHMB_1:
        case RTHMB_2:
            return (other_record->event.key.row != 3);
        case LGUI_T(KC_V):
        case LGUI_T(KC_DOT):
            if (other_keycode == LTHMB_2) {
                return true;
            }
    }

    if (other_record->event.key.col == 0) {
        return true;
    }
    return ((other_record->event.key.row <= 3) != (tap_hold_record->event.key.row <= 3));
}

/*bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return false;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return false;
    }
}*/

/*
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t tab_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPACE, KC_TAB);
const key_override_t colon_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, LSFT(KC_SEMICOLON));
const key_override_t semicolon_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SEMICOLON);

const key_override_t **key_overrides = (const key_override_t *[]) {
    &delete_key_override,
    &tab_key_override,
    &colon_key_override,
    &semicolon_key_override,
    NULL
};
*/

/*[0] = LAYOUT_split_3x6_3(
   KC_TAB,      KC_Z,      KC_L,      KC_C,      KC_K,      KC_P,              KC_Q,      KC_J,      KC_O,      KC_U,      KC_F,   KC_SLSH,
  KC_BSPC,HM_0(KC_R),HM_1(KC_N),HM_2(KC_S),HM_3(KC_T),      KC_G,              KC_Y,HM_3(KC_I),HM_2(KC_A),HM_1(KC_E),HM_0(KC_H),    KC_DOT,
LSFT(KC_SCLN),     GUI_W,      KC_M,      KC_V,      KC_D,      KC_B,              KC_X,      KC_U,   KC_QUOT,   KC_SLSH,  GUI_COMM,   KC_SCLN,
                                   LTHMB_0,   LTHMB_1,   LTHMB_2,           RTHMB_0,   RTHMB_1,   RTHMB_2
),*/
/*[0] = LAYOUT_split_3x6_3(
   KC_TAB,      KC_W,      KC_L,      KC_C,      KC_B,      KC_K,              KC_Z,      KC_U,      KC_O,      KC_Y,      KC_F,    KC_DEL,
  KC_BSPC,HM_0(KC_R),HM_1(KC_N),HM_2(KC_S),HM_3(KC_T),      KC_G,            KC_DOT,HM_3(KC_A),HM_2(KC_E),HM_1(KC_I),HM_0(KC_H),    KC_DOT,
LSFT(KC_SCLN),     GUI_X,      KC_M,      KC_V,      KC_D,      KC_P,           KC_SLSH,   KC_COMM,   KC_QUOT,     KC_J,      GUI_Q,   KC_SCLN,
                                   LTHMB_0,   LTHMB_1,   LTHMB_2,           RTHMB_0,   RTHMB_1,   RTHMB_2
),*/
/*[0] = LAYOUT_split_3x6_3(
   KC_TAB,      KC_P,      KC_F,      KC_H,      KC_B,      KC_Q,              KC_Z,      KC_J,      KC_U,      KC_O,ALT_REPEAT,    KC_DEL,
  KC_BSPC,HM_0(KC_Y),HM_1(KC_S),HM_2(KC_N),HM_3(KC_T),      KC_G,              KC_W,HM_3(KC_R),HM_2(KC_E),HM_1(KC_A),HM_0(KC_I),    KC_DOT,
LSFT(KC_SCLN),     GUI_C,      KC_V,      KC_M,      KC_D,      KC_K,              KC_X,      KC_L,   KC_SLSH,   KC_QUOT,  GUI_COMM,   KC_SCLN,
                                   LTHMB_0,   LTHMB_1,   LTHMB_2,           RTHMB_0,   RTHMB_1,   RTHMB_2
),*/
/*[0] = LAYOUT_split_3x6_3(
   KC_TAB,      KC_W,      KC_B,      KC_F,      KC_G,      KC_Q,              KC_Z,      KC_J,      KC_U,      KC_O,ALT_REPEAT,    KC_DEL,
  KC_BSPC,HM_0(KC_Y),HM_1(KC_N),HM_2(KC_S),HM_3(KC_T),      KC_M,              KC_H,HM_3(KC_R),HM_2(KC_E),HM_1(KC_A),HM_0(KC_I),    KC_DOT,
LSFT(KC_SCLN),     GUI_C,      KC_P,      KC_V,      KC_D,      KC_K,              KC_X,      KC_L,   KC_SLSH,   KC_QUOT,  GUI_COMM,   KC_SCLN,
                                   LTHMB_0,   LTHMB_1,   LTHMB_2,           RTHMB_0,   RTHMB_1,   RTHMB_2
),*/
/*[0] = LAYOUT_split_3x6_3(
   KC_TAB,      KC_F,      KC_G,      KC_H,      KC_W,      KC_P,              KC_Q,      KC_J,      KC_U,      KC_O,      KC_Y,    KC_DEL,
  KC_BSPC,HM_0(KC_S),HM_1(KC_T),HM_2(KC_N),HM_3(KC_C),      KC_B,              KC_T,HM_3(KC_R),HM_2(KC_E),HM_1(KC_A),HM_0(KC_I),    KC_DOT,
   KC_DEL,     GUI_V,      KC_K,      KC_M,      KC_D,      KC_Z,              KC_X,      KC_L,   KC_SLSH,   KC_QUOT,  GUI_COMM,   KC_SCLN,
                                   LTHMB_0,   LTHMB_1,   LTHMB_2,           RTHMB_0,   RTHMB_1,   RTHMB_2
),*/

/*
WLCKB ZUOYF
RNSTG .AEIH
XMVDP ,^'JQ
wlckbzuoyfrnstg.aeihxmvdp,;'jq

WLCKB ,.O F
RNSTG YIAEH
ZMVDP XUQJ'


WFMK. QLUOY
NSTHV ZREAI
PCGDB X^',J

FGYWB ZRUOH
CSITP QNAEL
MVJDK X^,'.

WHFBQ ZLUOY
CNSTG JREAI
PMVDK X^',.
whfbqzluoycnstgjreaipmvdkx;',.

WYFBQ ZLUO,
CNSTG JREAI
MPVDK XH^'.

WHFPB ZLUO,
CNSTG JREAI
YMVDK XQ^'.

XHLBV WPUO,
SNRTK YCEAI
ZMJDQ FG^'.

WPFMQ CLUO,
CNSTG XREAI
YBVDK JH^'.
wpfmqzluo,cnstgxreaiybvdkjh;'.

WYGKJ ZRUO,
CSTHM XNEAI
PFBDV ^L'Q.

 P-GFJ ZRUO,
WYSTHM XNEAI;
QCVBDK  L'/.
*/
/*
WBFGQ ZJUO,
YNSTM HREAI
CPVDK XL/'.

 ZBFGQ  JUO-
WYNSTM HREAI.
 CPVDK XL/',
⇥zbfgq=juo-`wynstmhreai.\cpvdkxl/',;

 ZBFMK  QUO,
WYNSTG HREAI
 CPVDJ XL/'.
*/

/*const uint16_t PROGMEM combo_caps_word[] = {KC_G, KC_Y, COMBO_END};*/
/*
const uint16_t PROGMEM combo_1[] = {KC_W, HOME_Y, COMBO_END};
const uint16_t PROGMEM combo_2[] = {KC_B, HOME_N, COMBO_END};
const uint16_t PROGMEM combo_3[] = {KC_F, HOME_S, COMBO_END};
const uint16_t PROGMEM combo_4[] = {KC_G, HOME_T, COMBO_END};
const uint16_t PROGMEM combo_5[] = {KC_Q, KC_M, COMBO_END};
const uint16_t PROGMEM combo_6[] = {KC_Z, KC_H, COMBO_END};
const uint16_t PROGMEM combo_7[] = {KC_J, HOME_R, COMBO_END};
const uint16_t PROGMEM combo_8[] = {KC_U, HOME_E, COMBO_END};
const uint16_t PROGMEM combo_9[] = {KC_O, HOME_A, COMBO_END};
const uint16_t PROGMEM combo_0[] = {KC_MINS, HOME_I, COMBO_END};
const uint16_t PROGMEM combo_parenth_open[]  = {KC_B, KC_F, COMBO_END};
const uint16_t PROGMEM combo_parenth_close[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM combo_bracket_open[]  = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM combo_bracket_close[] = {KC_J, KC_U, COMBO_END};
const uint16_t PROGMEM combo_curly_open[]    = {KC_B, KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM combo_curly_close[]   = {KC_J, KC_U, KC_O, COMBO_END};
*/
/*combo_t key_combos[] = { COMBO(combo_caps_word, CW_TOGG) COMBO(combo_1, KC_1), COMBO(combo_2, KC_2), COMBO(combo_3, KC_3), COMBO(combo_4, KC_4), COMBO(combo_5, KC_5), COMBO(combo_6, KC_6), COMBO(combo_7, KC_7), COMBO(combo_8, KC_8), COMBO(combo_9, KC_9), COMBO(combo_0, KC_0), COMBO(combo_parenth_open, PARENTHESIS_OPEN), COMBO(combo_parenth_close, PARENTHESIS_CLOSE), COMBO(combo_bracket_open, KC_LBRC), COMBO(combo_bracket_close, KC_RBRC), COMBO(combo_curly_open, LSFT(KC_LBRC)), COMBO(combo_curly_close, LSFT(KC_RBRC)) };*/
