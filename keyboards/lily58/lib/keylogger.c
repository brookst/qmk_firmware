#include <stdio.h>
#include "action.h"

char keylog_str[24] = {};
char keylogs_str[21] = {};
int keylogs_str_idx = 0;

const char code_to_name[104] = {
    '_', '_', '_', '_', 'a', 'b', 'c', 'd', 'e', 'f',       // 0_
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',       // 1_
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',       // 2_
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',       // 3_
    'R', 'E', 'B', 'T', ' ', '-', '=', '[', ']', '\\',      // 4_
    '#', ';', '\'', '`', ',', '.', '/', '_', 'F', 'F',      // 5_
    'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F',       // 6_
    'P', '_', '_', '_', '_', ' ', 'D', '_', '_', 0x1a,      // 7_
    0x1b, 0x19, 0x18, '_', '/', '*', '-', '+', 'R', '1',    // 8_
    '2', '3', '4', '5', '6', '7', '8', '9', '0', '.',       // 9_
    '\\', '_', '_', '='};                                   //10_

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = '_';
  if (keycode < 104) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);

  // update keylogs
  if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
    keylogs_str_idx -= 1;
    for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
      keylogs_str[i] = keylogs_str[i+1];
    }
  }

  keylogs_str[keylogs_str_idx] = name;
  keylogs_str_idx++;
}

const char *read_keylog(void) {
  return keylog_str;
}

const char *read_keylogs(void) {
  return keylogs_str;
}
