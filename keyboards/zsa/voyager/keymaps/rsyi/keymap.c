// rsyi Voyager keymap, ported from Oryx layout 7Dw7Y ("Dvorak Voyager", revision RjmE3W).
// The computer is expected to be set to Dvorak, so every printable key uses the DV_*
// software-dvorak codes from keymap_dvorak.h (same convention as the planck _SDRK layer).
// Layer numbering mirrors the Oryx layout so MO()/TG() references line up.

#include QMK_KEYBOARD_H
#include "keymap_dvorak.h"

enum voyager_layers {
    _MAC,    // 0: base (Mac)
    _LOWER,  // 1: F-keys / symbols / window management
    _RAISE,  // 2: numbers / brackets / arrows
    _MODS_L, // 3: unused placeholder (kept for Oryx layer numbering)
    _MODS_R, // 4: RGB / media / brightness, TG to PC layer
    _MOUSE,  // 5: mouse buttons (ZSA Navigator keys have no mainline equivalent)
    _PC      // 6: swaps the GUI/ALT mod-taps for non-mac machines
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (Mac, software dvorak)
 * ,-----------------------------------------.    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |    |   6  |   7  |   8  |   9  |   0  | Lang |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |    |   F  |   G  |   C  |   R  |   L  |   /  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |Esc/^ |   A  |   O  |   E  |   U  |   I  |    |   D  |   H  |   T  |   N  |   S  |   -  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+------|
 * |Shift |   ;  | Q/⌥  | J/⌘  |   K  |   X  |    |   B  |   M  |   W  |   V  |   Z  |Enter |
 * `-----------------------------------------'    `-----------------------------------------'
 *                       ,-------------.                  ,-------------.
 *                       |Spc/L1| MO(4)|                  |⌥Bspc |Bsp/L2|
 *                       `-------------'                  `-------------'
 */
[_MAC] = LAYOUT(
    DV_GRV,         KC_1,    KC_2,         KC_3,         KC_4, KC_5,        KC_6, KC_7, KC_8, KC_9, KC_0, LCA(KC_SPC),
    KC_TAB,         DV_QUOT, DV_COMM,      DV_DOT,       DV_P, DV_Y,        DV_F, DV_G, DV_C, DV_R, DV_L, DV_SLSH,
    CTL_T(KC_ESC),  DV_A,    DV_O,         DV_E,         DV_U, DV_I,        DV_D, DV_H, DV_T, DV_N, DV_S, DV_MINS,
    KC_LSFT,        DV_SCLN, LALT_T(DV_Q), LGUI_T(DV_J), DV_K, DV_X,        DV_B, DV_M, DV_W, DV_V, DV_Z, KC_ENT,
                                 LT(_LOWER, KC_SPC), MO(_MODS_R),        LALT(KC_BSPC), LT(_RAISE, KC_BSPC)
),

/* Lower: F-keys, shifted symbols, opening brackets left / closing right, window management
 * (Prev Displ = ^⌥⌘←, Left Half = ^⌥←, Maximize = ^⌥⏎, ⌥+arrows on the right hand)
 */
[_LOWER] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,         KC_F8,         KC_F9,       KC_F10,        _______,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_F11,                         KC_F12,  KC_PERC,       KC_CIRC,       KC_AMPR,     KC_ASTR,       DV_PIPE,
    _______, DV_TILD, DV_LCBR, DV_LBRC, DV_LPRN, LCAG(KC_LEFT),                  _______, DV_RPRN,       DV_RBRC,       DV_RCBR,     DV_GRV,        DV_PLUS,
    _______, _______, _______, _______, _______, LCA(KC_LEFT),                   _______, LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_UP), LALT(KC_RGHT), _______,
                                              _______, _______,        _______, LCA(KC_ENT)
),

/* Raise: numbers on home-ish rows, brackets, plain arrows
 * (Next Displ = ^⌥⌘→, Right Half = ^⌥→, Maximize = ^⌥⏎ on the left thumb)
 */
[_RAISE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                        _______,        _______, _______, _______, _______, _______,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,           KC_7,    KC_8,    KC_9,    KC_0,    DV_BSLS,
    _______, DV_TILD, DV_LCBR, DV_LBRC, DV_LPRN, _______,                        LCAG(KC_RGHT),  DV_RPRN, DV_RBRC, DV_RCBR, DV_GRV,  DV_EQL,
    _______, _______, _______, _______, _______, _______,                        LCA(KC_RGHT),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
                                        LCA(KC_ENT), _______,           _______, _______
),

/* Mods L: empty in the Oryx layout; kept so layer numbers stay aligned. */
[_MODS_L] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
                                              _______, _______,        _______, _______
),

/* Mods R: RGB on the home rows, media/brightness on the bottom rows, TG(_PC) top right.
 * QK_BOOT (top left) enters the bootloader without needing the physical reset button. */
[_MODS_R] = LAYOUT(
    QK_BOOT, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, TG(_PC),
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    _______, RM_NEXT, RM_SPDD, RM_SATD, RM_HUED, RM_VALD,                        RM_VALU, RM_HUEU, RM_SATU, RM_SPDU, _______, _______,
    _______, _______, KC_MUTE, KC_VOLD, KC_MPRV, KC_BRID,                        KC_BRIU, KC_MNXT, KC_VOLU, KC_MPLY, _______, _______,
                                              _______, _______,        _______, _______
),

/* Mouse: the Oryx layer is built around the ZSA Navigator trackball (CPI, drag/toggle
 * scroll, layer lock), which mainline QMK doesn't support — only the plain mouse
 * buttons are carried over. */
[_MOUSE] = LAYOUT(
    XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX,                        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, MS_BTN3, XXXXXXX,                        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, MS_BTN2, MS_BTN1, XXXXXXX,                        _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
                                              _______, _______,        _______, _______
),

/* PC: toggled from _MODS_R; swaps the Q/J thumb-row mod-taps so GUI/ALT match a PC. */
[_PC] = LAYOUT(
    _______, _______, _______,      _______,      _______, _______,              _______, _______, _______, _______, _______, _______,
    _______, _______, _______,      _______,      _______, _______,              _______, _______, _______, _______, _______, _______,
    _______, _______, _______,      _______,      _______, _______,              _______, _______, _______, _______, _______, _______,
    _______, _______, LGUI_T(DV_Q), LALT_T(DV_J), _______, _______,              _______, _______, _______, _______, _______, _______,
                                              _______, _______,        _______, _______
),

};
