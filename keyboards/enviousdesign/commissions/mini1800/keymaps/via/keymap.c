/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(
		QK_GESC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_BSLS,    KC_PGUP, KC_PGDN, KC_DEL,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_BSPC,             KC_7,    KC_8,    KC_9,
		MO(1),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT,                       KC_4,    KC_5,    KC_6,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_SLSH, KC_RSFT,    			 	 KC_1,    KC_2,    KC_3, 
																 KC_UP,   
		KC_LCTL, KC_LGUI, KC_LALT,          LT(1,KC_SPC),     KC_SPC,           KC_RALT, KC_RCTL,            				 	  KC_0,    LT(1,KC_DOT),
															KC_LEFT, KC_DOWN, KC_RGHT           
	),

	[1] = LAYOUT(
		KC_PWR,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MUTE,    KC_HOME, KC_END,  KC_MSTP,
		KC_CAPS, MO(2),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INS,  KC_PAUS, KC_PSCR, KC_RBRC, KC_SLEP,             KC_P7,   KC_P8,   KC_P9,
		KC_TRNS, KC_SCRL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,                      KC_P4,   KC_P5,   KC_P6,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NUM,  KC_TRNS, KC_TRNS, KC_DOT,  KC_SLSH,                               KC_P1,   KC_P2,   KC_P3, 
																 KC_VOLU,     
		KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_MPLY,          KC_TRNS, KC_TRNS,            			         	  KC_P0,   KC_PDOT,
															KC_MPRV, KC_VOLD, KC_MNXT   
	),
	
	[2] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, QK_BOOT,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                               KC_TRNS, KC_TRNS, KC_TRNS, 
																 KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,            				          KC_TRNS, KC_TRNS,
															KC_TRNS, KC_TRNS, KC_TRNS 
	),
};


void matrix_init_user(void) {
  setPinOutput(GP9);
  writePinLow(GP9);
}
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 1:
        writePinHigh(GP9);
        break;
    default:
        writePinLow(GP9);
        break;
    }
    return state;
}

bool led_update_user(led_t led_state) {
    led_state.num_lock = !led_state.num_lock;
    led_update_ports(led_state);
    return false;
}