#include QMK_KEYBOARD_H

/*
 * See https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes
 */

enum keymap_layers {
  BASE,
  SYMBOLS,
  FUN,
  COLORS,
  EMPTY,
  DEFAULT_BASE,
  DEFAULT_SYMB,
  DEFAULT_MDIA,
};

enum custom_keycodes {
  VERSION = ML_SAFE_RANGE,
  SMILEY,
#ifdef CONFIG_ENABLE_SONGS
  SONG_1, SONG_2, SONG_3, SONG_4, SONG_5, SONG_6, SONG_7, SONG_8, SONG_9, 
#endif
};

#define UC_A_GRAVE	UC(0x00E0)
#define UC_A_AIGU	UC(0x00E1)
#define UC_C_CEDILLE	UC(0x00E7)
#define UC_E_GRAVE	UC(0x00E8)
#define UC_E_AIGU	UC(0x00E9)
#define UC_E_CIRC	UC(0x00EA)
#define UC_E_TREMA	UC(0x00EB)
#define UC_N_TILDE	UC(0x00F1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,           _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSPC,           KC_TAB, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, TG(FUN),
    KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    MO(SYMBOLS),_______,_______,KC_LEFT, KC_RGHT,  KC_LCTL,    KC_RCTL,   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(SYMBOLS),
                                          KC_SPC,  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT
  ),

  [SYMBOLS] = LAYOUT_moonlander(
    VERSION, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, UC_A_GRAVE, UC_E_AIGU, UC_E_TREMA, UC_E_GRAVE, _______, _______,           _______, _______, _______, _______, _______, KC_ASTR, KC_EQUAL,
    UC_A_AIGU, KC_AT, KC_DLR, UC_E_CIRC, _______, _______, _______,           _______, _______, _______, _______, _______, KC_PLUS, _______,
    _______, _______, _______, UC_C_CEDILLE, _______, _______,                             UC_N_TILDE, _______, _______, _______, KC_BSLS, _______,
    _______, _______, _______, _______, _______,         _______,            _______,          KC_PGUP, KC_PGDOWN, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
  ),

  [FUN] = LAYOUT_moonlander(
    LED_LEVEL, SMILEY,VERSION, SONG_1 , SONG_2 , SONG_3 , _______,           _______, _______, _______, _______, _______, _______, RESET,
    BL_TOGG, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
    RGB_TOG, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, TG(FUN),
    _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
    MO(COLORS), _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
  ),

  [COLORS] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,         _______,            _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
  ),

  [EMPTY] = LAYOUT_moonlander(
    _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,         _______,            _______,          _______, _______, _______, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
  ),

  [DEFAULT_BASE] = LAYOUT_moonlander(
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,           KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_DEL,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TG(DEFAULT_SYMB),         TG(DEFAULT_SYMB), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    LT(DEFAULT_MDIA, KC_SCLN), LGUI_T(KC_QUOT),
    KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
    LT(DEFAULT_SYMB,KC_GRV),WEBUSB_PAIR,A(KC_LSFT),KC_LEFT, KC_RGHT,  LALT_T(KC_APP),    RCTL_T(KC_ESC),   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(DEFAULT_SYMB),
                                            KC_SPC,  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT
  ),

  [DEFAULT_SYMB] = LAYOUT_moonlander(
    VERSION, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,           _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,           _______, KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                             KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
    EEP_RST, _______, _______, _______, _______,          RGB_VAI,           RGB_TOG,          _______, KC_DOT,  KC_0,    KC_EQL,  _______,
                                            RGB_HUD, RGB_VAD, RGB_HUI, TOGGLE_LAYER_COLOR,_______, _______
  ),

  [DEFAULT_MDIA] = LAYOUT_moonlander(
    LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, RESET,
    _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
    _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
    _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
  ),


};
