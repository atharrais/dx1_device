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
 * @brief wifi.c
 */

#include "wifi.h"

esp_err_t ath_wifi_initi(ath_wifi_config_s* wifi) {
	ATH_APP_INFO("Wifi initializing...");
	esp_err_t err = esp_netif_init();

	err = esp_event_loop_create_default();
	if(err != ESP_OK) return err;

	esp_netif_t* sta_netif = esp_netif_create_default_wifi_sta();
	if(sta_netif == NULL) return ESP_FAIL;

	esp_netif_t* ap_netif = esp_netif_create_default_wifi_ap();
	if(ap_netif == NULL) return ESP_FAIL;

	err = esp_event_handler_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &wifi_event_handler, NULL);
	if(err != ESP_OK) return err;
	err = esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &ip_event_handler, NULL);
	if(err != ESP_OK) return err;

	err = esp_wifi_init(&wifi->config);

	switch(wifi->mode) {
	case WIFI_MODE_STA:
		return ath_wifi_start_sta();
	case WIFI_MODE_AP:
		return ath_wifi_start_ap();
	default:
		return ath_wifi_start_sta();
	}
}


