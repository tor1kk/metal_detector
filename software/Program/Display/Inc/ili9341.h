/**
 * @file ili9341.h
 * @brief Header file for the ILI9341 LCD driver.
 *
 * This file contains the declarations for the ILI9341 LCD driver.
 * It includes function prototypes for initialization, command and data transmission,
 * setting window areas, filling windows, and handling DMA completion.
 * The driver is designed to interface with the ILI9341 LCD controller using SPI.
 *
 * Created on: Apr 5, 2024
 * Author: Viktor
 */

#ifndef INC_ILI9341_H_
#define INC_ILI9341_H_

#include "main.h"

/*********************
 *      DEFINES
 *********************/


#define ILI9341_HOR_RES        240    	/*!< Horizontal resolution of the ILI9341 LCD. */
#define ILI9341_VER_RES        320		/*!< Vertical resolution of the ILI9341 LCD. */

#define MY_DISP_HOR_RES        ILI9341_HOR_RES
#define MY_DISP_VER_RES        ILI9341_VER_RES

#define ILI9341_BGR            1		/*!< Use BGR color order. */
#define ILI9341_RGB            0		/*!< Use RGB color order. */

#define ILI9341_GAMMA          1		/*!< Enable gamma correction. */


/* Level 1 Commands -------------- [section] Description */

#define ILI9341_NOP            0x00		/*!< No Operation / Terminate Frame Memory Write. */

#define ILI9341_SWRESET        0x01		/*!< Software Reset. */

#define ILI9341_RDDIDIF        0x04		/*!< Read Display Identification Information. */

#define ILI9341_RDDST          0x09		/*!< Read Display Status. */

#define ILI9341_RDDPM          0x0A		/*!< Read Display Power Mode. */

#define ILI9341_RDDMADCTL      0x0B		/*!< Read Display MADCTL. */

#define ILI9341_RDDCOLMOD      0x0C		/*!< Read Display Pixel Format. */

#define ILI9341_RDDIM          0x0D		/*!< Read Display Image Mode. */

#define ILI9341_RDDSM          0x0E		/*!< Read Display Signal Mode. */

#define ILI9341_RDDSDR         0x0F		/*!< Read Display Self-Diagnostic Result. */

#define ILI9341_SLPIN          0x10		/*!< Enter Sleep Mode. */

#define ILI9341_SLPOUT         0x11		/*!< Leave Sleep Mode. */

#define ILI9341_PTLON          0x12		/*!< Partial Display Mode ON. */

#define ILI9341_NORON          0x13		/*!< Normal Display Mode ON. */

#define ILI9341_DINVOFF        0x20		/*!< Display Inversion OFF. */

#define ILI9341_DINVON         0x21		/*!< Display Inversion ON. */

#define ILI9341_GAMSET         0x26		/*!< Gamma Set. */

#define ILI9341_DISPOFF        0x28		/*!< Display OFF. */

#define ILI9341_DISPON         0x29		/*!< Display ON. */

#define ILI9341_CASET          0x2A		/*!< Column Address Set. */

#define ILI9341_PASET          0x2B		/*!< Page Address Set. */

#define ILI9341_RAMWR          0x2C		/*!< Memory Write. */

#define ILI9341_RGBSET         0x2D		/*!< Color Set (LUT for 16-bit to 18-bit color depth conversion). */

#define ILI9341_RAMRD          0x2E		/*!< Memory Read. */

#define ILI9341_PTLAR          0x30		/*!< Partial Area. */

#define ILI9341_VSCRDEF        0x33		/*!< Vertical Scrolling Definition. */

#define ILI9341_TEOFF          0x34		/*!< Tearing Effect Line OFF. */

#define ILI9341_TEON           0x35		/*!< Tearing Effect Line ON. */

#define ILI9341_MADCTL         0x36		/*!< Memory Access Control. */

#define     MADCTL_MY          0x80		/*!< MY row address order. */

#define     MADCTL_MX          0x40		/*!< MX column address order. */

#define     MADCTL_MV          0x20		/*!< MV row / column exchange. */

#define     MADCTL_ML          0x10		/*!< ML vertical refresh order. */

#define     MADCTL_MH          0x04		/*!< MH horizontal refresh order. */

#define     MADCTL_RGB         0x00		/*!< RGB Order [default]. */

#define     MADCTL_BGR         0x08		/*!< BGR Order. */

#define ILI9341_VSCRSADD       0x37		/*!< Vertical Scrolling Start Address. */

#define ILI9341_IDMOFF         0x38		/*!< Idle Mode OFF. */

#define ILI9341_IDMON          0x39		/*!< Idle Mode ON. */

#define ILI9341_PIXSET         0x3A		/*!< Pixel Format Set. */

#define ILI9341_WRMEMCONT      0x3C		/*!<Write Memory Continue.  */

#define ILI9341_RDMEMCONT      0x3E		/*!< Read Memory Continue. */

#define ILI9341_SETSCANTE      0x44		/*!< Set Tear Scanline. */

#define ILI9341_GETSCAN        0x45		/*!< Get Scanline. */

#define ILI9341_WRDISBV        0x51		/*!< Write Display Brightness Value. */

#define ILI9341_RDDISBV        0x52		/*!< Read Display Brightness Value. */

#define ILI9341_WRCTRLD        0x53		/*!< Write Control Display. */

#define ILI9341_RDCTRLD        0x54		/*!< Read Control Display. */

#define ILI9341_WRCABC         0x55		/*!< Write Content Adaptive Brightness Control Value. */

#define ILI9341_RDCABC         0x56		/*!< Read Content Adaptive Brightness Control Value. */

#define ILI9341_WRCABCMIN      0x5E		/*!< Write CABC Minimum Brightness. */

#define ILI9341_RDCABCMIN      0x5F		/*!< Read CABC Minimum Brightness. */

#define ILI9341_RDID1          0xDA		/*!< Read ID1 - Manufacturer ID (user). */

#define ILI9341_RDID2          0xDB		/*!< Read ID2 - Module/Driver version (supplier). */

#define ILI9341_RDID3          0xDC		/*!< Read ID3 - Module/Driver version (user). */


/* Level 2 Commands -------------- [section] Description */

#define ILI9341_IFMODE         0xB0 /* [8.3.1 ] Interface Mode Control */
#define ILI9341_FRMCTR1        0xB1 /* [8.3.2 ] Frame Rate Control (In Normal Mode/Full Colors) */
#define ILI9341_FRMCTR2        0xB2 /* [8.3.3 ] Frame Rate Control (In Idle Mode/8 colors) */
#define ILI9341_FRMCTR3        0xB3 /* [8.3.4 ] Frame Rate control (In Partial Mode/Full Colors) */
#define ILI9341_INVTR          0xB4 /* [8.3.5 ] Display Inversion Control */
#define ILI9341_PRCTR          0xB5 /* [8.3.6 ] Blanking Porch Control */
#define ILI9341_DISCTRL        0xB6 /* [8.3.7 ] Display Function Control */
#define ILI9341_ETMOD          0xB7 /* [8.3.8 ] Entry Mode Set */
#define ILI9341_BLCTRL1        0xB8 /* [8.3.9 ] Backlight Control 1 - Grayscale Histogram UI mode */
#define ILI9341_BLCTRL2        0xB9 /* [8.3.10] Backlight Control 2 - Grayscale Histogram still picture mode */
#define ILI9341_BLCTRL3        0xBA /* [8.3.11] Backlight Control 3 - Grayscale Thresholds UI mode */
#define ILI9341_BLCTRL4        0xBB /* [8.3.12] Backlight Control 4 - Grayscale Thresholds still picture mode */
#define ILI9341_BLCTRL5        0xBC /* [8.3.13] Backlight Control 5 - Brightness Transition time */
#define ILI9341_BLCTRL7        0xBE /* [8.3.14] Backlight Control 7 - PWM Frequency */
#define ILI9341_BLCTRL8        0xBF /* [8.3.15] Backlight Control 8 - ON/OFF + PWM Polarity*/
#define ILI9341_PWCTRL1        0xC0 /* [8.3.16] Power Control 1 - GVDD */
#define ILI9341_PWCTRL2        0xC1 /* [8.3.17] Power Control 2 - step-up factor for operating voltage */
#define ILI9341_VMCTRL1        0xC5 /* [8.3.18] VCOM Control 1 - Set VCOMH and VCOML */
#define ILI9341_VMCTRL2        0xC7 /* [8.3.19] VCOM Control 2 - VCOM offset voltage */
#define ILI9341_NVMWR          0xD0 /* [8.3.20] NV Memory Write */
#define ILI9341_NVMPKEY        0xD1 /* [8.3.21] NV Memory Protection Key */
#define ILI9341_RDNVM          0xD2 /* [8.3.22] NV Memory Status Read */
#define ILI9341_RDID4          0xD3 /* [8.3.23] Read ID4 - IC Device Code */
#define ILI9341_PGAMCTRL       0xE0 /* [8.3.24] Positive Gamma Control */
#define ILI9341_NGAMCTRL       0xE1 /* [8.3.25] Negative Gamma Correction */
#define ILI9341_DGAMCTRL1      0xE2 /* [8.3.26] Digital Gamma Control 1 */
#define ILI9341_DGAMCTRL2      0xE3 /* [8.3.27] Digital Gamma Control 2 */
#define ILI9341_IFCTL          0xF6 /* [8.3.28] 16bits Data Format Selection */

/* Extended Commands --------------- [section] Description*/

#define ILI9341_PWCTRLA       0xCB /* [8.4.1] Power control A */
#define ILI9341_PWCTRLB       0xCF /* [8.4.2] Power control B */
#define ILI9341_TIMECTRLA_INT 0xE8 /* [8.4.3] Internal Clock Driver timing control A */
#define ILI9341_TIMECTRLA_EXT 0xE9 /* [8.4.4] External Clock Driver timing control A */
#define ILI9341_TIMECTRLB     0xEA /* [8.4.5] Driver timing control B (gate driver timing control) */
#define ILI9341_PWSEQCTRL     0xED /* [8.4.6] Power on sequence control */
#define ILI9341_GAM3CTRL      0xF2 /* [8.4.7] Enable 3 gamma control */
#define ILI9341_PUMPRATIO     0xF7 /* [8.4.8] Pump ratio control */

/**
 * @brief Macro to introduce a delay.
 *
 * This macro uses the HAL_Delay function to introduce a delay in milliseconds.
 *
 * @param __DELAY__ Duration of the delay in milliseconds.
 */
#define ILI9341_DELAY( __DELAY__ ) HAL_Delay(__DELAY__)


typedef struct
{
    uint32_t buff_remain_len;     /*!< Remaining length of the buffer to be sent */
    uint32_t buff_current_pos;    /*!< Current position in the buffer */
    uint8_t *buff;                /*!< Pointer to the buffer */
} ILI9341CurrentBuffer_t;

/**
 * @brief Initializes the ILI9341 LCD.
 */
void ILI9341_Init(void);

/**
 * @brief Writes a command to the ILI9341 LCD.
 *
 * @param cmd Command byte to be sent to the LCD.
 */
void ILI9341_WriteCommand(uint8_t cmd);

/**
 * @brief Writes data to the ILI9341 LCD.
 *
 * @param data_buff Pointer to the data buffer to be sent to the LCD.
 * @param data_len Length of the data buffer.
 */
void ILI9341_WriteData(uint8_t *data_buff, uint32_t data_len);

/**
 * @brief Rotates the ILI9341 LCD display.
 *
 * @param degrees Rotation angle in degrees (0, 90, 180, 270).
 * @param bgr BGR color order flag (1 for BGR, 0 for RGB).
 */
void ILI9341_Rotate(uint16_t degrees, uint8_t bgr);

/**
 * @brief Sets the window area for the ILI9341 LCD.
 *
 * @param x_axis_start Starting X-axis position.
 * @param x_axis_end Ending X-axis position.
 * @param y_axis_start Starting Y-axis position.
 * @param y_axis_end Ending Y-axis position.
 */
void ILI9341_SetWindow(uint16_t x_axis_start, uint16_t x_axis_end, uint16_t y_axis_start, uint16_t y_axis_end);

/**
 * @brief Fills the window area of the ILI9341 LCD.
 *
 * @param buff Pointer to the buffer containing the data to be written to the LCD.
 * @param buff_len Length of the data buffer.
 */
void ILI9341_FillWindow(uint8_t *buff, uint32_t buff_len);

/**
 * @brief Fills the window area of the ILI9341 LCD using DMA.
 *
 * @param buff Pointer to the buffer containing the data to be written to the LCD.
 * @param buff_len Length of the data buffer.
 */
void ILI9341_FillWindowDMA(uint8_t *buff, uint32_t buff_len);

/**
 * @brief Handles SPI DMA transfer completion.
 */
void ILI9341_SPICmpltHandler(void);

/**
 * @brief Weak callback function for window fill completion.
 */
void ILI9341_FillWindowCmpltCallBack(void);

#endif
