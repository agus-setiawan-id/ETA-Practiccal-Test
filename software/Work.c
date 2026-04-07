/*
 * Work.c
 *
 *  Created on: Apr 4, 2026
 *      Author: pegug
 */

#include "stm32f401ccx.h"
#include "Timer.h"
#include "adc.h"
#include "GlobalData.h"
#include "UART.h"

void DryContactRun(void){
	Data.Digital1_In = ((GPIOA_IDR >> 3) & 1);
	if(Data.Digital1_In != Data.Digital1_Stable){
		Data.DebounceMs++;
		if(Data.DebounceMs > 20){
			Data.DebounceMs = 0;
			Data.Digital1_Stable = Data.Digital1_In;
		}
	}
	else if(Data.Digital1_In == Data.Digital1_Stable){
		Data.DebounceMs = 0;
	}
}

void WetContactRun(void){
	Data.Digital2_Stable = ((GPIOA_IDR >> 5) & 1);
}

void PulseInputHandler(void){
	Data.Pulse_In = ((GPIOA_IDR >> 4) & 1);

	if((Data.Pulse_In == 1) && (Data.Pulse_Data == 0)){
		//Rising edge
		Data.Pulse_Count++;
	}
	Data.Pulse_Data = Data.Pulse_In;
}

void WorkRun(void){
	Data.AnalogValue = adc_read();
	DryContactRun();
	WetContactRun();
	PulseInputHandler();
	if(Data.OneSeconFlag == 1){
		UART_SendAll(Data.Digital1_Stable, Data.Digital2_Stable, Data.Digital_Out, Data.Pulse_Count, Data.AnalogValue);
		Data.OneSeconFlag = 0;
		Data.Pulse_Count = 0;
		//GPIOC_ODR ^= (1 << 13);
	}
}
