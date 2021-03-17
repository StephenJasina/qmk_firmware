/* Copyright 2015-2017 Jack Humbert
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


enum planck_layers {
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum planck_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  BSS
};

#define COLEMAK DF(_COLEMAK)
#define QWERTY DF(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak Mod-DHm
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |  Q   |  W   |  F   |  P   |  B   |  J   |  L   |  U   |  Y   |  ;   |Delete|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |  A   |  R   |  S   |  T   |  G   |  M   |  N   |  E   |  I   |  O   |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|  Z   |  X   |  C   |  D   |  V   |  K   |  H   |  ,   |  .   |  /   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|LCtrl | LAlt | LGui |Raise |Space | Bss  |Lower | RGui | RAlt |RCtrl |RShift|
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_DEL ,
    KC_ESC , KC_A   , KC_R   , KC_S   , KC_T   , KC_G   , KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, RAISE  , KC_SPC , BSS    , LOWER  , KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ;   |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LShift|LCtrl | LAlt | LGui |Raise |Space | Bss  |Lower | RGui | RAlt |RCtrl |RShift|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_DEL ,
    KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, RAISE  , KC_SPC , BSS    , LOWER  , KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |XXXXXX|  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |XXXXXX|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |XXXXXX|  `   |  {   |  [   |  (   |  -   |  =   |  )   |  ]   |  }   |  \   |XXXXXX|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    XXXXXXX, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , XXXXXXX,
    XXXXXXX, KC_GRV , KC_LCBR, KC_LBRC, KC_LPRN, KC_MINS, KC_EQL , KC_RPRN, KC_RBRC, KC_RCBR, KC_BSLS, XXXXXXX,
    KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |XXXXXX| Stop | Prev | Play | Next |XXXXXX| PgDn |XXXXXX|  Up  |XXXXXX| PgUp |XXXXXX|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |XXXXXX| Bri- | Vol- | Mute | Vol+ | Bri+ | Home | Left | Down |Right | End  |XXXXXX|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps |Print |Scroll|Pause |Insert| Num  |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    XXXXXXX, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, KC_PGDN, XXXXXXX, KC_UP  , KC_END , XXXXXXX, XXXXXXX,
    XXXXXXX, KC_BRID, KC_VOLD, KC_MUTE, KC_VOLU, KC_BRIU, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END , XXXXXXX,
    KC_CAPS, KC_PSCR, KC_SLCK, KC_PAUS, KC_INS , KC_NLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|Colemk|Qwerty|XXXXXX|XXXXXX|XXXXXX|XXXXXX|XXXXXX|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK, QWERTY , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};

bool bss_waiting = false;
int bss_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      return false;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      return false;
    case BSS:
      if (record->event.pressed) {
        bss_waiting = true;
        register_code(KC_LSFT);
        bss_timer = timer_read();
      } else {
        unregister_code(KC_LSFT);
        if (bss_waiting && timer_elapsed(bss_timer) < 250) {
          tap_code(KC_BSPC);
        }
        bss_waiting = false;
      }
      return false;
    default:
      if (bss_waiting && record->event.pressed) {
        bss_waiting = false;
      }

      return true;
  }
}
