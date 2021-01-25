#include QMK_KEYBOARD_H

/*
 * See https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgb_matrix
 */

#define MY_HSV_ORANGE		8, 255, 255

#define KEY_PRINTS_ANON		HSV_WHITE
#define KEY_PRINTS_LETTER	HSV_CYAN
#define KEY_PRINTS_NUMBER	HSV_BLUE
#define KEY_PRINTS_SYMBOL	MY_HSV_ORANGE
#define KEY_PRINTS_INDEX	HSV_MAGENTA
#define SYMBOL_USE		HSV_GREEN
#define SYMBOL_NOUSE		HSV_MAGENTA
#define COLOR_DEFAULT		HSV_OFF

enum ledmap_layers {
  LEDMAP_KEY_PRINTS,
//  LEDMAP_FUN,
  LEDMAP_CLR,
};

/*
 * Unlike keymaps, each line below is a key column, not a key row!
 */
const uint8_t PROGMEM ledmaps[][DRIVER_LED_TOTAL][3] = {
  [LEDMAP_KEY_PRINTS] = {
    // Column below key 0
    {KEY_PRINTS_ANON},		{KEY_PRINTS_ANON},	{KEY_PRINTS_ANON},	{KEY_PRINTS_ANON},	{KEY_PRINTS_ANON},
    // Column below key 1
    {KEY_PRINTS_NUMBER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_SYMBOL},
    // Column below key 2
    {KEY_PRINTS_NUMBER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_ANON},
    // Column below key 3
    {KEY_PRINTS_NUMBER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_SYMBOL},
    // Column below key 4
    {KEY_PRINTS_NUMBER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_INDEX},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_SYMBOL},
    // Column below key 5
    {KEY_PRINTS_NUMBER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_LETTER},
    // Column below key 5'
    {KEY_PRINTS_ANON},		{KEY_PRINTS_ANON},	{KEY_PRINTS_ANON},
    // Left thumb: left, middle, right, red
    {KEY_PRINTS_ANON},		{KEY_PRINTS_ANON},	{KEY_PRINTS_ANON},	{KEY_PRINTS_ANON},
    // Column below key 0'
    {KEY_PRINTS_ANON},		{KEY_PRINTS_ANON},	{KEY_PRINTS_ANON},	{KEY_PRINTS_ANON},	{KEY_PRINTS_ANON},
    // Column below key 0
    {KEY_PRINTS_NUMBER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_SYMBOL},	{KEY_PRINTS_SYMBOL},	{KEY_PRINTS_SYMBOL},
    // Column below key 9
    {KEY_PRINTS_NUMBER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_SYMBOL},	{KEY_PRINTS_SYMBOL},
    // Column below key 8
    {KEY_PRINTS_NUMBER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_SYMBOL},	{KEY_PRINTS_SYMBOL},
    // Column below key 7
    {KEY_PRINTS_NUMBER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_INDEX},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_SYMBOL},
    // Column below key 6
    {KEY_PRINTS_NUMBER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_LETTER},	{KEY_PRINTS_LETTER},
    // Column below key 5''
    {KEY_PRINTS_ANON},		{KEY_PRINTS_ANON},	{KEY_PRINTS_ANON},
    // Right thumb: right, middle, left, red
    {KEY_PRINTS_ANON},		{KEY_PRINTS_ANON},	{KEY_PRINTS_ANON},	{KEY_PRINTS_ANON},
  },
/*
  [LEDMAP_FUN] = {
    // Column below key 0
    {SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_USE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},
    // Column below key 1
    {SYMBOL_NOUSE},		{SYMBOL_USE},		{SYMBOL_USE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},
    // Column below key 2
    {SYMBOL_NOUSE},		{SYMBOL_USE},		{SYMBOL_USE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},
    // Column below key 3
    {SYMBOL_NOUSE},		{SYMBOL_USE},		{SYMBOL_USE},		{SYMBOL_USE},		{SYMBOL_NOUSE},
    // Column below key 4
    {SYMBOL_NOUSE},		{SYMBOL_USE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},
    // Column below key 5
    {SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},
    // Column below key 5'
    {SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},
    // Left thumb: left, middle, right, red
    {SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},
    // Column below key 0'
    {SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},
    // Column below key 0
    {SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},
    // Column below key 9
    {SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},
    // Column below key 8
    {SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},
    // Column below key 7
    {SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},
    // Column below key 6
    {SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_USE},
    // Column below key 5''
    {SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},
    // Right thumb: right, middle, left, red
    {SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},		{SYMBOL_NOUSE},
  },
*/
  [LEDMAP_CLR] = {
    // Column below key 0
    {HSV_WHITE},		{HSV_BLUE},		{COLOR_DEFAULT},	{COLOR_DEFAULT},	{COLOR_DEFAULT},
    // Column below key 1
    {HSV_RED},			{HSV_PURPLE},		{COLOR_DEFAULT},	{COLOR_DEFAULT},	{COLOR_DEFAULT},
    // Column below key 2
    {HSV_CORAL},		{HSV_MAGENTA},		{COLOR_DEFAULT},	{COLOR_DEFAULT},	{COLOR_DEFAULT},
    // Column below key 3
    {HSV_ORANGE},		{HSV_PINK},		{COLOR_DEFAULT},	{COLOR_DEFAULT},	{COLOR_DEFAULT},
    // Column below key 4
    {HSV_GOLDENROD},		{28, 255, 255},		{COLOR_DEFAULT},	{COLOR_DEFAULT},	{COLOR_DEFAULT},
    // Column below key 5
    {HSV_GOLD},			{8, 255, 255},		{COLOR_DEFAULT},	{COLOR_DEFAULT},
    // Column below key 5'
    {HSV_YELLOW},		{23, 99, 99},		{COLOR_DEFAULT},
    // Left thumb: left, middle, right, red
    {COLOR_DEFAULT},		{COLOR_DEFAULT},	{COLOR_DEFAULT},	{COLOR_DEFAULT},
    // Column below key 0'
    {HSV_GREEN},		{COLOR_DEFAULT},	{COLOR_DEFAULT},	{COLOR_DEFAULT},	{COLOR_DEFAULT},
    // Column below key 0
    {HSV_SPRINGGREEN},		{COLOR_DEFAULT},	{COLOR_DEFAULT},	{COLOR_DEFAULT},	{COLOR_DEFAULT},
    // Column below key 9
    {HSV_TURQUOISE},		{COLOR_DEFAULT},	{COLOR_DEFAULT},	{COLOR_DEFAULT},	{COLOR_DEFAULT},
    // Column below key 8
    {HSV_TEAL},			{COLOR_DEFAULT},	{COLOR_DEFAULT},	{COLOR_DEFAULT},	{COLOR_DEFAULT},
    // Column below key 7
    {HSV_CHARTREUSE},		{COLOR_DEFAULT},	{COLOR_DEFAULT},	{COLOR_DEFAULT},	{COLOR_DEFAULT},
    // Column below key 6
    {HSV_CYAN},			{COLOR_DEFAULT},	{COLOR_DEFAULT},	{COLOR_DEFAULT},
    // Column below key 5''
    {HSV_AZURE},		{COLOR_DEFAULT},	{COLOR_DEFAULT},
    // Right thumb: right, middle, left, red
    {COLOR_DEFAULT},		{COLOR_DEFAULT},	{COLOR_DEFAULT},	{COLOR_DEFAULT},
  },
};
