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
 * @brief logging.h
 */

#pragma once

#include "esp_system.h"
#include "esp_log.h"

#ifndef ATH_LOGGING_H_
#define ATH_LOGGING_H_

#define ATH_BLU_TAG "BLUETOOTH"
#define ATH_BLU_INFO(fmt, ...)   ESP_LOGI(ATH_BLU_TAG, fmt, ##__VA_ARGS__)
#define ATH_BLU_ERROR(fmt, ...)  ESP_LOGE(ATH_BLU_TAG, fmt, ##__VA_ARGS__)

#define ATH_WIFI_TAG "WIFI"
#define ATH_WIFI_INFO(fmt, ...)   ESP_LOGI(ATH_WIFI_TAG, fmt, ##__VA_ARGS__)
#define ATH_WIFI_ERROR(fmt, ...)  ESP_LOGE(ATH_WIFI_TAG, fmt, ##__VA_ARGS__)

#define ATH_STR_TAG "STORAGE"
#define ATH_STR_INFO(fmt, ...)   ESP_LOGI(ATH_STR_TAG, fmt, ##__VA_ARGS__)
#define ATH_STR_ERROR(fmt, ...)  ESP_LOGE(ATH_STR_TAG, fmt, ##__VA_ARGS__)

#define ATH_APP_TAG "ATHARRAIS"
#define ATH_APP_INFO(fmt, ...)   ESP_LOGI(ATH_APP_TAG, fmt, ##__VA_ARGS__)
#define ATH_APP_ERROR(fmt, ...)  ESP_LOGE(ATH_APP_TAG, fmt, ##__VA_ARGS__)

#endif /* ATH_LOGGING_H_ */
