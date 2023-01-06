/*
 * Copyright (c) 2023, ATHARRAIS LLC. All rights Reserved
 */
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

/**
 * @brief Application main entry point
 *
 * @description Main entry point to the DX-1 device application.
 *
 * @author Robert R Murrell
 */
void app_main(void) {
	// Enable everything for MPU and such
	// Read flash and see if we are in factory mode
		// Start Bluetooth for app setup
		// Do app setup
		// Write flag out of factory mode
		// Restart
	// Start Wifi and connected to configured wifi
	// Start Monte Carlo Method Look on CPU1
	// Report Data
    while (true) {
        printf("Hello from app_main!\n");
        sleep(1);
    }
}
