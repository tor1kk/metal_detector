/**
 * @file metal_detecting.h
 * @brief Header file for metal detecting functionality.
 *
 * This file defines the types, constants, and function prototypes for metal detecting.
 * It includes definitions for detection status, data structures for signal information,
 * and handle structures for metal detecting operations.
 *
 * Created on: Jul 23, 2024
 * Author: Viktor
 */

#ifndef SIGNALSPROCESSING_INC_METAL_DETECTING_H_
#define SIGNALSPROCESSING_INC_METAL_DETECTING_H_

#include <stdint.h>
#include "arm_math.h"

/**
 * @brief Detection status for metal detecting.
 */
typedef enum
{
    TARGET_DETECTED = 0, 				/*!< Indicates that a target has been detected */
    NO_TARGET            				/*!< Indicates that no target has been detected */
} MD_DetectStatus_t;

/**
 * @brief Structure to hold signal data for metal detection.
 */
typedef struct
{
    float32_t tx_signal_phase;    		/*!< Phase of the transmitted signal in radians */
    float32_t rx_signal_magnitude; 		/*!< Magnitude of the received signal */
    float32_t rx_signal_phase;    		/*!< Phase of the received signal in radians */
} MD_Data_t;

/**
 * @brief Structure to hold detection parameters and state.
 */
typedef struct
{
    float32_t last_magnitude; 			/*!< Last recorded signal magnitude */
    float32_t gnd_balance;    			/*!< Ground balance parameter for detection */
    float32_t sensitivity;    			/*!< Sensitivity parameter for detection */
} MD_Handle_t;

/** @brief Global handle for metal detecting operations. */
extern MD_Handle_t md_handle;

/**
 * @brief Detects the presence of a target based on signal data.
 *
 * This function evaluates whether a target is detected by comparing the received signal
 * magnitude with ground balance and sensitivity thresholds. It calculates the phase
 * difference between the transmitted and received signals.
 *
 * @param handle Pointer to the MD_Handle_t structure containing detection parameters.
 * @param data Pointer to the MD_Data_t structure containing the received signal data.
 * @param phase_difference Pointer to an integer where the calculated phase difference will be stored.
 * @return MD_DetectStatus_t Detection status indicating whether a target was detected or not.
 */
MD_DetectStatus_t md_detect(MD_Handle_t *const handle, const MD_Data_t *const data, int16_t *const phase_difference);

/**
 * @brief Sets the ground balance parameter for metal detection.
 *
 * This function updates the ground balance value used in target detection.
 *
 * @param handle Pointer to the MD_Handle_t structure containing detection parameters.
 * @param new_balance New ground balance value to be set.
 */
void md_set_gndbalance(MD_Handle_t *const handle, uint16_t new_balance);

/**
 * @brief Sets the sensitivity parameter for metal detection.
 *
 * This function updates the sensitivity value used in target detection.
 *
 * @param handle Pointer to the MD_Handle_t structure containing detection parameters.
 * @param new_sens New sensitivity value to be set.
 */
void md_set_sensitivity(MD_Handle_t *const handle, uint16_t new_sens);

#endif /* SIGNALSPROCESSING_INC_METAL_DETECTING_H_ */
