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

#include "globals.h"
#include "logging.h"

#include "esp_bt.h"
#include "esp_blufi_api.h"


/**
 * @brief Creates a default wifi configuration.
 */
static void ath_bt_config_create(ath_bt_config_s* config) {
	esp_bt_controller_config_t _defaults = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
	config->config = _defaults;
}

/**
 * @brief
 *
 * @details
 *
 * @param[in] config Pointer to the bluetooth configuration from the context.
 */
esp_err_t ath_bt_initi(ath_bt_config_s* bt);

/**
 * @brief
 */
static esp_err_t ath_bt_init_bluefi(ath_bt_config_s* bt) {
	esp_err_t err = esp_bt_controller_mem_release(bt->mode);
	if(err != ESP_OK)return err;

	err = esp_bt_controller_init(&bt->config);
	if(err != ESP_OK)return err;

	err = esp_bt_controller_enable(bt->controller);
	if(err != ESP_OK)return err;

	//ATH_BLU_INFO("Blufi API version %04x\n", esp_blufi_get_version());
	ATH_APP_INFO("Bluetooth initialized in blufi mode.");
	return -1;
}

/**
 * @brief
 */
static esp_err_t ath_bt_init_ble(ath_bt_config_s* bt) {
	return -1;
}

#endif /* ATH_BLUETOOTH_H_ */
