#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "storage.h"
#include "features.h"

/**
 * @brief Structure to hold global application state.
 *
 * @details Holds global application state across FreeRTOS threads and application
 *          states.
 */
typedef struct {
	/*@{*/
	uint32_t featureFlags;			/**< Feature flags from NVS Flash. */
	wifi_init_config_t wifiConfig;	/**< Wifi Configuration for Atharrais. */
	/*@}*/
} ath_context_s;

static ath_context_s* GBL_CONST_APP_CONTEXT = &(ath_context_s){
	.featureFlags = 0
};

/**
 * @brief Starting the application.
 */
void app_main(void) {
	// Initialize Storage
	ESP_ERROR_CHECK(ath_storage_initi());

	// Loads the feature flags from storage.
	ath_storage_s _storage = {
		.id = 0,
		.namespace = "fflags",
		.mode = NVS_READWRITE,
		.error = ESP_OK
	};
	ath_storage_open(&_storage);
	ESP_ERROR_CHECK(_storage.error);
	ath_storage_getFeatureFlags(&_storage, &GBL_CONST_APP_CONTEXT->featureFlags);
	ESP_ERROR_CHECK(_storage.error);
	ath_storage_close(&_storage);

	if(ath_features_isConfigured(GBL_CONST_APP_CONTEXT->featureFlags)) {
		// Start up the app as normal.
	}
	else {
		// Start in unbox mode and get ready to configure.
	}

}
