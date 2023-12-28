/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "main.h"
#include "cmsis_os.h"
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "stm32f429i_discovery_sdram.h"
#include "stm32f429i_discovery_lcd.h"
#include "usbd_cdc_if.h"
#include "stm32f429i_discovery_gyroscope.h"
#include "stm32f429i_discovery_io.h"
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
osThreadId Task01Handle;
osThreadId Task02Handle;
/* USER CODE BEGIN PV */
//float valxyz[3];
//uint8_t transmit_d[64];
volatile uint32_t value;
//uint8_t buffer[200];//text buffer

osMailQId(myMailQID);
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void StartTask01(void const * argument);
void StartTask02(void const * argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  BSP_SDRAM_Init();
  *((uint32_t*)SDRAM_DEVICE_ADDR)=0x12345678;
  value=*((uint32_t*)SDRAM_DEVICE_ADDR);
  BSP_LCD_Init();
  BSP_GYRO_Init();
  BSP_LCD_LayerDefaultInit(1, SDRAM_DEVICE_ADDR);
  BSP_LCD_SelectLayer(1);//select on which layer we
  BSP_LCD_DisplayOn();//turn on LCD
  BSP_LCD_Clear(LCD_COLOR_BLACK);//clear the LCD on blACK
  BSP_LCD_SetBackColor(LCD_COLOR_BLACK);//set text background color
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);//set text color
  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */


  osMailQDef( myMailQ, 3, float );

  myMailQID = osMailCreate(osMailQ(myMailQ), NULL);




  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of Task01 */
  osThreadDef(Task01, StartTask01, osPriorityNormal, 0, 256);
  Task01Handle = osThreadCreate(osThread(Task01), NULL);

  /* definition and creation of Task02 */
  osThreadDef(Task02, StartTask02, osPriorityNormal, 0, 128);
  Task02Handle = osThreadCreate(osThread(Task02), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
//
//	  HAL_Delay(1000);
//	  BSP_GYRO_GetXYZ(valxyz);
//	  sprintf(buffer,"xyz:	%f	%f	%f\r\n",valxyz[0],valxyz[1],valxyz[2]);
//	  CDC_Transmit_HS(buffer,64);
//
//
//	  if ((valxyz[0]<0) && (valxyz[1]<0) && (valxyz[2] > 0)){
//		  BSP_LCD_Clear(LCD_COLOR_BLACK);//clear the LCD on blACK
//		  BSP_LCD_DisplayStringAtLine(1,"      ^");
//		  BSP_LCD_DisplayStringAtLine(4,"<");
//	  } else if ((valxyz[0]<0) && (valxyz[1]>0) && (valxyz[2] < 0)){
//		  BSP_LCD_Clear(LCD_COLOR_BLACK);//clear the LCD on blACK
//		  BSP_LCD_DisplayStringAtLine(1,"      ^");
//		  BSP_LCD_DisplayStringAtLine(4,"             >");
//	  } else if (valxyz[0]>0 && valxyz[1]<0 && valxyz[2] < 0){
//		  BSP_LCD_Clear(LCD_COLOR_BLACK);//clear the LCD on blACK
//		  BSP_LCD_DisplayStringAtLine(4,"<");
//		  BSP_LCD_DisplayStringAtLine(8,"      v");
//	  } else if (valxyz[0]>0 && valxyz[1]>0 && valxyz[2] > 0){
//		  BSP_LCD_Clear(LCD_COLOR_BLACK);//clear the LCD on blACK
//		  BSP_LCD_DisplayStringAtLine(4,"             >");
//		  BSP_LCD_DisplayStringAtLine(8,"      v");
//	  }
//
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartTask01 */
/**
  * @brief  Function implementing the Task01 thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartTask01 */
void StartTask01(void const * argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN 5 */
	uint8_t buffer[200];//text buffer
	osSignalWait(0x1, osWaitForever);
	osSignalSet(Task02Handle, 0x1);
  /* Infinite loop */
  for(;;)
  {
	  osEvent event = osMailGet(myMailQID, osWaitForever); //Get mail
	  float *valxyz = event.value.p;
	  sprintf(buffer,"xyz:	%f	%f	%f\r\n",valxyz[0],valxyz[1],valxyz[2]);
	  osMailFree(myMailQID, valxyz); //Free mail queue memory
	  CDC_Transmit_HS(buffer,64);
  }
  for(;;){
  		  osDelay(1);
  	  }
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the Task02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void const * argument)
{
  /* USER CODE BEGIN StartTask02 */
  /* Infinite loop */
	if (BSP_GYRO_Init() != GYRO_OK)
	  {
	    Error_Handler();
	  }
	float valxyz[3];

	osSignalWait(0x1, osWaitForever);
  for(;;)
  {
	  BSP_GYRO_GetXYZ(valxyz);
	  float *transmit_d;
	  transmit_d = NULL;
	  do
	      {
	        transmit_d = (float *)osMailAlloc(myMailQID, osWaitForever); //Allocate memory slot
	      } while (NULL == transmit_d);

	  transmit_d = valxyz;

	  osMailPut(myMailQID, transmit_d); //Put data into mail queue. Check cmsis_os.c for API named
	  if ((valxyz[0]<0) && (valxyz[1]<0) && (valxyz[2] > 0)){
		  BSP_LCD_Clear(LCD_COLOR_BLACK);//clear the LCD on blACK
		  BSP_LCD_DisplayStringAtLine(1,"      ^");
		  BSP_LCD_DisplayStringAtLine(4,"<");
	  } else if ((valxyz[0] <0) && (valxyz[1]>0) && (valxyz[2] < 0)){
		  BSP_LCD_Clear(LCD_COLOR_BLACK);//clear the LCD on blACK
		  BSP_LCD_DisplayStringAtLine(1,"      ^");
		  BSP_LCD_DisplayStringAtLine(4,"             >");
	  } else if (valxyz[0] > 0 && valxyz[1] < 0 && valxyz[2] < 0){
		  BSP_LCD_Clear(LCD_COLOR_BLACK);//clear the LCD on blACK
		  BSP_LCD_DisplayStringAtLine(4,"<");
		  BSP_LCD_DisplayStringAtLine(8,"      v");
	  } else if (valxyz[0] >0 && valxyz[1] >0 && valxyz[2] > 0){
		  BSP_LCD_Clear(LCD_COLOR_BLACK);//clear the LCD on blACK
		  BSP_LCD_DisplayStringAtLine(4,"             >");
		  BSP_LCD_DisplayStringAtLine(8,"      v");
	  } else {
		  BSP_LCD_Clear(LCD_COLOR_BLACK);//clear the LCD on blACK
		  BSP_LCD_DisplayStringAtLine(4,"      *");
	  }
	  free(transmit_d);
  }
  for(;;){
    		  osDelay(1);
    	  }
  /* USER CODE END StartTask02 */
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
