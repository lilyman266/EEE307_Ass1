/*********************************************************************
*                    SEGGER Microcontroller GmbH                     *
*                        The Embedded Experts                        *
**********************************************************************

-------------------------- END-OF-HEADER -----------------------------

File    : main.c
Purpose : Generic application start

*/

#include <stdio.h>
#include <stdlib.h>

/*********************************************************************
*
*       main()
*
*  Function description
*   Application entry point.
*/
#include "config.h"
#include "stm32g491xx.h"

uint32_t led_number = 1;

int main(void) {
    GPIO_Config();
    TIM_Config();
    NVIC_EnableIRQ(TIM3_IRQn);
    TIM3->DIER |= TIM_DIER_UIE;
    if ( (TIM3->SR & TIM_SR_CC2IF) == 1) { // Test UIF
 // If hardware sets UIF, do some actions

 // Clear UIF
 TIM3->SR &= ~TIM_SR_CC2IF;
}
    while(1) {
      
}
}

void TIM3_IRQHandler(void) {
    //clear sr
    TIM3->SR &= ~TIM_SR_CC2IF;
    //check if ive reached the aar value
    if (ccr2 == aar){
        //return ccr2 to 10
        ccr2 = 10;
        TIM3->CCR2 = ccr2;
        //set current LED to 0 (ON)
        if (led_number == 1){
            //set led 1 to on
            GPIOA->MODER &= ~(GPIO_MODER_MODER4);
            GPIOA->MODER |= GPIO_MODER_MODER4_0;
            GPIOA->ODR &= ~GPIO_ODR_OD4;
            //set led 2 to pwm
            GPIOA->MODER &= ~(GPIO_MODER_MODER7);
            GPIOA->MODER |= GPIO_MODER_MODER7_1;
            
            led_number++;
        }
        else if (led_number == 2) {
            //set led 2 to on
            GPIOA->MODER &= ~(GPIO_MODER_MODER7);
            GPIOA->MODER |= GPIO_MODER_MODER7_0;
            GPIOA->ODR &= ~GPIO_ODR_OD7;
            //set led 3 to pwm
            GPIOB->MODER &= ~(GPIO_MODER_MODER5);
            GPIOB->MODER |= GPIO_MODER_MODER5_1;
            
            led_number++;
        }
        else if (led_number == 3) {
            //set led 3 to on
            GPIOB->MODER &= ~(GPIO_MODER_MODER5);
            GPIOB->MODER |= GPIO_MODER_MODER5_0;
            GPIOB->ODR &= ~GPIO_ODR_OD5;
            //set led 4 to pwm
            GPIOC->MODER &= ~(GPIO_MODER_MODER7);
            GPIOC->MODER |= GPIO_MODER_MODER7_1;
            
            led_number++;
        }
        else if (led_number == 4) {
            //turn all LED's off
            GPIOC->MODER &= ~(GPIO_MODER_MODER7);
            GPIOC->MODER |= GPIO_MODER_MODER7_0;
            
            GPIOA->ODR |= GPIO_ODR_OD4;
            GPIOA->ODR |= GPIO_ODR_OD7;
            GPIOB->ODR |= GPIO_ODR_OD5;
            GPIOC->ODR |= GPIO_ODR_OD7;

            //set led 1 to pwm
            GPIOA->MODER &= ~(GPIO_MODER_MODER4);
            GPIOA->MODER |= GPIO_MODER_MODER4_1;
            
            led_number = 1;
        }
    }
    //if no, increment
    else{
        ccr2++;
        TIM3->CCR2 = ccr2;

    }
    //if yes, turn it to 0 and enable the next led, reset ccr to 10
}

/*************************** End of file ****************************/
