/*
 * SystemInit.H
 *
 *  Created on: Apr 4, 2026
 *      Author: pegugu
 */

#ifndef SYSTEMINIT_H_
#define SYSTEMINIT_H_

void gpio_init();

void tim2_init();

void adc_init(void);

void uart1_init(void);

void iwdg_init(void);

void pwm_pa15_init(void);

void pwm_pa15_off(void);

void pwm_pa15_on(void);

#endif /* SYSTEMINIT_H_ */
