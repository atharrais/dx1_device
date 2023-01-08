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
 * @brief globals.h
 */

#pragma once

#ifndef ATH_GLOBALS_H_
#define ATH_GLOBALS_H_

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

#include "esp_system.h"
#include "esp_mac.h"
#include "esp_wifi.h"
#include "esp_bt.h"
#include "esp_blufi_api.h"
#include "esp_event.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"

#include "storage.h"
#include "memory.h"
#include "features.h"

/**
 * @brief
 */
typedef enum {
	/*@{*/
	ATH_BT_MODE_BLUFI = 0,	/**< Use ESP blufi for configuration. */
	ATH_BT_MODE_BLE = 1		/**< Use ESP BT BLE mode. */
	/*@}*/
} ath_bt_mode_e;

/**
 * @brief Wifi specific configuration details.
 */
typedef struct {
	/*@{*/
	esp_bt_controller_config_t config;	/**< BT API configuration */
	esp_bt_mode_t mode;					/**< BT memory profile mode */
	esp_bt_mode_t controller;			/**< BT controller mode */
	ath_bt_mode_e device_mode; 			/**< BT device mode */
	esp_blufi_callbacks_t callbacks;	/**< BT blufi call-backs */
	/*@}*/
} ath_bt_config_s;

/**
 * @brief Wifi specific configuration details.
 */
typedef struct {
	/*@{*/
	wifi_init_config_t config;	/**< Wifi API configuration */
	wifi_mode_t mode;			/**< Wifi mode */

	/*@}*/
} ath_wifi_config_s;

/**
 * @brief Structure to hold global application state.
 *
 * @details Holds global application state across FreeRTOS threads and application
 *          states.
 */
typedef struct {
	/*@{*/
	uint32_t fflags;		/**< Feature flags from NVS Flash. */
	ath_wifi_config_s wifi;	/**< Wifi Configuration for Atharrais. */
	ath_bt_config_s bt;		/**< Bluetooth Configuration for Atharrais. */
	/*@}*/
} ath_context_s;

/**
 * @brief Static global instance of the Atharrais appliction configuration.
 */
static ath_context_s* ATH_APP_CONTEXT = &(ath_context_s){};

#endif /* ATH_GLOBALS_H_ */
