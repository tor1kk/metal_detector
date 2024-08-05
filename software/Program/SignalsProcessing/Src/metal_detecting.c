/**
 * @file metal_detecting.c
 * @brief Implementation file for metal detecting functionality.
 *
 * This file contains the implementation of functions for metal detecting.
 * It includes functions for detecting targets based on signal magnitude and phase difference,
 * as well as setting ground balance and sensitivity parameters.
 *
 * Created on: Jul 23, 2024
 * Author: Viktor
 */

#include "metal_detecting.h"
#include "app_signal.h"

/** @brief Global handle for metal detecting operations. */
MD_Handle_t md_handle = {0 };


/**
 * @brief Detects the presence of a target based on signal magnitude and phase difference.
 *
 * This function determines if a target is detected by comparing the current signal magnitude
 * with a ground balance and sensitivity threshold. It also calculates the phase difference between
 * the transmitted and received signals.
 *
 * @param handle Pointer to the MD_Handle_t structure containing detection parameters.
 * @param data Pointer to the MD_Data_t structure containing the received signal data.
 * @param phase_difference Pointer to an integer where the calculated phase difference will be stored.
 * @return MD_DetectStatus_t Detection status indicating whether a target was detected or not.
 */
MD_DetectStatus_t md_detect(MD_Handle_t *const handle, const MD_Data_t *const data, int16_t *const phase_difference)
{
    MD_DetectStatus_t return_value = NO_TARGET;        /*!< Default return value indicating no target detected */
    float32_t phase_difference_float = 0;              /*!< Variable to hold the calculated phase difference */

    /* Check if the received signal magnitude exceeds the ground balance */
    if( data->rx_signal_magnitude > handle->gnd_balance )
    {
        /* Further check if the received signal magnitude exceeds the last magnitude by a certain sensitivity */
        if( data->rx_signal_magnitude > handle->last_magnitude + handle->sensitivity )
        {
            return_value = TARGET_DETECTED;  /*!< Set the return value to indicate that a target is detected */

            /* Calculate the phase difference between the transmitted and received signals */
            phase_difference_float = data->tx_signal_phase - data->rx_signal_phase;
            phase_difference_float *= 180.0f / PI;  /*!< Convert phase difference to degrees */

            /* Normalize phase difference to the range of [-180, 180] degrees */
            if (phase_difference_float > 180.0f)
            {
                phase_difference_float -= 360.0f;
            }
            else if (phase_difference_float < -180.0f)
            {
                phase_difference_float += 360.0f;
            }

            phase_difference_float = fabs(phase_difference_float);  /*!< Take the absolute value of the phase difference */

            *phase_difference = (int32_t) phase_difference_float;  /*!< Store the phase difference in the provided pointer */
        }
    }

    /* Update the last magnitude with the current signal magnitude */
    handle->last_magnitude = data->rx_signal_magnitude;

    return return_value;  /*!< Return the detection status */
}


/**
 * @brief Sets the ground balance parameter for metal detection.
 *
 * This function updates the ground balance value used in target detection.
 *
 * @param handle Pointer to the MD_Handle_t structure containing detection parameters.
 * @param new_balance New ground balance value to be set.
 */
void md_set_gndbalance(MD_Handle_t *const handle, const uint16_t new_balance)
{
    handle->gnd_balance = (float32_t)new_balance;  /*!< Update the ground balance parameter */
}


/**
 * @brief Sets the sensitivity parameter for metal detection.
 *
 * This function updates the sensitivity value used in target detection.
 *
 * @param handle Pointer to the MD_Handle_t structure containing detection parameters.
 * @param new_sens New sensitivity value to be set.
 */
void md_set_sensitivity(MD_Handle_t *const handle, const uint16_t new_sens)
{
    handle->sensitivity = (float32_t)new_sens;  /*!< Update the sensitivity parameter */
}
