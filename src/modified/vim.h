// Check out https://support.apple.com/en-us/HT201236 for shortcuts
//
// Ideas: :q, :w, .
// viw -> char right, word left, shift word right

#define KEY_DOWN(keycode) register_code16(keycode)
#define KEY_UP(keycode) unregister_code16(keycode)

void TAP(uint16_t keycode) {
  KEY_DOWN(keycode);
  KEY_UP(keycode);
}

void CMD(uint16_t keycode) {
  KEY_DOWN(KC_LGUI);
  TAP(keycode);
  KEY_UP(KC_LGUI);
}

void CTRL(uint16_t keycode) {
  KEY_DOWN(KC_LCTRL);
  TAP(keycode);
  KEY_UP(KC_LCTRL);
}

void SHIFT(uint16_t keycode) {
  KEY_DOWN(KC_LSHIFT);
  TAP(keycode);
  KEY_UP(KC_LSHIFT);
}

void OPT(uint16_t keycode) {
  KEY_DOWN(KC_LALT);
  TAP(keycode);
  KEY_UP(KC_LALT);
}

enum vim_modes {
  VIM_NORMAL_MODE,
  VIM_VISUAL_MODE,
};

enum vim_modes vim_mode = VIM_NORMAL_MODE;

bool vim_in_normal_mode(void) {
  return vim_mode == VIM_NORMAL_MODE;
}

bool vim_in_visual_mode(void) {
  return vim_mode == VIM_VISUAL_MODE;
}

void vim_normal_mode_activate(void) {
  if (vim_in_visual_mode()) {
    unregister_code16(KC_LSHIFT);
  }
  vim_mode = VIM_NORMAL_MODE;
}

void vim_visual_mode_activate(void) {
  if (!vim_in_visual_mode()) {
    register_code16(KC_LSHIFT);
  }
  vim_mode = VIM_VISUAL_MODE;
}

enum vim_prefixes {
  VIM_NO_PREFIX,
  VIM_PREFIX_D,
  VIM_PREFIX_G,
};

enum vim_prefixes vim_prefix = VIM_NO_PREFIX;

void vim_clear_prefix(void) {
  vim_prefix = VIM_NO_PREFIX;
}

void vim_set_prefix(enum vim_prefixes prefix) {
  vim_prefix = prefix;
}

bool vim_has_any_prefix(void) {
  return vim_prefix != VIM_NO_PREFIX;
}

bool vim_has_prefix(enum vim_prefixes prefix) {
  return vim_prefix == prefix;
}

enum vim_modifiers {
  VIM_NO_MODIFIERS = 0,
  VIM_MODIFIER_LEFT_SHIFT = 1,
  VIM_MODIFIER_RIGHT_SHIFT = 2,
  VIM_MODIFIER_LEFT_CTRL = 4,
  VIM_MODIFIER_RIGHT_CTRL = 8,
};

enum vim_modifiers vim_modifiers = VIM_NO_MODIFIERS;

void vim_modifier_down(enum vim_modifiers modifier) {
  vim_modifiers = vim_modifiers | modifier;
}

void vim_modifier_up(enum vim_modifiers modifier) {
  vim_modifiers = vim_modifiers & ~modifier;
}

bool vim_has_modifier(enum vim_modifiers modifier) {
  return vim_modifiers & modifier;
}

void vim_clear_modifiers(void) {
  vim_modifiers = VIM_NO_MODIFIERS;
}

void vim_no_op(void) {

}

void (*vim_function_to_repeat)(void) = &vim_no_op;

void vim_repeat(void) {
  (*vim_function_to_repeat)();
}

/**
 * Simulates vim's `X` and `dh` command by sending BSPACE.
 */
void vim_backspace(void) {
  TAP(KC_BSPACE);
  vim_function_to_repeat = &vim_backspace;
}

/**
 * Simulates vim's `y` command by sending ⌘C
 */
void vim_copy(void) {
  CMD(KC_C);
}

/**
 * Simulates vim's `x` command by sending ⌘X.
 */
void vim_cut(void) {
  CMD(KC_X);
}

/**
 * Simulates vim's `x` and `dl` command by sending DELETE.
 */
void vim_delete(void) {
  TAP(KC_DELETE);
  vim_function_to_repeat = &vim_delete;
}

/**
 * Simulates vim's `d0` command by sending ⌘⌫
 */
void vim_delete_to_beginning_of_line(void) {
  CMD(KC_BSPACE);
  vim_function_to_repeat = &vim_delete_to_beginning_of_line;
}

/**
 * Simulates vim's `db` command by sending ⌥⌫
 */
void vim_delete_to_beginning_of_word(void) {
  OPT(KC_BSPACE);
  vim_function_to_repeat = &vim_delete_to_beginning_of_word;
}

/**
 * Simulates vim's `d$` command by sending ⌘⌦
 */
void vim_delete_to_end_of_line(void) {
  CMD(KC_DELETE);
  vim_function_to_repeat = &vim_delete_to_end_of_line;
}

/**
 * Simulates vim's `de` command by sending ⌥⌦
 */
void vim_delete_to_end_of_word(void) {
  OPT(KC_DELETE);
  vim_function_to_repeat = &vim_delete_to_end_of_word;
}

/**
 * Sends ↓
 */
void vim_move_down(void) {
  TAP(KC_DOWN);
}

/**
 * Sends ←
 */
void vim_move_left(void) {
  TAP(KC_LEFT);
}

/**
 * Simulates vim's `^D` command by sending PgDn
 */
void vim_move_page_down(void) {
  TAP(KC_PGDN);
}

/**
 * Simulates vim's `^U` command by sending PgUp
 */
void vim_move_page_up(void) {
  TAP(KC_PGUP);
}

/**
 * Sends →
 */
void vim_move_right(void) {
  TAP(KC_RIGHT);
}

/**
 * Simulates vim's `gg` by sending ⌘↑
 */
void vim_move_to_beginning_of_document(void) {
  CMD(KC_UP);
}

/**
 * Simulates vim's `0` command by sending ⌘←.
 */
void vim_move_to_beginning_of_line(void) {
  CMD(KC_LEFT);
}

/**
 * Simulates vim's `b` command by sending ⌥←
 */
void vim_move_to_beginning_of_word(void) {
  OPT(KC_LEFT);
}

/**
 * Simulates vim's `G` command by sending ⌘↓
 */
void vim_move_to_end_of_document(void) {
  CMD(KC_DOWN);
}

/**
 * Simulates vim's `$` command by sending ⌘→
 */
void vim_move_to_end_of_line(void) {
  CMD(KC_RIGHT);
}

/**
 * Simulates vim's `e` command by sending ⌥→
 */
void vim_move_to_end_of_word(void) {
  OPT(KC_RIGHT);
}

/**
 * Sends ↑
 */
void vim_move_up(void) {
  TAP(KC_UP);
}

/**
 * Simulates vim's `p` command by sending ⌘V
 */
void vim_paste(void) {
  CMD(KC_V);
  vim_function_to_repeat = &vim_backspace;
}

/**
 * Simulates vim's `^r` command by sending ⌘⇧Z
 */
void vim_redo(void) {
  KEY_DOWN(KC_LSHIFT);
  CMD(KC_Z);
  KEY_UP(KC_LSHIFT);
}

/**
 * Simulates vim's `u` command by sending ⌘Z
 */
void vim_undo(void) {
  CMD(KC_Z);
}
