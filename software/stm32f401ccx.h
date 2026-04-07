#ifndef STM32F401CCX_H_
#define STM32F401CCX_H_

#include <stdint.h>

// ================= BASE =================
#define RCC_BASE      0x40023800
#define GPIOA_BASE    0x40020000
#define GPIOC_BASE    0x40020800
#define TIM2_BASE     0x40000000
#define USART1_BASE   0x40011000
#define ADC1_BASE     0x40012000
#define IWDG_BASE      0x40003000

#define IWDG_KR        (*(volatile unsigned int*)(IWDG_BASE + 0x00))
#define IWDG_PR        (*(volatile unsigned int*)(IWDG_BASE + 0x04))
#define IWDG_RLR       (*(volatile unsigned int*)(IWDG_BASE + 0x08))
#define IWDG_SR        (*(volatile unsigned int*)(IWDG_BASE + 0x0C))

#define IWDG_KEY_ENABLE    0xCCCC
#define IWDG_KEY_REFRESH   0xAAAA
#define IWDG_KEY_ACCESS    0x5555

#define IWDG_PRESCALER_4     0x0
#define IWDG_PRESCALER_8     0x1
#define IWDG_PRESCALER_16    0x2
#define IWDG_PRESCALER_32    0x3
#define IWDG_PRESCALER_64    0x4
#define IWDG_PRESCALER_128   0x5
#define IWDG_PRESCALER_256   0x6

#define NVIC_ISER0    (*(volatile uint32_t*)0xE000E100)

#define TIM2_CNT (*(volatile unsigned int*)(TIM2_BASE + 0x24))

// ================= RCC =================
#define RCC_AHB1ENR   (*(volatile uint32_t*)(RCC_BASE + 0x30))
#define RCC_APB1ENR   (*(volatile uint32_t*)(RCC_BASE + 0x40))
#define RCC_APB2ENR   (*(volatile uint32_t*)(RCC_BASE + 0x44))

#define USART1_SR   (*(volatile unsigned int*)0x40011000)
#define USART1_DR   (*(volatile unsigned int*)0x40011004)
#define USART1_BRR  (*(volatile unsigned int*)0x40011008)
#define USART1_CR1  (*(volatile unsigned int*)0x4001100C)

// ================= GPIO =================
#define GPIOA_MODER   (*(volatile uint32_t*)(GPIOA_BASE + 0x00))
#define GPIOA_PUPDR   (*(volatile uint32_t*)(GPIOA_BASE + 0x0C))
#define GPIOA_IDR     (*(volatile uint32_t*)(GPIOA_BASE + 0x10))
#define GPIOA_ODR     (*(volatile uint32_t*)(GPIOA_BASE + 0x14))
#define GPIOA_AFRH    (*(volatile uint32_t*)(GPIOA_BASE + 0x24))

#define GPIOC_MODER   (*(volatile uint32_t*)(GPIOC_BASE + 0x00))
#define GPIOC_ODR     (*(volatile uint32_t*)(GPIOC_BASE + 0x14))

// ================= TIMER =================
#define TIM2_CR1      (*(volatile uint32_t*)(TIM2_BASE + 0x00))
#define TIM2_DIER     (*(volatile uint32_t*)(TIM2_BASE + 0x0C))
#define TIM2_SR       (*(volatile uint32_t*)(TIM2_BASE + 0x10))
#define TIM2_PSC      (*(volatile uint32_t*)(TIM2_BASE + 0x28))
#define TIM2_ARR      (*(volatile uint32_t*)(TIM2_BASE + 0x2C))

#define TIM2_CCR1  	  (*(volatile uint32_t*)0x40000034)
#define TIM2_CCMR1 	  (*(volatile uint32_t*)0x40000018)
#define TIM2_CCER  	  (*(volatile uint32_t*)0x40000020)

// ================= ADC =================
#define ADC1_SR       (*(volatile uint32_t*)(ADC1_BASE + 0x00))
#define ADC1_CR2      (*(volatile uint32_t*)(ADC1_BASE + 0x08))
#define ADC1_SMPR2    (*(volatile uint32_t*)(ADC1_BASE + 0x10))
#define ADC1_SQR3     (*(volatile uint32_t*)(ADC1_BASE + 0x34))
#define ADC1_DR       (*(volatile uint32_t*)(ADC1_BASE + 0x4C))

#endif
