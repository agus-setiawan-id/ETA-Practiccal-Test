/*
 * Adc.c
 *
 *  Created on: Apr 4, 2026
 *      Author: pegug
 */

#include "stm32f401ccx.h"
#include "GlobalData.h"
#include "adc.h"

uint16_t filtered = 0;

uint16_t iir_filter(uint16_t input)
{
    filtered = filtered + ((input - filtered) >> 3); // alpha = 1/8
    return filtered;
}

unsigned int adc_read(void)
{
    // start conversion
    ADC1_CR2 |= (1 << 30);

    // wait done
    while (!(ADC1_SR & (1 << 1)));

    return iir_filter(ADC1_DR);
}
