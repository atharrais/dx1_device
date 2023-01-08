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
 * @brief bluetooth.c
 */

#include "bluetooth.h"

esp_err_t ath_bt_initi(ath_bt_config_s* config) {
	ATH_APP_INFO("Bluetooth initializing...");

	esp_err_t err = esp_bt_controller_mem_release(config->mode);
	if(err != ESP_OK)return err;

	err = esp_bt_controller_init(&config->config);
	if(err != ESP_OK)return err;

	err = esp_bt_controller_enable(config->controller);
	if(err != ESP_OK)return err;

	err = esp_blufi_host_and_cb_init(&config->callbacks);
	if(err != ESP_OK)return err;

	ATH_BLU_INFO("Blufi API version %04x\n", esp_blufi_get_version());
	ATH_APP_INFO("Bluetooth initialized.");

	return ESP_OK;
}
