/*
 *
 */
/**
 * @brief storage.h, heads storage.c
 *
 * @details Atharrais wrapper around the ESP32 NVS libraries for accessing NVS Flash.
 *
 * @author Robert R Murrell
 */

#ifndef ATH_STORAGE_H_
#define ATH_STORAGE_H_

#include <stdint.h>
#include "esp_system.h"
#include "nvs_flash.h"
#include "nvs.h"

/**
 * @brief Structure to hold storage information.
 */
typedef struct {
	/*@{*/
	const char* namespace;	/**< tThe storage name-space in NVS Flash */
	nvs_handle_t id;		/**< The Storage Handle to the NVS Flash Storage Manager */
	nvs_open_mode_t mode;	/**< The mode enumeration (read only/read write). */
	esp_err_t error;		/**< The error value set after storage operations. */
	/*@}*/
} ath_storage_s;

/**
 * @brief
 *
 * @return esp_err_t Returns ESP_OK if initialization was successful, any other value otherwise.
 */
esp_err_t ath_storage_initi();

/**
 * @brief Opens a new storage handle to the name space specified
 *
 * @param[in] handle A pointer to a Storage structure containing the storage information.
 */
void ath_storage_open(ath_storage_s* handle);

void ath_storage_getFeatureFlags(ath_storage_s* handle, uint32_t* flags);

void ath_storage_close(ath_storage_s* handle);

#endif /* ATH_STORAGE_H_ */
