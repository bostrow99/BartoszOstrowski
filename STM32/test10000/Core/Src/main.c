/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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
#include "adc.h"
#include "dac.h"
#include "dma.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include <math.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define FullBufSize 1024
#define DataSize 512
#define Multiplicator 2

#define k_G1 1730*Multiplicator
#define k_G2 1494*Multiplicator
#define k_G3 1941*Multiplicator
#define k_G4 2156*Multiplicator
#define k_WP1 240*Multiplicator
#define k_WP2 81*Multiplicator
#define k_WP3 23*Multiplicator
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

uint32_t ADC_val[FullBufSize];
uint32_t DAC_val[FullBufSize];
float floatBufor[DataSize];

static volatile uint32_t* InBufPtr;
static volatile uint32_t* OutBufPtr;


float W = 0.7f;
float T = 1.0f;

int	Read_Ready = 0;
int DSP_Ready = 0;

int count=0;
float count2;
int G1_lim, G2_lim, G3_lim, G4_lim, WP1_lim, WP2_lim, WP3_lim;

float Gbuf1[k_G1], Gbuf2[k_G2], Gbuf3[k_G3], Gbuf4[k_G4];
float WPbuf1[k_WP1], WPbuf2[k_WP1], WPbuf3[k_WP1];

float G1_alpha = 0.805f, G2_alpha = 0.827f, G3_alpha = 0.783f, G4_alpha = 0.764f;
float WP1_alpha = 0.7f, WP2_alpha = 0.7f, WP3_alpha = 0.7f;

int G1_p = 0, G2_p = 0, G3_p = 0, G4_p = 0, WP1_p = 0, WP2_p = 0,WP3_p = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef *hadc)
{
InBufPtr = &ADC_val[0];
OutBufPtr = &DAC_val[DataSize];
HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
Read_Ready = 1;
if(DSP_Ready == 0)HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, GPIO_PIN_SET);
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
InBufPtr = &ADC_val[DataSize];
OutBufPtr = &DAC_val[0];
HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
if(DSP_Ready == 0)HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, GPIO_PIN_SET);
Read_Ready = 1;
}

float DO_G1(float inSample){
	float readback = Gbuf1[G1_p];
	float new = readback*G1_alpha + inSample;
	Gbuf1[G1_p] = new;
	G1_p++;
	if(G1_p == G1_lim) G1_p = 0;
	return readback;
}

float DO_G2(float inSample){
	float readback = Gbuf2[G2_p];
	float new = readback*G2_alpha + inSample;
	Gbuf2[G2_p] = new;
	G2_p++;
	if(G2_p == G2_lim) G2_p = 0;
	return readback;
}

float DO_G3(float inSample){
	float readback = Gbuf3[G3_p];
	float new = readback*G3_alpha + inSample;
	Gbuf3[G3_p] = new;
	G3_p++;
	if(G3_p == G3_lim) G3_p = 0;
	return readback;
}

float DO_G4(float inSample){
	float readback = Gbuf4[G4_p];
	float new = readback*G4_alpha + inSample;
	Gbuf4[G4_p] = new;
	G4_p++;
	if(G4_p == G4_lim) G4_p = 0;
	return readback;
}

float DO_WP1(float inSample){
	float readback = WPbuf1[WP1_p];
	readback += (-WP1_alpha) * inSample;
	float new = readback*WP1_alpha + inSample;
	WPbuf1[WP1_p] = new;
	WP1_p++;
	if(WP1_p == WP1_lim) WP1_p = 0;
	return readback;
}

float DO_WP2(float inSample){
	float readback = WPbuf2[WP2_p];
	readback += (-WP2_alpha) * inSample;
	float new = readback*WP2_alpha + inSample;
	WPbuf2[WP2_p] = new;
	WP2_p++;
	if(WP2_p == WP2_lim) WP2_p = 0;
	return readback;
}

float DO_WP3(float inSample){
	float readback = WPbuf3[WP3_p];
	readback += (-WP3_alpha) * inSample;
	float new = readback*WP3_alpha + inSample;
	WPbuf3[WP3_p] = new;
	WP3_p++;
	if(WP3_p == WP3_lim) WP3_p = 0;
	return readback;
}

float Do_Reverb(float inSample){
	float newsample = (DO_G1(inSample) + DO_G2(inSample) + DO_G3(inSample) + DO_G4(inSample))/4.0f;
	newsample = DO_WP1(newsample);
	newsample = DO_WP2(newsample);
	newsample = DO_WP3(newsample);
	return newsample;
}

void processDSPstraight(){
	for(int n=0; n<DataSize; n++){
		OutBufPtr[n]=InBufPtr[n];
	}
}

void processDSP(){
	DSP_Ready = 0;
	for(int n=0; n<DataSize; n++){
		floatBufor[n] = (((float)(InBufPtr[n])-2048)/2048);
		float sum = floatBufor[n];
		sum = (1.0f-W)*sum + W*Do_Reverb(sum);
		OutBufPtr[n]=(uint32_t)((sum*2048)+2048);
	}
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
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM6_Init();
  MX_ADC1_Init();
  MX_DAC1_Init();
  MX_TIM7_Init();
  /* USER CODE BEGIN 2 */

  G1_lim = (int)(T*k_G1);
  G2_lim = (int)(T*k_G2);
  G3_lim = (int)(T*k_G3);
  G4_lim = (int)(T*k_G4);
  WP1_lim = (int)(T*k_WP1);
  WP2_lim = (int)(T*k_WP2);
  WP3_lim = (int)(T*k_WP3);


  HAL_TIM_Base_Start(&htim6);
  HAL_TIM_Base_Start(&htim7);
  HAL_ADC_Start_DMA(&hadc1, (uint32_t*)ADC_val, FullBufSize);
  HAL_DAC_Start_DMA(&hdac1, DAC_CHANNEL_1, (uint32_t*)DAC_val, FullBufSize, DAC_ALIGN_12B_R);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  if(Read_Ready == 1){
		  __HAL_TIM_SET_COUNTER(&htim7,0);
		  //processDSPstraight();
		  processDSP();
		  count=__HAL_TIM_GET_COUNTER(&htim7);
		  count2 =(float)(count)*1e-5;
		  Read_Ready = 0;
		  DSP_Ready = 1;
		  HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, GPIO_PIN_RESET);
	  }
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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 9;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCCLKSOURCE_PLLSAI1;
  PeriphClkInit.PLLSAI1.PLLSAI1Source = RCC_PLLSOURCE_HSI;
  PeriphClkInit.PLLSAI1.PLLSAI1M = 1;
  PeriphClkInit.PLLSAI1.PLLSAI1N = 8;
  PeriphClkInit.PLLSAI1.PLLSAI1P = RCC_PLLP_DIV7;
  PeriphClkInit.PLLSAI1.PLLSAI1Q = RCC_PLLQ_DIV2;
  PeriphClkInit.PLLSAI1.PLLSAI1R = RCC_PLLR_DIV2;
  PeriphClkInit.PLLSAI1.PLLSAI1ClockOut = RCC_PLLSAI1_ADC1CLK;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
