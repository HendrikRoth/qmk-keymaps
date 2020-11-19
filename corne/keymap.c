#include QMK_KEYBOARD_H
#include "keymap_german.h"

extern uint8_t is_master;

#define ____      KC_TRANSPARENT
#define KC_RESET  RESET
#define MY_ESC    LT(_NAVIGATION, KC_ESC)
#define MY_SPC    LT(_SYMBOLS, KC_SPACE)
#define MY_ENT    LT(_NUMPAD, KC_ENTER)
#define MY_BSPC   LT(_SYMBOLS, KC_BSPC)
#define MY_DEL    LT(_NUMPAD, KC_DEL)
#define MY_TAB    LALT_T(KC_TAB)
#define MY_MINS   RGUI_T(DE_MINS)
#define MY_PLUS   RSFT_T(DE_PLUS)
#define MY_ACUT   LALT_T(DE_ACUT)
#define MY_Y LGUI_T(KC_Y)
#define MY_T LCTL_T(KC_T)

enum corne_layers {
    _BASE,
    _SYMBOLS,
    _NUMPAD,
    _NAVIGATION
};

enum combo_events {
    COMBO_QA = 0,
    COMBO_WS,
    COMBO_ED,
    COMBO_RF,
    COMBO_TG,
    COMBO_YH,
    COMBO_UJ,
    COMBO_IK,
    COMBO_OL,
    COMBO_PHASH,
    COMBO_UE,
    COMBO_OE,
    COMBO_AE,
    COMBO_SS
};

const uint16_t PROGMEM combo_QA[] = {DE_Q, DE_A, COMBO_END};
const uint16_t PROGMEM combo_WS[] = {DE_W, DE_S, COMBO_END};
const uint16_t PROGMEM combo_ED[] = {DE_E, DE_D, COMBO_END};
const uint16_t PROGMEM combo_RF[] = {DE_R, DE_F, COMBO_END};
const uint16_t PROGMEM combo_TG[] = {DE_T, DE_G, COMBO_END};
const uint16_t PROGMEM combo_YH[] = {DE_Y, DE_H, COMBO_END};
const uint16_t PROGMEM combo_UJ[] = {DE_U, DE_J, COMBO_END};
const uint16_t PROGMEM combo_IK[] = {DE_I, DE_K, COMBO_END};
const uint16_t PROGMEM combo_OL[] = {DE_O, DE_L, COMBO_END};
const uint16_t PROGMEM combo_PHASH[] = {DE_P, DE_HASH, COMBO_END};
const uint16_t PROGMEM combo_UE[] = {DE_U, DE_E, COMBO_END};
const uint16_t PROGMEM combo_OE[] = {DE_O, DE_E, COMBO_END};
const uint16_t PROGMEM combo_AE[] = {DE_A, DE_E, COMBO_END};
const uint16_t PROGMEM combo_SS[] = {DE_S, DE_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [COMBO_QA] = COMBO(combo_QA, KC_1),
    [COMBO_WS] = COMBO(combo_WS, KC_2),
    [COMBO_ED] = COMBO(combo_ED, KC_3),
    [COMBO_RF] = COMBO(combo_RF, KC_4),
    [COMBO_TG] = COMBO(combo_TG, KC_5),
    [COMBO_YH] = COMBO(combo_YH, KC_6),
    [COMBO_UJ] = COMBO(combo_UJ, KC_7),
    [COMBO_IK] = COMBO(combo_IK, KC_8),
    [COMBO_OL] = COMBO(combo_OL, KC_9),
    [COMBO_PHASH] = COMBO(combo_PHASH, KC_0),
    [COMBO_UE] = COMBO(combo_UE, DE_UE),
    [COMBO_OE] = COMBO(combo_OE, DE_OE),
    [COMBO_AE] = COMBO(combo_AE, DE_AE),
    [COMBO_SS] = COMBO(combo_SS, DE_SS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-------------------------------------------------------.
       MY_TAB,    DE_Q,    DE_W,    DE_E,    DE_R,    MY_T,                         MY_Y,    DE_U,    KC_I,    KC_O,   KC_P,  MY_DEL,  \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+----------|
      KC_LCTL,    DE_A,    DE_S,    DE_D,    DE_F,    DE_G,                         DE_H,    DE_J,    KC_K,    KC_L, KC_SCLN, MY_PLUS, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+----------|
      KC_LSFT,    DE_Z,    DE_X,    DE_C,    DE_V,    DE_B,                         DE_N,    DE_M, DE_COMM,  DE_DOT, MY_MINS, KC_RCTRL,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+----------|
                                          KC_LGUI,   MY_ESC,  MY_ENT,     MY_SPC,  KC_BSPC,  KC_RGUI \
                                      //`--------------------------'  `--------------------------'

  ),

  [_SYMBOLS] = LAYOUT_split_3x6_3( \
  //,------------------------------------------------------.                     ,-------------------------------------------------------.
      KC_PAUS, DE_MORE, DE_RBRC, DE_RCBR, DE_RPRN, DE_BSLS,                       DE_SLSH, DE_LPRN, DE_LCBR, DE_LBRC, DE_LESS, KC_PAUSE, \
  //|---------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+----------|
      ____,    DE_LESS, DE_LBRC, DE_LCBR, DE_LPRN, DE_SLSH,                       DE_BSLS, DE_RPRN, DE_RCBR, DE_RBRC, DE_MORE, ____,     \
  //|---------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+----------|
      ____,    DE_DLR,  DE_PERC, DE_PIPE, DE_AT,   DE_AMPR,                       DE_AMPR, DE_AT,   DE_PIPE, DE_PERC, DE_DLR,  ____,     \
  //|---------+--------+--------+--------+--------+--------+------|  |-----+-----+--------+--------+--------+--------+--------+----------|
                                          ____,    ____,    ____,     ____, ____, ____    \
                                         //`---------------------'  `---------------------'
    ),

  [_NUMPAD] = LAYOUT_split_3x6_3( \
  //,---------------------------------------------------.               ,--------------------------------------------------.
      KC_NUMLOCK, KC_PPLS, KC_P9, KC_P8, KC_P7, KC_PAST,                 KC_PAST, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_NUMLOCK,\
  //|------------+--------+------+------+------+--------|               |--------+------+------+------+--------+-----------|
      KC_PDOT,    KC_PMNS, KC_P6, KC_P5, KC_P4, KC_PSLS,                 KC_PSLS, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_PDOT,   \
  //|------------+--------+------+------+------+--------|               |--------+------+------+------+--------+-----------|
      KC_P0,      KC_PENT, KC_P3, KC_P2, KC_P1, KC_PDOT ,                KC_PDOT, KC_P1, KC_P2, KC_P3, KC_PENT, KC_P0,     \
  //|------------+--------+------+------+------+--------+------|  |-----+--------+------+------+------+--------+-----------|
                                          ____, ____,    ____,     ____, ____,    ____  \
                                      //`---------------------'  `----------------------'
  ),

  [_NAVIGATION] = LAYOUT_split_3x6_3( \
  //,---------------------------------------------------.              ,----------------------------------------------------.
      ____, KC_PGUP, KC_HOME, KC_UP,   KC_END,   KC_BSPC,               KC_BSPC, KC_PGUP,  KC_DEL, KC_END,   KC_PGUP, ____,\
  //|------+--------+--------+--------+---------+-------|              |--------+--------+--------+---------+--------+-----|
      ____, KC_PGDN, KC_LEFT, KC_PGDN, KC_RIGHT, KC_DEL,                KC_LEFT,  KC_DOWN, KC_UP,  KC_RIGHT, KC_PGDN, ____,\
  //|------+--------+--------+--------+---------+-------|              |--------+--------+--------+---------+--------+-----/
      RESET, ____,    ____,    ____,    ____,     ____,                  ____,    ____,    ____,    ____,     ____,   ____,\
  //|------+--------+--------+--------+---------+-------+-----|  |-----+--------+--------+--------+---------+--------+-----|
                                       ____,     ____,   ____,    ____, ____,    ____ \
                                    //`----------------------'  `--------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

#ifdef SSD1306OLED

const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  return true;
}
