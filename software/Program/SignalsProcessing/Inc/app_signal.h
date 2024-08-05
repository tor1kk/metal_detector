/**
 * @file app_signal.h
 * @brief Header file for signal processing and FFT operations.
 *
 * This file contains the declarations for functions and data types used
 * in signal processing tasks, including ADC and DAC setup, sample loading,
 * and FFT operations. It defines constants, data structures, and function
 * prototypes for managing and processing signals.
 *
 * Created on: Jul 5, 2024
 * Author: Viktor
 */

#ifndef INC_SIGNAL_H_
#define INC_SIGNAL_H_

#include <stdint.h>
#include "arm_math.h"

/** @brief Length of the output sine wave signal array. */
#define OUTPUT_SINE_SIGNAL_LEN              10

/** @brief Length of the output audio signal array. */
#define OUTPUT_SINE_AUDIO_LEN              100

/** @brief Length of the input buffer for ADC samples. */
#define INPUT_BUFF_LEN                     2048

/** @brief Number of samples to be used for the FFT (half of the input buffer length). */
#define BUFF_TO_DFT_LEN                    ( INPUT_BUFF_LEN / 2 )

/** @brief Number of frequency domain bins (quarter of the input buffer length). */
#define FREQ_DOMAIN_LEN                    ( BUFF_TO_DFT_LEN / 2 )

/** @brief Length of the polar form array (same as frequency domain length). */
#define POLAR_FORM_LEN                     FREQ_DOMAIN_LEN

/** @brief Maximum value of the ADC output (12-bit resolution). */
#define ADC_MAX_VALUE                      4095

/** @brief Reference voltage for the ADC. */
#define REF_VOLTAGE                        3.3f

/** @brief Flag indicating that the ADC conversion is complete for the first half of the buffer. */
#define ADC_HALF_COMPLETE_FLAG             0

/** @brief Flag indicating that the ADC conversion is complete for the entire buffer. */
#define ADC_FULL_COMPLETE_FLAG             1


/**
 * @brief Structure to hold ADC conversion values from two channels.
 */
typedef struct
{
    uint16_t adc1;  				/*!< ADC value from ADC1 */
    uint16_t adc2;  				/*!< ADC value from ADC2 */
} SIG_ADCRegister_t;


/**
 * @brief Structure representing a complex number in the frequency domain.
 */
typedef struct
{
    float32_t real_part;       		/*!< Real part of the complex number */
    float32_t imaginary_part;  		/*!< Imaginary part of the complex number */
} SIG_FreqDomain_t;


/**
 * @brief Structure representing the magnitude and phase of a frequency component.
 */
typedef struct
{
    float32_t phase;       			/*!< Phase of the frequency component */
    float32_t magnitude;   			/*!< Magnitude of the frequency component */
} SIG_PolarForm_t;


/**
 * @brief Handle structure for managing signal processing tasks.
 */
typedef struct SIG_Handle_t
{
    SIG_ADCRegister_t input_sig[INPUT_BUFF_LEN];  				/*!< Buffer for ADC input samples */

    float32_t rx_coil_sig_to_dft[BUFF_TO_DFT_LEN]; 				/*!< Buffer for RX coil signal before FFT */
    float32_t tx_coil_sig_to_dft[BUFF_TO_DFT_LEN]; 				/*!< Buffer for TX coil signal before FFT */

    SIG_FreqDomain_t rx_coil_freq_domain[FREQ_DOMAIN_LEN]; 		/*!< Frequency domain representation of RX coil signal */
    SIG_FreqDomain_t tx_coil_freq_domain[FREQ_DOMAIN_LEN]; 		/*!< Frequency domain representation of TX coil signal */

    SIG_PolarForm_t rx_coil_polar[POLAR_FORM_LEN]; 				/*!< Polar form of RX coil frequency domain data */
    SIG_PolarForm_t tx_coil_polar[POLAR_FORM_LEN]; 				/*!< Polar form of TX coil frequency domain data */
} SIG_Handle_t;


extern SIG_Handle_t sig_handle;  /*!< Global handle for signal processing */

/**
 * @brief Starts the signal processing by initializing ADC and DAC, and starting timers.
 * @param handle Pointer to the SIG_Handle_t structure.
 */
void sig_start(SIG_Handle_t *const handle);

/**
 * @brief Loads samples from the ADC buffer into the processing buffers.
 * @param handle Pointer to the SIG_Handle_t structure.
 * @param flag Flag indicating the ADC conversion status (half or full completion).
 */
void sig_load_samples(SIG_Handle_t *const handle, uint8_t flag);

/**
 * @brief Performs FFT on the loaded signal data and computes magnitude and phase.
 * @param handle Pointer to the SIG_Handle_t structure.
 * @return Index of the frequency with the maximum magnitude.
 */
size_t sig_perform_fft(SIG_Handle_t *const handle);


#endif /* INC_SIGNAL_H_ */
