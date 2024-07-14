/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#define TAPPING_TERM 200

#undef RGBLED_NUM

#define SPLIT_OLED_ENABLE
#define OLED_BRIGHTNESS 128
#define OLED_BRIGHTNESS_STEP (256/16)
#undef OLED_FONT_H
#define OLED_FONT_H "lily60_font.c"
#define OLED_FADE_OUT
#define OLED_TIMEOUT 20000
#define OLED_FADE_OUT_INTERVAL 5
#define KEYLOG_ENABLE
// #define OLED_SCROLL_TIMEOUT 10

// Conflicts with default COMMAND shortcut!
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define SPLIT_TRANSACTION_IDS_KB OLED_SYNC
