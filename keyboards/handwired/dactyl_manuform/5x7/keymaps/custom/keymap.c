#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN     1
#define _NUMPAD 2

// Some basic macros
#define TASK   LCTL(LSFT(KC_ESC))
#define TAB_R  LCTL(KC_TAB)
#define TAB_L  LCTL(LSFT(KC_TAB))
#define TAB_RO LCTL(LSFT(KC_T))

// Combo mods begin
// ===========================================
// define combo names
enum combos {
    COMBO_LCTL,
    COMBO_LGUI,
    COMBO_LALT,
    COMBO_LCTLGUI,
    COMBO_LGUIALT,
    COMBO_LCTLALT,
    COMBO_LCTLGUIALT,
    COMBO_RCTL,
    COMBO_RGUI,
    COMBO_RALT,
    COMBO_RCTLGUI,
    COMBO_RGUIALT,
    COMBO_RCTLALT,
    COMBO_RCTLGUIALT,
    // more here...

    COMBO_LENGTH // nifty trick to avoid manually specifying how many combos you have
};
// d = lctl
// s = gui
// a = alt

uint16_t COMBO_LEN = COMBO_LENGTH; // nifty trick continued

// define keys that make up combos
const uint16_t PROGMEM fd_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM fs_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM fa_combo[] = {KC_F, KC_A, COMBO_END};
const uint16_t PROGMEM fds_combo[] = {KC_F, KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM fsa_combo[] = {KC_F, KC_S, KC_A, COMBO_END};
const uint16_t PROGMEM fda_combo[] = {KC_F, KC_D, KC_A, COMBO_END};
const uint16_t PROGMEM fdsa_combo[] = {KC_F, KC_S, KC_D, KC_A, COMBO_END};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM jscln_combo[] = {KC_J, KC_SCLN, COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM jlslcn_combo[] = {KC_J, KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM jkslcn_combo[] = {KC_J, KC_K, KC_SCLN, COMBO_END};
const uint16_t PROGMEM jklslcn_combo[] = {KC_J, KC_K, KC_L, KC_SCLN, COMBO_END};
// more here...

// map combo names to their keys and the key they trigger
combo_t key_combos[] = {
    [COMBO_LCTL] = COMBO(fd_combo, KC_LCTL),
    [COMBO_LGUI] = COMBO(fs_combo, KC_LGUI),
    [COMBO_LALT] = COMBO(fa_combo, KC_LALT),
    [COMBO_LCTLGUI] = COMBO(fds_combo, LCTL(KC_LGUI)),
    [COMBO_LGUIALT] = COMBO(fsa_combo, LALT(KC_LGUI)),
    [COMBO_LCTLALT] = COMBO(fda_combo, LCTL(KC_LALT)),
    [COMBO_LCTLGUIALT] = COMBO(fdsa_combo, LCA(KC_LGUI)),


    [COMBO_RCTL] = COMBO(jk_combo, KC_RCTL),
    [COMBO_RGUI] = COMBO(jl_combo, KC_RGUI),
    [COMBO_RALT] = COMBO(jscln_combo, KC_RALT),
    [COMBO_RCTLGUI] = COMBO(jkl_combo, LCTL(KC_RGUI)),
    [COMBO_RGUIALT] = COMBO(jlslcn_combo, RALT(KC_RGUI)),
    [COMBO_RCTLALT] = COMBO(jkslcn_combo, RCTL(KC_RALT)),
    [COMBO_RCTLGUIALT] = COMBO(jklslcn_combo, LCA(KC_RGUI)),
    // more here...
};
// ===========================================
// End combo mods

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x7(
        // left hand
        KC_ESC,         KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,
        KC_TAB,         KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_LBRC,
        KC_LSFT,        KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_LPRN,
        KC_LEFT_CTRL,   KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,

        /*-----------------------------------------------------------
        Thumb clusters - 6 following keys correspond to indexes below
        ===============
        | 1 | 2 |
                | 3 | 4 | 5 |
                        | 6 |
        -------------------------------------------------------------*/
        KC_NO,
        KC_NO,
        MO(_FN), /*layer toggle*/
        KC_SPACE,
        MT(MOD_LSFT, KC_TAB),
        MT(MOD_LSFT, KC_TAB),

        // right hand
        KC_7,      KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_GRV,
        KC_RBRC,   KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSLS,
        KC_RPRN,   KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
                   KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_NO,
        /*-----------------------------------------------------------
        Thumb clusters - 6 following keys correspond to indexes below
        ===============
                    | 2 | 1 |
        | 5 | 4 | 3 |        
        | 6 |
        -------------------------------------------------------------*/
        // KC_NO,
        // KC_NO,
        // KC_ENTER,
        // KC_BACKSPACE,
        // KC_RIGHT_SHIFT,
        // KC_TAB // possible mod tap here

        KC_NO,
        KC_NO,
        KC_ENTER,
        KC_SPACE,
        KC_BACKSPACE,
        MT(MOD_LSFT, KC_TAB)
    ),

    [_FN] = LAYOUT_5x7(
        // left hand
        _______,  KC_F1,    KC_F2,      KC_F3,     KC_F4,     KC_F5,     KC_F6,
        _______,  KC_WH_L,  KC_MS_U,    KC_WH_R,   KC_BTN2,   KC_WH_U,   _______,
        _______,  KC_MS_L,  KC_MS_D,    KC_MS_R,   KC_BTN1,   KC_WH_D,   _______,
        _______,  _______,  _______,    _______,   _______,   _______,
        /*-----------------------------------------------------------
        Thumb clusters - 6 following keys correspond to indexes below
        ===============
        | 3 | 4 |       | 2 |
                | 5 | 6 |    
                        | 1 |
        -------------------------------------------------------------*/
        _______,
        _______,
        _______,
        _______,
        KC_TRNS,
        _______,


        // right hand
        KC_F7,     KC_F8,      KC_F9,     KC_F10,    KC_F11,     KC_F12,    KC_PAGE_UP,
        _______,   _______,    _______,   _______,   _______,    _______,   KC_HOME,
        _______,   KC_LEFT,    KC_DOWN,   KC_UP,     KC_RIGHT,   _______,   KC_END,
                   _______,    _______,   _______,   _______,    _______,   KC_PAGE_DOWN,
        /*-----------------------------------------------------------
        Thumb clusters - 6 following keys correspond to indexes below
        ===============
        | 5 |       | 3 | 4 |
            | 1 | 2 |        
        | 6 |
        -------------------------------------------------------------*/
        _______,
        _______,
        _______,
        KC_BACKSPACE,
        KC_DELETE,
        _______
    ),

    // [_NUMPAD] = LAYOUT_5x7(
    //     // left hand
    //     _______,   _______,   _______,   _______,   _______,   _______,  _______,
    //     _______,   _______,   _______,   _______,   _______,   _______,  _______,
    //     _______,   _______,   _______,   _______,   _______,   _______,  _______,
    //     _______,   _______,   _______,   _______,   _______,   _______,
    //     _______,   _______,   _______,   _______, _______, _______,
    //     // right hand
    //                       _______,   _______,   KC_NUM,    _______,   KC_PMNS,   KC_PPLS,   _______,
    //                       _______,   _______,   KC_P7,     KC_P8,     KC_P9,     _______,   _______,
    //                       _______,   _______,   KC_P4,     KC_P5,     KC_P6,     KC_PAST,   _______,
    //                                  _______,   KC_P1,     KC_P2,     KC_P3,     KC_PSLS,   _______,
    //                                                        KC_P0,     KC_PDOT,   _______,   _______, _______, KC_PENT
    // ),
};
