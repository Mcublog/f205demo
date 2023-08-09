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
#include <stdio.h>
#include <stdbool.h>

#include "application.h"
#include "gpio.h"
#include "i2c.h"
#include "main.h"
#include "version.h"
#include "ee24/ee24.h"
//>>---------------------- Log control
#define LOG_MODULE_NAME app
#define LOG_MODULE_LEVEL (3)
#include "log_libs.h"
//<<----------------------

//>>---------------------- Global variables
extern I2C_HandleTypeDef hi2c1;
//<<----------------------

//>>---------------------- Local variables
static const uint8_t EEPROM_ADR = 0xA0;
static const uint16_t EEPROM_ADR_IN_MEM = 0;
//<<----------------------

/**
 * @brief
 *
 */
void application(void)
{
    LOG_INFO("Version: %s", FW_VERSION);
    HAL_GPIO_WritePin(ON_3V3_P_GPIO_Port, ON_3V3_P_Pin, GPIO_PIN_SET);

    while (ee24_isConnected() == false)
        HAL_Delay(1);

    if (ee24_isConnected())
        LOG_INFO("EEPROM is connected");

    bool res = ee24_eraseChip();
    LOG_INFO("ee24_eraseChip: %d", res);

    HAL_Delay(100);
    uint8_t data[1024] = {0};
    for (uint32_t i = 0; i < 1024; i++)
        data[i] = (i + 1);

    res = ee24_write(0, data, 1024, 1000);
    LOG_INFO("ee24_write: %d", res);

    res = ee24_read(0, data, 1024, 100);
    LOG_INFO("ee24_read: %d", res);

    for (uint32_t i = 0; i < 1024; i++)
    {
        if (data[i] != ((i + 1) & 0xFF))
            LOG_ERROR("0x%02x != 0x%02x", data[i], (i + 1) & 0xFF);
        printf("0x%02x ", data[i]);
        HAL_Delay(1);
        if (i == 0)
            continue;
        if (i % 15)
            continue;
        puts("");
    }

    while (1)
    {
        HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_RED_Pin);
        HAL_GPIO_TogglePin(LED_DEBUG_GPIO_Port, LED_DEBUG_Pin);
        HAL_Delay(250);
    }
}