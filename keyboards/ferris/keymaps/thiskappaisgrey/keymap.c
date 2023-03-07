#include QMK_KEYBOARD_H

/* #define H_A LALT_T(KC_A) */
/* #define H_S LCTL_T(KC_S) */
/* #define H_E LSFT_T(KC_E) */
/* #define H_T LGUI_T(KC_T) */

/* #define H_H RALT_T(KC_H) */
/* #define H_O RCTL_T(KC_O) */
/* #define H_I RSFT_T(KC_I) */
/* #define H_N RGUI_T(KC_N) */


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


// Tap Dance declarations
enum {
    TD_NUM,
};



// TODO What I need is a tap dance, separate, shift key
// a spammable delete key
// be able to press "alt" / "mod" and symbols + numbers
// be able to spam numbers or common symbols

// TODO Right key should always set you to layer 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_NORMAN] = LAYOUT( /* QWERTY */
    KC_Q,    KC_W,    KC_D,    KC_F,    KC_K,         KC_J,    KC_U,  KC_R,    KC_L,   KC_SCLN,
    H_A,     H_S,    H_E,    H_T,    KC_G,            KC_Y,    H_N,  H_I,    H_O,  H_H,
    KC_Z, KC_X,    KC_C,    KC_V,    KC_B,            KC_P,    KC_M,  KC_COMM, KC_DOT, KC_SLSH,
    // TODO add mod-shift to KC_BSPC
    // tap dance to switch to different layers
    // TODO set up tap dance so that double tap
    // toggles to the num layer (backspace is in the other layer)
    // tap dance has a lot of powerful features, (see example 6)
    // I can have it hold for escape maybe? 
             OSL(_NUM), LT(_RAISE, KC_ENT),           OSM(MOD_LSFT), KC_SPC
  ),
  // put numpad on the right
  // then "common" symbols on the left
  // and other symbols on raise
  // and the home row would still hve the modifier keys (cntrl + alt + other keys)
  [_NUM] = LAYOUT( /* NUM LAYER */
		   
    KC_GRV, KC_LCBR,    KC_RCBR,    KC_LBRC,    KC_RBRC,          KC_TAB,    KC_1,    KC_2,    KC_3,    KC_CIRC,
    KC_PLUS, KC_MINS, KC_LPRN,  KC_ESC, KC_RPRN,                   KC_EQL,    KC_4,    KC_5,    KC_6,  KC_0,
    // TODO I can have it KC_CIRC mod/tap or tap hold
    // actually, I can make these keys accessible through combos on the home row
    // missing: KC_AT , KC_PERC, KC_TILD (can be reached by shift..), exclamation mark 
    // I want these to be mod/tap modifiers (or does a different key when held) so I don't have to make new layers
    // pick keys that aren't likely to be pressed twice most the time
    // or have a combination of keys activate that symbol? like OSL(_NUM) or something
    KC_PIPE,   KC_UNDS, KC_ASTR,  KC_AMPR, KC_DLR,                    KC_BACKSLASH, KC_7, KC_8, KC_9, KC_HASH,
    // I can make tab the tap dance?
    // TODO if this works, this key would then send me to the raise layer
                                TO(_NUM), KC_QUOTE,                  KC_BSPC, TO(0)
  ),
  
  /* [_NUM2] = LAYOUT( /\* NUM LAYER *\/ */
  /*   KC_4,    KC_2,    KC_3,    KC_1,    KC_5,          KC_6,    KC_0,    KC_8,    KC_9,    KC_7, */
  /*   KC_PERC, KC_DLR,  KC_TILD, KC_LPRN, KC_RPRN,       KC_LCBR, KC_RCBR, KC_EQL, KC_ASTR, KC_PLUS, */
  /*   KC_AT,   KC_GRV, KC_PIPE,  KC_AMPR, KC_LBRC,          KC_RBRC, KC_UNDS, KC_CIRC, KC_HASH, KC_MINS, */
  /*                                   OSL(_NUM), KC_ENT, KC_QUOTE, KC_TAB */
  /* ), */


  [_RAISE] = LAYOUT( /* QWERTY */
    _______, KC_MUTE, _______, KC_MPLY, _______,       _______, _______, _______, _______, _______,
    RESET, _______, _______, _______, _______,       KC_BACKSLASH, KC_P, _______, _______, _______,

    _______, _______, _______, KC_PSCR, _______,       _______, _______, _______, _______, _______,
                                    OSL(_NUM), KC_ENT, KC_QUOTE, KC_TAB
  ),

};




// Tap Dance definitions

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
  [TD_NUM] = ACTION_TAP_DANCE_DOUBLE(OSL(_NUM), TO(_NUM)),
};



