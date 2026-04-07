/*
 * Timer.H
 *
 *  Created on: Apr 4, 2026
 *      Author: pegug
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>

void TIM2_IRQHandler(void);

void iwdg_refresh(void);

void pwm_pa15_set(unsigned int duty);

#endif
