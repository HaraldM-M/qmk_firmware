/* A Norwegian layout for the Dactyl Manuform 5x6 Keyboard. With some support for both MacOS and Windows.*/

#include QMK_KEYBOARD_H
#include "keymap_nordic.h"
#include "keymap_swedish.h"

enum dactyl_layers {
  _MAC_QWERTY,
  _WIN_QWERTY,
  _LOWER_MAC,
  _RAISE_MAC,
  _LOWER_WIN,
  _RAISE_WIN,
};

#define RAISE_M  MO(_RAISE_MAC)
#define LOWER_M  MO(_LOWER_MAC)
#define RAISE_W  MO(_RAISE_WIN)
#define LOWER_W  MO(_LOWER_WIN)
#define SET_WIN DF(_WIN_QWERTY)
#define SET_MAC DF(_MAC_QWERTY)

#define TERM   LGUI(LSFT(KC_ENT))
#define ALTTAB LGUI(KC_TAB)
#define KILL   LGUI(LSFT(KC_C))
#define OPEN   LGUI(KC_P)
#define KC_QSM LSFT(SE_PLUS)
#define KC_AA  SE_AA
#define KC_AE  SE_AE
#define KC_OE  SE_OSLH

#define NO_QUES LSFT(NO_PLUS)  //duplicate, delere
#define NO_HALF KC_GRV        // mac: <  Rename? wrong?
#define NO_PLUS KC_MINS       // mac: + ? duplicate delete
#define NO_ACUT KC_EQL        // Test
#define NO_AM KC_LBRC         // Not tested
#define NO_QUOT KC_RBRC       // Not tested // this is the "umlaut" char on Nordic keyboards, Apple layout. Test
#define NO_OSLH KC_QUOT       // Not tested
#define NO_APOS KC_NUHS       // mac: @ *
#define NO_LESS KC_NUBS       // Delete?
#define NO_MINS KC_SLSH       // mac: -  _ duplicate

//Custom
#define RTAB S(KC_TAB)
#define MN_STAR S(NO_APOS)

//Custom MacOS Norwegian
#define MN_RABK KC_TILD       // > <
#define MN_LCBR S(SE_LBRC)    // {
#define MN_RCBR S(SE_RBRC)    // }
#define MN_EURO ALGR(KC_NUBS) // € ¢
#define MN_PLSM ALGR(NO_PLUS) // ± ¿
#define MN_CIRC S(KC_RCBR)    //^ ^   RALT(KC_RCBR) is also an alternative
#define MN_PIPB RALT(KC_7)    // | s: |  For consistency
#define MN_BSLS S(RALT(KC_7)) // \           !
#define MN_LABR KC_GRV        // < >

//Custom Windows Norwegian
#define WN_STAR KC_PIPE //* *
#define WN_BSLS KC_EQL //   \ !!!
#define WN_PIPE KC_GRV //   |
  //NO_PIPE has no output
  //LSFT(KC_4) -> Standard currency
  //RALT(KC_COMM) has no output
  //KC_GRV -> |
  //KC_EQL -> \ !!


/* TODO
  * Rename for consistency
  * remove unused and gather useful to one table
 */

//TODO Can't find correct code.
#define MN_TILD _______ //LSFT(KC_RBRC) blir bare ^//RALT(KC_GESC)  ble ingenting //RALT(KC_RCBR)   //TODO | s: \    , men blir bare ^

//Missing correct shifted value. Look to macro?
#define WN_AT NO_AT             //TODO @ s: *      Win at burde gi * ved shift.... macro necessary(?)
#define WN_BSL2 SE_LBRC         //TODO eventually. [ and {. Shift not working
#define WN_BSR2 SE_RBRC         //T55ODO eventually. ] and }. Shift not working

//TODO Impossible?
#define WN_PLSM _______        // ± ¿
#define WN_ABOU _______        // ≈ ≠
#define WN_EURO _______       //€ ¢



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_WIN_QWERTY] = LAYOUT_5x6(//                              Windows base layer
     KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , NO_PLUS,
     KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_AA  ,
     KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                        KC_H   , KC_J   , KC_K   , KC_L   , KC_OE  , KC_AE  ,
     KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                        KC_N   , KC_M   , KC_COMM, KC_DOT , NO_MINS, WN_AT  ,
                       WN_BSL2, WN_BSR2,                                                             SE_LABK, SE_RABK,
                                                  RAISE_W, KC_SPC ,      KC_ENT , LOWER_W,
                                                  KC_DEL , KC_BSPC,      KC_RCTL, KC_RALT,
                                                  KC_LALT, KC_LCTL,      KC_RSFT, KC_RGUI
  ),

  [_MAC_QWERTY] = LAYOUT_5x6(//                               MacOS base layer
     KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , NO_PLUS,
     KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_AA  ,
     KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                        KC_H   , KC_J   , KC_K   , KC_L   , KC_OE  , KC_AE  ,
     KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                        KC_N   , KC_M   , KC_COMM, KC_DOT , NO_MINS, NO_APOS,
                       SE_LBRC, SE_RBRC,                                                            MN_LABR, MN_RABK,
                                                  RAISE_M, KC_SPC ,      KC_ENT , LOWER_M,
                                                  KC_DEL , KC_BSPC,      KC_RGUI, KC_RALT,
                                                  KC_LALT, KC_LGUI,      KC_RSFT, KC_RCTL
  ),

  [_LOWER_WIN] = LAYOUT_5x6(//                             Windows lowered layer
     _______, _______, NO_APOS, _______, WN_EURO, KC_F13 ,                        NO_CIRC, S(KC_7), NO_LPRN, NO_RPRN, WN_ABOU, WN_PLSM,
     RTAB   , _______, _______, _______, NO_PND , KC_VOLU,                        _______, WN_PIPE, NO_LBRC, NO_RBRC, _______, KC_VOLU,
     _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END , KC_VOLD,                        _______, WN_BSLS, NO_LCBR, NO_RCBR, _______, KC_VOLD,
     _______, _______, _______, _______, _______, KC_MUTE,                        _______, KC_MPRV, KC_MPLY, KC_MNXT, NO_TILD, WN_STAR,
                       _______, _______,                                                            _______, _______,
                                                  _______, _______,      _______, _______,
                                                  _______, KC_DEL ,      _______, _______,
                                                  _______, _______,      _______, _______
  ),

  [_RAISE_WIN] = LAYOUT_5x6(//                              Windows raised layer
     KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                        KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
     RTAB   , _______, _______, _______, KC_F14 , KC_VOLU,                        KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 ,
     _______, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, KC_VOLD,                        _______, _______, _______, _______, _______, _______,
     _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END , KC_MUTE,                        _______, _______, _______, _______, _______, NO_APOS,
                       _______, _______,                                                            _______, _______,
                                                  _______, _______,      _______, _______,
                                                  _______, KC_DEL ,      _______, _______,
                                                  _______, _______,      SET_MAC, _______

  ),

  [_LOWER_MAC] = LAYOUT_5x6(//                              MacOS lowered layer
     _______, _______, SE_LESS, _______, MN_EURO, KC_F13 ,                        MN_CIRC, S(KC_7), NO_LPRN, NO_RPRN, SE_RCBR, MN_PLSM,
     RTAB   , _______, _______, _______, NO_PND , KC_VOLU,                        _______, MN_PIPB, SE_LBRC, SE_RBRC, _______, KC_VOLU,
     _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END , KC_VOLD,                        _______, MN_BSLS, MN_LCBR, MN_RCBR, _______, KC_VOLD,
     _______, _______, _______, _______, _______, KC_MUTE,                        _______, KC_MPRV, KC_MPLY, KC_MNXT, MN_TILD, MN_STAR,
                       _______, _______,                                                            _______, _______,
                                                  _______, _______,      _______, _______,
                                                  _______, KC_DEL ,      _______, _______,
                                                  _______, _______,      _______, _______
  ),

  [_RAISE_MAC] = LAYOUT_5x6(//                               MacOs raised layer
     KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                        KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
     RTAB   , _______, _______, _______, KC_F14 , KC_VOLU,                        KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 ,
     _______, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, KC_VOLD,                        _______, _______, _______, _______, _______, _______,
     _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END , KC_MUTE,                        _______, _______, _______, _______, _______, _______,
                       _______, _______,                                                            _______, _______,
                                                  _______, _______,      _______, _______,
                                                  _______, KC_DEL ,      _______, _______,
                                                  _______, _______,      SET_WIN, _______

  ),
};


//Definitions from atreus62
/*
#define  NO_AE    KC_QUOT     //  Æ
#define  NO_AO    KC_LBRC     //  Å
#define  NO_BSLS  KC_EQL      //  Backslash
#define  NO_LT    KC_NUBS     //  <
#define  NO_MINS  KC_SLSH     //  -
#define  NO_OE    KC_SCLN     //  Ø
#define  NO_PIPE  KC_GRV      //  |
#define  NO_PLUS  KC_MINS     //  +
#define  NO_QUOT  KC_NUHS     //  '
#define  NO_UMLA  KC_RBRC     //  ¨
//Norwegian - Modifier dependant definitions
#define  NO_EXLM  LSFT(KC_1)        //  !
#define  NO_DQT   LSFT(KC_2)        //  "
#define  NO_AT    RALT(KC_2)        //  @
#define  NO_HASH  LSFT(KC_3)        //  #
#define  NO_EUR   LSFT(KC_4)        //  €
#define  NO_DLR   RALT(KC_4)        //  $
#define  NO_PERC  LSFT(KC_5)        //  %
#define  NO_AND   LSFT(KC_6)        //  &
#define  NO_SLSH  LSFT(KC_7)        //  /
#define  NO_PO    LSFT(KC_8)        //  (
#define  NO_PC    LSFT(KC_9)        //  )
#define  NO_EQL   LSFT(KC_0)        //  =
#define  NO_LCBR  RALT(KC_7)        //  {
#define  NO_LBRC  RALT(KC_8)        //  [
#define  NO_RBRC  RALT(KC_9)        //  ]
#define  NO_RCBR  RALT(KC_0)        //  }
#define  NO_COLN  LSFT(KC_DOT)      //  :
#define  NO_SCLN  LSFT(KC_COMM)     //  ;
#define  NO_MU    RALT(KC_M)        //  µ
#define  NO_EURO  RALT(KC_E)        //  €
#define  NO_SECT  LSFT(KC_GRV)      //  §
#define  NO_GERC  RALT(KC_COMM)     //  ¸
#define  NO_QUAR  LSFT(RALT(KC_4))  //  ¼
//Norwegian layout - dependant on previous definitions
#define  NO_UNDS  LSFT(NO_MINS)  //  _
#define  NO_QUES  LSFT(NO_PLUS)  //  ?
#define  NO_ACUT  RALT(NO_BSLS)  //  Acute
#define  NO_GRAV  LSFT(NO_BSLS)  //  `
#define  NO_GT    LSFT(NO_LT)    //  >
#define  NO_HALF  RALT(NO_LT)    //  ½
#define  NO_HAT   LSFT(NO_UMLA)  //  ^
#define  NO_ASTR  LSFT(NO_QUOT)  //  *
#define  NO_TILD  RALT(NO_UMLA)  //  ~
*/
