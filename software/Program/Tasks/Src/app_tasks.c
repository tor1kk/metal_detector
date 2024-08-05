/**
 * @file app_tasks.c
 * @brief Application tasks for signal processing, metal detecting, and LVGL GUI updates.
 *
 * This file contains the implementation of various tasks:
 * - ProduceAudioTask: Manages audio output for detected targets.
 * - SignalProcessingTask: Handles signal acquisition, processing, and metal detection.
 * - LvHandlerTask: Manages updates to the LVGL user interface based on signal processing results.
 *
 * Created on: Jul 21, 2024
 * Author: Viktor
 */

#include "app_tasks.h"
#include "signal.h"
#include "lvgl.h"
#include "ui.h"
#include "app_signal.h"
#include "metal_detecting.h"
#include "main.h"

/* Static variables to hold detection status, phase difference, and magnitude */

static MD_DetectStatus_t md_flag = NO_TARGET;  /*!< Metal detection flag */
static int16_t phase_diff = 0;                 /*!< Phase difference between signals */
static uint16_t magnitude = 0;                 /*!< Magnitude of the received signal */

/**
 * @brief Task to produce audio when metal is detected.
 *
 * This task waits for the AudioSemaphoreHandle to be released,
 * then enables the audio amplifier for a specified duration to produce an audio signal.
 *
 * @param argument: Task argument (unused).
 */
void ProduceAudioTask(void *argument)
{
    for(;;)
    {
        /* Wait for the semaphore to be released */
        osSemaphoreAcquire(AudioSemaphoreHandle, osWaitForever);

        /* Enable Audio Amplifier */
        HAL_GPIO_WritePin(AMP_SD_CNTRL_GPIO_Port, AMP_SD_CNTRL_Pin, SET);

        /* Delay to keep the amplifier on for the duration of the audio signal */
        osDelay(AUDIO_DURATION);

        /* Disable Audio Amplifier */
        HAL_GPIO_WritePin(AMP_SD_CNTRL_GPIO_Port, AMP_SD_CNTRL_Pin, RESET);
    }
}

/**
 * @brief Task to process signals and detect metal.
 *
 * This task waits for a flag from the input queue, processes the signal to
 * perform FFT and detect metal, and updates detection status and phase difference.
 *
 * @param argument: Task argument (unused).
 */
void SignalProcessingTask(void *argument)
{
    uint8_t flag;
    MD_Data_t signal_data = {0};
    int16_t phase_difference = 0;
    size_t main_freq = 0;

    for(;;)
    {
        /* Wait for a message from the queue and get the flag */
        osMessageQueueGet(InputFlagQueueHandle, (void *)&flag, 0, osWaitForever);

        /* Load ADC samples into the signal handler */
        sig_load_samples(&sig_handle, flag);

        /* Perform FFT and get the dominant frequency index */
        main_freq = sig_perform_fft(&sig_handle);

        /* Populate signal data structure with magnitude and phase values */
        signal_data.rx_signal_magnitude = sig_handle.rx_coil_polar[main_freq].magnitude;
        signal_data.rx_signal_phase = sig_handle.rx_coil_polar[main_freq].phase;
        signal_data.tx_signal_phase = sig_handle.tx_coil_polar[main_freq].phase;

        /* Detect metal and calculate phase difference if target is detected */
        if( md_detect(&md_handle, &signal_data, &phase_difference) == TARGET_DETECTED )
        {
            /* Release the audio semaphore to trigger audio output */
            osSemaphoreRelease(AudioSemaphoreHandle);

            /* Update detection flag, phase difference, and magnitude */
            md_flag = TARGET_DETECTED;
            phase_diff = phase_difference;
            magnitude = sig_handle.rx_coil_polar[main_freq].magnitude - md_handle.gnd_balance;
        }
    }
}

/**
 * @brief Task to handle LVGL GUI updates.
 *
 * This task updates the LVGL user interface with signal processing results,
 * including depth bar, phase arc, and charts for time and frequency domains.
 *
 * @param argument: Task argument (unused).
 */
void LvHandlerTask(void *argument)
{
    uint8_t refresh_delay = 0;

    for(;;)
    {
        /* Update LVGL bars and arcs if target is detected */
        if( md_flag == TARGET_DETECTED )
        {
            /* Set value for depth bar */
            lv_bar_set_value(ui_DepthBar, magnitude, LV_ANIM_OFF);

            /* Trigger value change event for depth bar */
            lv_obj_send_event(ui_DepthBar, LV_EVENT_VALUE_CHANGED, NULL);

            /* Set value for phase arc */
            lv_arc_set_value(ui_PhaseArc, phase_diff);

            /* Trigger value change event for phase arc */
            lv_obj_send_event(ui_PhaseArc, LV_EVENT_VALUE_CHANGED, NULL);

            /* Reset detection flag */
            md_flag = NO_TARGET;
        }
        else if( md_flag == NO_TARGET )
        {
            /* Update bars and arcs if no target is detected and refresh delay is met */
            if( refresh_delay >= 35 )
            {
                /* Reset value for depth bar */
                lv_bar_set_value(ui_DepthBar, 0, LV_ANIM_OFF);

                /* Trigger value change event for depth bar */
                lv_obj_send_event(ui_DepthBar, LV_EVENT_VALUE_CHANGED, NULL);

                /* Reset value for phase arc */
                lv_arc_set_value(ui_PhaseArc, 0);

                /* Trigger value change event for phase arc */
                lv_obj_send_event(ui_PhaseArc, LV_EVENT_VALUE_CHANGED, NULL);

                /* Reset refresh delay counter */
                refresh_delay = 0;
            }
            else
            {
                /* Increment refresh delay counter */
                refresh_delay++;
            }
        }

        /* Update chart based on current domain */
        if( ui_chart_domain == CHART_TIME_DOMAIN )
        {
            /* Add time domain values to chart */
            for(uint32_t i = 0; i < TIME_DOMAIN_CHART_LEN; i++)
            {
                lv_chart_set_next_value(ui_Chart, ui_Chart_series_1, sig_handle.input_sig[i].adc2);
                lv_chart_set_next_value(ui_Chart, ui_Chart_series_2, sig_handle.input_sig[i].adc1);
            }
        }
        else if( ui_chart_domain == CHART_FREQ_DOMAIN )
        {
            /* Add frequency domain values to chart */
            for(uint32_t i = 0; i < FREQ_DOMAIN_CHART_LEN; i++)
            {
                lv_chart_set_next_value(ui_Chart, ui_Chart_series_1, sig_handle.rx_coil_polar[i].magnitude);
            }
        }

        /* Call the LVGL timer handler to process GUI events */
        lv_timer_handler();

        /* Delay for 35 ms before next iteration */
        osDelay(35);
    }
}



