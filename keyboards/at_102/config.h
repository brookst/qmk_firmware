// Copyright 2023 Tim Brooks (@brookst)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG
#define MATRIX_HAS_GHOST
#define LED_CAPS_LOCK_PIN GP21
#define LED_NUM_LOCK_PIN GP20
#define LED_SCROLL_LOCK_PIN GP25

/* Anodes are common on VCC, invert states */
#define LED_PIN_ON_STATE 0

/* debugging info */
#define DEBUG_MATRIX_SCAN_RATE
#define DEBUG_MATRIX

/* use esc key to enter bootloader on powerup */
#define BOOTMAGIC_LITE_ROW 2
#define BOOTMAGIC_LITE_COLUMN 0

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/*
#define LAYOUT_fullsize_iso( \
    k00,      k01, k02, k03, k04, k05, k06, k07, k08, k09, k10, k11, k12, k13, k14, k15, \
    k16, k17, k18, k19, k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k30, k31, k32, k33, k34, k35, k36, \
    k37, k38, k39, k40, k41, k42, k43, k44, k45, k46, k47, k48, k49,      k50, k51, k52, k53, k54, k55, k56, \
    k57, k58, k59, k60, k61, k62, k63, k64, k65, k66, k67, k68, k69, k70,                k71, k72, k73, \
    k74, k75, k76, k77, k78, k79, k80, k81, k82, k83, k84, k85,      k86,      k87,      k88, k89, k90, k91, \
    k92,      k93,                k94,                k95,           k96, k97, k98, k99, k100,     k101 \
) { \
    {KC_NO, KC_NO,   k00,   k75,   k04,   k62,   k05,   k63,   k06, KC_NO,   k68, KC_NO,  k100,  k101,   k87,   k93}, \
    {KC_NO,   k74,   k37,   k57,   k03,   k42,   k29,   k43,   k49,   k07,   k48,   k71,   k72,   k73, KC_NO, KC_NO}, \
    {  k92, KC_NO,   k16,   k01,   k02,   k21,   k09,   k22,   k28,   k08,   k27,   k50,   k30,   k32,   k31, KC_NO}, \
    {KC_NO, KC_NO,   k17,   k18,   k19,   k20,   k10,   k23,   k24,   k25,   k26,   k11,   k12,   k52,   k51,   k13}, \
    {KC_NO, KC_NO,   k38,   k39,   k40,   k41, KC_NO,   k44,   k45,   k46,   k47,   k53,   k54,   k55,   k56,   k14}, \
    {KC_NO, KC_NO,   k58,   k59,   k60,   k61, KC_NO,   k64,   k65,   k66,   k67,   k88,   k89,   k90,   k91, KC_NO}, \
    {  k96,   k86,   k76,   k77,   k78,   k79,   k70,   k82,   k83,   k84,   k69,   k33,   k34,   k35,   k15, KC_NO}, \
    {KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   k80,   k94,   k81, KC_NO, KC_NO,   k85,   k98,   k99,   k36,   k97,   k95} \
}
*/
