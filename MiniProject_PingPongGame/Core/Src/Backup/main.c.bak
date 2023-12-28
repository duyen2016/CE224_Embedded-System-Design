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
#include "usbd_cdc_if.h"
#include "stm32f429i_discovery_lcd.h"
#include "stm32f429i_discovery_gyroscope.h"
#define X_drift 4.75
#define Y_drift 2.85
#define Z_drift 1.15

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
/* Definitions for Task0 */
osThreadId_t Task0Handle;
const osThreadAttr_t Task0_attributes = {
  .name = "Task0",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Task1 */
osThreadId_t Task1Handle;
const osThreadAttr_t Task1_attributes = {
  .name = "Task1",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Task2 */
osThreadId_t Task2Handle;
const osThreadAttr_t Task2_attributes = {
  .name = "Task2",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal1,
};
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void StartTask0(void *argument);
void StartTask1(void *argument);
void StartTask2(void *argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
	float X_up;
	int flag_up = 0, flag_down = 0, flag_start = 0, d = 0, score = 0, i = 0, sp;
	char X[10], Y[10], Z[10];

	int t0 = 0, t1 = 0, t2 = 0;
int distance (float x){
	int s;

	switch(i){
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5: s = 1; break;
		case 6:
		case 7:
		case 8:
		case 9:
		case 10: s = 2; break;
		case 11:
		case 12:
		case 13:
		case 14:
		default:s = 3; break;
	}

	x = x / s;

	if (x <= 30) {return 20;}	//10
	else if (x <= 60) {return 22;}	//11
	else if (x <= 90) {return 24;}	//12
	else if (x <= 120) {return 26;}	//13
	else if (x <= 150) {return 28;}	//14
	else if (x <= 180) {return 30;}	//15
	else if (x <= 210) {return 32;}	//16
	else if (x <= 240) {return 34;}	//17
	else if (x <= 270) {return 36;}	//18
	else if (x <= 300) {return 40;}	//20
	else if (x <= 330) {return 44;}	//22
	else if (x <= 360) {return 48;}	//24
    else if (x <= 390) {return 52;}	//26
    else if (x <= 420) {return 56;}	//28
    else if (x <= 450) {return 60;}	//30
    else if (x <= 480) {return 64;}	//32
    else if (x <= 510) {return 68;}	//34
    else if (x <= 540) {return 72;}	//36
    else if (x <= 570) {return 76;}	//38
    else {return 80;}	//40
}

int speed(float x){

	if (x <= 30) {return 100;}	//10
	else if (x <= 120) {return 90;}	//13
	else if (x <= 210) {return 80;}	//16
	else if (x <= 300) {return 70;}	//20
    else if (x <= 390) {return 60;}	//26
    else if (x <= 480) {return 50;}	//32
    else {return 40;}	//40
}
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
  BSP_SDRAM_Init();
  MX_GPIO_Init();
  BSP_GYRO_Init();
  MX_USB_DEVICE_Init();
          /* USER CODE BEGIN 2 */
  BSP_LCD_Init();//init LCD
          //set the layer buffer address into SDRAM
  BSP_LCD_LayerDefaultInit(1, SDRAM_DEVICE_ADDR);
  BSP_LCD_SelectLayer(1);//select on which layer we write
  BSP_LCD_DisplayOn();//turn on LCD
  BSP_LCD_Clear(LCD_COLOR_BLUE);//clear the LCD on blue color
  BSP_LCD_SetBackColor(LCD_COLOR_BLUE);//set text background color
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);//set text color

  /* USER CODE BEGIN 2 */
  CDC_Transmit_HS((uint8_t*)"Chieu cao bong:\n", 17);
  /* USER CODE END 2 */

  /* Init scheduler */
  osKernelInitialize();

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
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of Task0 */
  Task0Handle = osThreadNew(StartTask0, NULL, &Task0_attributes);

  /* creation of Task1 */
  Task1Handle = osThreadNew(StartTask1, NULL, &Task1_attributes);

  /* creation of Task2 */
  Task2Handle = osThreadNew(StartTask2, NULL, &Task2_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
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
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
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

  /** Enables the Clock Security System
  */
  HAL_RCC_EnableCSS();
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartTask0 */
/**
  * @brief  Function implementing the Task0 thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartTask0 */
void StartTask0(void *argument)
{
  /* init code for USB_DEVICE */
	//char X[20];

  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
	  if(d >= 20 && flag_down == 0){
		  i++;
		  if(i == d){flag_down = 1;}
	  }

	  if(flag_down == 1){
		  BSP_LCD_Clear(LCD_COLOR_BLUE);
		  BSP_LCD_FillCircle(120, 150, i + 20);
		  d--;
		  i--;
	  }
	  else{
		  BSP_LCD_FillCircle(120, 150, i + 20);
	  }

	  sprintf(X,"Score: %d", score);
	  BSP_LCD_DisplayStringAtLine(0, (uint8_t *)X);

	  if (flag_down == 0){
		  if (i <= (d - d*0.375)) {osDelay(sp * 0.375);}
		  else if (i <= (d - d*0.75)) {osDelay(sp * 0.75);}
		  else if (i <= (d - d*0.875)) {osDelay(sp * 0.875);}
		  else {osDelay(sp);}
	  }
	  else{
		  osDelay(100);
	  }

  }
  /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartTask1 */
/**
* @brief Function implementing the Task1 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask1 */
void StartTask1(void *argument)
{
  /* USER CODE BEGIN StartTask1 */
	char U[2];
	int u;
  /* Infinite loop */
  for(;;)
  {
	  u = i / 2;
	  sprintf(U, "%d", u);

	  CDC_Transmit_HS((uint8_t*)U, 2);
	  HAL_Delay(20);
	  CDC_Transmit_HS((uint8_t*)" cm\n", 5);
	  osDelay(200);
  }
  /* USER CODE END StartTask1 */
}

/* USER CODE BEGIN Header_StartTask2 */
/**
* @brief Function implementing the Task2 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask2 */
void StartTask2(void *argument)
{
  /* USER CODE BEGIN StartTask2 */
	float DATA[3] = {0};
  /* Infinite loop */
  for(;;)
  {
	  L3GD20_ReadXYZAngRate(DATA);

	  DATA[0] = DATA[0] - X_drift;
	  DATA[1] = DATA[1] - Y_drift;
	  DATA[2] = DATA[2] - Z_drift;

	  if (d < 15){
		  if (DATA[0] > 20){
			  if (DATA[0] > X_up) X_up = DATA[0];
			  flag_up = 1;
		  }

		  if (-20 <= DATA[0] && DATA[0] <= 20 && flag_up == 1){
			  d = distance(X_up);
			  sp = speed(X_up);
			  if(flag_start == 1){score++;}

			  flag_up = 0;
			  flag_down = 0;
			  flag_start = 1;
		  }

		  if(d < 0){
			  BSP_LCD_Clear(LCD_COLOR_BLUE);
			  sprintf(X,"Score: %d", score);
			  BSP_LCD_DisplayStringAtLine(0, (uint8_t *)X);
			  BSP_LCD_DisplayStringAt(0, 120, (uint8_t *)"GAME OVER!", CENTER_MODE);
			  BSP_LCD_DisplayStringAt(0, 160, (uint8_t *)"Press reset", CENTER_MODE);
			  BSP_LCD_DisplayStringAt(0, 180, (uint8_t *)"button to play", RIGHT_MODE);
			  while(1);
		  }
	  }
	  	osDelay(100);
  }
  /* USER CODE END StartTask2 */
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
