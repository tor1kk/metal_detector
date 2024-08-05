/**
 * @file app_tasks.h
 * @brief Header file for application tasks related to signal processing and metal detection.
 *
 * This file contains the declarations for tasks that handle signal processing,
 * metal detection, and audio output. It also declares external handles for
 * message queues and semaphores used in these tasks.
 *
 * Created on: Jul 21, 2024
 * Author: Viktor
 */

#ifndef TASKS_INC_APP_TASKS_H_
#define TASKS_INC_APP_TASKS_H_

#include "cmsis_os.h"


#define AUDIO_DURATION 250								/*!< Duration for which the audio signal is produced when metal is detected, in milliseconds. */


extern osMessageQueueId_t InputFlagQueueHandle; 		/*!< Handle for the message queue used for input flags */

extern osSemaphoreId_t AudioSemaphoreHandle; 			/*!< Handle for the semaphore used for audio control */

#endif /* TASKS_INC_APP_TASKS_H_ */
