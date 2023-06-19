/**
 * @file application.c
 * @author Viacheslav (v.konovalo@crystals.ru)
 * @brief
 * @version 0.1
 * @date 2022-11-09
 *
 * @copyright CSI Copyright (c) 2022
 *
 */
#include "application.h"
#include "gpio.h"
#include "main.h"
#include "version.h"
//>>---------------------- Log control
#define LOG_MODULE_NAME app
#if defined(NDEBUG)
#define LOG_MODULE_LEVEL (3)
#else
#define LOG_MODULE_LEVEL (3)
#endif
#include "log_libs.h"
//<<----------------------
/**
 * @brief
 *
 */
void application(void)
{
    LOG_INFO("Version: %s", FW_VERSION);
    while (1)
    {
        HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_RED_Pin);
        HAL_Delay(250);
        LOG_INFO("Version: %s", FW_VERSION);
    }
}