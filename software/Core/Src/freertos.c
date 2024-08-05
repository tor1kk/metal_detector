/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticTask_t osStaticThreadDef_t;
typedef StaticQueue_t osStaticMessageQDef_t;
typedef StaticSemaphore_t osStaticMutexDef_t;
typedef StaticSemaphore_t osStaticSemaphoreDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

#define MS_TO_TICKS(ms) ((ms * osKernelGetTickFreq()) / 1000)

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for SignalProcessing */
osThreadId_t SignalProcessingHandle;
uint32_t SignalProcessingBuffer[ 1000 ];
osStaticThreadDef_t SignalProcessingControlBlock;
const osThreadAttr_t SignalProcessing_attributes = {
  .name = "SignalProcessing",
  .cb_mem = &SignalProcessingControlBlock,
  .cb_size = sizeof(SignalProcessingControlBlock),
  .stack_mem = &SignalProcessingBuffer[0],
  .stack_size = sizeof(SignalProcessingBuffer),
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for ProduceAudio */
osThreadId_t ProduceAudioHandle;
uint32_t ProduceAudioBuffer[ 128 ];
osStaticThreadDef_t ProduceAudioControlBlock;
const osThreadAttr_t ProduceAudio_attributes = {
  .name = "ProduceAudio",
  .cb_mem = &ProduceAudioControlBlock,
  .cb_size = sizeof(ProduceAudioControlBlock),
  .stack_mem = &ProduceAudioBuffer[0],
  .stack_size = sizeof(ProduceAudioBuffer),
  .priority = (osPriority_t) osPriorityBelowNormal7,
};
/* Definitions for lvHandler */
osThreadId_t lvHandlerHandle;
uint32_t lvHandlerBuffer[ 5000 ];
osStaticThreadDef_t lvHandlerControlBlock;
const osThreadAttr_t lvHandler_attributes = {
  .name = "lvHandler",
  .cb_mem = &lvHandlerControlBlock,
  .cb_size = sizeof(lvHandlerControlBlock),
  .stack_mem = &lvHandlerBuffer[0],
  .stack_size = sizeof(lvHandlerBuffer),
  .priority = (osPriority_t) osPriorityRealtime,
};
/* Definitions for InputFlagQueue */
osMessageQueueId_t InputFlagQueueHandle;
uint8_t InputFlagQueueBuffer[ 1 * sizeof( uint32_t ) ];
osStaticMessageQDef_t InputFlagQueueControlBlock;
const osMessageQueueAttr_t InputFlagQueue_attributes = {
  .name = "InputFlagQueue",
  .cb_mem = &InputFlagQueueControlBlock,
  .cb_size = sizeof(InputFlagQueueControlBlock),
  .mq_mem = &InputFlagQueueBuffer,
  .mq_size = sizeof(InputFlagQueueBuffer)
};
/* Definitions for LvMutex */
osMutexId_t LvMutexHandle;
osStaticMutexDef_t LvMutexControlBlock;
const osMutexAttr_t LvMutex_attributes = {
  .name = "LvMutex",
  .cb_mem = &LvMutexControlBlock,
  .cb_size = sizeof(LvMutexControlBlock),
};
/* Definitions for AudioSemaphore */
osSemaphoreId_t AudioSemaphoreHandle;
osStaticSemaphoreDef_t AudioSemaphoreControlBlock;
const osSemaphoreAttr_t AudioSemaphore_attributes = {
  .name = "AudioSemaphore",
  .cb_mem = &AudioSemaphoreControlBlock,
  .cb_size = sizeof(AudioSemaphoreControlBlock),
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void SignalProcessingTask(void *argument);
void ProduceAudioTask(void *argument);
void LvHandlerTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */
  /* Create the mutex(es) */
  /* creation of LvMutex */
  LvMutexHandle = osMutexNew(&LvMutex_attributes);

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* creation of AudioSemaphore */
  AudioSemaphoreHandle = osSemaphoreNew(1, 1, &AudioSemaphore_attributes);

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */

  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of InputFlagQueue */
  InputFlagQueueHandle = osMessageQueueNew (1, sizeof(uint32_t), &InputFlagQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of SignalProcessing */
  SignalProcessingHandle = osThreadNew(SignalProcessingTask, NULL, &SignalProcessing_attributes);

  /* creation of ProduceAudio */
  ProduceAudioHandle = osThreadNew(ProduceAudioTask, NULL, &ProduceAudio_attributes);

  /* creation of lvHandler */
  lvHandlerHandle = osThreadNew(LvHandlerTask, NULL, &lvHandler_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_SignalProcessingTask */
/**
* @brief Function implementing the SignalProcessing thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_SignalProcessingTask */
__weak void SignalProcessingTask(void *argument)
{
  /* USER CODE BEGIN SignalProcessingTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END SignalProcessingTask */
}

/* USER CODE BEGIN Header_ProduceAudioTask */
/**
* @brief Function implementing the ProduceAudio thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_ProduceAudioTask */
__weak void ProduceAudioTask(void *argument)
{
  /* USER CODE BEGIN ProduceAudioTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END ProduceAudioTask */
}

/* USER CODE BEGIN Header_LvHandlerTask */
/**
* @brief Function implementing the lvHandler thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_LvHandlerTask */
__weak void LvHandlerTask(void *argument)
{
  /* USER CODE BEGIN LvHandlerTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END LvHandlerTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

