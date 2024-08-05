/**
 * @file xpt2046.c
 * @brief Implementation file for XPT2046 touch screen controller driver.
 *
 * This file contains the implementation of the XPT2046 touch screen controller driver.
 * It includes functions for reading touch coordinates, handling interrupts, calibrating
 * the touch screen, and performing basic tests. The calibration procedure is implemented
 * based on Texas Instruments' application note SLYT277 "Calibration in touch-screen systems".
 *
 * @see https://www.ti.com/lit/an/slyt277/slyt277.pdf for calibration details.
 */

#include "xpt2046.h"
#include "ili9341.h"


#define CMD_X_READ                    0b10010000  /*!< Command for reading X position */
#define CMD_Y_READ                    0b11010000  /*!< Command for reading Y position */


extern SPI_HandleTypeDef *xpt2046_spi;


static uint8_t transmit_receive_byte(uint8_t data);
static void manage_cs(uint8_t state);
static void draw_target(uint32_t x, uint32_t y, uint16_t color);

static const float XPT2046_VER_COEF = (float)XPT2046_VER_RES / 4096;
static const float XPT2046_HOR_COEF = (float)XPT2046_HOR_RES / 4096;


/**
 * @brief Reads the IRQ pin state of the XPT2046.
 * 
 * This function reads the state of the IRQ pin of the XPT2046 touch controller.
 * 
 * @retval uint8_t: 1 if the pin is high, 0 if the pin is low.
 */
uint8_t XPT2046_ReadIRQPin(void)
{
    return HAL_GPIO_ReadPin(XPT2046_IRQ_GPIO_Port, XPT2046_IRQ_Pin);
}


/**
 * @brief Reads calibrated touch coordinates from the XPT2046.
 * 
 * This function reads raw touch data from the XPT2046 and applies calibration
 * coefficients to convert them to screen coordinates.
 * 
 * @param handle Pointer to the XPT2046 handle structure.
 */
void XPT2046_ReadData(XPT2046Handle_t *handle)
{
    uint16_t x = 0, y = 0;
    float x_f = 0, y_f = 0;

    /* Read raw data from the touch controller */
    XPT2046_ReadRawData(&x, &y);

    /* Apply calibration coefficients */
    x_f = handle->x_calib_values.alpha * x + handle->x_calib_values.beta * y + handle->x_calib_values.delta;
    y_f = handle->y_calib_values.alpha * x + handle->y_calib_values.beta * y + handle->y_calib_values.delta;

    /* Clamp values to display resolution */
    if (x_f > ILI9341_VER_RES)
    {
        x_f = ILI9341_VER_RES;
    }

    if (y_f > ILI9341_HOR_RES)
    {
        y_f = ILI9341_HOR_RES;
    }

    /* Update handle with the last known coordinates */
    handle->last_coor.x = (uint16_t)x_f;
    handle->last_coor.y = (uint16_t)y_f;
}


/**
 * @brief Reads raw touch data from the XPT2046.
 * 
 * This function reads the raw touch data from the XPT2046 touch controller by sending
 * appropriate commands via SPI and processing the received data. It implements a simple
 * averaging filter to improve the touch data quality.
 * 
 * @param x Pointer to store the raw x-coordinate.
 * @param y Pointer to store the raw y-coordinate.
 */
void XPT2046_ReadRawData(uint16_t *x, uint16_t *y)
{
    uint8_t buff = 0;
    uint16_t local_x = 0, local_y = 0, samples_counter = 0;
    uint32_t x_samples = 0, y_samples = 0;

    /* Lower the CS pin to start communication */
    manage_cs(GPIO_PIN_RESET);

    do
    {
        /* Start x read */
        transmit_receive_byte(CMD_X_READ);

        /* Read x MSB */
        buff = transmit_receive_byte(0);
        local_x = buff << 8;
        
        /* Until x LSB converted y command can be sent */
        buff = transmit_receive_byte(CMD_Y_READ);
        local_x |= buff;

        /* Read y MSB */
        buff = transmit_receive_byte(0);
        local_y = buff << 8;

        /* Read y LSB */
        buff = transmit_receive_byte(0);
        local_y |= buff;

        /* Adjust raw data */
        local_x = local_x >> 4;
        local_y = local_y >> 4;

        /* Apply calibration coefficients */
        local_x *= XPT2046_VER_COEF;
        local_y *= XPT2046_HOR_COEF;

        /* Accumulate samples */
        x_samples += local_x;
        y_samples += local_y;

        samples_counter++;
    } while (!XPT2046_ReadIRQPin() && samples_counter < XPT2046_MAX_SAMPLES);

    /* Raise the CS pin to end communication */
    manage_cs(GPIO_PIN_SET);

    /* Average the samples */
    local_x = x_samples / samples_counter;
    local_y = y_samples / samples_counter;

    /* Update output parameters */
    *x = local_x;
    *y = local_y;
}


/**
 * @brief Handles touch interrupt for the XPT2046.
 * 
 * This function is the interrupt handler for the XPT2046 touch controller. It reads
 * the touch data and updates the touch state.
 * 
 * @param handle Pointer to the XPT2046 handle structure.
 */
void XPT2046_IRQHandler(XPT2046Handle_t *handle)
{
    uint16_t x = 0, y = 0;

    /* Read touch data */
    XPT2046_ReadData(handle);

    /* Update handle state */
    handle->state = XPT2046_PRESSED;
    handle->last_coor.x = x;
    handle->last_coor.y = y;

    /* Call the user-defined callback function */
    XPT2046_CallBack(handle);
}


/**
 * @brief Calibrates the XPT2046 touch controller.
 * 
 * This function performs calibration of the XPT2046 touch controller using three 
 * reference points on the screen. The calibration process is based on the method 
 * described in the TI application note SLYT277.
 * 
 * @param handle Pointer to the XPT2046 handle structure.
 */
void XPT2046_Calibrate(XPT2046Handle_t *handle)
{
    XPT2046Coordinates_t actual_coor[3] =
    {
        {.x = 55, .y = 15},
        {.x = ILI9341_VER_RES / 4, .y = ILI9341_HOR_RES / 2},
        {.x = ILI9341_VER_RES - 15, .y = ILI9341_HOR_RES - 55}
    };
    XPT2046Coordinates_t sampled_coor[3] = {0};
    float delta = 0, delta_x[3] = {0}, delta_y[3] = {0};

    for(uint32_t i = 0; i < 3; i++)
    {
        /* Draw the calibration target on the screen */
        draw_target(actual_coor[i].x, actual_coor[i].y, 0xF800);

        /* Wait for the user to press the target */
        HAL_Delay(500);

        while( XPT2046_ReadIRQPin() );

        /* Read the raw data when the user touches the screen */
        XPT2046_ReadRawData(&sampled_coor[i].x, &sampled_coor[i].y);

        /* Wait for the user to release the touch */
        while( !XPT2046_ReadIRQPin() );

        /* Erase the calibration target */
        draw_target(actual_coor[i].x, actual_coor[i].y, 0xFFFF);
    }

    /* Calculate the calibration coefficients */
    delta = (sampled_coor[0].x - sampled_coor[2].x) * (sampled_coor[1].y - sampled_coor[2].y) - \
            (sampled_coor[1].x - sampled_coor[2].x) * (sampled_coor[0].y - sampled_coor[2].y);

    delta_x[0] = (actual_coor[0].x - actual_coor[2].x) * (sampled_coor[1].y - sampled_coor[2].y) - \
                 (actual_coor[1].x - actual_coor[2].x) * (sampled_coor[0].y - sampled_coor[2].y);

    delta_x[1] = (sampled_coor[0].x - sampled_coor[2].x) * (actual_coor[1].x - actual_coor[2].x) - \
                 (sampled_coor[1].x - sampled_coor[2].x) * (actual_coor[0].x - actual_coor[2].x);

    delta_x[2] = actual_coor[0].x * (sampled_coor[1].x * sampled_coor[2].y - sampled_coor[2].x * sampled_coor[1].y) - \
                 actual_coor[1].x * (sampled_coor[0].x * sampled_coor[2].y - sampled_coor[2].x * sampled_coor[0].y) + \
                 actual_coor[2].x * (sampled_coor[0].x * sampled_coor[1].y - sampled_coor[1].x * sampled_coor[0].y);

    delta_y[0] = (actual_coor[0].y - actual_coor[2].y) * (sampled_coor[1].y - sampled_coor[2].y) - \
                 (actual_coor[1].y - actual_coor[2].y) * (sampled_coor[0].y - sampled_coor[2].y);

    delta_y[1] = (sampled_coor[0].x - sampled_coor[2].x) * (actual_coor[1].y - actual_coor[2].y) - \
                 (sampled_coor[1].x - sampled_coor[2].x) * (actual_coor[0].y - actual_coor[2].y);

    delta_y[2] = actual_coor[0].y * (sampled_coor[1].x * sampled_coor[2].y - sampled_coor[2].x * sampled_coor[1].y) - \
                 actual_coor[1].y * (sampled_coor[0].x * sampled_coor[2].y - sampled_coor[2].x * sampled_coor[0].y) + \
                 actual_coor[2].y * (sampled_coor[0].x * sampled_coor[1].y - sampled_coor[1].x * sampled_coor[0].y);

    /* Update calibration values in the handle structure */
    handle->x_calib_values.alpha = delta_x[0] / delta;
    handle->x_calib_values.beta = delta_x[1] / delta;
    handle->x_calib_values.delta = delta_x[2] / delta;

    handle->y_calib_values.alpha = delta_y[0] / delta;
    handle->y_calib_values.beta = delta_y[1] / delta;
    handle->y_calib_values.delta = delta_y[2] / delta;
}


/**
 * @brief Sets the calibration values for the XPT2046 touch controller.
 * 
 * This function updates the calibration values for the XPT2046 touch controller.
 * 
 * @param handle Pointer to the XPT2046 handle structure.
 * @param x_calib Pointer to the calibration values for the X axis.
 * @param y_calib Pointer to the calibration values for the Y axis.
 */
void XPT2046_SetCalibrationValues(XPT2046Handle_t *handle, XPT2046CalibrationValues_t *x_calib, XPT2046CalibrationValues_t *y_calib)
{
    handle->x_calib_values = *x_calib;
    handle->y_calib_values = *y_calib;
}


/**
 * @brief Gets the calibration values from the XPT2046 touch controller.
 * 
 * This function retrieves the current calibration values from the XPT2046 touch controller.
 * 
 * @param handle Pointer to the XPT2046 handle structure.
 * @param x_calib Pointer to store the calibration values for the X axis.
 * @param y_calib Pointer to store the calibration values for the Y axis.
 */
void XPT2046_GetCalibrationValues(XPT2046Handle_t *handle, XPT2046CalibrationValues_t *x_calib, XPT2046CalibrationValues_t *y_calib)
{
    *x_calib = handle->x_calib_values;
    *y_calib = handle->y_calib_values;
}


/**
 * @brief Tests the XPT2046 touch controller.
 * 
 * This function tests the XPT2046 touch controller by reading the touch coordinates and
 * drawing a target on the screen at the touch location.
 * 
 * @param handle Pointer to the XPT2046 handle structure.
 */
void XPT2046_Test(XPT2046Handle_t *handle)
{
    if (!XPT2046_ReadIRQPin())
    {
        XPT2046_ReadData(handle);
        draw_target(handle->last_coor.x, handle->last_coor.y, 0xF800);
    }

    HAL_Delay(5);
}


/**
 * @brief Weak callback function for the XPT2046 touch controller.
 * 
 * This function is a weakly defined callback that can be overridden by the user.
 * It is called when a touch event is processed.
 * 
 * @param handle Pointer to the XPT2046 handle structure.
 */
__attribute__((weak)) void XPT2046_CallBack(XPT2046Handle_t *handle)
{
    /* User-defined callback implementation */
}


/**
 * @brief Draws a target on the screen at the specified coordinates.
 * 
 * This function draws a small target at the specified (x, y) coordinates on the screen
 * with the given color.
 * 
 * @param x X coordinate of the target.
 * @param y Y coordinate of the target.
 * @param color Color of the target.
 */
static void draw_target(uint32_t x, uint32_t y, uint16_t color)
{
    uint16_t red_buff[81] = {0};

    /* Fill the buffer with the specified color */
    for(uint32_t i = 0; i < sizeof(red_buff) / 2; i++)
    {
        red_buff[i] = color;
    }

    /* Set the drawing window and fill it with the color buffer */
    ILI9341_SetWindow(x - 4, x + 4, y - 4, y + 4);
    ILI9341_FillWindow((uint8_t *)red_buff, sizeof(red_buff));
    ILI9341_SetWindow(0, 0, 0, 0);
}


/**
 * @brief Transmits and receives a byte via SPI.
 * 
 * This function transmits a byte of data via SPI and receives a byte of data in response.
 * 
 * @param data Byte of data to be transmitted.
 * @retval uint8_t Byte of data received in response.
 */
static uint8_t transmit_receive_byte(uint8_t data)
{
    uint8_t buff = 0;

    HAL_SPI_TransmitReceive(xpt2046_spi, &data, &buff, 1, HAL_MAX_DELAY);

    return buff;
}


/**
 * @brief Manages the chip select (CS) pin state.
 * 
 * This function sets the state of the CS pin to either low (active) or high (inactive).
 * 
 * @param state Desired state of the CS pin (GPIO_PIN_RESET or GPIO_PIN_SET).
 */
static void manage_cs(uint8_t state)
{
    HAL_GPIO_WritePin(XPT2046_CS_GPIO_Port, XPT2046_CS_Pin, state);
}





