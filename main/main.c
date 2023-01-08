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
 * @brief main.c
 */

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "storage.h"
#include "features.h"

#include "unboxed.h"

#include "logging.h"
#include "globals.h"

/**
 * @brief Starting the application.
 */
void app_main(void) {
	ATH_APP_INFO("Welcome to Atharrais DX-1 Module. Starting initialization.");

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
	ath_storage_getFeatureFlags(&_storage, &ATH_APP_CONTEXT->featureFlags);
	if(_storage.error == ESP_ERR_NVS_NOT_FOUND) {
		ATH_APP_ERROR("No flags in NVS, creating new.");
		ath_storage_setFeatureFlags(&_storage, ATH_APP_CONTEXT->featureFlags);
		ESP_ERROR_CHECK(_storage.error);
	}
	else ESP_ERROR_CHECK(_storage.error);
	ath_storage_close(&_storage);

	if(ath_features_isConfigured(ATH_APP_CONTEXT->featureFlags)) {
		// Start up the app as normal.
	}
	else {
		ATH_APP_INFO("First time boot, setting up unboxed applet.");
		//ath_wifi_gblconfig_create(&ATH_APP_CONTEXT->wifi);

	}
}
