/*
 * UART.c
 *
 *  Created on: Apr 4, 2026
 *      Author: pegug
 */

#include <stdio.h>
#include <stdint.h>
#include "stm32f401ccx.h"
#include "GlobalData.h"
#include "UART.h"
#include "Timer.h"
#include "SystemInit.h"

void UART1_SendChar(char c)
{
    while (!(USART1_SR & (1 << 7)));
    USART1_DR = c;
}

void UART1_SendString(char *s)
{
    while (*s)
    {
        UART1_SendChar(*s++);
    }
}

void UART_SendAll(uint8_t d1, uint8_t d2, uint8_t d3, uint32_t pulse, uint16_t adc)
{
    char buffer[50];

    sprintf(buffer, "{%d,%d,%d,%lu,%u}\r\n", d1, d2, d3, pulse, adc);

    UART1_SendString(buffer);
}

void uart_process(void)
{
	unsigned char state = Data.rx_data;
	switch(state){
	case 0xAA:
		pwm_pa15_off();
		Data.Digital_Out = 0;
		break;
	case 0xAB:
		pwm_pa15_init();
		pwm_pa15_on();
		pwm_pa15_set(1600); //10%
		Data.Digital_Out = 10;
		break;
	case 0xAD:
		pwm_pa15_init();
		pwm_pa15_on();
		pwm_pa15_set(3200); //20%
		Data.Digital_Out = 20;
		break;
	case 0xAE:
		pwm_pa15_init();
		pwm_pa15_on();
		pwm_pa15_set(4800); //30%
		Data.Digital_Out = 30;
		break;
	case 0xAF:
		pwm_pa15_init();
		pwm_pa15_on();
		pwm_pa15_set(6400); //40%
		Data.Digital_Out = 40;
		break;
	case 0xBB:
		pwm_pa15_init();
		pwm_pa15_on();
		pwm_pa15_set(8000); //50%
		Data.Digital_Out = 50;
		break;
	case 0xBC:
		pwm_pa15_init();
		pwm_pa15_on();
		pwm_pa15_set(9600); //60%
		Data.Digital_Out = 60;
		break;
	case 0xBD:
		pwm_pa15_init();
		pwm_pa15_on();
		pwm_pa15_set(11200); //70%
		Data.Digital_Out = 70;
		break;
	case 0xBF:
		pwm_pa15_init();
		pwm_pa15_on();
		pwm_pa15_set(12800); //80%
		Data.Digital_Out = 80;
		break;
	case 0xCC:
		pwm_pa15_init();
		pwm_pa15_on();
		pwm_pa15_set(14400); //90%
		Data.Digital_Out = 90;
		break;
	case 0xCD:
		pwm_pa15_init();
		pwm_pa15_on();
		pwm_pa15_set(16000); //100%
		Data.Digital_Out = 100;
		break;
	}
}
