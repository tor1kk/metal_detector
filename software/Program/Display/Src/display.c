/**
 * @file display.c
 * @brief Implementation file for display and touch handling.
 *
 * This file contains the implementation for initializing and managing the display and touch
 * input for the system. It includes functions for setting up the LVGL display buffer,
 * flushing display data, and reading touch input from the XPT2046 touch screen controller.
 * The file also includes a callback function for the ILI9341 display driver to indicate
 * when a window fill operation is complete.
 *
 * Created on: Jul 5, 2024
 * Author: Viktor
 */

#include "display.h"
#include "lvgl.h"
#include "spi.h"


lv_display_t *display;      				/*!< Pointer to the LVGL display object */
lv_indev_t *indev;          				/*!< Pointer to the LVGL input device object */


XPT2046Handle_t xpt2046Handle;    			/*!< Handle for the XPT2046 touch screen controller */
SPI_HandleTypeDef *ili9341_spi = &hspi1;   	/*!< SPI handle for the ILI9341 display */
SPI_HandleTypeDef *xpt2046_spi = &hspi3;  	/*!< SPI handle for the XPT2046 touch screen */


/**
 * @brief Flush the display buffer to the ILI9341 display.
 *
 * This function is called by LVGL to update the display area.
 * It sets the window area on the ILI9341 and then starts the DMA transfer.
 *
 * @param disp Pointer to the display structure.
 * @param area Pointer to the area to be updated.
 * @param px_map Pointer to the pixel map containing the buffer data.
 */
static void dp_lvgl_flush(lv_display_t * disp, const lv_area_t * area, uint8_t * px_map)
{
	uint32_t buff_len = 2 * ( (area->x2 - area->x1 + 1) * (area->y2 - area->y1 + 1) );

	/* Set the window area on the ILI9341 display */
	ILI9341_SetWindow(area->x1, area->x2, area->y1, area->y2);

	/* Start DMA transfer to fill the window */
	ILI9341_FillWindowDMA((uint8_t *)px_map, buff_len);
}


/**
 * @brief Read touch input data from the XPT2046 touchscreen.
 *
 * This function is called by LVGL to get touch input data from the XPT2046 touchscreen.
 * It checks if the screen is pressed and reads the coordinates if it is.
 *
 * @param indev Pointer to the input device structure.
 * @param data Pointer to the data structure where the touch input will be stored.
 */
static void dp_lvgl_read(lv_indev_t * indev, lv_indev_data_t*data)
{
    /* Check if the touchscreen is pressed */
    if( !XPT2046_ReadIRQPin() ) {
		data->state = LV_INDEV_STATE_PRESSED;

		/* Read the touch data from XPT2046 */
		XPT2046_ReadData(&xpt2046Handle);

		/* Set the touch coordinates */
		data->point.x = xpt2046Handle.last_coor.x;
		data->point.y = xpt2046Handle.last_coor.y;
    } else {
    	data->state = LV_INDEV_STATE_RELEASED;
    }
}


/**
 * @brief Initialize the display and touchscreen.
 *
 * This function initializes the ILI9341 display and the XPT2046 touchscreen,
 * including setting calibration values for the touchscreen.
 */
void dp_init(void)
{
	XPT2046CalibrationValues_t x_calib =
	{
		.alpha = 2.32558131,
		.beta = -0.116279073,
		.delta = -373.604645
	};

	XPT2046CalibrationValues_t y_calib =
	{
		.alpha = -0,
		.beta = 2.33333325,
		.delta = -297.666656
	};

	/* Initialize the ILI9341 display */
	ILI9341_Init();

	/* Set calibration values for the XPT2046 touchscreen */
	XPT2046_SetCalibrationValues(&xpt2046Handle, &x_calib, &y_calib);
}


/**
 * @brief Initialize LVGL and set up the display buffer and input device.
 *
 * This function initializes LVGL, creates a display and input device, sets up
 * the display buffer, and assigns callback functions for display flushing
 * and input reading.
 */
void dp_lvgl_init(void)
{
	/* Declare a buffer for 1/10 screen size */
	static lv_color_t buf1[MY_DISP_HOR_RES * MY_DISP_VER_RES / 10];
	static lv_color_t buf2[MY_DISP_HOR_RES * MY_DISP_VER_RES / 10];

	/* Initialize LVGL library */
	lv_init();

	/* Create a display object */
	display = lv_display_create((int32_t)MY_DISP_VER_RES, (int32_t)MY_DISP_HOR_RES);

	/* Create an input device object */
	indev = lv_indev_create();

	/* Initialize the display buffer */
	lv_display_set_buffers(display, buf1, buf2, sizeof(buf1), LV_DISPLAY_RENDER_MODE_PARTIAL);

	/* Set the flush callback function for the display */
	lv_display_set_flush_cb(display, dp_lvgl_flush);

	/* Set up the input device */
	lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
	lv_indev_set_read_cb(indev, dp_lvgl_read);
}


/**
 * @brief Callback function for ILI9341 fill window complete.
 *
 * This function is called when the DMA transfer to fill the window on the
 * ILI9341 display is complete. It signals LVGL that the flush operation
 * is done and the display is ready for the next update.
 */
void ILI9341_FillWindowCmpltCallBack(void)
{
	/* Indicate you are ready with the flushing */
	lv_display_flush_ready(display);
}
