// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SERIAL_USART_PIN_SWAP

#define USB_VBUS_PIN GP19

#define SPLIT_HAND_PIN GP17
#define SPLIT_HAND_PIN_LOW_IS_LEFT

#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_TERM 25
#define QUICK_TAP_TERM 0
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define RETRO_TAPPING
#define RETRO_TAPPING_PER_KEY
