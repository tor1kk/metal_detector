/**
 * @file app_signal.c
 * @brief Implementation file for signal processing and FFT operations.
 *
 * This file contains the implementation for handling signal processing tasks,
 * including ADC and DAC setup, sample loading, and FFT operations.
 * Functions include initialization of ADC and DAC, loading samples from
 * the ADC buffer, performing FFT, and handling ADC conversion complete callbacks.
 * The file interfaces with the hardware and performs signal analysis
 * using the CMSIS DSP library.
 *
 * Created on: Jul 5, 2024
 * Author: Viktor
 */


#include "adc.h"
#include "dac.h"
#include "tim.h"
#include "lvgl.h"
#include "ui.h"
#include "app_tasks.h"
#include "app_signal.h"


const uint32_t OUTPUT_SINE_SIGNAL[OUTPUT_SINE_SIGNAL_LEN] = {2048, 3251, 3995, 3996, 3253, 2051, 847, 101, 98, 839};

const uint32_t OUTPUT_AUDIO_SIGNAL[OUTPUT_SINE_AUDIO_LEN] = {
		2048, 2176, 2304,
		2431, 2557, 2680, 2801, 2919, 3034, 3145, 3251, 3353, 3449, 3540, 3625,
		3704, 3776, 3842, 3900, 3951, 3995, 4031, 4059, 4079, 4091, 4095, 4091,
		4079, 4059, 4031, 3995, 3951, 3900, 3842, 3776, 3704, 3625, 3540, 3449,
		3353, 3251, 3145, 3034, 2919, 2801, 2680, 2557, 2431, 2304, 2176, 2047,
		1919, 1791, 1664, 1538, 1415, 1294, 1176, 1061, 950, 844, 742, 646, 555,
		470, 391, 319, 253, 195, 144, 100, 64, 36, 16, 4, 0, 4, 16, 36, 64, 100,
		144, 195, 253, 319, 391, 470, 555, 646, 742, 844, 950, 1061, 1176, 1294,
		1415, 1538, 1664, 1791, 1919
};

SIG_Handle_t sig_handle = {0};


/**
 * @brief Initializes and starts the signal processing components.
 *
 * This function initializes the ADC and DAC peripherals, starts the ADC conversion
 * in DMA mode, and begins the DAC output with a sine wave signal. It also starts
 * the timer used for signal processing.
 *
 * @param handle Pointer to the SIG_Handle_t structure containing the configuration.
 */
void sig_start(SIG_Handle_t *const handle)
{
    /* Start ADC calibration for ADC1 and ADC2 */
    HAL_ADCEx_Calibration_Start(&hadc1, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED);
    HAL_ADCEx_Calibration_Start(&hadc1, ADC_CALIB_OFFSET_LINEARITY, ADC_SINGLE_ENDED);
    HAL_ADCEx_Calibration_Start(&hadc2, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED);
    HAL_ADCEx_Calibration_Start(&hadc2, ADC_CALIB_OFFSET_LINEARITY, ADC_SINGLE_ENDED);

    /* Start ADC and DAC in DMA mode */
    HAL_ADC_Start(&hadc2);
    HAL_ADCEx_MultiModeStart_DMA(&hadc1, (uint32_t *)handle->input_sig, INPUT_BUFF_LEN);
    HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_1, OUTPUT_AUDIO_SIGNAL, OUTPUT_SINE_AUDIO_LEN, DAC_ALIGN_12B_R);
    HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_2, OUTPUT_SINE_SIGNAL, OUTPUT_SINE_SIGNAL_LEN, DAC_ALIGN_12B_R);

    /* Start the timer */
    HAL_TIM_Base_Start(&htim2);
}


/**
 * @brief Loads samples into the processing buffers.
 *
 * This function copies samples from the input buffer to the processing buffers for
 * further signal analysis. The samples are loaded based on the provided flag.
 *
 * @param handle Pointer to the SIG_Handle_t structure containing the buffers.
 * @param flag Flag indicating the completion status of ADC conversion.
 */
void sig_load_samples(SIG_Handle_t *const handle, uint8_t flag)
{
    size_t counter = 0;

    /* Set counter based on ADC conversion completion flag */
    if (flag == ADC_FULL_COMPLETE_FLAG)
    {
        counter = INPUT_BUFF_LEN / 2;
    }

    /* Copy samples to processing buffers */
    for(size_t i = 0; i < BUFF_TO_DFT_LEN; i++)
    {
        handle->tx_coil_sig_to_dft[i] = ( (float32_t) handle->input_sig[counter].adc1 );
        handle->rx_coil_sig_to_dft[i] = ( (float32_t) handle->input_sig[counter].adc2 );
        counter++;
    }
}


/**
 * @brief Performs Fast Fourier Transform (FFT) on the signal data.
 *
 * This function calculates the FFT of the input signals for both the receive and
 * transmit coils. It then computes the magnitude and phase of the frequency domain
 * data and returns the index of the maximum magnitude value.
 *
 * @param handle Pointer to the SIG_Handle_t structure containing the signal data.
 * @return size_t Index of the maximum magnitude value in the frequency domain.
 */
size_t sig_perform_fft(SIG_Handle_t *const handle)
{
    arm_rfft_fast_instance_f32 rx_fft_instance = {0};
    arm_rfft_fast_instance_f32 tx_fft_instance = {0};
    size_t last_max_value = 0, last_max_value_index = 0, magnitude = 0;

    /* Initialize FFT instances */
    arm_rfft_fast_init_f32(&rx_fft_instance, BUFF_TO_DFT_LEN);
    arm_rfft_fast_init_f32(&tx_fft_instance, BUFF_TO_DFT_LEN);

    /* Perform FFT on receive and transmit signals */
    arm_rfft_fast_f32(&rx_fft_instance, (float32_t *)handle->rx_coil_sig_to_dft, (float32_t *)handle->rx_coil_freq_domain, 0);
    arm_rfft_fast_f32(&tx_fft_instance, (float32_t *)handle->tx_coil_sig_to_dft, (float32_t *)handle->tx_coil_freq_domain, 0);

    /* Compute magnitude and phase for each frequency bin */
    for(size_t i = 0; i < FREQ_DOMAIN_LEN; i++)
    {
        magnitude = sqrtf(handle->rx_coil_freq_domain[i].real_part * handle->rx_coil_freq_domain[i].real_part +
                          handle->rx_coil_freq_domain[i].imaginary_part * handle->rx_coil_freq_domain[i].imaginary_part)
                    / BUFF_TO_DFT_LEN;

        /* Track maximum magnitude value */
        if (last_max_value < magnitude && i > 10)
        {
            last_max_value = magnitude;
            last_max_value_index = i;
        }

        handle->rx_coil_polar[i].magnitude = magnitude;
        handle->rx_coil_polar[i].phase = atan2f(handle->rx_coil_freq_domain[i].imaginary_part, handle->rx_coil_freq_domain[i].real_part);
        handle->tx_coil_polar[i].phase = atan2f(handle->tx_coil_freq_domain[i].imaginary_part, handle->tx_coil_freq_domain[i].real_part);
    }

    return last_max_value_index;
}


/**
 * @brief Callback function for ADC conversion complete interrupt.
 *
 * This function is called when the ADC conversion is complete. It places a flag
 * in the message queue to indicate that the ADC data is ready for processing.
 *
 * @param hadc Pointer to the ADC_HandleTypeDef structure.
 */
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    uint8_t flag = (uint8_t) ADC_FULL_COMPLETE_FLAG;
    osMessageQueuePut(InputFlagQueueHandle, &flag, 0, 0);
}


/**
 * @brief Callback function for ADC half conversion complete interrupt.
 *
 * This function is called when half of the ADC conversion is complete. It places a flag
 * in the message queue to indicate that the first half of the ADC data is ready for processing.
 *
 * @param hadc Pointer to the ADC_HandleTypeDef structure.
 */
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef *hadc)
{
    uint8_t flag = (uint8_t) ADC_HALF_COMPLETE_FLAG;
    osMessageQueuePut(InputFlagQueueHandle, &flag, 0, 0);
}

