/**
 * @file tone.cpp
 * @author Viacheslav (v.konovalo@crystals.ru)
 * @brief
 * @version 0.1
 * @date 2024-05-04
 *
 * @copyright CSI Copyright (c) 2024
 *
 */
#include <cstdbool>
#include <cstdlib>

#include "tone.hpp"
#include "dwt/dwt.h"
#include "gpio.h"
#include "main.h"

static void set_buzzer_pin(bool state)
{
    GPIO_PinState pinstate = state ? GPIO_PIN_SET : GPIO_PIN_RESET;
    HAL_GPIO_WritePin(Buzzer_GPIO_Port, Buzzer_Pin, pinstate);
    HAL_GPIO_WritePin(LED_DEBUG_GPIO_Port, LED_DEBUG_Pin, pinstate);
}


void delay(double ms)
{
    dwt_delay_us((uint32_t)(ms * 1000));
}

void delay(uint32_t ms)
{
    dwt_delay_us(ms * 1000);
}

void delay(int32_t ms)
{
    dwt_delay_us(abs(ms) * 1000);
}


void tone(uint32_t frequency, uint32_t duration)
{
    set_buzzer_pin(true);

    // calculate the delay value between transitions
    uint32_t delayValue = 1000000 / frequency / 4;
    //// 1 second's worth of microseconds, divided by the frequency, then split
    /// in half since / there are two phases to each cycle

    // calculate the number of cycles for proper timing
    uint32_t numCycles = frequency * duration / 1000;
    //// multiply frequency, which is really cycles per second, by the number of
    /// seconds to / get the total number of cycles to produce
    for (uint32_t i = 0; i < numCycles; i++)
    { // for the calculated duration of time...
        // write the buzzer pin high to push out the diaphram
        set_buzzer_pin(true);
        dwt_delay_us(delayValue); // wait for the calculated delay value
        // write the buzzer pin low to pull back the diaphram
        set_buzzer_pin(false);
        // wait again or the calculated delay value
        dwt_delay_us(delayValue);
    }
    set_buzzer_pin(false);
}

void tone(int32_t pin, uint32_t frequency, double duration)
{
    tone(frequency, (uint32_t)duration);
}