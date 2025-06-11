#include QMK_KEYBOARD_H
#include "version.h"

// CUSTOM ADDITIONS START

#include "print.h"

const char* get_keycode_string(uint16_t keycode);

// CUSTOM ADDITIONS END

#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
};



#define DUAL_FUNC_0 LT(5, KC_F8)
#define DUAL_FUNC_1 LT(4, KC_3)
#define DUAL_FUNC_2 LT(7, KC_X)
#define DUAL_FUNC_3 LT(11, KC_Y)
#define DUAL_FUNC_4 LT(4, KC_J)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    LALT(KC_F4),    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           LGUI(LSFT(KC_LEFT)),                                KC_AUDIO_MUTE,  KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           TG(1),
    KC_TRANSPARENT, KC_F1,          KC_U,           KC_O,           KC_F,           KC_QUES,        LGUI(LSFT(KC_RIGHT)),                                KC_AUDIO_VOL_UP,KC_Q,           KC_J,           KC_D,           KC_G,           KC_F12,         KC_TRANSPARENT,
    KC_BSPC,        KC_A,           MT(MOD_LSFT, KC_I),MT(MOD_LCTL, KC_E),KC_H,           KC_Y,           LGUI(KC_UP),                                                                    KC_AUDIO_VOL_DOWN,KC_L,           KC_N,           MT(MOD_RCTL, KC_T),MT(MOD_RSFT, KC_S),KC_C,           KC_V,
    KC_DELETE,      MT(MOD_LALT, KC_QUOTE),LT(4, KC_COMMA),KC_SLASH,       KC_P,           KC_TRANSPARENT,                                 KC_Z,           KC_R,           KC_M,           LT(6, KC_W),    MT(MOD_RALT, KC_B),KC_TRANSPARENT,
    LSFT(KC_DELETE),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_K,           DUAL_FUNC_0,                                                                                                    KC_LEFT_GUI,    KC_X,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    LT(2, KC_SPACE),LT(5, KC_ENTER),LALT(LCTL(KC_A)),                LGUI(LSFT(KC_S)),CW_TOGG,        LT(3, KC_DOT)
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_A,           MT(MOD_LSFT, KC_S),KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           MT(MOD_RSFT, KC_L),KC_SLASH,       KC_UNDS,
    KC_TRANSPARENT, MT(MOD_LSFT | MOD_LCTL, KC_Z),MT(MOD_LCTL, KC_X),KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       MT(MOD_RCTL, KC_QUOTE),DUAL_FUNC_1,    KC_GRAVE,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_NO,          KC_LPRN,        KC_RPRN,        KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LCTL(KC_KP_0),  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,
    KC_TRANSPARENT, KC_NO,          KC_ESCAPE,      LCTL(KC_D),     KC_F5,          LGUI(LCTL(KC_V)),KC_TRANSPARENT,                                 LCTL(KC_KP_PLUS),KC_NO,          KC_HOME,        KC_UP,          KC_END,         LCTL(KC_HOME),  KC_NO,
    KC_TRANSPARENT, KC_F2,          LSFT(KC_TAB),   KC_TAB,         LCTL(KC_Z),     LCTL(KC_Y),     KC_TRANSPARENT,                                                                 LCTL(KC_KP_MINUS),KC_PAGE_UP,     KC_LEFT,        KC_DOWN,        KC_RIGHT,       LCTL(KC_END),   LCTL(KC_PAGE_UP),
    KC_TRANSPARENT, LCTL(KC_L),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCTL(LSFT(KC_V)),                                KC_PGDN,        LCTL(KC_LEFT),  LCTL(KC_UP),    RCTL(KC_RIGHT), LALT(KC_UP),    LCTL(KC_PGDN),
    KC_TRANSPARENT, LCTL(KC_A),     KC_NO,          KC_NO,          KC_NO,          KC_INSERT,                                                                                                      KC_TRANSPARENT, LALT(KC_LEFT),  LCTL(KC_DOWN),  LALT(KC_RIGHT), LALT(KC_DOWN),  KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_ESCAPE,      KC_ENTER,       KC_RIGHT_SHIFT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,
    KC_TRANSPARENT, KC_NO,          KC_LPRN,        KC_RPRN,        KC_AMPR,        KC_QUES,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_TILD,        KC_SLASH,       KC_COLN,        KC_NO,          KC_NO,
    LCTL(KC_BSPC),  KC_LCBR,        KC_EQUAL,       KC_MINUS,       KC_RCBR,        KC_DLR,         KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_ASTR,        KC_SCLN,        KC_UNDS,        KC_DQUO,        KC_PLUS,        KC_NO,
    LCTL(KC_DELETE),KC_LABK,        KC_PIPE,        KC_HASH,        KC_RABK,        KC_AT,                                          KC_PERC,        KC_EXLM,        KC_BSLS,        KC_GRAVE,       KC_CIRC,        KC_NO,
    KC_TRANSPARENT, KC_NO,          KC_LBRC,        KC_RBRC,        KC_NO,          KC_TRANSPARENT,                                                                                                 RGB_TOG,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT, LSFT(KC_ENTER), LCTL(KC_ENTER),                 MOON_LED_LEVEL, TOGGLE_LAYER_COLOR,KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_MEDIA_PREV_TRACK,KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_MEDIA_NEXT_TRACK,KC_PERC,        KC_7,           KC_8,           KC_9,           KC_EQUAL,       KC_NUM,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_MEDIA_PLAY_PAUSE,KC_PLUS,        KC_4,           KC_5,           KC_6,           KC_MINUS,       KC_SLASH,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_ASTR,        KC_1,           KC_2,           KC_3,           KC_COLN,        KC_NO,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_0,           KC_UNDS,        KC_TILD,        KC_CIRC,        KC_NO,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_ENTER,       KC_SPACE,       KC_DOT
  ),
  [5] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_NO,                                          KC_MEDIA_PREV_TRACK,KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_NO,          KC_NO,          LCTL(KC_W),     LCTL(LSFT(KC_R)),LCTL(KC_N),     LCTL(KC_GRAVE), KC_F12,                                         KC_MEDIA_NEXT_TRACK,KC_PERC,        KC_7,           KC_8,           KC_9,           KC_EQUAL,       KC_NUM,
    KC_TRANSPARENT, ST_MACRO_0,     LCTL(KC_S),     DUAL_FUNC_2,    ST_MACRO_1,     DUAL_FUNC_3,    DUAL_FUNC_4,                                                                    KC_MEDIA_PLAY_PAUSE,KC_PLUS,        KC_4,           KC_5,           KC_6,           KC_MINUS,       KC_SLASH,
    KC_TRANSPARENT, LALT(KC_INSERT),LALT(KC_F2),    LCTL(KC_DOT),   ST_MACRO_2,     LCTL(LSFT(KC_B)),                                KC_ASTR,        KC_1,           KC_2,           KC_3,           KC_COLN,        KC_NO,
    KC_TRANSPARENT, ST_MACRO_3,     ST_MACRO_4,     ST_MACRO_5,     ST_MACRO_6,     QK_BOOT,                                                                                                        KC_TRANSPARENT, KC_0,           KC_UNDS,        KC_TILD,        KC_CIRC,        KC_NO,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_ENTER,       KC_SPACE,       KC_DOT
  ),
  [6] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_7,     ST_MACRO_8,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, ST_MACRO_9,     ST_MACRO_10,    ST_MACRO_11,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, ST_MACRO_12,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();


  // CUSTOM ADDITIONS START

#ifdef CONSOLE_ENABLE
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
#endif

  // CUSTOM ADDITIONS END
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {188,255,255}, {0,0,0}, {0,245,245}, {0,245,245}, {152,255,255}, {74,255,255}, {219,255,255}, {34,255,255}, {109,252,245}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {109,252,245}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {109,252,245}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {74,255,255}, {109,252,245}, {34,255,255}, {0,0,0}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {219,255,255}, {152,255,255}, {109,252,245}, {219,255,255}, {0,0,0}, {34,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {219,255,255}, {34,255,255}, {34,255,255}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,245,245}, {188,255,255}, {152,255,255}, {219,255,255} },

    [1] = { {188,255,255}, {0,0,0}, {0,245,245}, {0,245,245}, {152,255,255}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {219,255,255}, {152,255,255}, {109,252,245}, {219,255,255}, {109,252,245}, {109,252,245}, {109,252,245}, {0,0,0}, {74,255,255}, {34,255,255}, {109,252,245}, {109,252,245}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {109,252,245}, {0,0,255}, {74,255,255}, {34,255,255}, {34,255,255}, {109,252,245}, {0,0,255}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,245,245}, {219,255,255}, {152,255,255}, {219,255,255} },

    [2] = { {188,255,255}, {0,0,0}, {0,245,245}, {0,245,245}, {152,255,255}, {74,255,255}, {0,0,0}, {219,255,255}, {152,255,255}, {152,255,255}, {74,255,255}, {152,255,255}, {109,252,245}, {152,255,255}, {0,0,0}, {74,255,255}, {152,255,255}, {34,255,255}, {152,255,255}, {0,0,0}, {74,255,255}, {219,255,255}, {152,255,255}, {152,255,255}, {0,0,0}, {74,255,255}, {188,255,255}, {152,255,255}, {188,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {219,255,255}, {152,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {0,0,0}, {74,255,255}, {219,255,255}, {219,255,255}, {152,255,255}, {152,255,255}, {74,255,255}, {109,252,245}, {0,245,245}, {219,255,255}, {152,255,255}, {74,255,255}, {0,245,245}, {0,245,245}, {219,255,255}, {219,255,255}, {74,255,255}, {109,252,245}, {0,245,245}, {219,255,255}, {152,255,255}, {74,255,255}, {0,0,0}, {109,252,245}, {109,252,245}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {219,255,255}, {152,255,255}, {219,255,255} },

    [3] = { {188,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {152,255,255}, {74,255,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,0}, {74,255,255}, {0,0,255}, {109,252,245}, {109,252,245}, {0,0,255}, {74,255,255}, {0,0,255}, {109,252,245}, {109,252,245}, {0,0,255}, {74,255,255}, {109,252,245}, {0,0,255}, {0,0,255}, {0,0,0}, {74,255,255}, {109,252,245}, {109,252,245}, {109,252,245}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {219,255,255}, {152,255,255}, {109,252,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {109,252,245}, {109,252,245}, {0,0,0}, {74,255,255}, {109,252,245}, {109,252,245}, {109,252,245}, {0,0,0}, {74,255,255}, {109,252,245}, {109,252,245}, {109,252,245}, {0,0,0}, {74,255,255}, {109,252,245}, {109,252,245}, {109,252,245}, {0,0,0}, {74,255,255}, {0,0,0}, {109,252,245}, {109,252,245}, {219,255,255}, {219,255,255}, {219,255,255}, {0,245,245}, {109,252,245}, {109,252,245}, {109,252,245} },

    [4] = { {188,255,255}, {0,0,0}, {0,245,245}, {0,245,245}, {152,255,255}, {74,255,255}, {219,255,255}, {34,255,255}, {109,252,245}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {109,252,245}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {109,252,245}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {74,255,255}, {109,252,245}, {34,255,255}, {0,0,0}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {219,255,255}, {152,255,255}, {109,252,245}, {34,255,255}, {152,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {34,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {74,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {74,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {34,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,255}, {152,255,255}, {219,255,255}, {219,255,255} },

    [5] = { {188,255,255}, {0,0,0}, {0,245,245}, {0,245,245}, {152,255,255}, {34,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {34,255,255}, {188,255,255}, {0,245,245}, {219,255,255}, {152,255,255}, {152,255,255}, {34,255,255}, {152,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {34,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {74,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {74,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {34,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,255}, {152,255,255}, {219,255,255}, {219,255,255} },

    [6] = { {188,255,255}, {0,0,0}, {0,245,245}, {0,245,245}, {152,255,255}, {74,255,255}, {219,255,255}, {188,255,255}, {152,255,255}, {0,0,0}, {74,255,255}, {188,255,255}, {152,255,255}, {109,252,245}, {0,0,0}, {74,255,255}, {188,255,255}, {152,255,255}, {109,252,245}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {74,255,255}, {109,252,245}, {34,255,255}, {0,0,0}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {219,255,255}, {152,255,255}, {109,252,245}, {219,255,255}, {0,0,0}, {34,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {219,255,255}, {34,255,255}, {34,255,255}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,245,245}, {188,255,255}, {152,255,255}, {219,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // CUSTOM ADDITIONS START

#ifdef CONSOLE_ENABLE
    uprintf("process_record_user     : kc: 0x%04X, kch: %s, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, get_keycode_string(keycode), record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

  // CUSTOM ADDITIONS END

  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_K))SS_DELAY(100)  SS_LCTL(SS_TAP(X_S)));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_E))SS_DELAY(100)  SS_LCTL(SS_TAP(X_F)));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_R))SS_DELAY(100)  SS_LCTL(SS_TAP(X_V)));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_K))SS_DELAY(100)  SS_LCTL(SS_TAP(X_I)));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_K))SS_DELAY(100)  SS_LCTL(SS_TAP(X_U)));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_K))SS_DELAY(100)  SS_LCTL(SS_TAP(X_C)));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_R))SS_DELAY(100)  SS_LCTL(SS_TAP(X_M)));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_9) ));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_8) ));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_2) ));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_4) ));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_3) ));
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_2) ));
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LALT(KC_TAB));
        } else {
          unregister_code16(LALT(KC_TAB));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LALT(LCTL(KC_TAB)));
        } else {
          unregister_code16(LALT(LCTL(KC_TAB)));
        }
      }
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_DQUO);
        } else {
          unregister_code16(KC_DQUO);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_ALT);
        } else {
          unregister_code16(KC_RIGHT_ALT);
        }
      }
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LCTL(KC_T));
        } else {
          unregister_code16(LCTL(KC_T));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(LSFT(KC_T)));
        } else {
          unregister_code16(LCTL(LSFT(KC_T)));
        }
      }
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LCTL(KC_F));
        } else {
          unregister_code16(LCTL(KC_F));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(LSFT(KC_F)));
        } else {
          unregister_code16(LCTL(LSFT(KC_F)));
        }
      }
      return false;
    case DUAL_FUNC_4:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LCTL(KC_H));
        } else {
          unregister_code16(LCTL(KC_H));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(LSFT(KC_H)));
        } else {
          unregister_code16(LCTL(LSFT(KC_H)));
        }
      }
      return false;
    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }

  // CUSTOM ADDITIONS START

  bool process_hold_linger_all(uint16_t keycode, keyrecord_t *record, bool is_pre);
  if (!process_hold_linger_all(keycode, record, false)) {
    return false;
  }

  // CUSTOM ADDITIONS END

  return true;
}


// CUSTOM ADDITIONS START

// does not seem to work for some reason
bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef CONSOLE_ENABLE
    uprintf("pre_process_record_user : kc: 0x%04X, kch: %s, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, get_keycode_string(keycode), record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

  bool process_hold_linger_all(uint16_t keycode, keyrecord_t *record, bool is_pre);
  return process_hold_linger_all(keycode, record, true);
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {

#ifdef CONSOLE_ENABLE
    uprintf("post_process_record_user: kc: 0x%04X, kch: %s, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, get_keycode_string(keycode), record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

    void post_process_record_user_openclose_combo_all(uint16_t keycode, keyrecord_t *record);
    post_process_record_user_openclose_combo_all(keycode, record);

#ifdef CONSOLE_ENABLE
    uprintf("\n");
#endif
}

// exclude thumb keys from chordal hold
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_moonlander(
      'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
      'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
      'L', 'L', 'L', 'L', 'L', 'L', 'L', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
      'L', 'L', 'L', 'L', 'L', 'L',           'R', 'R', 'R', 'R', 'R', 'R',
      'L', 'L', 'L', 'L', 'L', '*',           '*', 'R', 'R', 'R', 'R', 'R',
                          '*', '*', '*', '*', '*', '*'
    );

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode & 0x00FF) {
        case KC_SPACE:
            return TAPPING_TERM_FOR_SPACE;
        case KC_DOT:
            return TAPPING_TERM_FOR_DOT;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode & 0x00FF) {
        // we do not want to enable permissive hold for alphas that are rarely used for holding
        case KC_E:
        case KC_T:
        case KC_QUOTE:
        case KC_B:
        case KC_W:
            return false;
        default:
            // enable permissive hold for all other keys
            return true;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    // see get_chordal_hold, this is a workaround for ./
    if (record->tap.reserved2) {
      return false;
    }

    switch (keycode & 0x00FF) {
        // we only want to enable early hold detection for some very few keys that are rarely
        // used in the normal flow of typing (with some exceptions like comma->space which are
        // solved using chordal holds below)
        case KC_COMMA: // num layer on comma
        case KC_ENTER: // code layer on enter (left thumb)
        case KC_DOT: // symbol layer on period (right thumb)
            return true;
        default:
            // do not select the hold action when another key is pressed.
            return false;
    }
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    bool other_key_is_space = (other_keycode & 0x00FF) == KC_SPACE;
    bool other_key_is_enter = (other_keycode & 0x00FF) == KC_ENTER;

    // there are some special situations in which we want to always suppress holds, especially
    // for keys with "hold on other key press" enabled
    switch (tap_hold_keycode & 0x00FF) {
        case KC_COMMA:
            // a space or line break after a comma should never enter the hold
            if (other_key_is_space || other_key_is_enter) {
                return false;
            }
            break;

        case KC_DOT:
            // we have a special requirement for the combination ./ for which we want
            // to enable permissive_hold while using hold_on_other_key_press for all
            // other combinations with DOT; however, by default QMK does not pass the
            // second pressed key into get_hold_on_other_key_press, so we need a work-
            // around; looking at the code in action_tapping.c we can see that this
            // function is called just before get_hold_on_other_key_press, so we can
            // leverage another implementation detail that there are some unused boolean
            // properties that we can use to mark the tap to disable hold_on_other_key_press
            if (other_keycode == KC_SLASH) {
              tap_hold_record->tap.reserved2 = true;
            }

            // when the dot is followed by a space or question mark, we still want to
            // type the dot before the other key, so we exclude those chords (which is
            // safe since those keys are the same on the symbol layer anyways)
            if (other_key_is_space || other_keycode == KC_QUES) {
                return false;
            }
            break;
    }

    // otherwise defer to the opposite hands rule
    return get_chordal_hold_default(tap_hold_record, other_record);
}

// this is pretty much the default except we exclude some key codes
bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }

    switch (get_tap_keycode(keycode)) {
        // case KC_SPC:
        case KC_A ... KC_Z:
        // case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

// this is pretty much the default except KC_MINUS is not shifted, since we have
// dash and underscore on different keys; see here for docs: https://docs.qmk.fm/features/caps_word
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_MINUS:
        case KC_UNDS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

// placeholder until we can use community modules with the ZSA firmware version
static char buffer[32];

const char* get_keycode_string(uint16_t keycode) {
  buffer[0] = '\0';
  return buffer;
}

typedef enum {
  NONE,
  HOLD_LINGER_PRESSED,
  FOLLOWER_PRESSED,
  HOLD_LINGER_RELEASED,
  HOLD_LINGER_TAPPED,
  HOLD_LINGER_TAP_RELEASED_BEFORE_FOLLOWER_TAP,
  HOLD_LINGER_TAP_RELEASED_AFTER_FOLLOWER_TAP,
  FOLLOWER_TAPPED_BEFORE_HOLD_LINGER_TAP_RELEASE,
  FOLLOWER_TAPPED_AFTER_HOLD_LINGER_TAP_RELEASE,
} hold_linger_state_t;

typedef struct {
    hold_linger_state_t state;
    uint16_t hold_linger_release_time;
    uint16_t follower_keycode;
} hold_linger_record_t;

hold_linger_record_t HL_NONE = {
    state: NONE,
};

// emulate sm_td behavior for hold keys to emit key output with hold
// even when the hold key is released slightly before the target key
bool process_hold_linger(uint16_t keycode,
                         keyrecord_t *record,
                         uint16_t hold_linger_keycode,
                         hold_linger_record_t *hl_record,
                         char handedness,
                         uint16_t hold_linger_term,
                         void (*on_act)(uint16_t),
                         bool is_pre
                        ) {
    bool is_plain_alpha = keycode >= KC_A && keycode <= KC_Z;

    bool is_press = record->event.pressed;
    bool is_press_release = !record->event.pressed;

    // for tap-hold keys the record->tap.count will be 1 if the key was settled as a tap, but for
    // plain alpha keys the value will always be 0, so we just assume this was a tap release
    bool is_tap = record->event.pressed && (is_plain_alpha || record->tap.count);
    bool is_tap_release = !record->event.pressed && (is_plain_alpha || record->tap.count);

    bool is_hold_linger_key = keycode == hold_linger_keycode;
    bool is_follower_key = keycode == hl_record->follower_keycode;

    bool was_flow_press = false;

    if (is_pre) {
#ifdef FLOW_TAP_TERM
        // our hold linger logic doesn't propery detect flow tapping from the QMK feature, so we simulate that ourselves
        static uint16_t latest_press_time = 0;

        if (is_press) {
            if (keycode != hold_linger_keycode) {
                latest_press_time = record->event.time;
            } else {
                was_flow_press = TIMER_DIFF_16(record->event.time, latest_press_time) <= FLOW_TAP_TERM;
                latest_press_time = 0;
            }
        }
#endif

        switch (hl_record->state) {
            case NONE:
                if (is_hold_linger_key && is_press && !was_flow_press) {
                    hl_record->state = HOLD_LINGER_PRESSED;
                }

                return true;

            case HOLD_LINGER_PRESSED:
                // the key was on the opposite hand (i.e. we also emulate the chordal hold behavior)
                bool is_not_same_hand_key = chordal_hold_layout[record->event.key.row][record->event.key.col] != handedness;

                if (!is_hold_linger_key && is_press && is_not_same_hand_key) {
                    hl_record->state = FOLLOWER_PRESSED;
                    hl_record->follower_keycode = keycode;
                } else {
                    *hl_record = HL_NONE;
                }

                return true;

            case FOLLOWER_PRESSED:
                if (is_hold_linger_key && is_press_release) {
                    hl_record->state = HOLD_LINGER_RELEASED;
                    hl_record->hold_linger_release_time = record->event.time;
                } else {
                    *hl_record = HL_NONE;
                }

                return true;

            default:
                break;
        }

        return true;
    }

    uint16_t hold_linger_plain_keycode = hold_linger_keycode & 0x00FF;

    switch (hl_record->state) {
        case NONE:
            return true;

        case HOLD_LINGER_RELEASED:
            uint8_t mods = get_mods() | get_oneshot_mods();

            // we ignore any situations in which other mods are held down
            // since that would complicate things too much, and our primary
            // use case only considers a single hold / mod key
            if (is_hold_linger_key && is_tap && mods == 0) {
                hl_record->state = HOLD_LINGER_TAPPED;
                return false;
            }

            *hl_record = HL_NONE;
            return true;

        case HOLD_LINGER_TAPPED:
            // if the follower is another hold-tap key, QMK (with our particular
            // config at least) will send the tap release event before the follower
            // tap event, so we need to account for that when we later need to
            // replay the actions
            if (is_hold_linger_key && is_tap_release) {
                hl_record->state = HOLD_LINGER_TAP_RELEASED_BEFORE_FOLLOWER_TAP;
                return false;
            }

            if (is_follower_key && is_tap) {
                hl_record->state = FOLLOWER_TAPPED_BEFORE_HOLD_LINGER_TAP_RELEASE;
                return false;
            }

            // we suppressed the *press* of hold linger before, so we need to send it now;
            // the press release will be handled as normal once the tap release event
            // is processed
            register_code16(hold_linger_plain_keycode);

            *hl_record = HL_NONE;
            return true;

        case HOLD_LINGER_TAP_RELEASED_BEFORE_FOLLOWER_TAP:
            // the hold_linger release was sent before the follower tap, because the follower
            // is also a hold-tap key
            if (is_follower_key && is_tap) {
                hl_record->state = FOLLOWER_TAPPED_AFTER_HOLD_LINGER_TAP_RELEASE;
                return false;
            }

            // we suppressed the *tap* of hold linger before, so we need to send it now
            tap_code16_delay(hold_linger_plain_keycode, 0);

            *hl_record = HL_NONE;
            return true;

        case FOLLOWER_TAPPED_BEFORE_HOLD_LINGER_TAP_RELEASE:
            // the hold_linger tap release was in between the follower tap and tap release
            if (is_hold_linger_key && is_tap_release) {
                hl_record->state = HOLD_LINGER_TAP_RELEASED_AFTER_FOLLOWER_TAP;
                return false;
            }

            // we suppressed the *press* of both the hold linger key and the follower
            // before, so we need to send them now
            register_code16(hold_linger_plain_keycode);
            register_code16(hl_record->follower_keycode);

            *hl_record = HL_NONE;
            return true;

        case FOLLOWER_TAPPED_AFTER_HOLD_LINGER_TAP_RELEASE:
            if (is_follower_key && is_tap_release) {
                uint16_t time_since_release = TIMER_DIFF_16(record->event.time, hl_record->hold_linger_release_time);

#ifdef CONSOLE_ENABLE
                uprintf("hold_linger_decision    : hl_kc: 0x%04X, hl_kch: %s, state: %u, time_diff: %u, decision: %u\n", hold_linger_keycode, get_keycode_string(hold_linger_keycode), prev_state, time_since_release, time_since_release <= hold_linger_term);
#endif

                if (time_since_release <= hold_linger_term) {
                    *hl_record = HL_NONE;
                    on_act(keycode);
                    return false;
                }
            }

            // we suppressed the *tap* of hold linger before, so we need to send it now
            tap_code16_delay(hold_linger_plain_keycode, 0);

            // we suppressed the *press* of the follower before, so we need to send it now
            register_code16(hl_record->follower_keycode);

            *hl_record = HL_NONE;
            return true;

        case HOLD_LINGER_TAP_RELEASED_AFTER_FOLLOWER_TAP:
            if (is_follower_key && is_tap_release) {
                uint16_t time_since_release = TIMER_DIFF_16(record->event.time, hl_record->hold_linger_release_time);

#ifdef CONSOLE_ENABLE
                uprintf("hold_linger_decision    : hl_kc: 0x%04X, hl_kch: %s, state: %u, time_diff: %u, decision: %u\n", hold_linger_keycode, get_keycode_string(hold_linger_keycode), prev_state, time_since_release, time_since_release <= hold_linger_term);
#endif

                if (time_since_release <= hold_linger_term) {
                    *hl_record = HL_NONE;
                    on_act(keycode);
                    return false;
                }
            }

            // we suppressed the *press* of both the hold linger key and the follower
            // before, and we also suppressed the tap release of the hold_linger key,
            // so we need to send them now
            register_code16(hold_linger_plain_keycode);
            register_code16(hl_record->follower_keycode);
            unregister_code16(hold_linger_plain_keycode);

            *hl_record = HL_NONE;
            return true;

        default:
            *hl_record = HL_NONE;
            return true;
    }

    return true;
}

bool process_hold_linger_with_log(uint16_t keycode,
                                  keyrecord_t *record,
                                  uint16_t hold_linger_keycode,
                                  hold_linger_record_t *hl_record,
                                  char handedness,
                                  uint16_t hold_linger_term,
                                  void (*on_act)(uint16_t),
                                  bool is_pre
                                 ) {
    hold_linger_state_t prev_state = hl_record->state;
    bool result = process_hold_linger(keycode, record, hold_linger_keycode, hl_record, handedness, hold_linger_term, on_act, is_pre);
    hold_linger_state_t next_state = hl_record->state;

    if (prev_state != next_state) {
#ifdef CONSOLE_ENABLE
        uprintf("hold_linger_state       : hl_kc: 0x%04X, hl_kch: %s, state: %u -> %u\n", hold_linger_keycode, get_keycode_string(hold_linger_keycode), prev_state, next_state);
#endif
    }

    return result;
}

void act_on_hold_linger_shft(uint16_t keycode, uint16_t shift_keycode) {
    register_code(shift_keycode);
    tap_code16_delay(keycode & 0x00FF, 0);
    unregister_code(shift_keycode);
}

void act_on_hold_linger_lshft(uint16_t keycode) {
    act_on_hold_linger_shft(keycode, KC_LEFT_SHIFT);
}

void act_on_hold_linger_rshft(uint16_t keycode) {
    act_on_hold_linger_shft(keycode, KC_RIGHT_SHIFT);
}

bool process_hold_linger_all(uint16_t keycode, keyrecord_t *record, bool is_pre) {
    bool is_letter = (keycode & 0x00FF) >= KC_A && (keycode & 0x00FF) <= KC_Z;

    if (!is_letter) {
      return true;
    }

    static hold_linger_record_t lshft_record = {
        state: NONE,
        hold_linger_release_time: 0,
        follower_keycode: 0,
    };

    uint16_t lshft_hold_linger_term = 55;

    // 'is' is a commonly typed sequence that can cause false positives with a higher
    // term, so we special case it
    if ((keycode & 0x00FF) == KC_S) {
      lshft_hold_linger_term = 35;
    }

    if (!process_hold_linger_with_log(
      keycode,
      record,
      MT(MOD_LSFT, KC_I),
      &lshft_record,
      'L',
      lshft_hold_linger_term,
      &act_on_hold_linger_lshft,
      is_pre)) {
        return false;
    }

    static hold_linger_record_t rshft_record = {
        state: NONE,
        hold_linger_release_time: 0,
        follower_keycode: 0,
    };

    // it seems that typing a vowel after an 's' is either just faster or more common
    // for me, but in any case, a higher term on RSHFT caused more false positives, so
    // we reduce it
    uint16_t rshft_hold_linger_term = 35;

    return process_hold_linger_with_log(
      keycode,
      record,
      MT(MOD_RSFT, KC_S),
      &rshft_record,
      'R',
      rshft_hold_linger_term,
      &act_on_hold_linger_rshft,
      is_pre);
}

void post_process_record_user_openclose_combo(uint16_t keycode,
                                              keyrecord_t *record,
                                              uint16_t open_keycode,
                                              uint16_t close_keycode,
                                              uint16_t *open_tap_time) {
    uint8_t mods = get_mods() | get_oneshot_mods();

    // we ignore any situations in which other mods are held down
    if (mods != 0) {
        *open_tap_time = 0;
        return;
    }

    if (*open_tap_time == 0 && keycode == open_keycode && record->event.pressed) {
#ifdef CONSOLE_ENABLE
        uprintf("openclose_combo_start   : kc: 0x%04X, kch: %s, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, get_keycode_string(keycode), record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

        *open_tap_time = record->event.time;

        return;
    }

    bool is_after_open_tap = record->event.time > *open_tap_time;
    if (*open_tap_time == 0 || !is_after_open_tap || !record->event.pressed) {
        return;
    }

    uint16_t time_since_tap = record->event.time - *open_tap_time;
    if (time_since_tap >= OPENCLOSE_COMBO_TERM || keycode != close_keycode) {
#ifdef CONSOLE_ENABLE
        uprintf("openclose_combo_skip    : kc: 0x%04X, kch: %s, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, get_keycode_string(keycode), record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

        *open_tap_time = 0;
        return;
    }

    // at this point the closing char has been the first key press shortly after the opening char
#ifdef CONSOLE_ENABLE
    uprintf("openclose_combo_end     : kc: 0x%04X, kch: %s, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, get_keycode_string(keycode), record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

    *open_tap_time = 0;

    // the closing char might be a shifted character (e.g. RPAR) so we first clear
    // the key since otherwise the LEFT tap would be shifted, which would lead to
    // an unintended text selection of the closing char
    unregister_code16(keycode);

    tap_code16_delay(KC_LEFT, 0);
}

void post_process_record_user_openclose_combo_all(uint16_t keycode, keyrecord_t *record) {
    static uint16_t lprn_tap_time = 0;
    post_process_record_user_openclose_combo(keycode, record, KC_LPRN, KC_RPRN, &lprn_tap_time);

    static uint16_t lcbr_tap_time = 0;
    post_process_record_user_openclose_combo(keycode, record, KC_LCBR, KC_RCBR, &lcbr_tap_time);

    static uint16_t labk_tap_time = 0;
    post_process_record_user_openclose_combo(keycode, record, KC_LABK, KC_RABK, &labk_tap_time);

    static uint16_t lbrc_tap_time = 0;
    post_process_record_user_openclose_combo(keycode, record, KC_LBRC, KC_RBRC, &lbrc_tap_time);

    static uint16_t dquo_tap_time = 0;
    post_process_record_user_openclose_combo(keycode, record, KC_DQUO, KC_DQUO, &dquo_tap_time);

    static uint16_t quo_tap_time = 0;
    post_process_record_user_openclose_combo(keycode, record, MT(MOD_LALT, KC_QUOTE), MT(MOD_LALT, KC_QUOTE), &quo_tap_time);

    static uint16_t perc_tap_time = 0;
    post_process_record_user_openclose_combo(keycode, record, KC_PERC, KC_PERC, &perc_tap_time);
}

// CUSTOM ADDITIONS END
