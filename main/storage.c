/*
 *
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
