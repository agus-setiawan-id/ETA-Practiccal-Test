/*
 * Timer.C
 *
 *  Created on: Apr 4, 2026
 *      Author: pegugu
 */

#include "Timer.h"
#include "UART.h"
#include "stm32f401ccx.h"
#include "globaldata.h"
#include "SystemInit.h"

void TIM2_IRQHandler(void)
{
    if (TIM2_SR & 1)
    {
        TIM2_SR &= ~(1 << 0);

        Data.OneMsFlag = 1;

    	Data.Milisecon++;
    	if(Data.Milisecon >= 1000){
    		Data.Milisecon 		= 0;
    		Data.OneSeconFlag 	= 1;
    		//GPIOC_ODR ^= (1 << 13);
    	}
    }
    if (USART1_SR & (1 << 5)) // RXNE
    {
       Data.rx_data = USART1_DR;  // baca data
       uart_process();
    }
}

void iwdg_refresh(void)
{
    IWDG_KR = 0xAAAA;
}

void pwm_pa15_set(unsigned int duty)
{
    if (duty >= 16000) duty = 15999;
    TIM2_CCR1 = duty;
}
