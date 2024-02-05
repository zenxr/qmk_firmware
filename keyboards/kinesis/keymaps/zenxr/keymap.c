#include QMK_KEYBOARD_H

#define QWERTY 0 // Base qwerty
#define LAYER_1 1

// https://jasoncarloscox.com/writing/combo-mods/
// define combo names
enum combos {
    COMBO_LCTL,
    COMBO_LSUP,
    COMBO_LCTLSUP,
    COMBO_LALT,
    COMBO_LALTCTL,
    COMBO_LALTSUP,
    COMBO_LALTSUPCTL,

    COMBO_RCTL,
    COMBO_RSUP,
    COMBO_RCTLSUP,
    COMBO_RALT,
    COMBO_RALTCTL,
    COMBO_RALTSUP,
    COMBO_RALTSUPCTL,

    COMBO_LENGTH // nifty trick to avoid manually specifying how many combos you have
};

uint16_t COMBO_LEN = COMBO_LENGTH; // nifty trick continued

// define keys that make up combos
const uint16_t PROGMEM fd_combo[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM fs_combo[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM fsd_combo[] = {KC_F, KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM fa_combo[] = {KC_F, KC_A, COMBO_END};
const uint16_t PROGMEM fad_combo[] = {KC_F, KC_A, KC_D, COMBO_END};
const uint16_t PROGMEM fas_combo[] = {KC_F, KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM fasd_combo[] = {KC_F, KC_A, KC_S, KC_D, COMBO_END};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM jl_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM jlk_combo[] = {KC_J, KC_L, KC_K, COMBO_END};
const uint16_t PROGMEM jsemi_combo[] = {KC_J, KC_SEMICOLON, COMBO_END};
const uint16_t PROGMEM jsemik_combo[] = {KC_J, KC_SEMICOLON, KC_K, COMBO_END};
const uint16_t PROGMEM jsemil_combo[] = {KC_J, KC_SEMICOLON, KC_L, COMBO_END};
const uint16_t PROGMEM jsemilk_combo[] = {KC_J, KC_SEMICOLON, KC_K, KC_L, COMBO_END};

// map combo names to their keys and the key they trigger
combo_t key_combos[] = {
    [COMBO_LCTL] = COMBO(fd_combo, KC_LCTL),
    [COMBO_LSUP] = COMBO(fs_combo, KC_LGUI),
    [COMBO_LCTLSUP] = COMBO(fsd_combo, LCTL(KC_LGUI)),
    [COMBO_LALT] = COMBO(fa_combo, KC_LALT),
    [COMBO_LALTCTL] = COMBO(fad_combo, LCTL(KC_LALT)),
    [COMBO_LALTSUP] = COMBO(fas_combo, LALT(KC_LGUI)),
    [COMBO_LALTSUPCTL] = COMBO(fasd_combo, LCA(KC_LGUI)),

    [COMBO_RCTL] = COMBO(jk_combo, KC_RCTL),
    [COMBO_RSUP] = COMBO(jl_combo, KC_RGUI),
    [COMBO_RCTLSUP] = COMBO(jlk_combo, LCTL(KC_RGUI)),
    [COMBO_RALT] = COMBO(jsemi_combo, KC_RALT),
    [COMBO_RALTCTL] = COMBO(jsemil_combo, RALT(KC_RGUI)),
    [COMBO_RALTSUP] = COMBO(jsemik_combo, RCTL(KC_RALT)),
    [COMBO_RALTSUPCTL] = COMBO(jsemilk_combo, LCA(KC_RGUI)),
};

/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 |  BOOT  |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+--------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_     |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+--------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"     |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+--------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift  |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+--------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY] = LAYOUT(
           KC_CAPS, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
           KC_ESC, KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,
           KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
                   KC_GRV ,KC_INS ,KC_LEFT,KC_RGHT,
			   KC_LCTL,KC_LALT,
                                    LT(1,KC_HOME),
                           KC_BSPC,KC_DEL ,KC_END ,
    KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SCRL  ,KC_PAUS, KC_NO, QK_BOOT,
	KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
	KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
	KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
	KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
		KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
           KC_RGUI,KC_RCTL,
           KC_PGUP,
           KC_PGDN,KC_ENTER ,KC_SPC
    ),
[LAYER_1] = LAYOUT(
           DM_REC1, DM_PLY1 ,KC_TRNS ,KC_TRNS ,KC_TRNS    ,KC_TRNS ,KC_TRNS  ,KC_TRNS  ,KC_TRNS,
           KC_TRNS, KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS    ,KC_TRNS ,
           KC_TRNS, KC_WH_L ,KC_MS_U ,KC_WH_R ,KC_MS_BTN2 ,KC_WH_U ,
           KC_TRNS, KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_MS_BTN1 ,KC_WH_D ,
           KC_TRNS, KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS    ,KC_TRNS ,
                    KC_TRNS ,KC_TRNS ,KC_TRNS,KC_TRNS,
                    KC_TRNS,KC_TRNS,
                                    KC_TRNS,
                           KC_TRNS,KC_TRNS ,KC_TRNS ,
    KC_VOLD ,KC_VOLU ,KC_TRNS ,KC_TRNS   ,KC_TRNS ,KC_TRNS ,KC_TRNS, KC_TRNS, QK_BOOT,
    KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS   ,KC_TRNS ,KC_TRNS,
    KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS   ,KC_TRNS ,KC_TRNS,
    KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT  ,KC_TRNS, KC_TRNS,
    KC_TRNS ,KC_TRNS ,KC_TRNS,KC_TRNS ,KC_TRNS,KC_TRNS,
        KC_TRNS  ,KC_TRNS,KC_TRNS,KC_TRNS,
           KC_TRNS,KC_TRNS,
           KC_TRNS,
           KC_TRNS,KC_TRNS ,KC_TRNS
    )
};
