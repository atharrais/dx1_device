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
 * @brief storage.h
 */

#include "storage.h"

esp_err_t ath_storage_initi() {
	esp_err_t err = nvs_flash_init();
	if(err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
		err = nvs_flash_erase();
		if(err == ESP_OK)
			return nvs_flash_init();
		else
			return err;
	}
	else return err;
}

void ath_storage_open(ath_storage_s* handle) {
	handle->error = nvs_open(handle->namespace, handle->mode, &handle->id);
}

void ath_storage_getFeatureFlags(ath_storage_s* handle, uint32_t* flags) {
	handle->error = nvs_get_i32(handle->id, handle->namespace, flags);
}

void ath_storage_close(ath_storage_s* handle) {
	nvs_close(handle->id);
}
