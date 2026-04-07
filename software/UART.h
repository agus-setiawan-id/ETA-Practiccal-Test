/*
 * UART.h
 *
 *  Created on: Apr 4, 2026
 *      Author: pegug
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>

void UART_SendAll(uint8_t d1, uint8_t d2, uint8_t d3, uint32_t pulse, uint16_t adc);

void uart_process(void);

#endif /* UART_H_ */
