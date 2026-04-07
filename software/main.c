#include "stm32f401ccx.h"
#include "globaldata.h"
#include "SystemInit.h"
#include "Timer.h"
#include "work.h"

Data_t Data = {0};

int main(void)
{
    gpio_init();
    adc_init();
    tim2_init();
    uart1_init();
    iwdg_init();

    __asm volatile ("cpsie i");

    while(1)
    {
    	if(Data.OneMsFlag == 1){
    		Data.OneMsFlag = 0;
    		WorkRun();
    	}
        iwdg_refresh(); //watchdog 1S
    }
}
