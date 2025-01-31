
/*Configures LED's as Outputs
    Configures PA4 to be connected to TIM3_CH2
    
    Then outputs LOGIC HIGH to the output pins to turn the LED's OFF
    
    */
#include "stm32g491xx.h"

uint32_t psc = 1599;
uint32_t aar = 199;
uint32_t ccr2 = 50;

void GPIO_Config(void){
    //Configure LED's 0-3 as outputs
    //Set GPIOC enable
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;

    //Set pins 0-3 as digital output - 01
    GPIOA->MODER &= ~(GPIO_MODER_MODER4);
    GPIOA->MODER |= GPIO_MODER_MODER4_1; //TODO: THIS TURNS OFF THE LIGHT PERMANENTLY. 
    GPIOA->MODER &= ~(GPIO_MODER_MODER7);
    GPIOA->MODER |= GPIO_MODER_MODER7_0;
    GPIOB->MODER &= ~(GPIO_MODER_MODER5);
    GPIOB->MODER |= GPIO_MODER_MODER5_0;
    GPIOC->MODER &= ~(GPIO_MODER_MODER7);
    GPIOC->MODER |= GPIO_MODER_MODER7_0;

    //set low output speed - 00
    GPIOA->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED4;
    GPIOA->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED7;
    GPIOB->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED5;
    GPIOC->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED7;

    //set open-drain mode (1)
    GPIOA->OTYPER |= GPIO_OTYPER_OT4;
    GPIOA->OTYPER |= GPIO_OTYPER_OT7;
    GPIOB->OTYPER |= GPIO_OTYPER_OT5;
    GPIOC->OTYPER |= GPIO_OTYPER_OT7;

    //set pull-up resistors (01)
    GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR4;
    GPIOA->PUPDR &= ~GPIO_PUPDR_PUPDR7;
    GPIOB->PUPDR &= ~GPIO_PUPDR_PUPDR5;
    GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR7;

    //clear AF bits
    GPIOA->AFR[0] &= ~(GPIO_AFRL_AFSEL4);
    GPIOA->AFR[0] |= GPIO_AFRL_AFSEL4_1;
    //GPIOA->AFR[0] &= ~(GPIO_AFRL_AFSEL7);
    //GPIOA->AFR[0] |= GPIO_AFRL_AFSEL7_1;
    //GPIOB->AFR[0] &= ~(GPIO_AFRL_AFSEL5);
    //GPIOB->AFR[0] |= GPIO_AFRL_AFSEL5_1;
    //GPIOC->AFR[0] &= ~(GPIO_AFRL_AFSEL7);
    //GPIOC->AFR[0] |= GPIO_AFRL_AFSEL7_1;

    //output 1 on GPIO's
    GPIOA->ODR |= GPIO_ODR_OD4;
    GPIOA->ODR |= GPIO_ODR_OD7;
    GPIOB->ODR |= GPIO_ODR_OD5;
    GPIOC->ODR |= GPIO_ODR_OD7;

    //output 0 on GPIO's - turns them all on - FOR TESTING
    //GPIOA->ODR &= ~GPIO_ODR_OD4;
    //GPIOA->ODR &= ~GPIO_ODR_OD7;
    //GPIOB->ODR &= ~GPIO_ODR_OD5;
    //GPIOC->ODR &= ~GPIO_ODR_OD7;

    //Connecting PA4 to the TIM3 
    
}

void TIM_Config(void){
    //enable TIM3 clock
    RCC->APB1ENR1 |= RCC_APB1ENR1_TIM3EN;

    //configure TIM3 for PWN mode
    TIM3->PSC = 15999999; //PRESCALAR
    TIM3->ARR = 199;  //AUTO RELOAD VALUE
    TIM3->CCR2 = 10; //90% DUTY CYCLE
    TIM3->CCMR1 &= ~TIM_CCMR1_OC2M;
    TIM3->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_0 | TIM_CCMR1_OC2M_2; //PWM mode 1
    TIM3->CCER |= TIM_CCER_CC2E; //ENABLE OUTPUT ON CH1
    TIM3->CR1 |= TIM_CR1_CEN;   //ENABLE TIMER


}