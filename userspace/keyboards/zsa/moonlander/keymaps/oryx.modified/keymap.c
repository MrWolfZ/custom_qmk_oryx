#include QMK_KEYBOARD_H
#include "version.h"
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



#define DUAL_FUNC_0 LT(15, KC_H)
#define DUAL_FUNC_1 LT(6, KC_R)
#define DUAL_FUNC_2 LT(10, KC_4)
#define DUAL_FUNC_3 LT(14, KC_E)
#define DUAL_FUNC_4 LT(8, KC_F2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    LALT(KC_F4),    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           LGUI(LSFT(KC_LEFT)),                                KC_AUDIO_MUTE,  KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           TG(1),
    KC_TRANSPARENT, KC_F1,          KC_U,           KC_O,           KC_F,           KC_QUES,        LGUI(LSFT(KC_RIGHT)),                                KC_AUDIO_VOL_UP,KC_Q,           KC_J,           KC_D,           KC_G,           KC_F12,         KC_TRANSPARENT,
    KC_BSPC,        KC_A,           MT(MOD_LSFT, KC_I),MT(MOD_LCTL, KC_E),KC_H,           KC_Y,           LGUI(KC_UP),                                                                    KC_AUDIO_VOL_DOWN,KC_L,           KC_N,           MT(MOD_RCTL, KC_T),MT(MOD_RSFT, KC_S),KC_C,           KC_V,
    KC_DELETE,      MT(MOD_LALT, KC_QUOTE),LT(4, KC_COMMA),KC_SLASH,       KC_P,           KC_K,                                           KC_Z,           KC_R,           KC_M,           KC_W,           MT(MOD_RALT, KC_B),KC_TRANSPARENT,
    LSFT(KC_DELETE),ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     KC_TRANSPARENT, DUAL_FUNC_0,                                                                                                    KC_LEFT_GUI,    KC_X,           ST_MACRO_3,     ST_MACRO_4,     ST_MACRO_5,     KC_TRANSPARENT,
    LT(2, KC_SPACE),LT(5, KC_ENTER),LALT(LCTL(KC_A)),                LGUI(LSFT(KC_S)),CW_TOGG,        LT(3, KC_DOT)
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_A,           MT(MOD_LSFT, KC_S),KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           MT(MOD_RSFT, KC_L),KC_SLASH,       KC_UNDS,
    KC_TRANSPARENT, MT(MOD_LSFT | MOD_LCTL, KC_Z),MT(MOD_LCTL, KC_X),KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       MT(MOD_RCTL, KC_QUOTE),DUAL_FUNC_1,    KC_GRAVE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_NO,          KC_LPRN,        KC_RPRN,        KC_NO,          KC_TRANSPARENT,
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
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_0,           KC_UNDS,        KC_TILD,        KC_CIRC,        KC_NO,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_ENTER,       KC_SPACE,       KC_DOT
  ),
  [5] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_NO,                                          KC_MEDIA_PREV_TRACK,KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_NO,          KC_NO,          LCTL(KC_W),     LCTL(LSFT(KC_R)),LCTL(KC_N),     LCTL(KC_GRAVE), KC_F12,                                         KC_MEDIA_NEXT_TRACK,KC_PERC,        KC_7,           KC_8,           KC_9,           KC_EQUAL,       KC_NUM,
    KC_TRANSPARENT, ST_MACRO_6,     LCTL(KC_S),     DUAL_FUNC_2,    ST_MACRO_7,     DUAL_FUNC_3,    DUAL_FUNC_4,                                                                    KC_MEDIA_PLAY_PAUSE,KC_PLUS,        KC_4,           KC_5,           KC_6,           KC_MINUS,       KC_SLASH,
    KC_TRANSPARENT, LALT(KC_INSERT),LALT(KC_F2),    LCTL(KC_DOT),   ST_MACRO_8,     LCTL(LSFT(KC_B)),                                KC_ASTR,        KC_1,           KC_2,           KC_3,           KC_COLN,        KC_NO,
    KC_TRANSPARENT, ST_MACRO_9,     ST_MACRO_10,    ST_MACRO_11,    ST_MACRO_12,    QK_BOOT,                                                                                                        KC_TRANSPARENT, KC_0,           KC_UNDS,        KC_TILD,        KC_CIRC,        KC_NO,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_ENTER,       KC_SPACE,       KC_DOT
  ),
};



extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {188,255,255}, {0,0,0}, {0,245,245}, {0,245,245}, {152,255,255}, {74,255,255}, {219,255,255}, {34,255,255}, {109,252,245}, {188,255,255}, {74,255,255}, {34,255,255}, {34,255,255}, {109,252,245}, {188,255,255}, {74,255,255}, {34,255,255}, {34,255,255}, {109,252,245}, {188,255,255}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {0,0,0}, {74,255,255}, {109,252,245}, {34,255,255}, {34,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {219,255,255}, {152,255,255}, {109,252,245}, {219,255,255}, {0,0,0}, {34,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {219,255,255}, {34,255,255}, {34,255,255}, {188,255,255}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {188,255,255}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {188,255,255}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,245,245}, {188,255,255}, {152,255,255}, {219,255,255} },

    [1] = { {188,255,255}, {0,0,0}, {0,245,245}, {0,245,245}, {152,255,255}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {188,255,255}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {188,255,255}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {188,255,255}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {219,255,255}, {152,255,255}, {109,252,245}, {219,255,255}, {109,252,245}, {109,252,245}, {109,252,245}, {0,0,0}, {74,255,255}, {34,255,255}, {109,252,245}, {109,252,245}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {109,252,245}, {0,0,255}, {74,255,255}, {34,255,255}, {34,255,255}, {109,252,245}, {0,0,255}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {0,0,0}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,245,245}, {219,255,255}, {152,255,255}, {219,255,255} },

    [2] = { {188,255,255}, {0,0,0}, {0,245,245}, {0,245,245}, {152,255,255}, {74,255,255}, {0,0,0}, {219,255,255}, {152,255,255}, {152,255,255}, {74,255,255}, {152,255,255}, {109,252,245}, {152,255,255}, {0,0,0}, {74,255,255}, {152,255,255}, {34,255,255}, {152,255,255}, {0,0,0}, {74,255,255}, {219,255,255}, {152,255,255}, {152,255,255}, {0,0,0}, {74,255,255}, {188,255,255}, {152,255,255}, {188,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {219,255,255}, {152,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {219,255,255}, {219,255,255}, {0,0,0}, {74,255,255}, {219,255,255}, {219,255,255}, {152,255,255}, {152,255,255}, {74,255,255}, {109,252,245}, {0,245,245}, {219,255,255}, {152,255,255}, {74,255,255}, {0,245,245}, {0,245,245}, {219,255,255}, {219,255,255}, {74,255,255}, {109,252,245}, {0,245,245}, {219,255,255}, {152,255,255}, {74,255,255}, {0,0,0}, {109,252,245}, {109,252,245}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {219,255,255}, {152,255,255}, {219,255,255} },

    [3] = { {188,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {152,255,255}, {74,255,255}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,0}, {74,255,255}, {0,0,255}, {109,252,245}, {109,252,245}, {0,0,255}, {74,255,255}, {0,0,255}, {109,252,245}, {109,252,245}, {0,0,255}, {74,255,255}, {109,252,245}, {0,0,255}, {0,0,255}, {0,0,0}, {74,255,255}, {109,252,245}, {109,252,245}, {109,252,245}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {219,255,255}, {152,255,255}, {109,252,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {109,252,245}, {109,252,245}, {0,0,0}, {74,255,255}, {109,252,245}, {109,252,245}, {109,252,245}, {0,0,0}, {74,255,255}, {109,252,245}, {109,252,245}, {109,252,245}, {0,0,0}, {74,255,255}, {109,252,245}, {109,252,245}, {109,252,245}, {0,0,0}, {74,255,255}, {0,0,0}, {109,252,245}, {109,252,245}, {219,255,255}, {219,255,255}, {219,255,255}, {0,245,245}, {109,252,245}, {109,252,245}, {109,252,245} },

    [4] = { {188,255,255}, {0,0,0}, {0,245,245}, {0,245,245}, {152,255,255}, {74,255,255}, {219,255,255}, {34,255,255}, {109,252,245}, {188,255,255}, {74,255,255}, {34,255,255}, {34,255,255}, {109,252,245}, {188,255,255}, {74,255,255}, {34,255,255}, {34,255,255}, {109,252,245}, {188,255,255}, {74,255,255}, {34,255,255}, {34,255,255}, {34,255,255}, {0,0,0}, {74,255,255}, {109,252,245}, {34,255,255}, {34,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {0,245,245}, {219,255,255}, {152,255,255}, {109,252,245}, {34,255,255}, {152,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {34,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {74,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {74,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {34,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,255}, {152,255,255}, {219,255,255}, {219,255,255} },

    [5] = { {188,255,255}, {0,0,0}, {0,245,245}, {0,245,245}, {152,255,255}, {34,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {34,255,255}, {188,255,255}, {0,245,245}, {219,255,255}, {152,255,255}, {152,255,255}, {34,255,255}, {152,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {34,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {74,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {74,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {34,255,255}, {74,255,255}, {74,255,255}, {74,255,255}, {219,255,255}, {219,255,255}, {219,255,255}, {0,0,255}, {152,255,255}, {219,255,255}, {219,255,255} },

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
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_3) SS_TAP(X_KP_2) ));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_9) ));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_8) ));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_4) SS_TAP(X_KP_2) ));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_4) ));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_3) ));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_K))SS_DELAY(100)  SS_LCTL(SS_TAP(X_S)));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_E))SS_DELAY(100)  SS_LCTL(SS_TAP(X_F)));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_R))SS_DELAY(100)  SS_LCTL(SS_TAP(X_V)));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_K))SS_DELAY(100)  SS_LCTL(SS_TAP(X_I)));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_K))SS_DELAY(100)  SS_LCTL(SS_TAP(X_U)));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_K))SS_DELAY(100)  SS_LCTL(SS_TAP(X_C)));
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_R))SS_DELAY(100)  SS_LCTL(SS_TAP(X_M)));
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
  return true;
}



