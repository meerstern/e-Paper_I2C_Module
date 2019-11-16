
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f3xx_hal.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"

/* USER CODE BEGIN Includes */
#define USE_EPD1IN54_V2
//#define USE_EPD1IN54_V1
#ifdef USE_EPD1IN54_V1
	#include "epd1in54.h"
#endif
#ifdef USE_EPD1IN54_V2
	#include "epd1in54_v2.h"
#endif

#include "epdif.h"
#include "epdpaint.h"
#include "imagedata.h"
#include <stdlib.h>
#include "i2c-spi_bridge.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/
int _write (int fd, char *ptr, int len)
{
  HAL_UART_Transmit(&huart2, (uint8_t*)ptr, len, 1000);
  return len;
}
/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
#define COLORED      0
#define UNCOLORED    1
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  unsigned char* frame_buffer = (unsigned char*)malloc(EPD_WIDTH * EPD_HEIGHT / 8);
  char time_string[] = {'0', '0', ':', '0', '0', '\0'};
  unsigned long time_start_ms;
  unsigned long time_now_s;

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  printf("Init OK! \n");

  if(HAL_I2C_Master_Transmit(&hi2c1,SC18IS602_ADDRESS,(uint8_t*)0x00,0,50)!=HAL_OK){
	  printf("DEV NOT FOUND!\n");
  }

  SC18IS602_InitDevice();


#ifdef USE_EPD1IN54_V1
  EPD epd;
  if (EPD_Init(&epd, lut_full_update) != 0) {
    printf("e-Paper init failed\n");
    return -1;
  }
#endif
#ifdef USE_EPD1IN54_V2
  EPD_1IN54_V2_Init();

#endif

  Paint paint;
  //printf("W:%d, H:%d \n",epd.width,epd.height);
  Paint_Init(&paint, frame_buffer, EPD_WIDTH, EPD_HEIGHT);
  Paint_Clear(&paint, UNCOLORED);
  Paint_SetRotate(&paint, ROTATE_270);


  /* For simplicity, the arguments are explicit numerical coordinates */
  /* Write strings to the buffer */
  Paint_DrawFilledRectangle(&paint, 0, 10, 200, 50, COLORED);

  Paint_DrawStringAt(&paint, 52, 24, "Crescent ", &Font16, UNCOLORED);
  Paint_DrawStringAt(&paint, 40, 60, "e-Paper I2C ", &Font16, COLORED);
  Paint_DrawStringAt(&paint, 35, 80, "Grove Module", &Font16, COLORED);

  Paint_DrawStringAt(&paint, 60, 120, "Hello!!", &Font16, COLORED);

  /* Display the frame_buffer */
#ifdef USE_EPD1IN54_V1
  EPD_SetFrameMemory(&epd, frame_buffer, 0, 0, Paint_GetWidth(&paint), Paint_GetHeight(&paint));
  EPD_DisplayFrame(&epd);
  EPD_SetFrameMemory(&epd, frame_buffer, 0, 0, Paint_GetWidth(&paint), Paint_GetHeight(&paint));
  EPD_DisplayFrame(&epd);
  EPD_DelayMs(&epd, 2000);
#endif

#ifdef USE_EPD1IN54_V2
  EPD_1IN54_V2_Display(frame_buffer);
  HAL_Delay(1000);
  EPD_1IN54_V2_Init();
  EPD_1IN54_V2_DisplayPartBaseImage(frame_buffer);
#endif

  while(1);



  /* EPD_or partial update */
#ifdef USE_EPD1IN54_V1
  if (EPD_Init(&epd, lut_partial_update) != 0) {
    printf("e-Paper init failed\n");
    return -1;
  }
#endif

  time_start_ms = HAL_GetTick();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
	    time_now_s = (HAL_GetTick() - time_start_ms) / 1000;
	    time_string[0] = time_now_s / 60 / 10 + '0';
	    time_string[1] = time_now_s / 60 % 10 + '0';
	    time_string[3] = time_now_s % 60 / 10 + '0';
	    time_string[4] = time_now_s % 60 % 10 + '0';


#ifdef USE_EPD1IN54_V1
	    Paint_SetWidth(&paint, 32);
	    Paint_SetHeight(&paint, 96);
	    Paint_SetRotate(&paint, ROTATE_270);

	    Paint_Clear(&paint, UNCOLORED);
	    Paint_DrawStringAt(&paint, 10, 84, time_string, &Font24, COLORED);

	    EPD_SetFrameMemory(&epd, frame_buffer, 50, 100, Paint_GetWidth(&paint), Paint_GetHeight(&paint));
	    EPD_DisplayFrame(&epd);
#endif
#ifdef USE_EPD1IN54_V2

	    Paint_DrawFilledRectangle(&paint, 0, 140, 200, 180, UNCOLORED);
	    Paint_DrawStringAt(&paint, 50, 160, time_string, &Font24, COLORED);

	    EPD_1IN54_V2_DisplayPart(frame_buffer);

#endif

  }
  /* USER CODE END 3 */

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
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
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
