/**
 * @file display.h
 * @brief Header file for the display functionality.
 *
 * This file contains the declarations for functions and extern variables related to the display functionality.
 * It includes functions for initializing the display and setting up LVGL for the display and input device.
 * Additionally, it defines the external SPI handles used for interfacing with the ILI9341 and XPT2046.
 *
 * Created on: Jul 5, 2024
 * Author: Viktor
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_


#include "ili9341.h"
#include "xpt2046.h"


void dp_lvgl_init(void);
void dp_init(void);

extern SPI_HandleTypeDef *ili9341_spi;
extern SPI_HandleTypeDef *xpt2046_spi;


#endif /* INC_DISPLAY_H_ */
