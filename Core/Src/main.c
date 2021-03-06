/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "iwdg.h"
#include "rtc.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "trace.h"
#include "stdio.h"
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

/* USER CODE BEGIN PV */
RTC_TimeTypeDef time;
RTC_DateTypeDef date;
char str_for_date[100];
char str_for_time[100];
uint8_t msg_sending_from_USART3[] = "USART3";
uint8_t msg_receiving_in_USART2[6];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
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
  MX_IWDG_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  MX_RTC_Init();
  /* USER CODE BEGIN 2 */
/*
 * Функция включает прерывания по флагу RXNE, разобраться, что это за флаг
 * и какие еще бывают.
 * В рамках 1-й лабы, раскомментировать ее и перейти в файл stm32f4xx_it.c
 * В обработчике прерываний по USART2, принять и обработать сообщение.
 */
  //__HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);

  /* Do not remove this code below */
  MX_TRACE_Init();
  SDK_TRACE_Start();
  /* Do not remove this code from above */
/* Блок работы с UART и функциями обратного вызова ---------------------------------------------------------*/

  /* Блокирующие функции */
  /* HAL_UART_Transmit(&huart3, msg_sending_from_USART3, 6, 50);

  	 HAL_UART_Receive(&huart2, msg_receiving_in_USART2, 6, 50); */

  /* Неблокирующие функции */
  /*HAL_UART_Transmit_IT(&huart3, msg_sending_from_USART3, 6);

  	HAL_UART_Receive_IT(&huart2, msg_receiving_in_USART2, 6); */
/* ---------------------------------------------------------------------------------------------------------*/

/* Тестовый пример работы со светодиодами ------------------------------------------------------------------*/

  /*SDK_TRACE_Timestamp(PRINT, 1);
  SDK_TRACE_Print("%s","LEDs Blink test");
  SDK_TRACE_Timestamp(PRINT, 0);
  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
  SDK_TRACE_Timestamp(LED3, HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_15));*/
  /* Place your code from here */
  /* Example of using LED tracing */

  /*for (int i = 0; i < 10; i++) {
	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
  	  SDK_TRACE_Timestamp(LED1, HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_13));
  	  HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_15);
  	  SDK_TRACE_Timestamp(LED3, HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_15));
  	  HAL_Delay(250);
  }

  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
  SDK_TRACE_Timestamp(LED1, HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_13));
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
  SDK_TRACE_Timestamp(LED3, HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_15));

  SDK_TRACE_Timestamp(PRINT, 1);
  SDK_TRACE_Print("%s","Test passed");
  SDK_TRACE_Timestamp(PRINT, 0);*/

  /* Example of sending debug messages */

  // SDK_TRACE_Print("%s%d%s%X", "Decimal value: ", 255, " Hex value: ", 255);

  /* Place your code before here */
  /* Do not remove this code below */
 // SDK_TRACE_Stop();
  /* Do not remove this code from above */

/*---------------------------------------------------------------------------------------------------------*/

/* Блок работы c RTC --------------------------------------------------------------------------------------*/

  /*SDK_TRACE_Timestamp(PRINT, 0);
HAL_RTC_GetTime(&hrtc, &time, RTC_FORMAT_BCD);
HAL_RTC_GetDate(&hrtc, &date, RTC_FORMAT_BCD);
SDK_TRACE_Timestamp(PRINT, 1);

sprintf(str_for_time, "1: Hour = %d Minutes = %d Seconds = %d", time.Hours, time.Minutes, time.Seconds);
sprintf(str_for_date, "1: WeekDay = %d Date = %d Month = %d Year = %d", date.WeekDay, date.Date, date.Month, date.Year);

SDK_TRACE_Timestamp(PRINT, 0);
SDK_TRACE_Print(str_for_time);
SDK_TRACE_Print(str_for_date);
SDK_TRACE_Timestamp(PRINT, 1);

SDK_TRACE_Stop();*/

/*---------------------------------------------------------------------------------------------------------*/
  /* USER CODE END 2 */

  /* Call init function for freertos objects (in freertos.c) */
  MX_FREERTOS_Init();
  /* Start scheduler */

  //osKernelStart(); // Функция включает планировщик задач FreeRTOS

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
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
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
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}
/*
 * Функции обратного вызова, в рамках 1-й лабораторной,
 * разобраться в принципе их работы.
 */
/* USER CODE BEGIN 4 */
/*void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart == &huart2){
		//SDK_TRACE_Print("%s", msg_receiving_in_USART2);
		SDK_TRACE_Print("%s", msg_receiving_in_USART2);
		SDK_TRACE_Stop();
	}
}
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart == &huart3){
		SDK_TRACE_Print("%s","Callback function");


	}
}*/
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
