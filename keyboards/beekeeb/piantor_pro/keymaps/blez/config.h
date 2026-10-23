// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define TAPPING_TERM 200
#define PERMISSIVE_HOLD  // Hold if another key is tapped while the tap-hold key is down.
#define CHORDAL_HOLD     // Same-hand rolls are taps (layer-taps exempt, see keymap.c).
#define FLOW_TAP_TERM 150 // Tap-hold keys pressed during fast typing are taps.
#define QUICK_TAP_TERM 120
