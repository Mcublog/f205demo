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
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "application.h"
#include "dwt/dwt.h"
#include "ee24/ee24.h"
#include "gpio.h"
#include "i2c.h"
#include "main.h"
#include "melodies/bumer.h"
#include "melodies/melody.h"
#include "melodies/tone.hpp"
#include "version.h"
//>>---------------------- Log control
#define LOG_MODULE_NAME app
#define LOG_MODULE_LEVEL (3)
#include "log_libs.h"
//<<----------------------

//>>---------------------- Global variables
extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart6;
//<<----------------------

//>>---------------------- Local variables
static const uint8_t EEPROM_ADR = 0xA0;
static const uint16_t EEPROM_ADR_IN_MEM = 0;
//<<----------------------

/**
 * @brief Read/write to EEPROM
 *
 */
static void eeprom_test(void)
{
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
}


void play(const int32_t *melody, size_t melodySize, int tempo)
{
    // notes of the moledy followed by the duration.
    // a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
    // !!negative numbers are used to represent dotted notes,
    // so -4 means a dotted quarter note, that is, a quarter plus an
    // eighteenth!!

    // sizeof gives the number of bytes, each int value is composed of two bytes
    // (16 bits) there are two values per note (pitch and duration), so for each
    // note there are four bytes
    int notes = melodySize / sizeof(melody[0]) / 2;

    // this calculates the duration of a whole note in ms (60s/tempo)*4 beats
    int wholenote = (60000 * 4) / tempo;

    int divider = 0, noteDuration = 0;

    for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2)
    {

        // calculates the duration of each note
        divider = melody[thisNote + 1];
        if (divider > 0)
        {
            // regular note, just proceed
            noteDuration = (wholenote) / divider;
        }
        else if (divider < 0)
        {
            // dotted notes are represented with negative durations!!
            noteDuration = (wholenote) / abs(divider);
            noteDuration *=
                1.3; // increases the duration in half for dotted notes
        }

        // we only play the note for 90% of the duration, leaving 10% as a pause
        tone((uint32_t)melody[thisNote], (uint32_t)noteDuration * 0.9);

        // Wait for the specief duration before playing the next note.
        delay((uint32_t)noteDuration);

        // stop the waveform generation before the next note.
        tone((uint32_t)0, (uint32_t)noteDuration);
    }
}

/**
 * @brief
 *
 */
void application(void)
{
    LOG_INFO("Version: %s", FW_VERSION);
    HAL_GPIO_WritePin(ON_3V3_P_GPIO_Port, ON_3V3_P_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(ON_5V_GPIO_Port, ON_5V_Pin, GPIO_PIN_SET);

    // eeprom_test();
    dwt_init();

    int melodyCount = sizeof(melodySizes) / sizeof(uint32_t);
    int melodyIndex = 4;

    play(melody[melodyIndex], melodySizes[melodyIndex], (int)(325 / 2));

    // bumer(0);

    while (1)
    {
        HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_RED_Pin);
        delay((uint32_t)250);
    }
}