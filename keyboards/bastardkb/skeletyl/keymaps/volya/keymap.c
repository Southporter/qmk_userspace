/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum key_layers {
    _QWERTY,
    _COLEMAKDH,
    _ARROWS,
    _MEDIA,
    _NAV,
    _MOUSE,
    _SYM,
    _NUM,
    _FUN,
};

enum layer_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAKDH,
    ARROWS,
};

// Home row mods
// QWERTY
#define ALT_A   MT(MOD_LALT,  KC_A)
#define GUI_S   MT(MOD_LGUI,  KC_S)
#define SHFT_D  MT(MOD_LSFT,  KC_D)
#define CTRL_F  MT(MOD_LCTL, KC_F)

#define CTRL_J  MT(MOD_RCTL, KC_J)
#define SHFT_K  MT(MOD_RSFT,  KC_K)
#define GUI_L   MT(MOD_RGUI,  KC_L)
#define ALT_CLN MT(MOD_LALT,  KC_SCLN)

// COLEMAKDH
#define GUI_R   MT(MOD_LGUI,  KC_R)
#define SHFT_S  MT(MOD_LSFT,  KC_S)
#define CTRL_T  MT(MOD_LCTL, KC_T)

#define CTRL_N  MT(MOD_RCTL, KC_N)
#define SHFT_E  MT(MOD_RSFT,  KC_E)
#define GUI_I   MT(MOD_RGUI,  KC_I)
#define ALT_O   MT(MOD_LALT,  KC_O)


// Layer Toggles
#define E_NUM     LT(_NUM, KC_E)
#define MINS_NUM  LT(_NUM, KC_MINS)

#define BSPC_MS   LT(_MOUSE, KC_BSPC)
#define ESC_NAV   LT(_NAV, KC_ESC)

#define TAB_MEDIA LT(_MEDIA, KC_TAB)
#define SPC_SYM   LT(_SYM, KC_SPC)
#define ENT_FUN   LT(_FUN, KC_ENT)

#define NAV   TT(_NAV)
#define MOUSE TT(_MOUSE)
#define SYM   TT(_SYM)
#define NUM   TT(_NUM)
#define FUN   TT(_FUN)
#define UNDSC  RSFT(KC_MINS)
#define MAC_LOCK C(G(KC_Q))
#define ____   KC_TRANSPARENT
#define xxxx   KC_NO
#define REDO   LCTL(KC_Y)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.           ,--------------------------------------------.
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
      ALT_A,   GUI_S,   SHFT_D,  CTRL_F,  KC_G,                KC_H,    CTRL_J,  SHFT_K,  GUI_L,  ALT_CLN,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
                      TAB_MEDIA, MINS_NUM, ESC_NAV,           BSPC_MS, SPC_SYM, ENT_FUN
                    //`--------------------------'           `--------------------------'

  ),

  [_COLEMAKDH] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.           ,--------------------------------------------.
      KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
      ALT_A,   GUI_R,   SHFT_S,  CTRL_T,  KC_G,                KC_M,    CTRL_N,  SHFT_E,  GUI_I,  ALT_O,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
      KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
                      TAB_MEDIA, MINS_NUM, ESC_NAV,            BSPC_MS, SPC_SYM, ENT_FUN
                    //`--------------------------'           `--------------------------'
  ),

  [_ARROWS] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.           ,--------------------------------------------.
      XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
                        XXXXXXX, XXXXXXX,COLEMAKDH,            XXXXXXX, KC_SPC,  XXXXXXX
                    //`--------------------------'           `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.           ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
      KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, XXXXXXX,             KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_CAPS,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
      XXXXXXX, QWERTY, COLEMAKDH,ARROWS,  XXXXXXX,             KC_INS,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
                        ____,    ____,    ____,                ____,    ____,    ____
                    //`--------------------------'           `--------------------------'
  ),


  [_NUM] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.           ,--------------------------------------------.
       KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
      KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, XXXXXXX,             KC_EQL,   KC_4,    KC_5,    KC_6,   KC_QUOT,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, CW_TOGG, CW_TOGG, XXXXXXX,             KC_PIPE,  KC_1,    KC_2,    KC_3,   KC_GRV,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
                         ____,    ____,    ____,               KC_LBRC,  KC_0,   KC_RBRC
                    //`--------------------------'           `--------------------------'
  ),
  [_MEDIA] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.           ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
      KC_LALT, KC_LGUI, KC_LSFT, KC_LCTL, XXXXXXX,             XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
                        ____,    ____,    ____,                ____,    KC_MPLY, KC_MSTP
                    //`--------------------------'           `--------------------------'
  ),
  [_MOUSE] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.           ,--------------------------------------------.
      KC_ACL2, KC_WH_U, KC_MS_U, KC_WH_D, XXXXXXX,             QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
      KC_ACL1, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,             XXXXXXX, KC_RCTL, KC_RSFT, KC_RGUI, KC_RALT,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
      KC_ACL0, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX,             QK_RBT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
                        KC_BTN1, KC_BTN2, KC_BTN3,             ____,    ____,    ____
                    //`--------------------------'           `--------------------------'
  ),
  [_SYM] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.           ,--------------------------------------------.
      S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),             S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0),
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
      KC_LBRC,KC_RBRC,S(KC_9),S(KC_0), XXXXXXX,                XXXXXXX, KC_RCTL, KC_RSFT, KC_RGUI, KC_QUOT,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
      S(KC_MINS),KC_BSLS,S(KC_LBRC),S(KC_RBRC),XXXXXXX,        XXXXXXX,S(KC_QUOT),KC_QUOT,S(KC_GRV),KC_GRV,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
                        ____,    ____,    ____,                ____,    ____,    ____
                    //`--------------------------'           `--------------------------'
  ),
  [_FUN] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.           ,--------------------------------------------.
      KC_F11,  KC_F7,   KC_F8,   KC_F9,   KC_F14,              XXXXXXX, KC_F16,  KC_F17,  KC_F18,  KC_F19,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
      KC_F10,  KC_F4,   KC_F5,   KC_F6,   KC_F13,              KC_F24,  KC_RCTL, KC_RSFT, KC_RGUI, KC_RALT,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
      KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F15,              XXXXXXX, KC_F20,  KC_F21,  KC_F22,  KC_F23,
  //|--------+--------+--------+--------+--------|           |--------+--------+--------+--------+--------|
                        ____,    ____,    ____,                ____,    ____,    ____
                    //`--------------------------'           `--------------------------'
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAKDH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKDH);
            }
            return false;
            break;
        case ARROWS:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_ARROWS);
            }
            return false;
            break;
    }
    return true;
}
