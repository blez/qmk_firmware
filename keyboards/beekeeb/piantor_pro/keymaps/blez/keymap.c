// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    GO_EQ = SAFE_RANGE,
    ARROW,
    LAMBDA,
    NO_EQ
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GO_EQ:
      if (record->event.pressed) {
        SEND_STRING(":=");
      }
      return false;
    case ARROW:
      if (record->event.pressed) {
        SEND_STRING("->");
      }
      return false;
    case LAMBDA:
      if (record->event.pressed) {
        SEND_STRING("=>");
      }
      return false;
    case NO_EQ:
      if (record->event.pressed) {
        SEND_STRING("!=");
      }
      return false;
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_split_3x6_3(
    KC_PPLS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
    KC_TAB, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_PEQL,
    KC_DEL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_UNDS,
    KC_ESC, LT(MO(1), KC_SPC), ARROW, KC_MINS, LT(MO(2), KC_ENT), KC_GRV
    ),
[1] = LAYOUT_split_3x6_3(
    KC_DEL, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_LPRN, KC_RPRN, KC_AMPR, KC_NO, LAMBDA,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DQUO, KC_LCBR, KC_RCBR, KC_PIPE, KC_PAST, KC_QUOT,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, GO_EQ, KC_LBRC, KC_RBRC, NO_EQ, KC_BSLS, KC_TRNS,
    KC_TRNS, KC_NO, KC_NO, KC_TRNS, MO(3), KC_TRNS
    ),
[2] = LAYOUT_split_3x6_3(
    KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
    KC_PSCR, KC_1, KC_2, KC_3, KC_4, KC_5, KC_NO, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,
    KC_NO, KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, MO(3), KC_NO, KC_NO, KC_NO, KC_NO
    ),
[3] = LAYOUT_split_3x6_3(
    QK_BOOT, QK_RBT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_KB_VOLUME_DOWN, KC_KB_MUTE, KC_KB_VOLUME_UP, KC_NO, KC_NO,
    KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
};
