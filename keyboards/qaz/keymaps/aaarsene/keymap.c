#include QMK_KEYBOARD_H

enum layers{
  _BASE,
  _NUM_SYM,
  _NAV_FN
};
enum combo_events {
  COMBO_BSPC,
  COMBO_NUMBAK,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_DEL,
  COMBO_ENT,
  COMBO_QUOT,
  COMBO_DQUO,
};

#define KC_NUM_SPC LT(_NUM_SYM, KC_SPC)
#define KC_GA LGUI_T(KC_A)
#define KC_AS LALT_T(KC_S)
#define KC_CD LCTL_T(KC_D)
#define KC_SF LSFT_T(KC_F)
#define KC_SJ RSFT_T(KC_J)
#define KC_CK RCTL_T(KC_K)
#define KC_AL RALT_T(KC_L)
#define KC_GSCLN RGUI_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_space(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,   KC_O,     KC_P,
    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,    KC_K,   KC_L,     KC_SCLN,
    KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMM,   KC_DOT,
    KC_LGUI, KC_LALT, KC_LCTL, LT(_NUM_SYM,KC_SPACE), KC_LSFT, KC_RALT, MO(_NAV_FN), KC_MPLY
  ),

  [_NUM_SYM] = LAYOUT_split_space(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_GRV, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_BSLS, KC_MINS, KC_EQL, KC_SLSH,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_NAV_FN] = LAYOUT_split_space(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_HOME, KC_END, KC_TRNS, KC_UP, KC_INS, KC_DEL,
    KC_F5, KC_F6, KC_F7, KC_F8, KC_PGUP, KC_PGDN, KC_LEFT, KC_RGHT, KC_TRNS, KC_TRNS,
    KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_DOWN, KC_TRNS, KC_TRNS,
    RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_MINS, KC_EQL, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_quot[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_dquo[] = {KC_8, KC_9, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
  [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL),
  [COMBO_ENT] = COMBO(combo_ent,KC_ENT),
  [COMBO_QUOT] = COMBO(combo_quot,KC_QUOT),
  [COMBO_DQUO] = COMBO(combo_dquo,KC_DQUO),
};
#endif
