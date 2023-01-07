/*
 *
 */
/**
 *
 */

#include "wifi.h"

esp_err_t ath_wifi_initi(wifi_init_config_t* config, wifi_mode_t mode = WIFI_MODE_STA) {
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

	//wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
	err = esp_wifi_init(config);

	switch(mode) {
	case WIFI_MODE_STA:
		return ath_wifi_start_sta();
	case WIFI_MODE_AP:
		return ath_wifi_start_ap();
	default:
		return ath_wifi_start_sta();
	}
}

esp_err_t ath_wifi_start_sta() {
	esp_err_t err = esp_wifi_set_mode(WIFI_MODE_STA);
	err = esp_wifi_start();
}

esp_err_t ath_wifi_start_ap() {
	esp_err_t err = esp_wifi_set_mode(WIFI_MODE_AP);
	err = esp_wifi_start();
}


