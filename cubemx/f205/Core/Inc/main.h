/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f2xx_hal.h"

#include "stm32f2xx_ll_rcc.h"
#include "stm32f2xx_ll_bus.h"
#include "stm32f2xx_ll_system.h"
#include "stm32f2xx_ll_exti.h"
#include "stm32f2xx_ll_cortex.h"
#include "stm32f2xx_ll_utils.h"
#include "stm32f2xx_ll_pwr.h"
#include "stm32f2xx_ll_dma.h"
#include "stm32f2xx_ll_gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_DEBUG_Pin GPIO_PIN_13
#define LED_DEBUG_GPIO_Port GPIOC
#define BEEPER_Pin GPIO_PIN_0
#define BEEPER_GPIO_Port GPIOA
#define LED_RED_Pin GPIO_PIN_4
#define LED_RED_GPIO_Port GPIOC
#define LED_BLUE_Pin GPIO_PIN_5
#define LED_BLUE_GPIO_Port GPIOC
#define PWDN_Pin GPIO_PIN_0
#define PWDN_GPIO_Port GPIOB
#define PWDN_EXTI_IRQn EXTI0_IRQn
#define ON_3V3_P_Pin GPIO_PIN_15
#define ON_3V3_P_GPIO_Port GPIOA
#define ON_5V_Pin GPIO_PIN_10
#define ON_5V_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
