#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _APPS 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  APPS,
  ADJUST,
  G_RECON,
};

enum tap_dance {
  TD_LBRC,
  TD_RBRC,
  TD_ALT1,
  TD_LSFT,
  TD_RSFT,
  TD_RAIN,
};

// Shortcut to make keymap more readable
#define SYM_L   OSL(_SYMB)
#define APP_L   TG(_APPS)


#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)
#define KC_CSMN C_S_T(KC_PMNS)
#define KC_CAPL LCA_T(KC_PPLS)
#define KC_DEGR SAGR(KC_QUOT)

#define KC_APGR LT(_APPS, KC_GRV)

#define KC_TDLB TD(TD_LBRC)
#define KC_TDRB TD(TD_RBRC)
#define KC_TDAL TD(TD_ALT1)
#define KC_TDLS TD(TD_LSFT)
#define KC_TDRS TD(TD_RSFT)
#define KC_RAIN TD(TD_RAIN)

int cur_dance (tap_dance_state_t *state);
void alt_finished (tap_dance_state_t *state, void *user_data);
void alt_reset (tap_dance_state_t *state, void *user_data);

void lsft_finished (tap_dance_state_t *state, void *user_data);
void lsft_reset (tap_dance_state_t *state, void *user_data);

void rsft_finished (tap_dance_state_t *state, void *user_data);
void rsft_reset (tap_dance_state_t *state, void *user_data);

void rain_finished (tap_dance_state_t *state, void *user_data);
void rain_reset (tap_dance_state_t *state, void *user_data);

typedef struct {
    bool is_press_action;
    int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
};

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for [, twice for (
    [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LPRN),
    // Tap once for ], twice for )
    [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RPRN),
    [TD_ALT1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_finished, alt_reset),
    [TD_LSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lsft_finished, lsft_reset),
    [TD_RSFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rsft_finished, rsft_reset),
    [TD_RAIN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rain_finished, rain_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_APGR ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_ESC  ,                          APP_L   ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_EQL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     SYM_L   ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_TDLB ,                          KC_TDRB ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TDLS ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_PGUP ,KC_PGDN ,        KC_HOME ,KC_END  ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_TDRS ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LGUI ,KC_CAPL ,KC_CSMN ,KC_TDAL ,     KC_CTPL ,    KC_SPC  ,KC_BSPC ,        KC_ENT  ,KC_DEL  ,    KC_RAIN ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EXLM ,KC_AT   ,KC_LABK ,KC_RABK ,KC_PIPE ,_______ ,                          _______ ,KC_PSLS ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,KC_F12  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_HASH ,KC_DLR  ,KC_UNDS ,KC_DQUO ,KC_GRV  ,_______ ,                          _______ ,KC_PAST ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_PERC ,KC_CIRC ,KC_QUES ,KC_DEGR ,KC_TILD ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    KC_NUM  ,     KC_P0   ,KC_PDOT ,KC_PENT ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_APPS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_CALC ,KC_PSCR ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          _______ ,XXXXXXX ,XXXXXXX ,KC_VOLD ,KC_VOLU ,KC_MUTE ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,G_RECON ,XXXXXXX ,XXXXXXX ,KC_PGUP ,KC_PGDN ,XXXXXXX ,                          XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
};

int cur_dance (tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->pressed) return SINGLE_HOLD;
    else return SINGLE_TAP;
  }
  else if (state->count == 2) {
    if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else return 8;
}

static tap alttap_state = {
  .is_press_action = true,
  .state = 0
};

void alt_finished (tap_dance_state_t *state, void *user_data) {
  alttap_state.state = cur_dance(state);
  switch (alttap_state.state) {
    case SINGLE_TAP: set_oneshot_layer(_SYMB, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break;
    case SINGLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_TAP: set_oneshot_layer(_SYMB, ONESHOT_START); set_oneshot_layer(_SYMB, ONESHOT_PRESSED); break;
    case DOUBLE_HOLD: register_code(KC_LALT); layer_on(_SYMB); break;
  }
}

void alt_reset (tap_dance_state_t *state, void *user_data) {
  switch (alttap_state.state) {
    case SINGLE_TAP: break;
    case SINGLE_HOLD: unregister_code(KC_LALT); break;
    case DOUBLE_TAP: break;
    case DOUBLE_HOLD: layer_off(_SYMB); unregister_code(KC_LALT); break;
  }
  alttap_state.state = 0;
}

static tap lsfttap_state = {
  .is_press_action = true,
  .state = 0
};

void lsft_finished (tap_dance_state_t *state, void *user_data) {
  lsfttap_state.state = cur_dance(state);
  switch (lsfttap_state.state) {
    case SINGLE_TAP: set_oneshot_layer(_SYMB, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break;
    case SINGLE_HOLD: register_code(KC_LSFT); break;
    case DOUBLE_TAP: register_code(KC_CAPS_LOCK); break;
  }
}

void lsft_reset (tap_dance_state_t *state, void *user_data) {
  switch (lsfttap_state.state) {
    case SINGLE_TAP: break;
    case SINGLE_HOLD: unregister_code(KC_LSFT); break;
    case DOUBLE_TAP: unregister_code(KC_CAPS_LOCK); break;
  }
  lsfttap_state.state = 0;
}

static tap rsfttap_state = {
  .is_press_action = true,
  .state = 0
};

void rsft_finished (tap_dance_state_t *state, void *user_data) {
  rsfttap_state.state = cur_dance(state);
  switch (rsfttap_state.state) {
    case SINGLE_TAP: set_oneshot_layer(_SYMB, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break;
    case SINGLE_HOLD: register_code(KC_RSFT); break;
    case DOUBLE_TAP: register_code(KC_CAPS_LOCK); break;
  }
}

void rsft_reset (tap_dance_state_t *state, void *user_data) {
  switch (rsfttap_state.state) {
    case SINGLE_TAP: break;
    case SINGLE_HOLD: unregister_code(KC_RSFT); break;
    case DOUBLE_TAP: unregister_code(KC_CAPS_LOCK); break;
  }
  rsfttap_state.state = 0;
}

static tap raintap_state = {
  .is_press_action = true,
  .state = 0
};

void rain_finished (tap_dance_state_t *state, void *user_data) {
  raintap_state.state = cur_dance(state);
  switch (raintap_state.state) {
    case SINGLE_TAP: register_code(KC_INS); break;
    case SINGLE_HOLD: register_code(KC_RALT); break;
    case DOUBLE_TAP: set_oneshot_mods(MOD_BIT(KC_RALT)); break;
  }
}

void rain_reset (tap_dance_state_t *state, void *user_data) {
  switch (raintap_state.state) {
    case SINGLE_TAP: unregister_code(KC_INS); break;
    case SINGLE_HOLD: unregister_code(KC_RALT); break;
  }
  raintap_state.state = 0;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case G_RECON:
            if (record->event.pressed) {
                SEND_STRING("git rebase --continue\n");
            }
            break;
    }
    return true;
}
