#include "gherkin.h"

//Tap Dance Declarations
enum {
  TD_B_SPACE = 0,
  TD_X_BSPACE = 1
};

//Friendly Layer Names
enum gherkin_layers {
  _WORKMAN,
  _ARROW,
  _SYMBOL,
  _NUMBER,
  _FUNCTION,
  _MOUSE,
  _QWERTY
};

// custom keycodes
enum gherkin_keycodes {
  WORKMAN = SAFE_RANGE,
  ARROW,
  SYMBOL,
  NUMBER,
  FUNCTION,
  MOUSE,
  QWERTY
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

/* KEYMAP( */
/* 	LT(1, KC_Q), KC_W, KC_E, KC_R, KC_T, KC_Y,  */
/* 	KC_U, KC_I, KC_O, KC_P, KC_A, KC_S,  */
/* 	KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,  */
/* 	KC_L, KC_ESC, KC_Z, KC_X, KC_C, KC_V,  */
/* 	KC_BSPC, KC_SPC, KC_B, KC_N, KC_M, KC_ENT), */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* [_WORKMAN] = KEYMAP( */
  /*     F(22),  F(23),  F(24),  KC_P,   KC_Y,   KC_F,   KC_G,  KC_C,  KC_R,  KC_L, */
  /*     F(1),  F(2),  F(3),  F(4),  KC_I,   KC_D,   KC_H,  KC_T,  KC_N,  KC_S, */
  /*     F(21),  F(5),  KC_J,    KC_K,    TD(TD_X_BSPACE), TD(TD_B_SPACE),  KC_M,  KC_W,  KC_V,  F(25)), */
  [_WORKMAN] = KEYMAP(
      F(22),  KC_Q,  KC_D,  KC_R,   KC_W,   KC_B,   KC_J,  KC_F,  KC_U,  KC_P,
      F(1),  F(2),  F(3),  F(4),  KC_G,   KC_Y,   KC_N,  KC_E,  KC_O,  KC_I,
      F(21),  F(5),  KC_M,    KC_C,    TD(TD_X_BSPACE), TD(TD_B_SPACE),  KC_V,  KC_K,  KC_L,  F(25)),
  [_ARROW] = KEYMAP(
      KC_NO,    KC_NO,  KC_PGUP,  KC_UP,     KC_NO,   KC_NO,  KC_PGUP,  KC_HOME,  KC_UP,     KC_END,
      KC_TRNS,  KC_NO,  KC_PGDN,  KC_DOWN,   KC_NO,   KC_NO,  KC_PGDN,  KC_LEFT,     KC_DOWN,   KC_RIGHT,
      KC_NO,    KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,    KC_NO,  KC_NO),
  [_SYMBOL] = KEYMAP(
      KC_TILD,  KC_GRAVE,  KC_EQUAL,  KC_PLUS,  KC_LBRACKET,  KC_RBRACKET,  KC_NO,   KC_AMPR,  KC_ASTR, KC_LPRN,
      KC_NO,    KC_TRNS,    KC_SCOLON,   KC_COLN, KC_LCBR,   KC_RCBR,  F(12),  KC_DLR,   KC_PERC,   KC_CIRC,
      KC_EQUAL,   F(11),   KC_SLASH,   KC_MINUS,   KC_ASTR,  KC_BSLASH,   KC_SLASH,   KC_EXLM,   KC_AT,   KC_HASH),
  [_NUMBER] = KEYMAP(
      KC_ESC,  KC_NO,     KC_NO,    KC_PLUS,   KC_NO,   KC_NO,     KC_NO,  KC_7,  KC_8,  KC_9,
      KC_TAB,     KC_NO,     KC_TRNS,  KC_NO,     KC_NO,   KC_SLASH,  KC_NO,  KC_4,  KC_5,  KC_6,
      KC_NO,   KC_EQUAL,  KC_NO,    KC_ASTR,   KC_NO,   KC_MINUS,  KC_0,      KC_1,  KC_2,  KC_3),
  [_FUNCTION] = KEYMAP(
      KC_ESC,  KC_NO,  KC_NO,  KC_DELETE,  KC_F1,     KC_F2,     KC_F3,    KC_F4,    KC_F5,    KC_F6,
      KC_TAB,     KC_NO,  KC_NO,  KC_TRNS,    KC_F7,     KC_F8,     KC_F9,    KC_F10,   KC_F11,   KC_F12,
      KC_NO,   KC_NO,  KC_NO,  KC_INS,     KC_NO,  KC_NO,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END),
  [_MOUSE] = KEYMAP(
      KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,       KC_NO,       KC_MS_U,  KC_NO,
      KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,       KC_NO,       KC_MS_L,     KC_MS_D,  KC_MS_R,
      KC_NO,  KC_TRNS,  KC_NO,  KC_NO,  KC_NO,  KC_MS_BTN1,  KC_MS_BTN2,  KC_MS_BTN3,  KC_NO,    KC_NO)
};

const uint16_t PROGMEM fn_actions[] = {

  // Layers
  [1] =  ACTION_LAYER_TAP_KEY(1, KC_A),  // FN11 = momentary Layer1 (ARROW) on A
  [2] =  ACTION_LAYER_TAP_KEY(2, KC_S),  // FN12 = momentary Layer2 (SYMBOL) on O
  [3] =  ACTION_LAYER_TAP_KEY(3, KC_H),  // FN13 = momentary Layer3 (NUMBER) on E key
  [4] =  ACTION_LAYER_TAP_KEY(4, KC_T),  // FN14 = momentary Layer4 (FUNCTION) on U key
  [5] =  ACTION_LAYER_TAP_KEY(5, KC_X),  // FN15 = momentary Layer5 (MOUSE) on

  // Symbols
  [11] =  ACTION_MODS_KEY(MOD_LSFT, KC_SLASH), // FN11 = question mark
  [12] =  ACTION_MODS_KEY(MOD_LSFT, KC_MINUS), // FN12 = underscore

  // Mods
  [21] =  ACTION_MODS_TAP_KEY(MOD_LSFT, KC_Z), // Shift and ;
  [22] =  ACTION_MODS_TAP_KEY(MOD_LCTL, KC_QUOT), // Control and '
  [23] =  ACTION_MODS_TAP_KEY(MOD_LALT, KC_COMM), // Alt and ,
  [24] =  ACTION_MODS_TAP_KEY(MOD_LGUI, KC_DOT), // Meta and .
  [25] =  ACTION_MODS_TAP_KEY(MOD_RSFT, KC_ENT) // Shift and Z

};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_B_SPACE]  = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_SPACE),
  [TD_X_BSPACE]  = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_BSPACE)
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  keyevent_t event = record->event;
  (void)event;

  switch (id) {

  }
  return MACRO_NONE;
}

void matrix_init_kb(void) {
  rgblight_init();
  rgblight_mode(14);
  rgblight_sethsv_noeeprom(0, 255, 255);
}

void matrix_init_user(void) {
}

uint8_t lastLayer = 0;

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);
  if (lastLayer != layer)
  {
    switch (layer) {
     case 1:
        rgblight_mode(5);
        rgblight_setrgb(0, 200, 83);
        break;
      case 2:
        rgblight_mode(1);
        rgblight_setrgb(0, 184, 212);
        break;
      case 3:
        rgblight_mode(1);
        rgblight_setrgb(255, 171, 0);
        break;
      case 4:
        rgblight_mode(1);
        rgblight_setrgb(0, 200, 83);
        break;
      case 5:
        rgblight_mode(5);
        rgblight_setrgb(0, 200, 83);
        break;
      default:
        rgblight_mode(14);
        break;
    }
    lastLayer = layer;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

