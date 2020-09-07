#include QMK_KEYBOARD_H

enum layers {
	_QWERTY,
	_FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Base (Default) Layer
	 * ,-----------------------------------------------------------.
	 * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|   BS  |
	 * |-----------------------------------------------------------|
	 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  {|  }|     |
	 * |------------------------------------------------------.    |
	 * |CapsFn|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  #|Ent |
	 * |-----------------------------------------------------------|
	 * |Shift| \|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|  Shift   |
	 * |-----------------------------------------------------------|
	 * |Ctrl|Win |Alt |          Space         |Alt |Win |Menu|Ctrl|
	 * `-----------------------------------------------------------'
	 */
	[_QWERTY] = LAYOUT_60_iso(
	//      1                2        3        4        5        6        7        8        9        10             11       12       13       14
		KC_ESC,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,          KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
		KC_TAB,          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,          KC_P,    KC_LBRC, KC_RBRC,
		LT(_FN,KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,          KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
		OSM(MOD_LSFT),   KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,       KC_DOT,  KC_SLSH, OSM(MOD_RSFT),
		KC_LCTL,         KC_LGUI, KC_LALT,                   KC_SPC,                             OSM(MOD_RALT), KC_RGUI, KC_APP,  KC_RCTL
	),

	/* Fn Layer
	 * ,-----------------------------------------------------------.
	 * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|Hom|F11|F12| Del   |
	 * |-----------------------------------------------------------|
	 * |     |   |   |   |   |   |   |PUp|   |   |   |   |   |     |
	 * |------------------------------------------------------.    |
	 * |      |   |   |PDn|   |   |Lef|Dow|Up |Rig|   |   |End|    |
	 * |-----------------------------------------------------------|
	 * |    |   |   |   |   |   |   |   |Mut|Vo-|Vo+|   |          |
	 * |-----------------------------------------------------------|
	 * |Sleep|Reset|    |        F10            |    |    |   |Menu|
	 * `-----------------------------------------------------------'
	 */
	[_FN] = LAYOUT_60_iso(
	//      1        2        3        4        5        6        7        8        9        10       11       12       13       14
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_HOME, KC_F11,  KC_F12,  KC_DEL,
		_______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, _______,
		_______, _______, _______, KC_PGDN, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, KC_END,  _______,
		_______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
		KC_SLEP,   RESET, _______,                    KC_F10,                            _______, _______, _______, KC_APP
	),
};
