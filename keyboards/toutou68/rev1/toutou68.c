/* Copyright 2021 Mike toutou
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = { {
 // Key Matrix to LED Index
  {    0,        1,        2,        3,        4,        5,        6,         7,         8,        9,         10,      11,        12,       13,       14 },
  {    15,       16,       17,       18,       19,       20,       21,        22,        23,       24,        25,      26,        27,       28,       29 },
  {    30,       31,       32,       33,       34,       35,       36,        37,        38,       39,        40,      41,        42,       43,       NO_LED },
  {    44,       45,       46,       47,       48,       49,       50,        51,        52,       53,        54,      55,        56,       57,       NO_LED },
  {    58,       59,       60,       61,       62,       63,       64,        65,        66,       67,        NO_LED,  NO_LED,    NO_LED,   NO_LED,   NO_LED }
}, {
  // LED Index to Physical Position
      {0, 0},   {16, 0},   {32,  0}, {48,  0}, {64, 0},  {80, 0},  {96,  0},  {112, 0},  {128, 0}, {144, 0}, {160, 0}, {176, 0},  {192, 0}, {208, 0}, {224, 0},
      {4, 16},  {19,16},   {35, 16}, {51, 16}, {67,16},  {83,16},  {99, 16},  {115,16},  {131,16}, {147,16}, {163,16}, {179,16},  {195,16}, {210,16}, {224,16},
      {5, 32},  {26,32},   {42, 32}, {58, 32}, {74,32},  {90,32},  {106, 32}, {122,32},  {138,32}, {154,32}, {170,32}, {186,32},  {208,32}, {224,32},
      {9, 48},  {33,48},   {49, 48}, {65, 48}, {81,48},  {97,48},  {113, 48}, {129,48},  {145,48}, {161,48}, {177,48}, {193,48},  {208,48}, {224,48},
      {1, 64},  {21,64},   {41, 64}, {93,64}, {144,64}, {160,64}, {176,64},  {192,64}, {208,64}, {224,64}

}, {
  // LED Index to Flag
    // LED Index to Flag
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,  // Esc, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, -, =, Backspace, Delete
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,  // Tab, Q, W, E, R, T, Y, U, I, O, P, [, ], backslash , Home
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1,     // Capslock, A, S, D, F, G, H, J, K, L, ;, ', Enter, Page up
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1,     // LShift, Z, X, C, V, B, N, M, ,, ., /, Shift, Up, Page Down
    1, 1, 1,          4,       1, 1, 1, 1, 1, 1   // Ctrl, GUI, Alt, Space, RAlt, FN, Ctrl, Left, Down, Right

}
};


void suspend_power_down_kb(void)
{
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_kb(void)
{
    rgb_matrix_set_suspend_state(false);
}

void keyboard_post_init_kb(void)  {
    rgb_matrix_reload_from_eeprom();

}

//CAPS backlight
bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(30, 0xFF, 0xFF, 0xFF);
    }
    return true;
}

#endif  // #ifdef RGB_MATRIX_ENABLE
