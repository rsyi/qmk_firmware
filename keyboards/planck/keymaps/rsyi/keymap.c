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
#include "muse.h"
#include "keymap_extras/keymap_dvorak.h"

enum planck_layers {
  _SDRK,
  _DVORAK,
  _CODE,
  _LOWER,
  _SLOWER,
  _RAISE,
  _SRAISE,
  _ADJUST,
  _SADJUST
};

enum planck_keycodes {
  SDRK = SAFE_RANGE,
  DVORAK,
  BACKLIT,
};

#define LOWER MO(_LOWER)
#define CODE MO(_CODE)
#define RAISE MO(_RAISE)
#define SLOWER MO(_SLOWER)
#define SRAISE MO(_SRAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak base (two versions): `Dvorak` is for pair programming with a qwerty computer, while `sdrk` (or software dvorak) is meant for a dvorak-enabled computer.
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | /    |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  | -    |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |Space | Bksp | Raise| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_SDRK] = LAYOUT_planck_grid(
    KC_TAB,  DV_QUOT,    DV_COMM,    DV_DOT,    DV_P,    DV_Y,    DV_F,    DV_G,    DV_C,    DV_R,    DV_L, DV_SLSH,
    KC_LCTL,  DV_A,    DV_O,    DV_E,    DV_U,    DV_I,    DV_D,    DV_H,    DV_T,    DV_N,    DV_S,    DV_MINS,
    KC_LSFT, DV_SCLN,    DV_Q,    DV_J,    DV_K,    DV_X,    DV_B,    DV_M,    DV_W, DV_V,  DV_Z, KC_ENT,
    CODE, KC_LCTL, KC_LALT, KC_LGUI, SLOWER,     KC_SPC, KC_BSPC,     SRAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
[_DVORAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
    KC_LCTL,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT,
    CODE, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_BSPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Code, a third layer, for F keys
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  F9  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  F5  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  F1  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */


[_CODE] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_F9, KC_F10, KC_F11, KC_F12, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_F5, KC_F6, KC_F7, KC_F8, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_F1, KC_F2, KC_F3, KC_F4, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  {   |  [   |  (   |      |      |   )  |   ]  |   }  |  `   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   =  |  +   |   $  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Space| Del  |      | Home |Pg Up |Pg Dn | End  |
 * `-----------------------------------------------------------------------------------'
 */


[_RAISE] = LAYOUT_planck_grid(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, _______, S(KC_SLSH),
    _______,  _______,   KC_LCBR,   KC_LBRC,   KC_LPRN,   _______,   _______,   KC_RPRN, KC_RBRC, KC_RCBR, KC_GRV, _______,
    /*_______,  _______,   _______,   _______,   _______,   _______,   KC_BSLS,   KC_RPRN, KC_RBRC, KC_RCBR, _______, _______,*/
    _______,  _______, _______, _______, _______, _______, _______,  KC_EQL,  KC_PLUS, KC_DLR, _______, _______,
    _______, _______, _______, _______, _______, KC_SPACE, KC_DEL, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),
[_SRAISE] = LAYOUT_planck_grid(
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, _______, _______,
    _______,  _______,   DV_LCBR,   DV_LBRC,   KC_LPRN,   _______,   _______,   KC_RPRN, DV_RBRC, DV_RCBR, KC_GRV, _______,
    /*_______,  _______,   _______,   _______,   _______,   _______,   KC_BSLS,   KC_RPRN, DV_RBRC, DV_RCBR, _______, _______, */
    _______, _______, _______, _______, _______, _______, _______,  DV_EQL,  DV_PLUS, KC_DLR, _______, _______,
    _______, _______, _______, _______, _______, KC_SPACE, KC_DEL, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  `   |  {   |   [  |   (         |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   0  |   |  |   \  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Space| AltB |      | ALTL | ALTD | ALTU | ALTR |
 *`-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    KC_ESC, S(KC_GRV), KC_LCBR, KC_LBRC, KC_LPRN, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_0, KC_PIPE, KC_BSLS, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_SPC, LALT(KC_BSPC), _______, LALT(KC_LEFT), KC_PGDN, KC_PGUP, LALT(KC_RGHT)
),
[_SLOWER] = LAYOUT_planck_grid(
    _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
    KC_ESC, S(KC_GRV), DV_LCBR, DV_LBRC, DV_LPRN, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_0, DV_PIPE, KC_BSLS, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, KC_SPC, LALT(KC_BSPC), _______, LALT(KC_LEFT), KC_PGDN, KC_PGUP, LALT(KC_RGHT)

),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Voice-|Voice+|MUSmod|Aud on|Audoff|      |      |      |      |      |MIDIon|MIDIof|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Play | Prev | Next | Brte-| Brte+| Vol- | Vol+ | Mute |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |Mus on|Musoff|TermOn|TermOf|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    MUV_DE, MUV_IN, MU_MOD,  AU_ON,   AU_OFF,  _______, _______, _______,  _______,  _______,  MI_ON,  MI_OFF,
    _______, _______,   KC_MPLY,   KC_MPRV,   KC_MNXT,  KC_BRMD,  KC_BRMU,  KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,
    _______, _______, _______, _______, _______,  DVORAK, SDRK, _______, MU_ON,  MU_OFF, TERM_ON, TERM_OFF
),
[_SADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    MUV_DE, MUV_IN, MU_MOD,  AU_ON,   AU_OFF,  _______, _______, _______,  _______,  _______,  MI_ON,  MI_OFF,
    _______, _______,   KC_MPLY,   KC_MPRV,   KC_MNXT,  KC_BRMD,  KC_BRMU,  KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,
    _______, _______, _______, _______, _______,  DVORAK, SDRK, _______, MU_ON,  MU_OFF, TERM_ON, TERM_OFF
),

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _SLOWER, _SRAISE, _SADJUST);
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SDRK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_SDRK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE) || IS_LAYER_ON(_SRAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case SRAISE:
    case LOWER:
      return false;
    case CODE:
      return false;
    case SLOWER:
      return false;
    default:
      return true;
  }
}
