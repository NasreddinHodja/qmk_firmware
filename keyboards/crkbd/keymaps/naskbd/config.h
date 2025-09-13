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

// #define USE_MATRIX_I2C

#define PERMISSIVE_HOLD

#define QUICK_TAP_TERM 120
#define TAPPING_TERM 200

#ifdef MOUSEKEY_ENABLE
/* Delay between pressing a movement key and cursor movement */
#    define MOUSEKEY_DELAY 10
/* Time between cursor movements in milliseconds */
#    define MOUSEKEY_INTERVAL 20
/* Step size */
#    define MOUSEKEY_MOVE_DELTA 8
/* Maximum cursor speed at which acceleration stops */
#    define MOUSEKEY_MAX_SPEED 10
/* Time until maximum cursor speed is reached */
#    define MOUSEKEY_TIME_TO_MAX 30
/* Delay between pressing a wheel key and wheel movement */
#    define MOUSEKEY_WHEEL_DELAY 10
/* Time between wheel movements */
#    define MOUSEKEY_WHEEL_INTERVAL 80
/* Wheel movement step size */
#    define MOUSEKEY_WHEEL_DELTA 1
/* Maximum number of scroll steps per scroll action */
#    define MOUSEKEY_WHEEL_MAX_SPEED 8
/* Time until maximum scroll speed is reached */
#    define MOUSEKEY_WHEEL_TIME_TO_MAX 40
#endif

#ifdef SEND_STRING_ENABLE
#    define BELL_SOUND TERMINAL_SOUND
#endif

/* #ifdef RGBLIGHT_ENABLE */
/* #    define RGBLIGHT_EFFECT_BREATHING */
/* #    define RGBLIGHT_EFFECT_RAINBOW_MOOD */
/* #    define RGBLIGHT_EFFECT_RAINBOW_SWIRL */
/* #    define RGBLIGHT_EFFECT_SNAKE */
/* #    define RGBLIGHT_EFFECT_KNIGHT */
/* #    define RGBLIGHT_EFFECT_CHRISTMAS */
/* #    define RGBLIGHT_EFFECT_STATIC_GRADIENT */
/* #    define RGBLIGHT_EFFECT_RGB_TEST */
/* #    define RGBLIGHT_EFFECT_ALTERNATING */
/* #    define RGBLIGHT_EFFECT_TWINKLE */
/* #    define RGBLIGHT_LIMIT_VAL 120 */
/* #    define RGBLIGHT_HUE_STEP 10 */
/* #    define RGBLIGHT_SAT_STEP 17 */
/* #    define RGBLIGHT_VAL_STEP 17 */
/* #endif */
