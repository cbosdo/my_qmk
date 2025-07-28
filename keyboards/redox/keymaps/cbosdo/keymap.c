#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NAV 1
#define _FUN 2

// Shortcut to make keymap more readable
#define NAV_L   OSL(_NAV)


#define KC_CTBS LCTL_T(KC_BSLS)
#define KC_CSMN C_S_T(KC_PMNS)
#define KC_CAPL LCA_T(KC_PPLS)

#define KC_RAIN MT(MOD_RALT, KC_INS)

#define CMD_A   LCMD_T(KC_A)
#define SHIFT_S LSFT_T(KC_S)
#define CTRL_D  LCTL_T(KC_D)
#define ALT_F   LALT_T(KC_F)

#define ALT_J   LALT_T(KC_J)
#define CTRL_K  RCTL_T(KC_K)
#define SHIFT_L RSFT_T(KC_L)
#define CMD_SCL CMD_T(KC_SCLN)

#define FN_ESC LT(_FUN, KC_ESC)

#define EURO    LSFT(KC_1)
#define FR_LQOT LSFT(KC_2)
#define FR_RQOT LSFT(KC_3)


layer_state_t layer_state_set_user(layer_state_t state);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,_______ ,                          _______ ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,CMD_A   ,SHIFT_S ,CTRL_D  ,ALT_F   ,KC_G    ,_______ ,                          _______ ,KC_H    ,ALT_J   ,CTRL_K  ,SHIFT_L ,CMD_SCL ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,_______ ,_______ ,        _______ ,_______ ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     NAV_L   ,    KC_SPC  ,KC_BSPC ,        KC_ENT  ,FN_ESC  ,    KC_RAIN ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,EURO    ,KC_HOME ,KC_UP   ,KC_END  ,KC_PGUP ,_______ ,                          _______ ,KC_PSLS ,KC_P7   ,KC_P8   ,KC_P9   ,KC_F11  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_TAB  ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_PGDN ,_______ ,                          _______ ,KC_PMNS ,KC_P4   ,KC_P5   ,KC_P6   ,KC_P0   ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,KC_VOLD ,KC_MUTE ,KC_VOLU ,_______ ,_______ ,_______ ,        _______ ,_______ ,KC_NUM  ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PDOT ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,KC_DEL  ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_FUN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,FR_LQOT ,FR_RQOT ,_______ ,_______ ,_______ ,                          _______ ,_______ ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F11  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,KC_F4   ,KC_F5   ,KC_F6   ,KC_F10  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,KC_F1   ,KC_F2   ,KC_F3   ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        KC_CALC ,KC_PSCR ,    _______ ,     _______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
};


// Toggle num lock on when switching to NAV layer
layer_state_t layer_state_set_user(layer_state_t state) {
    led_t led_state = host_keyboard_led_state();
    bool g_num_lock_state = led_state.num_lock;

    switch(get_highest_layer(state)) {
        // replace number with your num lock layer number
        case _NAV:
        if (!g_num_lock_state) {
            tap_code(KC_NUM_LOCK);
        }
        break;
    }
    return state;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // ergo-L changes
        case KC_O:
        case KC_N:
            return false;

        case KC_C:
            return true;

        // KC_V continues Caps Word, with shift applied.
        // ALTGR(KC_V) continues Caps Word, without shifting.
        case KC_V:
            // Apply shift if altgr is not activated.
            if (!(get_mods() & MOD_BIT(KC_RALT))) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            return true;

        case KC_SCLN:
            case KC_COMM:
        case KC_SLSH:

        // Keycodes that continue Caps Word, with shift applied.
        case KC_A:
        case KC_B:
        case KC_D ... KC_M:
        case KC_P ... KC_U:
        case KC_W ... KC_Z:
            if (get_mods() & MOD_BIT(KC_RALT)) { // Stop on altgr symbols
                return false;
            }
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_P1 ... KC_P0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
};
