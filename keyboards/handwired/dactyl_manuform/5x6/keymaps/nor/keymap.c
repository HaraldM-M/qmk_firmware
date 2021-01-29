/* A Swedish XMonad layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H
#include "keymap_nordic.h"
#include "keymap_swedish.h"

enum dactyl_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
};

#define RAISE  MO(_RAISE)
#define LOWER  MO(_LOWER)
#define TERM   LGUI(LSFT(KC_ENT))
#define ALTTAB LGUI(KC_TAB)
#define KILL   LGUI(LSFT(KC_C))
#define OPEN   LGUI(KC_P)
#define KC_QSM LSFT(SE_PLUS)
#define KC_AA  SE_AA
#define KC_AE  SE_AE
#define KC_OE  SE_OSLH

#define NO_QUES LSFT(NO_PLUS)
#define NO_HALF KC_GRV        // <  Rename?
#define NO_PLUS KC_MINS       // + ?
#define NO_ACUT KC_EQL        // Not tested
#define NO_AM KC_LBRC         // Not tested
#define NO_QUOT KC_RBRC       // Not tested // this is the "umlaut" char on Nordic keyboards, Apple layout
#define NO_OSLH KC_QUOT       // Not tested
#define NO_APOS KC_NUHS       // @ *
#define NO_LESS KC_NUBS       // Not tested
#define NO_MINS KC_SLSH       // -  _

//Custom
#define NO_RABK KC_TILD       // > <
#define NN_LCBR S(SE_LBRC)    // {
#define NN_RCBR S(SE_RBRC)    // }
#define NN_EURO ALGR(KC_NUBS) // € ¢

//TODO test with windows. This configuration was tested with macOS.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , NO_PLUS,
     KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_AA  ,
     KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                        KC_H   , KC_J   , KC_K   , KC_L   , KC_OE  , KC_AE  ,
     KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                        KC_N   , KC_M   , KC_COMM, KC_DOT , NO_MINS, NO_APOS,
                       SE_LBRC, SE_RBRC,                                                            NO_HALF, NO_RABK,
                                                  RAISE  , KC_SPC ,      KC_ENT , LOWER  ,
                                                  KC_DEL , KC_BSPC,      KC_RGUI, KC_RALT,
                                                  KC_LALT, KC_LGUI,      KC_RSFT, KC_RCTL
  ),

  [_LOWER] = LAYOUT_5x6(
     _______, _______, SE_LESS, _______, NN_EURO, _______,                        _______, _______, NO_LPRN, NO_RPRN, SE_RCBR, KC_F13 ,
     _______, _______, _______, _______, NO_PND , _______,                        _______, _______, SE_LBRC, SE_RBRC, _______, KC_VOLU,
     _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END , _______,                        _______, _______, NN_LCBR, NN_RCBR, _______, KC_VOLD,
     _______, _______, _______, _______, _______, _______,                        _______, KC_MPRV, KC_MPLY, KC_MNXT, NO_BSLS, KC_MUTE,
                       _______, _______,                                                            _______, _______,
                                                  _______, _______,      _______, _______,
                                                  _______, _______,      _______, _______,
                                                  _______, _______,      _______, _______
  ),

  [_RAISE] = LAYOUT_5x6(
     KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                        KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
     _______, _______, _______, _______, KC_F14 , KC_F15 ,                        KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 ,
     _______, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, _______,                        _______, _______, _______, _______, _______, _______,
     _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END , _______,                        _______, _______, _______, _______, _______, _______,
                       _______, _______,                                                            _______, _______,
                                                  _______, _______,      _______, _______,
                                                  _______, _______,      _______, _______,
                                                  _______, _______,      _______, _______

  ),
};