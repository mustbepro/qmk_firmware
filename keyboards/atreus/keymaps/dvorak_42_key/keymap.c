#include QMK_KEYBOARD_H

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

//terminal - termite
#define TRM_VSL LCTL(LSFT(KC_SPACE))
#define TRM_CPY LCTL(LSFT(KC_C))
#define TRM_PST LCTL(LSFT(KC_V))

//i3
#define I3_KILL LALT(LSFT(KC_Q))

//shortcuts
//#define SC_CBRK KC_LCBR(KC_LCBR(KC_LEFT))

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
    KC_Z,    	     KC_X,          KC_C,       KC_V,                KC_B,                                 KC_K,       KC_M,      KC_COMMA,KC_DOT,        KC_SLASH,
    KC_ENTER,      KC_BSPC,       MO(KEYSEL), KC_LALT,                KC_SPACE, MO(KEYNAV), ALTENT,         MO(COMBINED), KC_BSPC, KC_LEAD, KC_LCTRL,          KC_LSFT
  ),

    /*
    ┌─────┬─────┬─────┬─────┬─────┐              ┌─────┬─────┬─────┬─────┬─────┐
    │ q   │ f   │ w   │ P   │ G   │              │ J   │ L   │ U   │ Y   │ ;   │
    ├─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┤
    │ A   │ R   │ S   │ T   │ D   │              │ H   │ N   │ E   │ I   │ O   │
    ├─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┤
    │ Z   │ X   │ C   │ V   │ B   ├────┐    ┌────┤ K   │ M   │ ,   │ .   │ /   │
    ├─────┼─────┼─────┼─────┼─────┤    │    │ALT/├─────┼─────┼─────┼─────┼─────┤
    │SHIFT│CTRL │KYSEL│BRO_C│COMBI│KEYN│    │ENT │SPACE│B-SPC│LEAD │CAPS │SHIFT│
    └─────┴─────┴─────┴─────┴─────┴────┘    └────┴─────┴─────┴─────┴─────┴─────┘
  */


  [KEYNAV] = LAYOUT(
    KC_ESC,       RCTL(KC_Z),            RCTL(KC_W),      TRM_PST,   _______,                              MEH(KC_B),     KC_HOME,    KC_UP,           KC_END,     KC_PGUP,
    LCTL(KC_A),   RCTL(KC_R),            RCTL(KC_S),      KC_TAB,    RCTL(KC_N),                           LCTL(KC_LEFT), KC_LEFT,    KC_DOWN,         KC_RIGHT,   LCTL(KC_RIGHT), 
    KC_ESC,       AS_CLASS,              AS_TABLEFT,      TRM_VSL,   AS_CLOSETAB,                          _______,       RCTL(KC_C), RCTL(KC_X),      RCTL(KC_V), KC_PGDOWN,
    I3_KILL,      AS_GO_DECLARATION,     _______,         _______,   _______,         _______, KC_ENTER,   KC_SPACE,      KC_BSPC,    RCTL(KC_BSPC),   KC_DELETE,  LCTL(KC_DELETE)
  ),

    /*
    ┌─────┬─────┬─────┬─────┬─────┐              ┌─────┬─────┬─────┬─────┬─────┐
    │ESC  │ctl-Z│ctl-W│TRM_P│     │              │MEH-b│HOME │  ↑  │END  │PG-↑ │
    ├─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┤
    │ctl-A│ctl-R│ctl-S│TAB  │ctl-N│              │ctl ←│  ←  │  ↓  │  →  │ctl →│
    ├─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┤
    │ ?   │ ?   │ ?   │TRM_V│ ?   ├────┐    ┌────┤_____│ctl-C│ctl-X│ctl-V│PG-↓ │
    ├─────┼─────┼─────┼─────┼─────┤    │    │    ├─────┼─────┼─────┼─────┼─────┤
    │i3kil│ ?   │_____│_____│_____│TRNS│    │ENT │SPACE│B-SPC│c-B-S│DEL  │c-del│
    └─────┴─────┴─────┴─────┴─────┴────┘    └────┴─────┴─────┴─────┴─────┴─────┘
  */

  [COMBINED] = LAYOUT(
    KC_PLUS,  KC_7, KC_8,   KC_9,    KC_ASTR,                  KC_EXLM, KC_AT,   KC_HASH,     KC_DLR,      KC_PERC, 
    KC_MINS,  KC_4, KC_5,   KC_6,    KC_SLSH,                  KC_LPRN, KC_RPRN, KC_LBRACKET, KC_RBRACKET, KC_UNDS, 
    KC_EQUAL, KC_1, KC_2,   KC_3,    KC_QUES,                  KC_COLN, KC_DQUO, KC_LCBR,     KC_RCBR,     KC_AMPR, 
    _______,  KC_0, KC_DOT, KC_PIPE, KC_BSLS,  _______, _______,_______, KC_TILD, KC_GRAVE,    KC_CIRC,     _______
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

    //design idea
    ┌─────┬─────┬─────┬─────┬─────┐              ┌─────┬─────┬─────┬─────┬─────┐
    │ (   │  "  │  :  │  *  │ )   │              │ +   │ 7   │ 8   │ 9   │  &  │
    ├─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┤
    │  [  │  -  │  ?  │  |  │ ]   │              │  _  │ 4   │ 5   │ 6   │ /   │
    ├─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┤
    │ {   │  #  │ \   │ $   │ }   ├────┐    ┌────┤ =   │ 1   │ 2   │ 3   │ ?   │
    ├─────┼─────┼─────┼─────┼─────┤    │    │    ├─────┼─────┼─────┼─────┼─────┤
    │_____│  @  │  !  │  ^  │_____│TRNS│    │TRNS│_____│ 0   │  .  │  `  │  %  │
    └─────┴─────┴─────┴─────┴─────┴────┘    └────┴─────┴─────┴─────┴─────┴─────┘
 ~
 "${}"
  */

  [BROWSER_CONTROL] = LAYOUT(
    MEH(KC_0), KC_BTN3,   KC_MS_U,   KC_BTN1,   KC_BTN2,                      KC_UP,      KC_PGUP,            KC_PGDN,      KC_MS_WH_UP,   MEH(KC_9),
    LALT(KC_1), KC_MS_L,   KC_MS_D,   KC_MS_R,   LALT(KC_6),                    KC_DOWN,    RSFT(RCTL(KC_TAB)), RCTL(KC_TAB), KC_MS_WH_DOWN, LALT(KC_LEFT),
    LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5), LALT(KC_7),                    MEH(KC_8),  RCTL(KC_1),         RCTL(KC_9),   KC_F6,         KC_F5,
    _______,   _______,   _______,   _______,   _______, _______, RCTL(KC_W), RCTL(KC_T), RSFT(RCTL(KC_TAB)), _______,      _______,       _______
  ),

    /*
    ┌─────┬─────┬─────┬─────┬─────┐              ┌─────┬─────┬─────┬─────┬─────┐
    │MEH-0│M-BTN│ms-up│BTN_l│BTN_r│              │up   │pg-up│pg-dn│m-w-u│MEH-9│
    ├─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┤
    │alt-1│ms-l │ms-dn│ms-r │alt-6│              │down │s-c-T│c-tab│m-w-d│a-lft│
    ├─────┼─────┼─────┼─────┼─────┤              ├─────┼─────┼─────┼─────┼─────┤
    │alt-2│alt-3│alt-4│alt-5│alt-7├────┐    ┌────┤MEH-8│ctl-1│ctl-9│F6   │F5   │
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
   //txt    
    SEQ_ONE_KEY(KC_F) {
      SEND_STRING("QMK is awesome.");
    }
   SEQ_ONE_KEY(KC_SCLN) {
      SEND_STRING(": >");
    }
   //backets
   // others things can add:
   //   - [a] {a} "a" completes
   //   - my_var => "my_var
    SEQ_ONE_KEY(KC_B) {
      SEND_STRING("[]");
      tap_code(KC_LEFT);
    }
     SEQ_TWO_KEYS(KC_B, KC_B) {
      SEND_STRING("{}");
      tap_code(KC_LEFT);
    }
    
    //bash sciprts 
    SEQ_TWO_KEYS(KC_B, KC_S) {
      SEND_STRING("#!/bin/bash");
      tap_code(KC_ENTER);
    }
    SEQ_TWO_KEYS(KC_B, KC_V) {
      SEND_STRING("\"${}\"");
      tap_code(KC_LEFT);
      tap_code(KC_LEFT);
    }
    SEQ_TWO_KEYS(KC_B, KC_F) {
      SEND_STRING("(){\n}");
      tap_code(KC_UP);
      tap_code(KC_LEFT);
      tap_code(KC_LEFT);
    }
    //shell
    SEQ_ONE_KEY(KC_H) {
      SEND_STRING(" ~/");
    }
    SEQ_TWO_KEYS(KC_S, KC_P) {
      SEND_STRING(" | ");
    }
    SEQ_TWO_KEYS(KC_S, KC_A) {
      SEND_STRING(" && ");
    }
    //misc
     SEQ_THREE_KEYS(KC_S, KC_S, KC_L) {
      SEND_STRING("https://");
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

