#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"
#include "keymap_croatian.h"
#include "keymap_turkish_q.h"
#include "keymap_slovak.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,

  VIM_0,
  VIM_4,
  VIM_B,
  VIM_C,
  VIM_D,
  VIM_E,
  VIM_G,
  VIM_H,
  VIM_J,
  VIM_K,
  VIM_L,
  VIM_P,
  VIM_PERIOD,
  VIM_R,
  VIM_U,
  VIM_V,
  VIM_X,
  VIM_Y,
  VIM_LSHIFT,
  VIM_RSHIFT,
  VIM_LCTRL,
  VIM_ESC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    LT(3,KC_TAB),   KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           LT(5,KC_BSPACE),
    LT(2,KC_ESCAPE),MT(MOD_LSFT, KC_A),MT(MOD_LCTL, KC_S),MT(MOD_LALT, KC_D),MT(MOD_LGUI, KC_F),KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           MT(MOD_RGUI, KC_J),MT(MOD_RALT, KC_K),MT(MOD_RCTL, KC_L),MT(MOD_RSFT, KC_SCOLON),LT(1,KC_ENTER), 
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSHIFT,      
    KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_LEFT,        KC_RIGHT,       KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_UP,          KC_DOWN,        KC_LBRACKET,    KC_RBRACKET,    KC_EQUAL,       
    MO(6),          MO(7),          KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE
  ),
  [1] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_QUOTE,       KC_LABK,        KC_RABK,        KC_DQUO,        KC_PERC,        KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_EXLM,        KC_MINUS,       KC_PLUS,        KC_EQUAL,       KC_HASH,        KC_NO,                                                                          KC_NO,          KC_NO,          KC_RGUI,        KC_RALT,        KC_RCTRL,       KC_RSHIFT,      KC_TRANSPARENT, 
    KC_NO,          KC_CIRC,        KC_SLASH,       KC_ASTR,        KC_BSLASH,      KC_AT,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_RSHIFT,      
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_NO,                          KC_NO,          KC_NO,          KC_NO
  ),
  [2] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_TILD,        KC_AMPR,        KC_LPRN,        KC_RPRN,        KC_UNDS,        KC_BSPACE,      
    KC_TRANSPARENT, KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_NO,          KC_NO,                                                                          KC_NO,          KC_GRAVE,       KC_PIPE,        KC_LCBR,        KC_RCBR,        KC_COLN,        KC_ENTER,       
    KC_LSHIFT,      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_DLR,         KC_LBRACKET,    KC_RBRACKET,    KC_QUES,        KC_RSHIFT,      
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,                          KC_NO,          KC_NO,          KC_NO
  ),
  [3] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_HOME,        KC_PGDOWN,      KC_PGUP,        KC_END,         KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,                          KC_NO,          KC_NO,          TO(4)
  ),
  [4] = LAYOUT_moonlander(
    KC_NO, KC_NO, KC_NO, KC_NO, VIM_4, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, VIM_0, KC_NO, 
    KC_NO, KC_NO, KC_NO, VIM_E, VIM_R, KC_NO, KC_NO, KC_NO, VIM_Y, VIM_U, KC_NO, KC_NO, VIM_P, KC_NO,
    VIM_ESC, VIM_LSHIFT, VIM_LCTRL, VIM_D, KC_NO, VIM_G, KC_NO, KC_NO, VIM_H, VIM_J, VIM_K, VIM_L, VIM_RSHIFT, KC_NO, 
    VIM_LSHIFT, KC_NO, VIM_X, VIM_C, VIM_V, VIM_B, KC_NO, KC_NO, KC_NO, KC_NO, VIM_PERIOD, VIM_RSHIFT,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  ),
  [5] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    CAPS_WORD,      OSM(MOD_LSFT),  OSM(MOD_LCTL),  OSM(MOD_LALT),  OSM(MOD_LGUI),  KC_NO,          KC_NO,                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    OSM(MOD_LSFT),  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_TRANSPARENT, KC_NO,                          KC_NO,          KC_NO,          KC_NO
  ),
  [6] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_MINUS,    KC_KP_PLUS,     
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_KP_0,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_SLASH,    KC_KP_ASTERISK, 
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_KP_DOT,      KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_EQUAL,       KC_PERC,        
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_NO,                          KC_NO,          KC_NO,          KC_NO
  ),
  [7] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_NO,          KC_F4,          KC_F5,          KC_F6,          KC_F11,         KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F12,         KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_TRANSPARENT, KC_NO,                          KC_NO,          KC_NO,          TO(8)
  ),
  [8] = LAYOUT_moonlander(
    RESET,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_NO,          
    TO(0),          KC_LSHIFT,      KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_NO,          KC_NO,                                                                          KC_NO,          KC_NO,          KC_F4,          KC_F5,          KC_F6,          KC_F11,         KC_NO,          
    KC_LSHIFT,      KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F12,         KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                                                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,                          KC_NO,          KC_NO,          KC_NO
  ),
};

// For dual VIM_L and VIM_RCTRL:
uint16_t time_since_last_vim_ctrl_right_down = 0;
uint16_t vim_last_keycode = KC_NO;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool shifted = vim_has_modifier(VIM_MODIFIER_LEFT_SHIFT | VIM_MODIFIER_RIGHT_SHIFT);
  bool left_ctrled = vim_has_modifier(VIM_MODIFIER_LEFT_CTRL);
  bool ctrled = vim_has_modifier(VIM_MODIFIER_LEFT_CTRL | VIM_MODIFIER_RIGHT_CTRL);
  bool result = true;

  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      vim_clear_prefix();
      result = false;
      break;
    case VIM_0:
      if (record->event.pressed && !shifted && !ctrled) {
        if (vim_has_prefix(VIM_PREFIX_D)) {
          vim_delete_to_beginning_of_line();
        } else if (!vim_has_any_prefix()) {
          vim_move_to_beginning_of_line();
        }
      }
      vim_clear_prefix();
      result = false;
      break;
    case VIM_4:
      if (record->event.pressed && shifted && !ctrled) {
        if (vim_has_prefix(VIM_PREFIX_D)) {
          vim_delete_to_end_of_line(); 
        } else if (!vim_has_any_prefix()) {
          vim_move_to_end_of_line();
        }
      }
      vim_clear_prefix();
      result = false;
      break;
    case VIM_B:
      if (record->event.pressed && !shifted && !ctrled) {
        if (vim_has_prefix(VIM_PREFIX_D)) {
          vim_delete_to_beginning_of_word();
        } else if (!vim_has_any_prefix()) {
          vim_move_to_beginning_of_word();
        }
      }
      vim_clear_prefix();
      result = false;
      break;
    case VIM_D:
      if (record->event.pressed) {
        if (!shifted && !ctrled) {
          if (vim_has_any_prefix()) {
            vim_clear_prefix();
          } else if (vim_in_visual_mode()) {
            vim_delete();
            vim_clear_prefix();
            vim_normal_mode_activate();
          } else {
            vim_set_prefix(VIM_PREFIX_D);
          }
        } else if (!shifted && ctrled) {
          if (!vim_has_any_prefix()) {
            vim_move_page_down();
          }
          vim_clear_prefix();
        }
      }
      result = false;
      break;
    case VIM_E:
      if (record->event.pressed && !shifted && !ctrled) {
        if (vim_has_prefix(VIM_PREFIX_D)) {
          vim_delete_to_end_of_word();
        } else if (!vim_has_any_prefix()) {
          vim_move_to_end_of_word();
        }
      }
      vim_clear_prefix();
      result = false;
      break;
    case VIM_G:
      if (record->event.pressed) {
        if (shifted && !ctrled) {
          if (!vim_has_any_prefix()) {
            vim_move_to_end_of_document();
          }
          vim_clear_prefix();
        } else if (!shifted && !ctrled) {
          if (vim_has_prefix(VIM_PREFIX_D)) {
            vim_clear_prefix();
          } else if (vim_has_prefix(VIM_PREFIX_G)) {
            vim_move_to_beginning_of_document();
            vim_clear_prefix();
          } else if (!vim_has_any_prefix()) {
            vim_set_prefix(VIM_PREFIX_G);
          }
        }
      }
      result = false;
      break;
    case VIM_H:
      if (record->event.pressed && !shifted && !ctrled) {
        if (vim_has_prefix(VIM_PREFIX_D)) {
          vim_backspace();
        } else if (!vim_has_any_prefix()) {
          vim_move_left();
        }
      }
      vim_clear_prefix();
      result = false;
      break;
    case VIM_J:
      if (record->event.pressed && !shifted && !ctrled) {
        if (!vim_has_any_prefix()) {
          vim_move_down();
        }
      }
      vim_clear_prefix();
      result = false;
      break;
    case VIM_K:
      if (record->event.pressed && !shifted && !ctrled) {
        if (!vim_has_any_prefix()) {
          vim_move_up();
        }
      }
      vim_clear_prefix();
      result = false;
      break;
    case VIM_L:
      if (record->event.pressed) {
        // When pressed, first emulate modifier.
        vim_modifier_down(VIM_MODIFIER_RIGHT_CTRL);
        
        // Start timer.
        time_since_last_vim_ctrl_right_down = timer_read();
      } else {
        // release modifier.
        vim_modifier_up(VIM_MODIFIER_RIGHT_CTRL);

        // Check if we need to send original key.
        if (timer_elapsed(time_since_last_vim_ctrl_right_down) < 200 && vim_last_keycode == VIM_L && !shifted && !left_ctrled) {
          if (vim_has_prefix(VIM_PREFIX_D)) {
            vim_delete();
          } else if (!vim_has_any_prefix()) {
            vim_move_right();
          }
          vim_clear_prefix();
        }
      }
      result = false;
      break;
    case VIM_P:
      if (record->event.pressed && !shifted && !ctrled) {
        if (!vim_has_any_prefix()) {
          vim_paste();
          vim_normal_mode_activate();
        }
      }
      vim_clear_prefix();
      result = false;
      break;
    case VIM_PERIOD:
      if (record->event.pressed && !shifted && !ctrled) {
        if (!vim_has_any_prefix() && vim_in_normal_mode()) {
          vim_repeat();
        }
      }
      vim_clear_prefix();
      result = false;
      break;
    case VIM_R:
      if (record->event.pressed && !shifted && ctrled) {
        if (!vim_has_any_prefix() && vim_in_normal_mode()) {
          vim_redo();
        }
      }
      vim_clear_prefix();
      result = false;
      break;
    case VIM_U:
      if (record->event.pressed) {
        if (!shifted && ctrled) {
          if (!vim_has_any_prefix()) {
            vim_move_page_up();
          }
        } else if (!shifted && !ctrled) {
          if (!vim_has_any_prefix() && vim_in_normal_mode()) {
            vim_undo();
          }
        }
      }
      vim_clear_prefix();
      result = false;
      break;
    case VIM_V:
      if (record->event.pressed && !shifted && !ctrled) {
        if (!vim_has_any_prefix() && vim_in_normal_mode()) {
          vim_visual_mode_activate();
        }
      }
      vim_clear_prefix();
      result = false;
      break;
    case VIM_X:
      if (record->event.pressed) {
        if (shifted && !ctrled) {
          if (!vim_has_any_prefix() && vim_in_normal_mode()) {
            vim_backspace();
          }
        } else if (!shifted && !ctrled) {
          if (!vim_has_any_prefix()) {
            if (vim_in_visual_mode()) {
              vim_cut();
              vim_normal_mode_activate();
            } else {
              vim_delete();
            }
          }
        }
      }
      vim_clear_prefix();
      result = false;
      break;  
    case VIM_Y:
      if (record->event.pressed && !shifted && !ctrled) {
        if (!vim_has_any_prefix() && vim_in_visual_mode()) {
          vim_copy();
          vim_normal_mode_activate();
        }
      }
      vim_clear_prefix();
      result = false;
      break;
    case VIM_LSHIFT:
      if (record->event.pressed) {
        vim_modifier_down(VIM_MODIFIER_LEFT_SHIFT);
      } else {
        vim_modifier_up(VIM_MODIFIER_LEFT_SHIFT);
      }
      result = false;
      break;
    case VIM_RSHIFT:
      if (record->event.pressed) {
        vim_modifier_down(VIM_MODIFIER_RIGHT_SHIFT);
      } else {
        vim_modifier_up(VIM_MODIFIER_RIGHT_SHIFT);
      }
      result = false;
      break;
    case VIM_LCTRL:
      if (record->event.pressed) {
        vim_modifier_down(VIM_MODIFIER_LEFT_CTRL);
      } else {
        vim_modifier_up(VIM_MODIFIER_LEFT_CTRL);
      }
      result = false;
      break;
    case VIM_ESC:
      if (record->event.pressed && !shifted && !ctrled) {
        if (vim_has_any_prefix()) {
          vim_clear_prefix();
        } else if (vim_in_visual_mode()) {
          vim_normal_mode_activate();
        } else {
          layer_clear();
        }
      }
      result = false;
      break;
    default:
      vim_clear_prefix();
      break;
  }
  vim_last_keycode = keycode;
  return result;
}


