#include QMK_KEYBOARD_H

#define H_A LALT_T(KC_A)
#define H_S LCTL_T(KC_S)
#define H_E LSFT_T(KC_E)
#define H_T LGUI_T(KC_T)

#define H_H RALT_T(KC_H)
#define H_O RCTL_T(KC_O)
#define H_I RSFT_T(KC_I)
#define H_N RGUI_T(KC_N)


enum custom_keycodes {
  _NORMAN,
  _NUM,
  _RAISE
};

/* enum ferris_tap_dances { */
/*   TD_Q_ESC */
/* }; */
#define H_A LALT_T(KC_A)
#define H_S LCTL_T(KC_S)
#define H_E LSFT_T(KC_E)
#define H_T LGUI_T(KC_T)

#define H_H RALT_T(KC_H)
#define H_O RCTL_T(KC_O)
#define H_I RSFT_T(KC_I)
#define H_N RGUI_T(KC_N)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_NORMAN] = LAYOUT( /* QWERTY */
    KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,            KC_J,    KC_U,  KC_R,    KC_L,   KC_SCLN,
    H_A, H_S,    H_E,    H_T,    KC_G,            KC_Y,    H_N,  H_I,    H_O,  H_H,
    KC_Z, KC_X,    KC_C,    KC_V,    KC_B,            KC_P,    KC_M,  KC_COMM, KC_DOT, KC_SLSH,
                                    LT(_NUM, KC_ESC), LT(_RAISE, KC_ENT), KC_BSPC, KC_SPC
  ),
  [_NUM] = LAYOUT( /* QWERTY */
    KC_4,    KC_2,    KC_3,    KC_1,    KC_5,          KC_6,    KC_0,    KC_8,    KC_9,    KC_7,
    KC_PERC, KC_DLR,  KC_TILD, KC_LPRN, KC_RPRN,       KC_LCBR, KC_RCBR, KC_EQL, KC_ASTR, KC_PLUS,
    KC_AT,   KC_GRV, KC_PIPE,  KC_AMPR, KC_LBRC,          KC_RBRC, KC_UNDS, KC_CIRC, KC_HASH, KC_MINS,
                                    OSL(_NUM), KC_ENT, KC_QUOTE, KC_TAB
  ),


  [_RAISE] = LAYOUT( /* QWERTY */
    _______, KC_MUTE, _______, KC_MPLY, _______,       _______, _______, _______, _______, _______,
    RESET, _______, _______, _______, _______,       KC_BACKSLASH, KC_P, _______, _______, _______,
    _______, _______, _______, KC_PSCR, _______,       _______, _______, _______, _______, _______,
                                    OSL(_NUM), KC_ENT, KC_QUOTE, KC_TAB
  ),

};

// Tap Dance Definitions
/* qk_tap_dance_action_t tap_dance_actions[] = { */
/*     // Tap once for Q, twice for ESC */
/*     [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC) */
/* }; */
