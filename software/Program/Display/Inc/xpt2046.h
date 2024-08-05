/**
 * @file xpt2046.h
 * @brief Header file for XPT2046 touch screen controller driver.
 * 
 * This file contains the declarations for the XPT2046 touch screen controller driver.
 * It includes function prototypes for reading touch coordinates, handling interrupts, 
 * calibrating the touch screen, and performing basic tests. The calibration procedure 
 * is implemented based on Texas Instruments' application note SLYT277 "Calibration in touch-screen systems".
 *
 * @see https://www.ti.com/lit/an/slyt277/slyt277.pdf for calibration details.
 */


#ifndef INC_XPT2046_H_
#define INC_XPT2046_H_

#include "main.h"

#define XPT2046_HOR_RES     			240			/*!< Horizontal resolution of the touch screen */
#define XPT2046_VER_RES     			320			/*!< Vertical resolution of the touch screen */
#define XPT2046_MAX_SAMPLES				100			/*!< Maximum number of samples for touch averaging */


/**
 * @brief Touch states for XPT2046.
 */
typedef enum
{
	XPT2046_PRESSED,          /*!< Touch screen is pressed */
	XPT2046_NOT_PRESSED       /*!< Touch screen is not pressed */
} XPT2046States_t;


/**
 * @brief Calibration values for XPT2046.
 */
typedef struct
{
	float alpha;              /*!< Calibration coefficient alpha */
	float beta;               /*!< Calibration coefficient beta */
	float delta;              /*!< Calibration coefficient delta */
} XPT2046CalibrationValues_t;


/**
 * @brief Coordinates structure for XPT2046.
 */
typedef struct
{
	uint16_t x;               /*!< X coordinate */
	uint16_t y;               /*!< Y coordinate */
} XPT2046Coordinates_t;


/**
 * @brief Handle structure for XPT2046.
 */
typedef struct
{
	XPT2046CalibrationValues_t x_calib_values;  /*!< Calibration values for X axis */
	XPT2046CalibrationValues_t y_calib_values;  /*!< Calibration values for Y axis */
	XPT2046Coordinates_t last_coor;             /*!< Last known coordinates */
	XPT2046States_t state;                      /*!< Current touch state */
} XPT2046Handle_t;


/**
 * @brief Reads the IRQ pin state of the XPT2046.
 * 
 * @retval uint8_t 1 if the pin is high, 0 if the pin is low.
 */
uint8_t XPT2046_ReadIRQPin(void);


/**
 * @brief Reads raw touch data from the XPT2046.
 * 
 * @param x Pointer to store the raw x-coordinate.
 * @param y Pointer to store the raw y-coordinate.
 */
void XPT2046_ReadRawData(uint16_t *x, uint16_t *y);


/**
 * @brief Reads calibrated touch coordinates from the XPT2046.
 * 
 * @param handle Pointer to the XPT2046 handle structure.
 */
void XPT2046_ReadData(XPT2046Handle_t *handle);


/**
 * @brief Handles touch interrupt for the XPT2046.
 * 
 * @param handle Pointer to the XPT2046 handle structure.
 */
void XPT2046_IRQHandler(XPT2046Handle_t *handle);


/**
 * @brief Callback function for the XPT2046 touch controller.
 * 
 * This is a weak function that can be overridden by the user.
 * It is called when a touch event is processed.
 * 
 * @param handle Pointer to the XPT2046 handle structure.
 */
void XPT2046_CallBack(XPT2046Handle_t *handle) __attribute__((weak));


/**
 * @brief Calibrates the XPT2046 touch controller.
 * 
 * @param handle Pointer to the XPT2046 handle structure.
 */
void XPT2046_Calibrate(XPT2046Handle_t *handle);


/**
 * @brief Sets the calibration values for the XPT2046 touch controller.
 * 
 * @param handle Pointer to the XPT2046 handle structure.
 * @param x_calib Pointer to the calibration values for the X axis.
 * @param y_calib Pointer to the calibration values for the Y axis.
 */
void XPT2046_SetCalibrationValues(XPT2046Handle_t *handle, XPT2046CalibrationValues_t *x_calib, XPT2046CalibrationValues_t *y_calib);


/**
 * @brief Gets the calibration values from the XPT2046 touch controller.
 * 
 * @param handle Pointer to the XPT2046 handle structure.
 * @param x_calib Pointer to store the calibration values for the X axis.
 * @param y_calib Pointer to store the calibration values for the Y axis.
 */
void XPT2046_GetCalibrationValues(XPT2046Handle_t *handle, XPT2046CalibrationValues_t *x_calib, XPT2046CalibrationValues_t *y_calib);


/**
 * @brief Tests the XPT2046 touch controller.
 * 
 * @param handle Pointer to the XPT2046 handle structure.
 */
void XPT2046_Test(XPT2046Handle_t *handle);


#endif /* INC_XPT2046_H_ */
