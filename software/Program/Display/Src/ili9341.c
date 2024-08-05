/**
 * @file ili9341.c
 * @brief Implementation file for the ILI9341 LCD driver.
 *
 * This file contains the implementation of the ILI9341 LCD driver.
 * It includes functions for initialization, command and data transmission,
 * setting window areas, filling windows, and handling DMA completion.
 * The driver is designed to interface with the ILI9341 LCD controller using SPI.
 *
 * Created on: Apr 5, 2024
 * Author: Viktor
 */

#include <string.h>
#include <stdint.h>
#include "ili9341.h"

#define DMA_CHUNK_MAX_LEN                (uint16_t)0xFFFFFF

extern SPI_HandleTypeDef *ili9341_spi;

static ILI9341CurrentBuffer_t _gILI9341CurrentBuffer = {0};

static void ConvHL(uint8_t *s, int32_t l);

/**
 * @brief Initializes the ILI9341 LCD.
 *
 * This function initializes the ILI9341 LCD by sending a sequence of commands and data to set up the display.
 * It performs a software reset, sets up power control, VCOM control, pixel format, and display orientation.
 * It also configures frame rate and gamma settings if enabled.
 */
void ILI9341_Init(void)
{
    uint8_t data[15];

    /* Software reset */
    ILI9341_WriteCommand(ILI9341_SWRESET);
    ILI9341_DELAY(5);
    ILI9341_WriteCommand(ILI9341_DISPOFF);

    /* Startup sequence */
    ILI9341_WriteCommand(ILI9341_PWCTRLB);
    data[0] = 0x00;
    data[1] = 0x83;
    data[2] = 0x30;
    ILI9341_WriteData(data, 3);

    ILI9341_WriteCommand(ILI9341_PWSEQCTRL);
    data[0] = 0x64;
    data[1] = 0x03;
    data[2] = 0x12;
    data[3] = 0x81;
    ILI9341_WriteData(data, 4);

    ILI9341_WriteCommand(ILI9341_TIMECTRLA_INT);
    data[0] = 0x85;
    data[1] = 0x01;
    data[2] = 0x79;
    ILI9341_WriteData(data, 3);

    ILI9341_WriteCommand(ILI9341_PWCTRLA);
    data[0] = 0x39;
    data[1] = 0x2c;
    data[2] = 0x00;
    data[3] = 0x34;
    data[4] = 0x02;
    ILI9341_WriteData(data, 5);

    ILI9341_WriteCommand(ILI9341_PUMPRATIO);
    data[0] = 0x20;
    ILI9341_WriteData(data, 1);

    ILI9341_WriteCommand(ILI9341_TIMECTRLB);
    data[0] = 0x00;
    data[1] = 0x00;
    ILI9341_WriteData(data, 2);

    /* Power control */
    ILI9341_WriteCommand(ILI9341_PWCTRL1);
    data[0] = 0x26;
    ILI9341_WriteData(data, 1);

    ILI9341_WriteCommand(ILI9341_PWCTRL2);
    data[0] = 0x11;
    ILI9341_WriteData(data, 1);

    /* VCOM control */
    ILI9341_WriteCommand(ILI9341_VMCTRL1);
    data[0] = 0x35;
    data[1] = 0x3e;
    ILI9341_WriteData(data, 2);

    ILI9341_WriteCommand(ILI9341_VMCTRL2);
    data[0] = 0xbe;
    ILI9341_WriteData(data, 1);

    /* Set orientation */
    ILI9341_Rotate(90, ILI9341_BGR);

    /* 16-bit pixel format */
    ILI9341_WriteCommand(ILI9341_PIXSET);
    data[0] = 0x55;
    ILI9341_WriteData(data, 1);

    /* Frame rate */
    ILI9341_WriteCommand(ILI9341_FRMCTR1);
    data[0] = 0x00;
    data[1] = 0x1b;
    ILI9341_WriteData(data, 2);

#if ILI9341_GAMMA
    /* Gamma curve set */
    ILI9341_WriteCommand(ILI9341_GAMSET);
    data[0] = 0x01;
    ILI9341_WriteData(data, 1);

    /* Positive gamma correction */
    ILI9341_WriteCommand(ILI9341_PGAMCTRL);
    data[0]  = 0x1f;
    data[1]  = 0x1a;
    data[2]  = 0x18;
    data[3]  = 0x0a;
    data[4]  = 0x0f;
    data[5]  = 0x06;
    data[6]  = 0x45;
    data[7]  = 0x87;
    data[8]  = 0x32;
    data[9]  = 0x0a;
    data[10] = 0x07;
    data[11] = 0x02;
    data[12] = 0x07;
    data[13] = 0x05;
    data[14] = 0x00;
    ILI9341_WriteData(data, 15);

    /* Negative gamma correction */
    ILI9341_WriteCommand(ILI9341_NGAMCTRL);
    data[0]  = 0x00;
    data[1]  = 0x25;
    data[2]  = 0x27;
    data[3]  = 0x05;
    data[4]  = 0x10;
    data[5]  = 0x09;
    data[6]  = 0x3a;
    data[7]  = 0x78;
    data[8]  = 0x4d;
    data[9]  = 0x05;
    data[10] = 0x18;
    data[11] = 0x0d;
    data[12] = 0x38;
    data[13] = 0x3a;
    data[14] = 0x1f;
    ILI9341_WriteData(data, 15);
#endif

    /* Window horizontal */
    ILI9341_WriteCommand(ILI9341_CASET);
    data[0] = 0;
    data[1] = 0;
    data[2] = (ILI9341_HOR_RES - 1) >> 8;
    data[3] = (uint8_t) (ILI9341_HOR_RES - 1);
    ILI9341_WriteData(data, 4);

    /* Window vertical */
    ILI9341_WriteCommand(ILI9341_PASET);
    data[0] = 0;
    data[1] = 0;
    data[2] = (ILI9341_VER_RES - 1) >> 8;
    data[3] = (uint8_t) (ILI9341_VER_RES - 1);
    ILI9341_WriteData(data, 4);

    ILI9341_WriteCommand(ILI9341_RAMWR);

#if ILI9341_TEARING
    /* Tearing effect off */
    ILI9341_WriteCommand(ILI9341_TEOFF);

    /* Tearing effect on */
    ILI9341_WriteCommand(ILI9341_TEON);
#endif

    /* Entry mode set */
    ILI9341_WriteCommand(ILI9341_ETMOD);
    data[0] = 0x07;
    ILI9341_WriteData(data, 1);

    /* Display function control */
    ILI9341_WriteCommand(ILI9341_DISCTRL);
    data[0] = 0x0a;
    data[1] = 0x82;
    data[2] = 0x27;
    data[3] = 0x00;
    ILI9341_WriteData(data, 4);

    /* Exit sleep mode */
    ILI9341_WriteCommand(ILI9341_SLPOUT);

    ILI9341_DELAY(100);

    /* Display on */
    ILI9341_WriteCommand(ILI9341_DISPON);

    ILI9341_DELAY(20);
}


/**
 * @brief Writes a command to the ILI9341 LCD.
 *
 * This function sends a command byte to the ILI9341 LCD controller.
 * It resets the chip select and data/command pins, transmits the command via SPI,
 * and then sets the chip select and data/command pins back.
 *
 * @param cmd Command byte to be sent to the LCD.
 */
void ILI9341_WriteCommand(uint8_t cmd)
{
    /* Reset chip select(SS) pin */
    HAL_GPIO_WritePin(ILI9341_CS_GPIO_Port, ILI9341_CS_Pin, RESET);

    /* Reset data/command pin */
    HAL_GPIO_WritePin(ILI9341_DC_GPIO_Port, ILI9341_DC_Pin, RESET);

    /* Write command */
    HAL_SPI_Transmit(ili9341_spi, (uint8_t *)&cmd, 1, HAL_MAX_DELAY);

    /* Set chip select(SS) pin */
    HAL_GPIO_WritePin(ILI9341_CS_GPIO_Port, ILI9341_CS_Pin, SET);

    /* Set data/command pin */
    HAL_GPIO_WritePin(ILI9341_DC_GPIO_Port, ILI9341_DC_Pin, SET);
}


/**
 * @brief Writes data to the ILI9341 LCD.
 *
 * This function sends a data buffer to the ILI9341 LCD controller.
 * It resets the chip select pin, transmits the data via SPI, and then sets the chip select pin back.
 *
 * @param data_buff Pointer to the data buffer to be sent to the LCD.
 * @param data_len Length of the data buffer.
 */
void ILI9341_WriteData(uint8_t *data_buff, uint32_t data_len)
{
    /* Reset chip select(SS) pin */
    HAL_GPIO_WritePin(ILI9341_CS_GPIO_Port, ILI9341_CS_Pin, RESET);

    /* Write data */
    HAL_SPI_Transmit(ili9341_spi, (uint8_t *)data_buff, data_len, HAL_MAX_DELAY);

    /* Set chip select(SS) pin */
    HAL_GPIO_WritePin(ILI9341_CS_GPIO_Port, ILI9341_CS_Pin, SET);
}


/**
 * @brief Sets the window area for the ILI9341 LCD.
 *
 * This function defines the rectangular area on the LCD where subsequent pixel data will be written.
 * It sends the column address set (CASET) and page address set (PASET) commands with the specified coordinates.
 *
 * @param x_axis_start Starting X-axis position.
 * @param x_axis_end Ending X-axis position.
 * @param y_axis_start Starting Y-axis position.
 * @param y_axis_end Ending Y-axis position.
 */
void ILI9341_SetWindow(uint16_t x_axis_start, uint16_t x_axis_end, uint16_t y_axis_start, uint16_t y_axis_end)
{
    uint8_t data[4];

    /* Set column address */
    ILI9341_WriteCommand(ILI9341_CASET);
    data[0] = x_axis_start >> 8;
    data[1] = x_axis_start & 0xFF;
    data[2] = x_axis_end >> 8;
    data[3] = x_axis_end & 0xFF;
    ILI9341_WriteData(data, 4);

    /* Set page address */
    ILI9341_WriteCommand(ILI9341_PASET);
    data[0] = y_axis_start >> 8;
    data[1] = y_axis_start & 0xFF;
    data[2] = y_axis_end >> 8;
    data[3] = y_axis_end & 0xFF;
    ILI9341_WriteData(data, 4);
}


/**
 * @brief Fills the window area of the ILI9341 LCD using DMA.
 *
 * This function fills the defined window area on the LCD with pixel data from a buffer using DMA.
 * It converts the high and low bytes of the buffer, writes the RAM write (RAMWR) command,
 * and initiates the DMA transfer.
 *
 * @param buff Pointer to the buffer containing the data to be written to the LCD.
 * @param buff_len Length of the data buffer.
 */
void ILI9341_FillWindowDMA(uint8_t *buff, uint32_t buff_len)
{
    uint32_t buff_len_to_send = 0;

    /* Convert high and low bytes */
    ConvHL(buff, buff_len);

    ILI9341_WriteCommand(ILI9341_RAMWR);

    /* Reset chip select(SS) pin */
    HAL_GPIO_WritePin(ILI9341_CS_GPIO_Port, ILI9341_CS_Pin, RESET);

    if (buff_len > DMA_CHUNK_MAX_LEN)
    {
        _gILI9341CurrentBuffer.buff = buff;
        _gILI9341CurrentBuffer.buff_current_pos += DMA_CHUNK_MAX_LEN;
        _gILI9341CurrentBuffer.buff_remain_len = buff_len - DMA_CHUNK_MAX_LEN;
        buff_len_to_send = DMA_CHUNK_MAX_LEN;
    }
    else
    {
        _gILI9341CurrentBuffer.buff_remain_len = 0;
        buff_len_to_send = buff_len;
    }

    /* Start DMA transfer */
    HAL_SPI_Transmit_DMA(ili9341_spi, buff, buff_len_to_send);
}


/**
 * @brief Fills the window area of the ILI9341 LCD.
 *
 * This function fills the defined window area on the LCD with pixel data from a buffer.
 * It converts the high and low bytes of the buffer, writes the RAM write (RAMWR) command,
 * and transmits the data via SPI.
 *
 * @param buff Pointer to the buffer containing the data to be written to the LCD.
 * @param buff_len Length of the data buffer.
 */
void ILI9341_FillWindow(uint8_t *buff, uint32_t buff_len)
{
    /* Convert high and low bytes */
    ConvHL(buff, buff_len);

    ILI9341_WriteCommand(ILI9341_RAMWR);

    /* Reset chip select(SS) pin */
    HAL_GPIO_WritePin(ILI9341_CS_GPIO_Port, ILI9341_CS_Pin, RESET);

    /* Transmit data via SPI */
    HAL_SPI_Transmit(ili9341_spi, buff, buff_len, HAL_MAX_DELAY);

    /* Set chip select(SS) pin */
    HAL_GPIO_WritePin(ILI9341_CS_GPIO_Port, ILI9341_CS_Pin, SET);
}


/**
 * @brief Handles SPI DMA transfer completion.
 *
 * This function handles the completion of SPI DMA transfers by checking the remaining
 * buffer length and continuing the transfer if needed, or finalizing it.
 * If the entire buffer has been transferred, it resets the chip select pin, clears
 * the current buffer structure, and calls the completion callback function.
 */
void ILI9341_SPICmpltHandler(void)
{
    uint32_t buff_len_to_send = 0;

    if (_gILI9341CurrentBuffer.buff_remain_len == 0)
    {
        /* Set chip select(SS) pin */
        HAL_GPIO_WritePin(ILI9341_CS_GPIO_Port, ILI9341_CS_Pin, SET);

        /* Clear current buffer structure */
        memset(&_gILI9341CurrentBuffer, 0, sizeof(_gILI9341CurrentBuffer));

        /* Reset window area */
        ILI9341_SetWindow(0, 0, 0, 0);

        /* Call completion callback */
        ILI9341_FillWindowCmpltCallBack();
        return;
    }
    else
    {
        if (_gILI9341CurrentBuffer.buff_remain_len > DMA_CHUNK_MAX_LEN)
        {
            _gILI9341CurrentBuffer.buff_remain_len -= DMA_CHUNK_MAX_LEN;
            buff_len_to_send = DMA_CHUNK_MAX_LEN;
        }
        else
        {
            buff_len_to_send = _gILI9341CurrentBuffer.buff_remain_len;
            _gILI9341CurrentBuffer.buff_remain_len = 0;
        }
    }

    /* Continue DMA transfer */
    HAL_SPI_Transmit_DMA(ili9341_spi, (uint8_t *)&_gILI9341CurrentBuffer.buff[_gILI9341CurrentBuffer.buff_current_pos], buff_len_to_send);

    /* Update current buffer position */
    _gILI9341CurrentBuffer.buff_current_pos += buff_len_to_send;
}


/**
 * @brief Rotates the ILI9341 LCD display.
 *
 * This function sets the memory access control (MADCTL) register to rotate the display by the specified angle.
 * It can rotate the display by 0, 90, 180, or 270 degrees and optionally change the color order to BGR.
 *
 * @param degrees Rotation angle in degrees (0, 90, 180, 270).
 * @param bgr BGR color order flag (1 for BGR, 0 for RGB).
 */
void ILI9341_Rotate(uint16_t degrees, uint8_t bgr)
{
    uint8_t color_order = MADCTL_RGB;
    uint8_t data;

    if (bgr)
    {
        color_order = MADCTL_BGR;
    }

    ILI9341_WriteCommand(ILI9341_MADCTL);

    switch (degrees)
    {
    case 270:
        data = MADCTL_MV | color_order;
        ILI9341_WriteData(&data, 1);
        break;
    case 180:
        data = MADCTL_MY | color_order;
        ILI9341_WriteData(&data, 1);
        break;
    case 90:
        data = MADCTL_MX | MADCTL_MY | MADCTL_MV | color_order;
        ILI9341_WriteData(&data, 1);
        break;
    case 0:
        /* fall-through */
    default:
        data = MADCTL_MX | color_order;
        ILI9341_WriteData(&data, 1);
        break;
    }
}


/**
 * @brief Converts high and low bytes.
 *
 * This function swaps the high and low bytes in the given buffer.
 * It is used to convert the byte order of pixel data before sending it to the LCD.
 *
 * @param s Pointer to the buffer.
 * @param l Length of the buffer.
 */
static void ConvHL(uint8_t *s, int32_t l)
{
    uint8_t v;
    while (l > 0)
    {
        v = *(s + 1);
        *(s + 1) = *s;
        *s = v;
        s += 2;
        l -= 2;
    }
}


/**
 * @brief Weak callback function for window fill completion.
 *
 * This function is a weakly defined callback that can be overridden by the user.
 * It is called when the window fill operation is completed.
 */
__attribute__((weak)) void ILI9341_FillWindowCmpltCallBack(void)
{
    /* User-defined callback implementation */
}



