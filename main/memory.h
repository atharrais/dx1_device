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
 * @brief memory.h
 *
 * @details Thread and Security Safe memory functions.
 *
 * @author Robert R Murrell
 */

#ifndef ATH_MEMORY_H_
#define ATH_MEMORY_H_

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "freertos/FreeRTOS.h"

/**
 * @brief Allocates a buffer of memory from the heap.
 *
 * @details This function suspends FreeRTOS scheduler, allocates the memory, then
 *          resumes the scheduler.
 *
 * @param[in] size The size of the block of memory to create.
 * @param[in] safe Sets all bytes to zero before returning the pointer.
 */
static void* ath_malloc(size_t size) {
	vTaskSuspendAll();
	void* _pntr = malloc(size);
	memset(_pntr, 0, size);
	xTaskResumeAll();
	return _pntr;
}

/**
 * @brief Memory copy.
 *
 * @details Shallow copies memory, byte-for-byte from the source to the target up to the
 *          size specified.
 *
 * @param[in] source Source to copy from.
 * @param[in] target Target to copy to.
 * @param[in] size The amount of bytes to copy.
 */
static void ath_memcopy(void* source, void* target, size_t size) {
	memcpy(target, source, size);
}

/**
 * @brief Memory copy.
 *
 * @details Shallow copies memory, byte-for-byte from the source to the target up to the
 *          size specified.
 *
 * @param[in] target The memory to set.
 * @param[in] value The value to set.
 * @param[in] size The amount of bytes to set.
 */
static void ath_memset(void* target, int value, size_t size) {
	memset(target, value, size);
}

/**
 * @brief Deallocates the memory.
 *
 * @details This function suspends FreeRTOS scheduler, frees the memory, then
 *          resumes the scheduler. The function sets all bytes to 0 before freeing.
 *
 * @param[in] pntr The pointer to the memory to free.
 * @param[in] size_t The size of bytes to set to zero.
 */
static void ath_free(void* pntr, size_t size) {
	vTaskSuspendAll();
	memset(pntr, 0, size);
	free(pntr);
	xTaskResumeAll();
}

#endif /* ATH_MEMORY_H_ */
