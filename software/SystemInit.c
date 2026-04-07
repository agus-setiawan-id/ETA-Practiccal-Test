/*
 * SystemInit.c
 *
 *  Created on: Apr 4, 2026
 *      Author: pegug
 */
#include "stm32f401ccx.h"
#include "globaldata.h"

void gpio_init(void)
{
    RCC_AHB1ENR |= (1 << 0) | (1 << 2);

    // INPUT PA3,4,5 pull-down
    GPIOA_MODER &= ~(3<<(3*2) | 3<<(4*2) | 3<<(5*2));
    GPIOA_PUPDR &= ~(3<<(3*2) | 3<<(4*2) | 3<<(5*2));
    GPIOA_PUPDR |=  (2<<(3*2) | 2<<(4*2) | 2<<(5*2));

    // ANALOG PA7
    GPIOA_MODER |= (3<<(7*2));
    GPIOA_PUPDR &= ~(3<<(7*2));

    // UART PA9/10 AF7
    GPIOA_MODER |= (2<<(9*2)) | (2<<(10*2));
    GPIOA_AFRH |= (7<<4) | (7<<8);

    // LED PC13
    GPIOC_MODER |= (1<<(13*2));
    GPIOC_ODR |= (1<<13);

    GPIOA_MODER &= ~(3 << (15 * 2));
    GPIOA_MODER |=  (1 << (15 * 2));

    GPIOA_ODR &= ~(1 << 15);
}

void uart1_init(void)
{
    RCC_AHB1ENR |= (1 << 0);   // GPIOA
    RCC_APB2ENR |= (1 << 4);   // USART1

    // PA9 TX, PA10 RX
    GPIOA_MODER &= ~((3 << (9*2)) | (3 << (10*2)));
    GPIOA_MODER |=  ((2 << (9*2)) | (2 << (10*2)));

    GPIOA_AFRH &= ~((0xF << (1*4)) | (0xF << (2*4)));
    GPIOA_AFRH |=  ((7 << (1*4)) | (7 << (2*4)));

    USART1_BRR = 0x8B; // 115200 @16MHz

    USART1_CR1 |= (1 << 2);  // RE
    USART1_CR1 |= (1 << 3);  // TE
    USART1_CR1 |= (1 << 5);  // RXNE interrupt enable
    USART1_CR1 |= (1 << 13); // UE

    // enable NVIC USART1
    *(volatile unsigned int*)0xE000E100 |= (1 << 37); // IRQ37 USART1
}

void pwm_pa15_off(void)
{
    // 1. disable output compare channel 1
    TIM2_CCER &= ~(1 << 0);

    // 2. stop timer (optional )
    //TIM2_CR1 &= ~(1 << 0);

    // 3. set PA15 jadi GPIO output
    GPIOA_MODER &= ~(3 << (15 * 2));
    GPIOA_MODER |=  (1 << (15 * 2)); // output mode

    // 4. set LOW (0V)
    GPIOA_ODR &= ~(1 << 15);
}

void pwm_pa15_on(void)
{
    // balik ke AF
    GPIOA_MODER &= ~(3 << (15 * 2));
    GPIOA_MODER |=  (2 << (15 * 2));

    // enable channel
    TIM2_CCER |= (1 << 0);

    // start timer
    TIM2_CR1 |= (1 << 0);
}

void adc_init(void)
{
    RCC_APB2ENR |= (1<<8);

    ADC1_SMPR2 |= (7<<(7*3));
    ADC1_SQR3 = 7;
    ADC1_CR2 |= (1<<0);
}

void tim2_init(void)
{
    RCC_APB1ENR |= (1 << 0);

    TIM2_PSC = 0; // 1kHz
    TIM2_ARR = 16000 - 1;         // 1ms

    TIM2_CNT = 0;
    TIM2_SR  = 0;

    TIM2_DIER |= (1 << 0);

    NVIC_ISER0 |= (1 << 28);

    TIM2_CR1 |= (1 << 0);
}
void pwm_pa15_init(void)
{
    // enable clock (tidak ganggu bit lain)
    RCC_AHB1ENR |= (1 << 0);  // GPIOA
    RCC_APB1ENR |= (1 << 0);  // TIM2

    // PA15 → AF mode
    GPIOA_MODER &= ~(3 << (15 * 2));
    GPIOA_MODER |=  (2 << (15 * 2));

    // AF1 (TIM2) → PA15 di AFRH index 7
    GPIOA_AFRH &= ~(0xF << (7 * 4));
    GPIOA_AFRH |=  (1 << (7 * 4));

    // PWM mode 1 (hanya ubah CH1 field)
    TIM2_CCMR1 &= ~(7 << 4);
    TIM2_CCMR1 |=  (6 << 4);  // PWM mode

    TIM2_CCMR1 |= (1 << 3);   // preload enable

    // duty awal 50%
    TIM2_CCR1 = 0;

    // enable output channel 1 saja
    TIM2_CCER |= (1 << 0);

    // start timer
    TIM2_CR1 |= (1 << 0);
}


void iwdg_init(void)
{
    // unlock
    IWDG_KR = 0x5555;

    // prescaler = 32
    IWDG_PR = 0x3;

    // reload value (~1 detik)
    IWDG_RLR = 1000;

    // reload counter
    IWDG_KR = 0xAAAA;

    // start watchdog
    IWDG_KR = 0xCCCC;
}
