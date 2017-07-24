// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum planck_layers {
  _WORKMAN,
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _GAMING,
  _LOWER,
  _RAISE,
  _CODING,
  _FUNCTION,
  _ADJUST
};

enum planck_keycodes {
  WORKMAN = SAFE_RANGE,
  QWERTY,
  COLEMAK,
  DVORAK,
  GAMING,
  LOWER,
  RAISE,
  CODING,
  FUNCTION,
  BACKLIT
};

//Tap Dance Declarations
enum {
  TD_COMM_SPACE = 0,
  TD_DOT_BSPACE = 1,
  TD_U_BKT = 2,
  TD_D_TAB = 3,
  TD_P_SCLN = 4,
  TD_Z_SFT_GUI = 5,
};

enum macro_keycodes {
  KC_ALT_TAB,
  KC_CMD_TAB,
  KC_CTL_TAB,
  KC_CMD_SLSH,
  KC_AG_FIND,
  KC_AG_AGAIN,
  KC_AG_UNDO,
  KC_AG_CUT,
  KC_AG_COPY,
  KC_AG_PASTE,
  KC_AG_DESK_L,
  KC_AG_DESK_R,
  KC_AG_TAB_C,
  KC_AG_TAB_N,
  KC_AG_TAB_R,
  /* KC_QUESTION, */
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define Z_SFT       SFT_T(KC_Z)
#define Z_GUI       LGUI_T(KC_Z)
#define CTL_ESC     CTL_T(KC_ESC)
#define ENT_SFT     SFT_T(KC_ENT)
#define M_ALT       ALT_T(KC_M)
#define C_ALT       ALT_T(KC_C)
#define DLR_SFT     SFT_T(KC_DLR)

#define TAB_COD     LT(_CODING, KC_TAB)
#define P_FUN       LT(_FUNCTION, KC_P)
/* #define A_ARR       LT(_ARROW, KC_A) */
/* #define S_SYM       LT(_SYMBOL, KC_S) */
/* #define H_NUM       LT(_NUMBER, KC_H) */
/* #define D_NUM       LT(_NUMBER, KC_D) */
/* #define T_FUN       LT(_FUNCTION, KC_T) */
/* #define F_FUN       LT(_FUNCTION, KC_F) */
/* #define X_MSE       LT(_MOUSE, KC_X) */
/* #define Q_COD       LT(_CODING,KC_Q) */
/* #define W_COD       LT(_CODING,KC_W) */

#define ALT_TAB     M(KC_ALT_TAB)               // Macro for Alt-Tab
#define CMD_TAB     M(KC_CMD_TAB)               // Macro for Cmd-Tab
#define CTL_TAB     M(KC_CTL_TAB)               // Macro for Ctl-Tab
#define CMD_SLSH    M(KC_CMD_SLSH)              // Macro for Cmd-Slash (personal shortcut to toggle iTerm2 visibility)
#define AG_FIND     M(KC_AG_FIND)               // Macros for Cmd-[x] vs Ctrl-[x] based on current AG_NORM or AG_SWAP settings
#define AG_AGAIN    M(KC_AG_AGAIN)
#define AG_UNDO     M(KC_AG_UNDO)
#define AG_CUT      M(KC_AG_CUT)
#define AG_COPY     M(KC_AG_COPY)
#define AG_PASTE    M(KC_AG_PASTE)
#define AG_D_L      M(KC_AG_DESK_L)             // For Virtual Desktop Switching: Left, and
#define AG_D_R      M(KC_AG_DESK_R)             //                                Right
#define AG_T_C      M(KC_AG_TAB_C)              // For Chrome, etc. Tab Close,
#define AG_T_N      M(KC_AG_TAB_N)              //                  Tab New, and
#define AG_T_R      M(KC_AG_TAB_R)              //                  Tab Reopen Closed

#define TD_SPC      TD(TD_COMM_SPACE)
#define TD_BSPC     TD(TD_DOT_BSPACE)
#define TD_U        TD(TD_U_BKT)
#define TD_D        TD(TD_D_TAB)
#define TD_P        TD(TD_P_SCLN)
#define TD_Z        TD(TD_Z_SFT_GUI)

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_WORKMAN] = {
  {TAB_COD,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    P_FUN,    KC_SCLN, KC_BSPC},
  {CTL_ESC,  KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, ENT_SFT},
  {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    P_FUN,    KC_BSPC},
  {CTL_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH},
  {KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT },
  {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},
[_GAMING] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {CTL_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_GRV,  _______,  KC_0, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9},
  {KC_DEL,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_DOT,   KC_ASTR, KC_DOT,  KC_4,    KC_5,    KC_6},
  {_______, KC_7,   KC_8,   KC_9,   KC_1,  KC_1,  KC_1,  KC_PLUS, KC_0, KC_1,    KC_2,    KC_3  },
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_PLUS, KC_MINUS, KC_SLSH, KC_EQL}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_DEL,  KC_MINUS,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_7,   KC_8,   KC_9,   KC_1,  KC_1,  KC_1,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY}
},
[_CODING] = {
  {_______, ALT_TAB, KC_AT,   KC_HASH, KC_DLR,  KC_LT, KC_GT, KC_QUES,    KC_QUOT,    KC_SCOLON, KC_LCBR, KC_RCBR},
  {KC_DEL,  KC_TILD,   KC_EXLM,   KC_PERC,   KC_PIPE,   KC_PLUS,  KC_BSLASH ,   KC_SLASH,    KC_CIRC,    KC_DLR, KC_LPRN, KC_RPRN},
  {_______, KC_7,   KC_8,   KC_9,   KC_1,  KC_ASTR,  KC_UNDS,  KC_MINUS, KC_COMM, KC_DOT, KC_LBRC , KC_RBRC},
  {_______, _______, _______, _______, _______, _______, KC_HOME, KC_END,    KC_MNXT,    KC_EQL, KC_LT, KC_GT}
},
  /* [_CODING] = KEYMAP( */
  /*     #<{(||----------`---------`----------`----------`----------`----------`----------`----------`----------`----------||)}># */
  /*         ALT_TAB  , _______ , XXXXXXX  ,  KC_LT   ,  KC_GT   , KC_QUES  , KC_QUOT  , KC_SCOLON,  KC_LCBR , KC_RCBR  , */
  /*     #<{(||----------`---------`----------`----------`----------`----------`----------`----------`----------`----------||)}># */
  /*         KC_CIRC  , KC_PERC , _______  , KC_PLUS  , KC_BSLASH, KC_SLASH , KC_CIRC  , KC_DLR   ,  KC_LPRN , KC_RPRN  , */
  /*     #<{(||----------`---------`----------`----------`----------`----------`----------`----------`----------`----------||)}># */
  /*         KC_LSFT  , KC_EQUAL, XXXXXXX  , KC_ASTR  , KC_UNDS  , KC_MINUS , KC_COMM  , KC_DOT   ,  KC_LBRC , KC_RBRC  ), */
  /*     #<{(||----------`---------`----------`----------`----------`----------`----------`----------`----------`----------||)}># */
[_FUNCTION] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    _______,    _______, _______, KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL },
  {_______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  WORKMAN,  GAMING},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

/* //Tap Dance Definitions */
/* qk_tap_dance_action_t tap_dance_actions[] = { */
/*   //Tap once for Esc, twice for Caps Lock */
/*   [TD_COMM_SPACE]  = ACTION_TAP_DANCE_DOUBLE(KC_SPACE, KC_COMM), */
/*   [TD_DOT_BSPACE]  = ACTION_TAP_DANCE_DOUBLE(KC_BSPACE, KC_DOT), */
/*   [TD_U_BKT] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_LBRC), */
/*   [TD_D_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_D, KC_TAB), */
/*   [TD_P_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_SCOLON), */
/*   [TD_Z_SFT_GUI] = ACTION_TAP_DANCE_DOUBLE(Z_SFT, KC_LGUI) */
/* }; */

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    if (!eeconfig_is_enabled()) {
      eeconfig_init();
    }

    bool use_cmd = true;    // Use, for example, Cmd-Tab, Cmd-C, Cmd-V, etc.
    // Compare to MAGIC_SWAP_ALT_GUI and MAGIC_UNSWAP_ALT_GUI configs, set in:
    // quantum/quantum.c
    /* if(keymap_config.swap_lalt_lgui == 1 && keymap_config.swap_ralt_rgui == 1) { */
    /*   use_cmd = false;      // ... or, Alt-Tab, Ctrl-C, Ctrl-V, etc. */
    /* } */

    switch (id) {
      case KC_ALT_TAB:
        if(use_cmd) { return (record->event.pressed ? MACRO( D(LALT),  D(TAB), END ) : MACRO( U(TAB), END )); }
        else        { return (record->event.pressed ? MACRO( D(LGUI),  D(TAB), END ) : MACRO( U(TAB), END )); }
      case KC_CMD_TAB:
        if(use_cmd) { return (record->event.pressed ? MACRO( D(LGUI),  D(TAB), END ) : MACRO( U(TAB), END )); }
        else        { return (record->event.pressed ? MACRO( D(LALT),  D(TAB), END ) : MACRO( U(TAB), END )); }

      case KC_CTL_TAB:
        return (record->event.pressed ? MACRO( D(LCTRL), D(TAB), END ) : MACRO( U(TAB), END ));
      case KC_CMD_SLSH:
        return (record->event.pressed ? MACRO( D(LGUI),  D(SLSH),END ) : MACRO( U(SLSH),END ));

      case KC_AG_FIND:
        return use_cmd ? MACRODOWN( D(LGUI), T(F), END ) : MACRODOWN( D(LCTRL), T(F), END );
      case KC_AG_AGAIN:
        return use_cmd ? MACRODOWN( D(LGUI), T(G), END ) : MACRODOWN( D(LCTRL), T(G), END );
      case KC_AG_UNDO:
        return use_cmd ? MACRODOWN( D(LGUI), T(Z), END ) : MACRODOWN( D(LCTRL), T(Z), END );
      case KC_AG_CUT:
        return use_cmd ? MACRODOWN( D(LGUI), T(X), END ) : MACRODOWN( D(LCTRL), T(X), END );
      case KC_AG_COPY:
        return use_cmd ? MACRODOWN( D(LGUI), T(C), END ) : MACRODOWN( D(LCTRL), T(C), END );
      case KC_AG_PASTE:
        return use_cmd ? MACRODOWN( D(LGUI), T(V), END ) : MACRODOWN( D(LCTRL), T(V), END );

      case KC_AG_DESK_L:
        return use_cmd ? MACRODOWN( D(LGUI), D(LCTRL), T(SCLN), END ) : MACRODOWN( D(LALT), D(LCTRL), T(SCLN), END );
      case KC_AG_DESK_R:
        return use_cmd ? MACRODOWN( D(LGUI), D(LCTRL), T(QUOT), END ) : MACRODOWN( D(LALT), D(LCTRL), T(QUOT), END );

      case KC_AG_TAB_C:
        return use_cmd ? MACRODOWN( D(LGUI),            T(W), END ) : MACRODOWN( D(LCTRL),            T(W), END );
      case KC_AG_TAB_N:
        return use_cmd ? MACRODOWN( D(LGUI),            T(T), END ) : MACRODOWN( D(LCTRL),            T(T), END );
      case KC_AG_TAB_R:
        return use_cmd ? MACRODOWN( D(LGUI), D(LSHIFT), T(T), END ) : MACRODOWN( D(LCTRL), D(LSHIFT), T(T), END );
    }

    return MACRO_NONE;
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
  rgblight_init();
  rgblight_mode(14);
}

uint8_t lastLayer = 0;

void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);
  if (lastLayer != layer)
  {
    switch (layer) {
     case 1:
        rgblight_mode(1);
        rgblight_setrgb(224, 64, 221);
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
        rgblight_mode(1);
        rgblight_setrgb(221, 44, 0);
        break;
      case 6:
        rgblight_mode(1);
        rgblight_setrgb(115, 23, 50);
        break;
      case 7:
        rgblight_mode(1);
        rgblight_setrgb(221, 78, 200);
        break;
      case 8:
        rgblight_mode(1);
        rgblight_setrgb(52, 73, 94);
        break;
      case 9:
        rgblight_mode(1);
        rgblight_setrgb(221, 78, 200);
        break;
      case 10:
        rgblight_mode(1);
        rgblight_setrgb(221, 78, 200);
        break;
      case 11:
        rgblight_mode(1);
        rgblight_setrgb(154, 55, 147);
        break;
      default:
        rgblight_mode(14);
        break;
    }
    lastLayer = layer;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case WORKMAN:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_WORKMAN);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_GAMING);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;
  }
  return true;
}

