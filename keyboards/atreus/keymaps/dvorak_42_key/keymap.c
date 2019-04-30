
#include QMK_KEYBOARD_H

#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250

// layers
#define BASE      0
#define KEYNAV    1
#define KEYSEL    2
#define COMBINED  3
#define BROWSER_CONTROL 4

// aliases
#define ALTENT ALT_T(KC_ENT)
// shell
#define SHELL_DEL_WORD RCTL(KC_W)
// android studio

#define AS_TABLEFT LALT(KC_LEFT)
#define AS_TABRIGHT LALT(KC_RIGHT)
#define AS_SYMBOL LCTL(LALT(KC_N))
#define AS_CLASS LCTL(KC_N)
#define AS_FINDUSAGE LALT(KC_F7)
#define AS_BACK LCTL(LALT(KC_LEFT))
#define AS_GO_DECLARATION LCTL(KC_B)
#define AS_GO_IMPLEMENTATION LCTL(LALT(KC_B))
#define AS_CLOSETAB LCTL(KC_F4)
#define AS_CLOSETOOLWINDOW LCTL(LSFT(KC_F4))

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here

  // Cloud9 macros
  CLOUD9_TAB_LEFT,
  CLOUD9_TAB_RIGHT,
  CLOUD9_TAB_CLOSE,
  CLOUD9_GOTO_SYMBOL,
  CLOUD9_GOTO_LINE,
  CLOUD9_NAVIGATE,

};

// building instructions:
// make atreus:dvorak_42_key

// flashing instructions:
// avrdude -p atmega32u4 -c avr109 -U flash:w:atreus_dvorak_42_key.hex  -P COM7

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    KC_Q,          KC_F,          KC_W,       KC_P,                KC_G,                                 KC_J,       KC_L,      KC_U,    KC_Y,          KC_SCLN,
    KC_A,          KC_R,          KC_S,       KC_T,                KC_D,                                 KC_H,       KC_N,      KC_E,    KC_I,          KC_O,
    KC_Z,    	   KC_X,          KC_C,       KC_V,                KC_B,                                 KC_K,       KC_M,      KC_COMMA,KC_DOT,        KC_SLASH,
    OSM(MOD_LSFT), OSM(MOD_LCTL), MO(KEYSEL), MO(BROWSER_CONTROL), MO(COMBINED), MO(KEYNAV), ALTENT,   KC_SPACE,  KC_BSPC, RCTL(KC_BSPC), KC_LEAD, OSM(MOD_LSFT)
  ),

    /*
    ┌─────┬─────┬─────┬─────┬─────┐              ┌─────┬─────┬─────┬─────┬─────┐
    │ "   │ <   │ >   │ P   │ G   │              │ J   │ L   │ U   │ Y   │ F   │
    ├─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┤
    │ A   │ R   │ S   │ T   │ D   │              │ H   │ N   │ E   │ I   │ O   │
    ├─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┤
    │ Z   │ X   │ C   │ V   │ B   ├────┐    ┌────┤ K   │ M   │ Q   │ W   │ ;   │
    ├─────┼─────┼─────┼─────┼─────┤    │    │ALT/├─────┼─────┼─────┼─────┼─────┤
    │SHIFT│CTRL │KYSEL│BRO_C│COMBI│KEYN│    │ENT │SPACE│B-SPC│c-B-S│CAPS │SHIFT│
    └─────┴─────┴─────┴─────┴─────┴────┘    └────┴─────┴─────┴─────┴─────┴─────┘
  */


  [KEYNAV] = LAYOUT(
    KC_ESC,             AS_GO_IMPLEMENTATION,  RCTL(KC_Z),      RCTL(KC_S),       MEH(KC_A),                           MEH(KC_B),     KC_HOME,    KC_UP,           KC_END,     KC_PGUP,
    AS_BACK,            AS_SYMBOL,             RSFT(KC_TAB),    KC_TAB,           SHELL_DEL_WORD,                      LCTL(KC_LEFT), KC_LEFT,    KC_DOWN,         KC_RIGHT,   LCTL(KC_RIGHT),
    AS_FINDUSAGE,       AS_CLASS,              AS_TABLEFT,      AS_TABRIGHT,      AS_CLOSETAB,                         _______,       RCTL(KC_C), RCTL(KC_X),      RCTL(KC_V), KC_PGDOWN,
    AS_CLOSETOOLWINDOW, AS_GO_DECLARATION,     _______,         _______,          _______,          _______, KC_ENTER, KC_SPACE,      KC_BSPC,    RCTL(KC_BSPC),   KC_DELETE,  LCTL(KC_DELETE)
  ),

    /*
    ┌─────┬─────┬─────┬─────┬─────┐              ┌─────┬─────┬─────┬─────┬─────┐
    │ESC  │ ?   │ctl-Z│ctl-S│MEH-a│              │MEH-b│HOME │  ↑  │END  │PG-↑ │
    ├─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┤
    │ ?   │ ?   │s-TAB│TAB  │ ?   │              │ctl ←│  ←  │  ↓  │  →  │ctl →│
    ├─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┤
    │ ?   │ ?   │ ?   │ ?   │ ?   ├────┐    ┌────┤_____│ctl-C│ctl-X│ctl-V│PG-↓ │
    ├─────┼─────┼─────┼─────┼─────┤    │    │    ├─────┼─────┼─────┼─────┼─────┤
    │ ?   │ ?   │_____│_____│_____│TRNS│    │ENT │SPACE│B-SPC│c-B-S│DEL  │c-del│
    └─────┴─────┴─────┴─────┴─────┴────┘    └────┴─────┴─────┴─────┴─────┴─────┘
  */

  [COMBINED] = LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH,     KC_DLR,      KC_PERC,                   KC_PLUS,  KC_7, KC_8,   KC_9,    KC_ASTR,
    KC_LPRN, KC_RPRN, KC_LBRACKET, KC_RBRACKET, KC_UNDS,                   KC_MINS,  KC_4, KC_5,   KC_6,    KC_SLSH,
    KC_COLN, KC_DQUO, KC_LCBR,     KC_RCBR,     KC_AMPR,                   KC_EQUAL, KC_1, KC_2,   KC_3,    KC_QUES,
    _______, KC_TILD, KC_GRAVE,    KC_CIRC,     _______, _______, _______, _______,  KC_0, KC_DOT, KC_PIPE, KC_BSLS
  ),

    /*
    ┌─────┬─────┬─────┬─────┬─────┐              ┌─────┬─────┬─────┬─────┬─────┐
    │ !   │ @   │ #   │ $   │ %   │              │ +   │ 7   │ 8   │ 9   │ *   │
    ├─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┤
    │ (   │ )   │ [   │ ]   │ _   │              │ -   │ 4   │ 5   │ 6   │ /   │
    ├─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┤
    │ :   │ "   │ {   │ }   │ &   ├────┐    ┌────┤ =   │ 1   │ 2   │ 3   │ ?   │
    ├─────┼─────┼─────┼─────┼─────┤    │    │    ├─────┼─────┼─────┼─────┼─────┤
    │_____│  ~  │  `  │  ^  │_____│TRNS│    │TRNS│_____│ 0   │  .  │ |   │  \  │
    └─────┴─────┴─────┴─────┴─────┴────┘    └────┴─────┴─────┴─────┴─────┴─────┘
  */

  [BROWSER_CONTROL] = LAYOUT(
    MEH(KC_0), KC_BTN3,   KC_MS_U,   KC_BTN1,   KC_BTN2,                      KC_UP,      KC_PGUP,            KC_PGDN,      KC_MS_WH_UP,   MEH(KC_9),
    MEH(KC_1), KC_MS_L,   KC_MS_D,   KC_MS_R,   MEH(KC_6),                    KC_DOWN,    RSFT(RCTL(KC_TAB)), RCTL(KC_TAB), KC_MS_WH_DOWN, LALT(KC_LEFT),
    MEH(KC_2), MEH(KC_3), MEH(KC_4), MEH(KC_5), MEH(KC_7),                    MEH(KC_8),  RCTL(KC_1),         RCTL(KC_9),   KC_F6,         KC_F5,
    _______,   _______,   _______,   _______,   _______, _______, RCTL(KC_W), RCTL(KC_T), RSFT(RCTL(KC_TAB)), _______,      _______,       _______
  ),

    /*
    ┌─────┬─────┬─────┬─────┬─────┐              ┌─────┬─────┬─────┬─────┬─────┐
    │MEH-0│M-BTN│ms-up│BTN_l│BTN_r│              │up   │pg-up│pg-dn│m-w-u│MEH-9│
    ├─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┤
    │MEH-1│ms-l │ms-dn│ms-r │MEH-6│              │down │s-c-T│c-tab│m-w-d│a-lft│
    ├─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┤
    │MEH-2│MEH-3│MEH-4│MEH-5│MEH-7├────┐    ┌────┤MEH-8│ctl-1│ctl-9│F6   │F5   │
    ├─────┼─────┼─────┼─────┼─────┤    │    │    ├─────┼─────┼─────┼─────┼─────┤
    │_____│_____│_____│_____│_____│TRNS│    │c-w │ctl-t│s-c-T│_____│_____│_____│
    └─────┴─────┴─────┴─────┴─────┴────┘    └────┴─────┴─────┴─────┴─────┴─────┘
  */

  [KEYSEL] = LAYOUT(
    MEH(KC_G), MEH(KC_H),MEH(KC_I), MEH(KC_J), MEH(KC_K),                    _______,             RSFT(KC_HOME), RSFT(KC_UP),   RSFT(KC_END),   RSFT(KC_PGUP),
    MEH(KC_L), MEH(KC_M),MEH(KC_N), MEH(KC_O), MEH(KC_P),                    RSFT(RCTL(KC_LEFT)), RSFT(KC_LEFT), RSFT(KC_DOWN), RSFT(KC_RIGHT), RSFT(RCTL(KC_RIGHT)),
    MEH(KC_Q), MEH(KC_R),MEH(KC_S), MEH(KC_T), MEH(KC_U),                    _______,             RCTL(KC_C),    RCTL(KC_X),    RCTL(KC_V),     RSFT(KC_PGDN),
    RESET,     _______,  _______,   _______,   _______,   _______, KC_ENTER, KC_SPACE,            KC_BSPC,       RCTL(KC_BSPC), KC_DELETE,      LCTL(KC_DELETE)
  ),

    /*
    ┌─────┬─────┬─────┬─────┬─────┐              ┌─────┬─────┬─────┬─────┬─────┐
    │MEH-g│MEH-h│MEH-i│MEH-j│MEH-k│              │_____│s-HME│ s-↑ │ END │s-PG↑│
    ├─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┤
    │MEH-l│MEH-m│MEH-n│MEH-o│MEH-p│              │s-c ←│ s-← │ s-↓ │ s-→ │s-c →│
    ├─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┤
    │MEH-q│MEH-r│MEH-s│MEH-t│MEH-u├────┐    ┌────┤_____│ctl-C│ctl-X│ctl-V│s-PG↓│
    ├─────┼─────┼─────┼─────┼─────┤    │    │    ├─────┼─────┼─────┼─────┼─────┤
    │RESET│_____│_____│_____│_____│TRNS│    │ENT │SPACE│B-SPC│c-B-S│ DEL │c-del│
    └─────┴─────┴─────┴─────┴─────┴────┘    └────┴─────┴─────┴─────┴─────┴─────┘
  */
};


LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      // Anything you can do in a macro.
      SEND_STRING("QMK is awesome.");
    }
    SEQ_TWO_KEYS(KC_D, KC_D) {
      SEND_STRING(SS_LCTRL("n")SS_LCTRL("c"));
    }
    SEQ_ONE_KEY(KC_S) {
      SEND_STRING("https://start.duckduckgo.com"SS_TAP(X_ENTER));
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if(record->event.pressed) {
    switch (keycode) {
		// Cloud9 macros
		case CLOUD9_TAB_LEFT:
            SEND_STRING(SS_LCTRL("["));
            return true;
			break;
		case CLOUD9_TAB_RIGHT:
            SEND_STRING(SS_LCTRL("]"));
            return true;
			break;
		case CLOUD9_TAB_CLOSE:
            SEND_STRING(SS_LALT("w"));
            return true;
			break;
		case CLOUD9_GOTO_SYMBOL:
            SEND_STRING(SS_LSFT(SS_LCTRL("e")));
            return true;
			break;
		case CLOUD9_GOTO_LINE:
            SEND_STRING(SS_LCTRL("g"));
            return true;
			break;
		case CLOUD9_NAVIGATE:
            SEND_STRING(SS_LCTRL("e"));
            return true;
			break;
	}
  }

  return true;
}

