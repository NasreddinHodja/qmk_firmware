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

#include <stdint.h>
#include QMK_KEYBOARD_H

// base mods
#define HRGUI(key) MT(MOD_LGUI, key)
#define HRALT(key) MT(MOD_LALT, key)
#define HRCTL(key) MT(MOD_LCTL, key)
#define HRSFT(key) MT(MOD_LSFT, key)
#define HRAGR(key) MT(MOD_RALT, key)

// sym mods
#define SYM_LGUI LGUI_T(KC_0)
#define SYM_LALT LALT_T(KC_1)
#define SYM_LCTL LCTL_T(KC_2)
#define SYM_LSFT LSFT_T(KC_3)
#define SYM_RGUI LGUI_T(KC_4)
#define SYM_RALT LALT_T(KC_5)
#define SYM_RCTL LCTL_T(KC_6)
#define SYM_RSFT LSFT_T(KC_7)

/* const key_override_t lbrc_ko = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_RBRC); */
/* const key_override_t lcbr_ko = ko_make_basic(MOD_MASK_SHIFT, KC_LCBR, KC_RCBR); */
/* const key_override_t lprn_ko = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_RPRN); */

/* // This globally defines all key overrides to be used */
/* const key_override_t *key_overrides[] = { */
/*     &lbrc_ko, */
/*     &lcbr_ko, */
/*     &lprn_ko, */
/* }; */

// combos
const uint16_t PROGMEM tab_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM dquote_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM quote_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM tilde_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM circ_combo[] = {KC_M, KC_COMM, COMBO_END};

combo_t key_combos[] = {
    COMBO(tab_combo, KC_TAB),
    COMBO(dquote_combo, KC_DQUO),
    COMBO(quote_combo, KC_QUOT),
    COMBO(tilde_combo, KC_TILD),
    COMBO(circ_combo, KC_CIRC),
};

enum layers {
    _BASE,
    _SYM,
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
   XXXXXXX, HRGUI(KC_A), HRALT(KC_S), HRCTL(KC_D), HRSFT(KC_F), HRAGR(KC_G), HRAGR(KC_H), HRSFT(KC_J), HRCTL(KC_K), HRALT(KC_L), HRGUI(KC_SCLN), XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                      KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, XXXXXXX,
//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                    XXXXXXX, LT(_NAV, KC_ESC), LT(_MOU, KC_BSPC),         LT(_FUN, KC_ENT), LT(_SYM, KC_SPC), XXXXXXX
                                      //`--------------------------'  `--------------------------'
    ),

    [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, SYM_LGUI, SYM_LALT, SYM_LCTL, SYM_LSFT, KC_QUOT,                  KC_GRV , SYM_RSFT, SYM_RCTL, SYM_RALT, SYM_RGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_EQL , KC_PLUS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_MINS, KC_UNDS,    XXXXXXX, _______, XXXXXXX
    ),

    [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_AGIN, KC_UNDO, KC_PSTE, KC_COPY, KC_CUT ,                      KC_CUT , KC_COPY, KC_PSTE, KC_UNDO, KC_AGIN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_VOLU,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_TAB , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_VOLD, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_CAPS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, _______, XXXXXXX,    KC_INS , KC_DEL , XXXXXXX
                                      //`--------------------------'  `--------------------------'
    ),

    [_MOU] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_AGIN, KC_UNDO, KC_PSTE, KC_COPY, KC_CUT ,                      KC_CUT , KC_COPY, KC_PSTE, KC_UNDO, KC_AGIN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_VOLU,                      MS_LEFT, MS_DOWN, MS_UP  , MS_RGHT, KC_TAB , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_VOLD, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT,                      MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, MS_BTN3, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, _______,    MS_BTN2, MS_BTN1, XXXXXXX
                                      //`--------------------------'  `--------------------------'
    ),

    [_FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_PAUS,                     TG(_GAM), QK_LOCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+---------+--------+--------+--------+--------|
      XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_PSCR,                      QK_BOOT, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_APP , XXXXXXX,    _______, XXXXXXX, XXXXXXX
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

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
    // hr mods in SYM
    case SYM_LGUI:
        if (record->tap.count) {
            if (record->event.pressed) {
                tap_code16(KC_BSLS);
            }
            return false;
        }
        break;

    case SYM_LALT:
        if (record->tap.count) {
            if (record->event.pressed) {
                tap_code16(KC_LBRC);
            }
            return false;
        }
        break;

    case SYM_LCTL:
        if (record->tap.count) {
            if (record->event.pressed) {
                tap_code16(KC_LCBR);
            }
        return false;
        }
        break;

    case SYM_LSFT:
        if (record->tap.count) {
            if (record->event.pressed) {
                tap_code16(KC_LPRN);
            }
            return false;
        }
        break;

    case SYM_RSFT:
        if (record->tap.count) {
            if (record->event.pressed) {
                tap_code16(KC_RPRN);
            }
            return false;
        }
        break;

    case SYM_RCTL:
        if (record->tap.count) {
            if (record->event.pressed) {
                tap_code16(KC_RCBR);
            }
            return false;
        }
        break;

    case SYM_RALT:
        if (record->tap.count) {
            if (record->event.pressed) {
                tap_code16(KC_RBRC);
            }
            return false;
        }
        break;

    case SYM_RGUI:
        if (record->tap.count) {
            if (record->event.pressed) {
                tap_code16(KC_PIPE);
            }
            return false;
        }
        break;
  }

  return true;
}
