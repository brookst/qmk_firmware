// UK/non-us lily58 layout
// Tim Brooks <brooks@skoorb.net>

#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "keyboard.h"
#ifdef OLED_ENABLE
#include "oled_driver.h"
#include "transactions.h"
#include "raw_hid.h"
#endif

enum layer_number {
  _QWERTY = 0,
  _GAME,
  _LOWER,
  _RAISE,
  _ADJUST,
  _INVENT,
};

enum custom_keycodes {
  KC_BUP = SAFE_RANGE,
  KC_BDN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 *         ,-----------------------------------------.                    ,-----------------------------------------.
 *         | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 *         |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *         | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 *         |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *         |LCtrl |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 *         |------+------+------+------+------+------|  LGUI |    | RAlt  |------+------+------+------+------+------|
 *         |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 *         `-----------------------------------------/       /     \      \-----------------------------------------'
 *                           | LGUI | LAlt |LOWER | / Space /       \ Enter\  |RAISE |BackSP| RCtl |
 *                           |      |      |      |/       /         \      \ |      |      |      |
 *                           `----------------------------'           `------`'--------------------'
 */

 [_QWERTY] = LAYOUT(
   KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_EQL,
   KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINS,
  KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LGUI, KC_RALT,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                             KC_LGUI, KC_LALT,MO(_LOWER),KC_SPC, KC_ENT,MO(_RAISE),KC_BSPC, KC_RCTL
),
/* LOWER
 *         ,-----------------------------------------.                    ,-----------------------------------------.
 *         | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 *         |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *         |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 *         |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *         |      |   !  |  @/" |  #/£ |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |  =   |
 *         |------+------+------+------+------+------|  GAME |    | RAlt  |------+------+------+------+------+------|
 *         |      |   \  |      |  #   |   ~  |      |-------|    |-------|   +  |   _  |   ,  |   .  |   /  |      |
 *         `-----------------------------------------/       /     \      \-----------------------------------------'
 *                           | LGUI | LAlt |LOWER | / Space /       \ Enter\  |RAISE |BackSP| RCtl |
 *                           |      |      |      |/       /         \      \ |      |      |      |
 *                           `----------------------------'           `------`'--------------------'
 */
[_LOWER] = LAYOUT(
   KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
   KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  _______, KC_EXLM, S(KC_2), KC_HASH,  KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_EQL,
  _______, KC_NUBS, _______, KC_NUHS,S(KC_NUHS),_______,TG(_GAME),_______,KC_PLUS, KC_UNDS, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
),
/* RAISE
 *         ,-----------------------------------------.                    ,-----------------------------------------.
 *         |      |      |      |      |      |      |                    |      |      | PSCR | SCRL | PAUSE|      |
 *         |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *         |  `   |   >  |   }  |   ]  |   )  |      |                    |      |   {  |   }  |   [  |   ]  |      |
 *         |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *         |      |   <  |   {  |   [  |   (  |      |-------.    ,-------| Left | Down |  Up  | Right|   :  |  =   |
 *         |------+------+------+------+------+------|  LGUI |    | RAlt  |------+------+------+------+------+------|
 *         |      |      |      |      |      |      |-------|    |-------| Home | PgDn | PgUp |  End |Insert|      |
 *         `-----------------------------------------/       /     \      \-----------------------------------------'
 *                           | LGUI | LAlt |LOWER | / Space /       \ Enter\  |RAISE |Delete| RCtl |
 *                           |      |      |      |/       /         \      \ |      |      |      |
 *                           `----------------------------'           `------`'--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, _______,
   KC_GRV, KC_RABK, KC_RCBR, KC_RBRC, KC_RPRN, _______,                   _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
  _______, KC_LABK, KC_LCBR, KC_LBRC, KC_LPRN, _______,                   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_COLN,  KC_EQL,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS, _______,
                             _______, _______, _______, _______, _______, _______,  KC_DEL, _______
),
/* ADJUST
 *         ,-----------------------------------------.                    ,-----------------------------------------.
 *         | NKRO |      |      |      |      | GAME |                    |      |      |      |      |      | DBG  |
 *         |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *         |      |      |      |      |      |      |                    | FFwd |      |      |  Rwd |      |      |
 *         |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *         |      | BBack| BRef | BStop| BFwd |      |-------.    ,-------| Prev | Play | Stop | Next |      |      |
 *         |------+------+------+------+------+------| OLED- |    | OLED+ |------+------+------+------+------+------|
 *         |      |      |      | Calc |      |      |-------|    |-------| Mute | VolDn| VolUp|      |      |      |
 *         `-----------------------------------------/       /     \      \-----------------------------------------'
 *                           | LGUI | LAlt |LOWER | / Space /       \ Enter\  |RAISE |BackSP| RCtl |
 *                           |      |      |      |/       /         \      \ |      |      |      |
 *                           `----------------------------'           `------`'--------------------'
 */
  [_ADJUST] = LAYOUT(
  NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,TG(_GAME),                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DB_TOGG,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MFFD, XXXXXXX, XXXXXXX, KC_MRWD, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_WBAK, KC_WREF, KC_WSTP, KC_WFWD, XXXXXXX,                   KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_CALC, XXXXXXX, XXXXXXX,  KC_BDN,  KC_BUP, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______, _______, _______, _______
  ),
/* GAME
 *         ,-----------------------------------------.                    ,-----------------------------------------.
 *         | ESC  |      |      |      |      |      |                    |      |      |      |      |      |      |
 *         |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *         |  T   | Tab  |  Q   |  W   |  E   |  R   |                    |      |      |      |      |      |      |
 *         |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *         |  H   | Shift|  A   |  S   |  D   |  F   |-------.    ,-------|      |      |      |      |      |      |
 *         |------+------+------+------+------+------|   G   |    |       |------+------+------+------+------+------|
 *         |      | Ctrl |  Z   |  X   |  C   |  V   |-------|    |-------|      |      |      |      |      |      |
 *         `-----------------------------------------/       /     \      \-----------------------------------------'
 *                           | LGUI |Enter |INVENT| / Space /       \ Enter\  |RAISE |BackSP| RCtl |
 *                           |      |      |      |/       /         \      \ |      |      |      |
 *                           `----------------------------'           `------`'--------------------'
 */
  [_GAME] = LAYOUT(
   KC_ESC, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
     KC_T,  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,                   _______, _______, _______, _______, _______, _______,
     KC_H, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,                   _______, _______, _______, _______, _______, _______,
  _______, KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_G, _______, _______, _______, _______, _______, _______, _______,
                             _______, KC_ENT,MO(_INVENT),KC_SPC, _______, _______, _______, _______
),
/* INVENTORY
 *         ,-----------------------------------------.                    ,-----------------------------------------.
 *         | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 *         |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *         |  `   |   1  |   2  |   3  |   4  |   5  |                    |      |      |      |      |      |      |
 *         |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 *         |      |   6  |   7  |   8  |   9  |   0  |-------.    ,-------|      |      |      |      |      |      |
 *         |------+------+------+------+------+------|  GAME |    |       |------+------+------+------+------+------|
 *         |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 *         `-----------------------------------------/       /     \      \-----------------------------------------'
 *                           | LGUI |Enter |INVENT| / Space /       \ Enter\  |RAISE |BackSP| RCtl |
 *                           |      |      |      |/       /         \      \ |      |      |      |
 *                           `----------------------------'           `------`'--------------------'
 */
[_INVENT] = LAYOUT(
   KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
   KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   _______, _______, _______, _______, _______, _______,
  _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,TG(_GAME),_______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE
// oled_brightness in drivers/oled/oled_driver.c
extern uint8_t oled_brightness;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_left())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_logo(void);
#ifdef KEYLOG_ENABLE
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);
#endif

#define HOST_STRINGS 6
#define HOST_STRING_LEN 21
char host_strings[HOST_STRINGS][HOST_STRING_LEN + 1];
typedef struct _master_to_slave_t {
    char brightness;
    char host_string[HOST_STRING_LEN+1];
} master_to_slave_t;

master_to_slave_t master_to_slave = {OLED_BRIGHTNESS};

// The input report size seems to need to be 33 bytes
// The leading byte always seems to be trimed so we recieve 32 bytes
void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t label = data[0];
    if (label >= HOST_STRINGS) {
#ifdef CONSOLE_ENABLE
        uprintf("HID recv invalid label: %d\n", label);
#endif
        return;
    }
    master_to_slave.host_string[0] = label;
    for (uint8_t i = 1; i < HOST_STRING_LEN + 1; ++i) {
        master_to_slave.host_string[i] = data[i];
        host_strings[label][i - 1] = data[i];
    }
    transaction_rpc_exec(OLED_SYNC, sizeof(master_to_slave_t), &master_to_slave, 0, NULL);
#ifdef CONSOLE_ENABLE
    dprintf("HID recv label: %d\n", label);
#endif
}

void oled_sync(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const master_to_slave_t *m2s = (const master_to_slave_t*)in_data;
    if (oled_brightness != m2s->brightness) {
        oled_set_brightness(m2s->brightness);
    }
    uint8_t label = m2s->host_string[0];
    for (uint8_t i = 1; i < HOST_STRING_LEN + 1; ++i) {
        host_strings[label][i - 1] = m2s->host_string[i];
    }
}

#define L_BASE 0
#define L_GAME (1 << 1)
#define L_LOWER (1 << 2)
#define L_RAISE (1 << 3)
#define L_ADJUST (1 << 4)
#define L_ADJUST_TRI (L_ADJUST | L_RAISE | L_LOWER)
#define L_INVENT (1 << 5)
bool booting = true;

bool oled_task_user(void) {
  uint8_t current_column = 0;
  if (is_keyboard_left()) {
    // The oled display area is shifted to the left, space appropriately
    current_column += 1;
    oled_advance_page(true);
  }
  if (booting && !debug_enable) {
      oled_write(read_logo(), false);
      if (timer_read() > 3000) {
          booting = false;
      }
      return false;
  }
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    if (debug_enable) {
        oled_write_P(PSTR("Master:"), false);
        oled_write(get_u8_str(layer_state, ' '), false);
        switch (layer_state) {
            case L_BASE:
                oled_write_P(PSTR("Qwerty  "), false);
                break;
            case L_GAME:
                oled_write_P(PSTR("Game    "), false);
                break;
            case L_RAISE:
            case (L_GAME | L_RAISE):
                oled_write_P(PSTR("Raise   "), false);
                break;
            case L_LOWER:
            case (L_GAME | L_LOWER):
                oled_write_P(PSTR("Lower   "), false);
                break;
            case L_ADJUST:
            case L_ADJUST_TRI:
            case (L_GAME | L_ADJUST_TRI):
                oled_write_P(PSTR("Adjust  "), false);
                break;
            case L_INVENT:
            case (L_GAME | L_INVENT):
                oled_write_P(PSTR("Invent  "), false);
                break;
            default:
                oled_write_P(PSTR("Unknown "), false);
        }
        oled_write(get_u8_str(oled_brightness, ' '), false);
#ifdef KEYLOG_ENABLE
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
#else
        oled_write_ln(host_strings[0], false);
        oled_write_ln(host_strings[1], false);
#endif
    } else {
        oled_set_cursor(0, current_column++);
        oled_write_ln(host_strings[0], false);
        oled_set_cursor(0, current_column++);
        oled_write_ln(host_strings[1], false);
        oled_set_cursor(0, current_column++);
        oled_write_ln(host_strings[2], false);
    }
    // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    // oled_write_ln(read_host_led_state(), false);
    // oled_write_ln(read_timelog(), false);
    // oled_write(read_logo(), false);
  } else {
    // oled_write(read_logo(), false);
    // oled_write_ln(get_u8_str(oled_brightness, ' '), false);
    // oled_write("Lens: ", false);
    // oled_write(get_u8_str(strlen(host_strings[0]), '_'), false);
    // oled_write(" ", false);
    // oled_write(get_u8_str(strlen(host_strings[3]), '_'), false);
    // oled_write(" ", false);
    // oled_write_ln(get_u8_str(strlen(host_strings[4]), '_'), false);
    oled_set_cursor(0, current_column++);
    oled_write_ln(host_strings[3], false);
    oled_set_cursor(0, current_column++);
    oled_write_ln(host_strings[4], false);
    oled_set_cursor(0, current_column++);
    oled_write_ln(host_strings[5], false);
  }
  return false;
}
#endif // OLED_ENABLE

void keyboard_post_init_user(void) {
#ifdef OLED_ENABLE
    transaction_register_rpc(OLED_SYNC, oled_sync);
    // Ensure null-terminators in host_strings
    for (uint8_t i=0; i<HOST_STRINGS; ++i) {
        host_strings[i][HOST_STRING_LEN] = 0;
    }
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef CONSOLE_ENABLE
    dprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
#ifdef OLED_ENABLE
#ifdef KEYLOG_ENABLE
    if (debug_enable) {
        set_keylog(keycode, record);
    }
#endif
    if ((keycode == KC_BUP) || (keycode == KC_BDN)) {
        char new_brightness = oled_brightness;
        if (keycode == KC_BUP) {
            new_brightness += OLED_BRIGHTNESS_STEP;
            if (new_brightness < oled_brightness) new_brightness = 255;
        } else {
            new_brightness -= OLED_BRIGHTNESS_STEP;
            if (new_brightness > oled_brightness) new_brightness = 0;
        }
        oled_set_brightness(new_brightness);
#ifdef CONSOLE_ENABLE
        uprintf("Set brightness: %d\n", oled_brightness);
#endif
        master_to_slave.brightness = oled_brightness;
        transaction_rpc_exec(OLED_SYNC, sizeof(master_to_slave_t), &master_to_slave, 0, NULL);
    }
#endif // OLED_ENABLE
  }
  return true;
}
