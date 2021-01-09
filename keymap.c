#include QMK_KEYBOARD_H
#include "version.h"

#include "keymap_bepo.h"
#include "keymap_french.h"

enum layers {
    ANSI_QWERTY,
    ANSI_QWERTY_SYMBOLS,
    BEPO_QWERTY,
    BEPO_QWERTY_SYMBOLS,
    FUN,
};

enum custom_keycodes {
    VERSION = ML_SAFE_RANGE,
    SMILEY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [ANSI_QWERTY] = LAYOUT_moonlander(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,           KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSPC,           KC_TAB, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, TG(FUN),
        KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
    TG(BEPO_QWERTY),WEBUSB_PAIR,A(KC_LSFT),KC_LEFT, KC_RGHT,  LALT_T(KC_APP),    KC_RCTL,   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(ANSI_QWERTY_SYMBOLS),
                                            KC_SPC,  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT
    ),

    [ANSI_QWERTY_SYMBOLS] = LAYOUT_moonlander(
        KC_GRV,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,           _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
        _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,           _______, KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                             KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
        EEP_RST, _______, _______, _______, _______,          RGB_VAI,           RGB_TOG,          _______, KC_DOT,  KC_0,    KC_EQL,  _______,
                                            RGB_HUD, RGB_VAD, RGB_HUI, TOGGLE_LAYER_COLOR,_______, _______
    ),

    [BEPO_QWERTY] = LAYOUT_moonlander(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,           KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  BP_B,    BP_E_ACUTE,    BP_P,           BP_O,           BP_E_GRAVE,    KC_BSPC,         KC_TAB, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, TG
(FUN),
        KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
    TG(BEPO_QWERTY),WEBUSB_PAIR,A(KC_LSFT),KC_LEFT, KC_RGHT,  LALT_T(KC_APP),    KC_RCTL,   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(BEPO_QWERTY_SYMBOLS),
                                            KC_SPC,  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT
    ),

    [BEPO_QWERTY_SYMBOLS] = LAYOUT_moonlander(
        KC_GRV,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TAB,  BP_B,    BP_E_ACUTE,    BP_P,           BP_O,           BP_E_GRAVE,    KC_BSPC,         KC_TAB, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_HYPR,           KC_MEH,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LGUI_T(KC_QUOT),
        KC_LSFT, LCTL_T(KC_Z),KC_X,KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  RCTL_T(KC_SLSH), KC_RSFT,
    TG(BEPO_QWERTY),WEBUSB_PAIR,A(KC_LSFT),KC_LEFT, KC_RGHT,  LALT_T(KC_APP),    KC_RCTL,   KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(ANSI_QWERTY_SYMBOLS),
                                            KC_SPC,  KC_BSPC, KC_LGUI,           KC_LALT,  KC_TAB,  KC_ENT
    ),

    [FUN] = LAYOUT_moonlander(
        LED_LEVEL, SMILEY,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, TG(FUN),
        _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);

    ML_LED_1(false);
    ML_LED_2(false);
    ML_LED_3(false);
    ML_LED_4(false);
    ML_LED_5(false);
    ML_LED_6(false);

//    for (int i = 0; i < 7; i++) {
//        rgblight_set_layer_state(i, layer_state_cmp(state, i));
//    }

    switch (layer) {
        case ANSI_QWERTY:
            ML_LED_1(1);
// THIS CAUSES PROBLEMS
//            rgblight_disable();
//            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            break;
        case ANSI_QWERTY_SYMBOLS:
            ML_LED_2(1);
//            rgblight_enable();
//            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
//            rgblight_set_layer_state(0, true);
            break;
        case BEPO_QWERTY:
            ML_LED_3(1);
            rgblight_enable();
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgblight_sethsv_noeeprom(HSV_CYAN);
//            rgblight_set_layer_state(1, true);
            break;
        case BEPO_QWERTY_SYMBOLS:
            ML_LED_4(1);
            rgblight_enable();
            rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
            rgblight_sethsv_noeeprom(HSV_CORAL);
            break;
        case FUN:
            ML_LED_5(1);
            rgblight_enable();
            rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINDROPS);
//            rgb_matrix_mode_noeeprom(RGB_MATRIX_BAND_SPIRAL_VAL);
            break;
        default:
            break;
    }

    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
        case VERSION:
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        case SMILEY:
            SEND_STRING (":-)");
            return false;
        }
    }
    return true;
}
