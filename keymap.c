#include QMK_KEYBOARD_H
#include "version.h"

#include "ledmaps.h"
#include "keymaps.h"

void keyboard_post_init_user(void) {
#ifdef CONFIG_ENABLE_RGB_MATRIX
  rgb_matrix_enable();
#else
  rgb_matrix_disable();
#endif
}

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmaps[layer][i][0]),
      .s = pgm_read_byte(&ledmaps[layer][i][1]),
      .v = pgm_read_byte(&ledmaps[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
    }
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t layer = get_highest_layer(state);

  ML_LED_1(false);
  ML_LED_2(false);
  ML_LED_3(false);
  ML_LED_4(false);
  ML_LED_5(false);
  ML_LED_6(false);

  switch (layer) {
    case BASE:
      ML_LED_1(1);
      ML_LED_4(1);
      rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
      break;
    case SYMBOLS:
      ML_LED_2(1);
      ML_LED_5(1);
      rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
      break;
    case FUN:
      ML_LED_3(1);
      ML_LED_6(1);
      rgb_matrix_mode_noeeprom(RGB_MATRIX_RAINDROPS);
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

#ifdef RGB_MATRIX_ENABLE
#    ifndef RGB_MATRIX_INDICATOR_SET_COLOR
#        define RGB_MATRIX_INDICATOR_SET_COLOR(i, r, g, b) rgb_matrix_set_color(i, r, g, b)
void rgb_matrix_indicators_user(void) {
  #else
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
# endif
  if (g_suspend_state || !rgb_matrix_config.enable) return;

  if (layer_state_is(BASE)) {
    set_layer_color(LEDMAP_KEY_PRINTS);
  } else if (layer_state_is(SYMBOLS)) {
    set_layer_color(LEDMAP_SYMBOLS);
  }
}
#endif
