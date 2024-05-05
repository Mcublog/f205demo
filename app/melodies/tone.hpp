
#ifndef TONE_H
#define TONE_H

#include <cstdint>

void tone(uint32_t frequency, uint32_t duration);
void tone(int32_t pin, uint32_t frequency, double duration);

void delay(double ms);
void delay(uint32_t ms);
void delay(int32_t ms);


#endif // TONE_H