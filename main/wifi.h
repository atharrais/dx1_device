/*
 *
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

/**
 * @brief
 */
typedef struct {
	/*@{*/
	wifi_init_config_t config;	/**< Wifi API configuration */
	wifi_mode_t mode;			/**< Wifi mode */
	/*@}*/
} auth_wifi_config_s;

esp_err_t ath_wifi_initi(wifi_init_config_t* config, wifi_mode_t mode = WIFI_MODE_STA);







static void wifi_event_handler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data) {
	//
}

static void ip_event_handler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data) {
	//
}

#endif /* ATH_WIFI_H_ */
