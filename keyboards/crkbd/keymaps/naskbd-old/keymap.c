/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// mods
#define HRGUI(key) MT(MOD_LGUI, key)
#define HRALT(key) MT(MOD_LALT, key)
#define HRCTL(key) MT(MOD_LCTL, key)
#define HRSFT(key) MT(MOD_LSFT, key)
#define HRAGR(key) MT(MOD_RALT, key)

const key_override_t lbrc_ko = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_RBRC);
const key_override_t lcbr_ko = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_RCBR);
const key_override_t lprn_ko = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_RPRN);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &lbrc_ko,
    &lcbr_ko,
    &lprn_ko,
};

enum layers {
    _BASE,
    _SYM,
    _NUM,
    _NAV,
    _MOU,
    _FUN,
    _MAC,
    _GAM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                      KC_Y   , KC_U   , KC_I   , KC_O   , KC_P  ,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
KC_TILD, HRGUI(KC_A), HRALT(KC_S), HRCTL(KC_D), HRSFT(KC_F), HRAGR(KC_G), HRAGR(KC_H), HRSFT(KC_J), HRCTL(KC_K), HRALT(KC_L), HRGUI(KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                      KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
              LT(_MAC, KC_TAB), LT(_NAV, KC_ESC), LT(_MOU, KC_BSPC),    LT(_NUM, KC_ENT), LT(_SYM, KC_SPC), LT(_FUN, KC_MINS)
                                      //`--------------------------'  `--------------------------'
    ),

    [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_PIPE, KC_AT  , KC_DLR , KC_AMPR, KC_EXLM,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_DQUO, KC_LBRC, KC_LCBR, KC_LPRN, KC_CIRC,                      KC_RALT, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_PERC, KC_COLN, KC_BSLS, KC_HASH, KC_GRV ,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_QUES, KC_UNDS,    XXXXXXX, _______, XXXXXXX
    ),

    [_NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_8   , KC_7   , KC_6   , KC_5   , KC_9   ,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_4   , KC_3   , KC_2   , KC_1   , KC_0   ,                      KC_RALT, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_MINS, KC_PAST, KC_PLUS , KC_PEQL, KC_SLSH,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_DOT , KC_COMM,    _______, XXXXXXX, XXXXXXX
    ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_AGIN, KC_UNDO, KC_PSTE, KC_COPY, KC_CUT ,                      KC_CUT , KC_COPY, KC_PSTE, KC_UNDO, KC_AGIN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_VOLD, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_VOLU,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,    KC_CAPS, KC_DEL , KC_INS
                                      //`--------------------------'  `--------------------------'
    ),

    [_MOU] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_AGIN, KC_UNDO, KC_PSTE, KC_COPY, KC_CUT ,                      KC_CUT , KC_COPY, KC_PSTE, KC_UNDO, KC_AGIN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_VOLD, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_VOLU,                      MS_LEFT, MS_DOWN, MS_UP  , MS_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT,                      MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    MS_BTN2, MS_BTN1, MS_BTN3
                                      //`--------------------------'  `--------------------------'
    ),

    [_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_F8  , KC_F7  , KC_F6  , KC_F5  , KC_PAUS,                     TG(_GAM), QK_LOCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+---------+--------+--------+--------+--------|
      XXXXXXX, KC_F4  , KC_F3  , KC_F2  , KC_F1  , KC_PSCR,                      QK_BOOT, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_F12 , KC_F11 , KC_F10 , KC_F9  , XXXXXXX,                      XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_APP , XXXXXXX,    XXXXXXX, XXXXXXX, _______
                                      //`--------------------------'  `--------------------------'
    ),

    [_MAC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
    ),

    [_GAM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_T   , KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   ,                     TG(_GAM), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_G   , KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   ,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_B   , KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   ,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_ESC , KC_SPC , KC_LALT,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
    ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
