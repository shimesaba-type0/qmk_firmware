/* Copyright 2019 'Takashi Kono'
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
#include "action_layer.h"


extern keymap_config_t keymap_config;


enum layer_number {
    _BASE,
    _ECLYN,     // Eucalyn Custom layout
    _ARROW,     // Arrow
    _META,
    _SYMB
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  ECLYN,
  ARROW,
  META,
  SYMB,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* BASE
 * ,-----------------------------------------.                 ,-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |                 |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------.                 |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                 |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------+------.   ,-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |  ~   |   |  =   |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |   Z  |   X  |   C  |   V  |   B  |  [   |   |  ]   |   N  |   M  |   ,  |   .  |   /  |\/Sft |
 * `------+------+------+------+------+------+------'   `------+------+------+------+------+------+------|
 *               | META/|ESC/  |Space/|Tab/  |                 |BS/   |Enter/| Del/ | SYMB/|
 *               | LALT |~SYMB |LCtrl |Shift |                 |Shift |~META | RCTRL| RALT |
 *               `---------------------------'                 `---------------------------'
 */

  [_BASE] = LAYOUT( \
    KC_ESC,  KC_1, KC_2,               KC_3,              KC_4,           KC_5,                             KC_6,           KC_7,              KC_8,            KC_9,            KC_0,             KC_MINS, \
    KC_TAB,  KC_Q, KC_W,               KC_E,              KC_R,           KC_T,                             KC_Y,           KC_U,              KC_I,            KC_O,            KC_P,             KC_BSLS, \
    KC_LCTL, KC_A, KC_S,               KC_D,              KC_F,           KC_G,           KC_GRV,  KC_EQL,  KC_H,           KC_J,              KC_K,            KC_L,            KC_SCLN,          KC_QUOT, \
    KC_LSFT, KC_Z, KC_X,               KC_C,              KC_V,           KC_B,           KC_LBRC, KC_RBRC, KC_N,           KC_M,              KC_COMM,         KC_DOT,          KC_SLSH,          KC_RSFT, \
                   LT(_META, KC_LALT), LT(_SYMB, KC_ESC), LCTL_T(KC_SPC), SFT_T(KC_TAB),                    SFT_T(KC_BSPC), LT(_META, KC_ENT), RCTL_T(KC_DELT), LT(_SYMB, KC_RALT) \
  ),

/* EUCALYN Custom
 * ,-----------------------------------------.                 ,-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |                 |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------.                 |------+------+------+------+------+------|
 * | TAB  |   Q  |  W   |   ,  |   .  |   ;  |                 |   M  |   R  |   D  |   Y  |   P  |  \   |
 * |------+------+------+------+------+------+------.   ,-------------+------+------+------+------+------|
 * | LCTL |   A  |  O   |   E  |   I  |   U  |  ~   |   |  =   |   H  |   J  |   K  |   L  |   N  |  '   |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | LSFT |   Z  |  X   |   C  |   V  |   F  |  [   |   |  ]   |   B  |   G  |   T  |   S  |   /  | RSFT |
 * `------+------+------+------+------+------+------'   `------+------+------+------+------+------+------|
 *               | META/|ESC/  |Space/|Tab/  |                 |BS/   |Enter/| Del/ | SYMB/|
 *               | LALT |~SYMB |LCtrl |Shift |                 |Shift |~META | RCTRL| RALT |
 *               `---------------------------'                 `---------------------------'
 */


  [_ECLYN] = LAYOUT( \
     KC_ESC, KC_1, KC_2,     KC_3,    KC_4,     KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
     KC_TAB, KC_Q, KC_W,     KC_COMM, KC_DOT,   KC_SCLN,                   KC_M,    KC_R,    KC_D,    KC_Y,    KC_P,    KC_BSLS, \
    KC_LCTL, KC_A, KC_O,     KC_E,    KC_I,     KC_U,    KC_GRV,  KC_EQL,  KC_H,    KC_J,    KC_K,    KC_L,    KC_N,    KC_QUOT, \
    KC_LSFT, KC_Z, KC_X,     KC_C,    KC_V,     KC_F,    KC_LBRC, KC_RBRC, KC_B,    KC_G,    KC_T,    KC_S,    KC_SLSH, KC_RSFT, \
                   _______,  _______, _______, _______,                    _______, _______, _______, _______ \
  ),


/* ARROW
 * ,-----------------------------------------.                 ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                 |      |      |      |      |      |Reset |
 * |------+------+------+------+------+------.                 |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                 |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------.   ,-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      | Left | Down | Up   |Right |      |      |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------'   `------+------+------+------+------+------+------|
 *               | META/|ESC/  |Space/|Tab/  |                 |BS/   |Enter/| Del/ | SYMB/|
 *               | LALT |~SYMB |LCtrl |Shift |                 |Shift |~META | RCTRL| RALT |
 *               `---------------------------'                 `---------------------------'
 */


 [_ARROW] = LAYOUT( \
   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  EEP_RST, RESET, \
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, \
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, XXXXXXX, XXXXXXX, \
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, \
                     _______, _______, _______, _______,                   _______, _______, _______, _______ \
 ),


/* META
 * ,-----------------------------------------.                 ,-----------------------------------------.
 * | Esc  |      |      |ARROW |ECLYN | BASE |                 | HOME |  END | CAPS |PrtSc |      |Reset |
 * |------+------+------+------+------+------.                 |------+------+------+------+------+------|
 * | Tab  |   1  |   2  |   3  |   4  |   5  |                 |   6  |   7  |   8  |   9  |   0  |  |   |
 * |------+------+------+------+------+------+------.   ,-------------+------+------+------+------+------|
 * | Ctrl |  F6  |      |Muhen |Henk  |      |  +   |   |  -   | Left | Down | Up   |Right |  F7  |      |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |  F1  |  F2  |  F3  |  F4  |  F5  |  *   |   |  /   |  F8  |  F9  | F10  | F11  | F12  |\/Sft |
 * `------+------+------+------+------+------+------'   `------+------+------+------+------+------+------|
 *               | META/|ESC/  |Space/|Tab/  |                 |BS/   |Enter/| Del/ | SYMB/|
 *               | LALT |~SYMB |LCtrl |Shift |                 |Shift |~META | RCTRL| RALT |
 *               `---------------------------'                 `---------------------------'
 */
 [_META] = LAYOUT( \
     _______, XXXXXXX, XXXXXXX, ARROW,    ECLYN,   BASE,                         KC_HOME, KC_END,  KC_LCAP, KC_PSCR,  XXXXXXX, RESET, \
     _______, KC_1,    KC_2,    KC_3,     KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,     KC_0,    KC_PIPE, \
     _______, KC_F6,   XXXXXXX, KC_MHEN,  KC_HENK, XXXXXXX, KC_PLUS,  S(KC_MINS), KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_F7,   XXXXXXX, \
     _______, KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,   KC_ASTR,     KC_SLSH, KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_RSFT, \
                       _______, _______,  _______, _______,                       _______, _______, _______, _______ \
 ),

/* SYMB
 * ,-----------------------------------------.                 ,-----------------------------------------.
 * | Esc  |      |      | CAPS |Prtsc |      |                 |      |      |      |      |      |Reset |
 * |------+------+------+------+------+------.                 |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |                 |   ^  |   &  |   *  |   `  |   ~  |  |   |
 * |------+------+------+------+------+------+------.   ,-------------+------+------+------+------+------|
 * | Ctrl |      |   `  |   ~  |   {  |   <  |  (   |   |  )   |   >  |   }  |   :  |   _  |  /   | JPY  |
 * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
 * | Sft  |      | APP  | GUI  |      |      |  [   |   |  ]   |   "  |   '  |   ;  | RALT |  ?   |\/Sft |
 * `------+------+------+------+------+------+------'   `------+------+------+------+------+------+------|
 *               | META/|ESC/  |Space/|Tab/  |                 |BS/   |Enter/| Del/ | SYMB/|
 *               | LALT |~SYMB |LCtrl |Shift |                 |Shift |~META | RCTRL| RALT |
 *               `---------------------------'                 `---------------------------'
 */
 [_SYMB] = LAYOUT( \
     _______, XXXXXXX,  XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   RESET, \
     _______, KC_EXLM,  KC_AT,   KC_HASH,   KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_GRV,  S(KC_GRV), S(KC_BSLS), \
     _______, XXXXXXX,  KC_GRV,  S(KC_GRV), KC_LCBR, KC_LT,   KC_LPRN, KC_RPRN, KC_GT,   KC_RCBR, KC_COLN, KC_UNDS, KC_SLSH,   KC_JYEN, \
     _______, XXXXXXX,  KC_APP,  KC_LGUI,   XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_DQT,  KC_QUOT, KC_SCLN, KC_RALT, KC_QUES,   KC_RSFT, \
                        _______, _______,   _______, _______,                   _______, _______, _______, _______ \
 ),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("This is BASE layer");
        set_single_persistent_default_layer(1UL<<_BASE);
      }
      return false;
      break;
    case ECLYN:
      if (record->event.pressed) {
        // when keycode ARROW is pressed
        SEND_STRING("Change layer to EUCALYN");
        set_single_persistent_default_layer(1UL<<_ECLYN);
      }
      return false;
      break;
    case ARROW:
      if (record->event.pressed) {
        // when keycode ARROW is pressed
        SEND_STRING("Change layer to ARROW");
        set_single_persistent_default_layer(1UL<<_ARROW);
      }
      return false;
      break;
    case META:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        layer_on(_META);
      } else {
        // when keycode QMKURL is released
        layer_off(_META);
      }
      return false;
      break;
    case SYMB:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        layer_on(_SYMB);
      } else {
        // when keycode QMKURL is released
        layer_off(_SYMB);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

