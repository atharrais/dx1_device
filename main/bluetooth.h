/*
 * Copyright (c) 2023 Atharrais LLC.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * @brief bluetooth.h
 */

#ifndef ATH_BLUETOOTH_H_
#define ATH_BLUETOOTH_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "esp_system.h"
#include "esp_bt.h"

#include "logging.h"

#include "globals.h"

/**
 * @brief Wifi specific configuration details.
 */
typedef struct {
	/*@{*/
	esp_bt_controller_config_t config;	/**< BT API configuration */
	esp_bt_mode_t mode;					/**< BT mode */
	esp_bt_mode_t controller;			/**< BT mode */
	esp_blufi_callbacks_t callbacks;	/**< BT mode */
	/*@}*/
} ath_bt_config_s;

/**
 * @brief Creates a default wifi configuration.
 */
static void ath_bt_gblconfig_create(ath_bt_config_s* config) {
	esp_bt_controller_config_t _defaults = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
	config->config = _defaults;
}

/**
 * @brief
 */
esp_err_t ath_bt_initi(ath_bt_config_s* config);

#endif /* ATH_BLUETOOTH_H_ */
