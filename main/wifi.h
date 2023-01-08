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
 *
 */

#ifndef ATH_WIFI_H_
#define ATH_WIFI_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "esp_system.h"
#include "esp_mac.h"
#include "esp_wifi.h"
#include "esp_event.h"

#include "memory.h"

#include "logging.h"

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
 * @brief Creates a default wifi configuration.
 */
static void ath_wifi_gblconfig_create(ath_wifi_config_s* config) {
	wifi_init_config_t _defaults = WIFI_INIT_CONFIG_DEFAULT();
	config->config = _defaults;
}

esp_err_t ath_wifi_initi(wifi_init_config_t* config, wifi_mode_t mode);

/**
 * @brief
 */
static esp_err_t ath_wifi_start_sta() {
	ATH_APP_INFO("Wifi initialized in sta mode.");
	esp_err_t err = esp_wifi_set_mode(WIFI_MODE_STA);
	err = esp_wifi_start();
	return err;
}

/**
 * @brief
 */
static esp_err_t ath_wifi_start_ap() {
	ATH_APP_INFO("Wifi initialized in ap mode.");
	esp_err_t err = esp_wifi_set_mode(WIFI_MODE_AP);
	err = esp_wifi_start();
	return err;
}

/**
 * @brief
 */
static void wifi_event_handler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data) {
	//
}

/**
 * @brief
 */
static void ip_event_handler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data) {
	//
}

#endif /* ATH_WIFI_H_ */
