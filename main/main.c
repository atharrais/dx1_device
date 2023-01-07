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
