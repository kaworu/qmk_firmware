#include QMK_KEYBOARD_H

enum layers {
	_QWERTY,
	_NOOSM,
	_FN,
};

enum custom_keycodes {
    W_BTN2_HOLD = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* Base (Default) Layer
	 * ,----------------------------------------------------------------.
	 * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|   BS  |Home|
	 * |----------------------------------------------------------------|
	 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  {|  }|     |PgUp|
	 * |------------------------------------------------------.    |----|
	 * |CapsFn|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  #|Ent |PgDn|
	 * |----------------------------------------------------------------|
	 * |Shift| \|  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Up |End |
	 * |----------------------------------------------------------------|
	 * |Ctrl|Win |Alt |          Space        |Alt |Ctrl|  |Lef|Dow|Rig |
	 * `------------------------------------------------'  `------------'
	 */
	[_QWERTY] = LAYOUT_65_iso(
		KC_ESC,               KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,    KC_BSPC,   KC_HOME,
		KC_TAB,                 KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,            KC_PGUP,
		LT(_FN,KC_CAPS),         KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_NUHS, KC_ENT,  KC_PGDN,
		OSM(MOD_LSFT),   KC_NUBS,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_RSFT),   KC_UP,   KC_END,
		KC_LCTL, KC_LGUI, KC_LALT,                        KC_SPC,                     OSM(MOD_RALT), XXXXXXX, KC_RCTL, KC_LEFT,        KC_DOWN, KC_RGHT
	),

	/*
	 * _NOOSM: gaming layer that neutralizes the one-shot modifiers.
	 * OSM shift/alt is great for typing chords but breaks games that
	 * rely on held modifiers — e.g. LShift for sprint in Minecraft.
	 * Plain KC_LSFT / KC_RSFT / KC_RALT are substituted here;
	 * everything else inherits from _QWERTY.
	 * Toggle via TG(_NOOSM), bound on Fn + G.
	 */
	[_NOOSM] = LAYOUT_65_iso(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RSFT, _______, _______,
		_______, _______, _______,                   _______,                  KC_RALT, W_BTN2_HOLD, _______, _______,        _______, _______
	),

	/* Fn Layer
	 * ,----------------------------------------------------------------.
	 * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|Hom|F11|F12| Del   |    |
	 * |----------------------------------------------------------------|
	 * |     |   |   |   |   |   |   |PUp|   |   |   |   |   |     |    |
	 * |------------------------------------------------------.    |----|
	 * |      |   |   |PDn|   |   |Lef|Dow|Up |Rig|   |   |End|    |    |
	 * |----------------------------------------------------------------|
	 * |    |  |   |   |   |   |   |   |Mut|Vo-|Vo+|   |       |PUp|    |
	 * |----------------------------------------------------------------|
	 * |Reset|     |Menu|        F10         |     |    |  |Hom|PDn|End |
	 * `------------------------------------------------'  `------------'
	 */
	[_FN] = LAYOUT_65_iso(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,  KC_F7,   KC_F8,   KC_F9,  KC_HOME,  KC_F11,  KC_F12,       KC_DEL,  _______,
		_______,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, KC_PGUP, _______, _______, _______, _______, _______,            _______,
		_______,     _______, _______, KC_PGDN, _______, TG(_NOOSM), KC_LEFT, KC_DOWN,  KC_UP, KC_RGHT, _______,  _______,  KC_END, _______, _______,
		_______,_______,_______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,       KC_PGUP, _______,
		QK_BOOT, _______,    KC_APP,                KC_F10,                          _______,  XXXXXXX,  _______,  KC_HOME,      KC_PGDN, KC_END
	),
};

/* see https://github.com/qmk/qmk_firmware/issues/3963 */
/*
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
*/

bool
process_record_user(uint16_t keycode, keyrecord_t *record)
{
	static bool w_btn2_active = false;

	switch (keycode) {
	/*
	 * W_BTN2_HOLD: press once to hold KC_W + mouse button 2, press
	 * again to release both. Automates walk-forward + use/place in
	 * Minecraft — e.g. long tunneling / strip-mining, or auto-place
	 * with Litematica schematics.
	 */
	case W_BTN2_HOLD:
		if (record->event.pressed) {
			if (!w_btn2_active) {
				register_code(KC_W);
				register_code(MS_BTN2);
			} else {
				unregister_code(MS_BTN2);
				unregister_code(KC_W);
			}
			w_btn2_active = !w_btn2_active;
		}
		return false;
	}
	return true;
}
