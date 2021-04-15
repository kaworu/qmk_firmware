#include QMK_KEYBOARD_H

enum layers {
	_QWERTY,
	_FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Base (Default) Layer
	 * ,----------------------------------------------------------------.
	 * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|   BS  |PgUp|
	 * |-----------------------------------------------------------|----|
	 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  {|  }|     |PgDn|
	 * |------------------------------------------------------.    |----'
	 * |CapsFn|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  #|Ent |
	 * |-----------------------------------------------------------|
	 * |Shift| \|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| Shift|Up |
	 * |---------------------------------------------------------------.
	 * |Ctrl |Win |Alt |         Space         |Alt |Ctrl| |Lft|Dwn|Rgt|
	 * `-------------------------------------------------' '-----------'
	 */
	[_QWERTY] = LAYOUT_65_iso_badge(
	//      1                2        3        4        5        6        7        8        9        10             11       12       13       14       15
		KC_ESC,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,          KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_PGUP,
		KC_TAB,          KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,          KC_P,    KC_LBRC, KC_RBRC,          KC_PGDN,
		LT(_FN,KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,          KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
		OSM(MOD_LSFT),   KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,       KC_DOT,  KC_SLSH, OSM(MOD_RSFT), KC_UP,
		KC_LCTL,         KC_LGUI, KC_LALT,                   KC_SPC,                             OSM(MOD_RALT), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
	),
	/* Fn Layer
	 * ,----------------------------------------------------------------.
	 * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|Hom|F11|F12| Del   |Home|
	 * |-----------------------------------------------------------|----|
	 * |     |   |   |   |   |   |   |PUp|   |   |   |   |   |     |End |
	 * |------------------------------------------------------.    |----'
	 * |      |   |   |PDn|   |   |Lef|Dow|Up |Rig|   |   |End|    |
	 * |-----------------------------------------------------------|
	 * |    |   |   |   |   |   |   |   |Mut|Vo-|Vo+|   |      |PUp|
	 * |---------------------------------------------------------------.
	 * |Reset|     |Menu|           F10        |    |    | |Hom|PDn|End|
	 * `-------------------------------------------------' '-----------'
	 */
	[_FN] = LAYOUT_65_iso_badge(
	//      1        2        3        4        5        6        7        8        9        10       11       12       13       14      15
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_HOME, KC_F11,  KC_F12,  KC_DEL, KC_HOME,
		_______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, _______, _______, _______, _______,         KC_END,
		_______, _______, _______, KC_PGDN, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, KC_END,  _______,
		_______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, KC_PGUP,
		QK_BOOT, _______,  KC_APP,                    KC_F10,                            _______, _______,          KC_HOME, KC_PGDN, KC_END
	),
};

void
keyboard_post_init_user(void)
{
	rgblight_enable_noeeprom();
	rgblight_sethsv_noeeprom(HSV_OFF);
}

bool
led_update_user(led_t led_state)
{
	if (led_state.caps_lock)
		rgblight_sethsv_noeeprom(HSV_PINK);
	else
		rgblight_sethsv_noeeprom(HSV_OFF);
	return true;
}

/* see https://github.com/qmk/qmk_firmware/issues/3963 */
bool
process_record_user(uint16_t keycode, keyrecord_t *record)
{
	switch (keycode) {
	case OSM(MOD_LSFT):
		del_oneshot_mods(MOD_BIT(KC_RSFT));
		del_oneshot_mods(MOD_BIT(KC_RALT));
		break;
	case OSM(MOD_RSFT):
		del_oneshot_mods(MOD_BIT(KC_LSFT));
		del_oneshot_mods(MOD_BIT(KC_RALT));
		break;
	case OSM(MOD_RALT):
		del_oneshot_mods(MOD_BIT(KC_LSFT));
		del_oneshot_mods(MOD_BIT(KC_RSFT));
		break;
	}
	return true;
}
