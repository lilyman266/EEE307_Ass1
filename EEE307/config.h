
/*Configures LED's as Outputs
    Configures PA4 to be connected to TIM3_CH2
    
    Then outputs LOGIC HIGH to the output pins to turn the LED's OFF
    
    */
void GPIO_Config(void){
    //Configure LED's 0-3 as outputs
    //Set GPIOC enable
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

    //Set pins 0-3 as digital output - 01
    GPIOC->MODER &= ~(GPIO_MODER_MODER0);
    GPIOC->MODER |= GPIO_MODER_MODER0_0;
    GPIOC->MODER &= ~(GPIO_MODER_MODER1);
    GPIOC->MODER |= GPIO_MODER_MODER1_0;
    GPIOC->MODER &= ~(GPIO_MODER_MODER2);
    GPIOC->MODER |= GPIO_MODER_MODER2_0;
    GPIOC->MODER &= ~(GPIO_MODER_MODER3);
    GPIOC->MODER |= GPIO_MODER_MODER3_0;

    //set low output speed - 00
    GPIOC->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED0;
    GPIOC->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED1;
    GPIOC->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED2;
    GPIOC->OSPEEDR &= ~GPIO_OSPEEDR_OSPEED3;

    //set open-drain mode (1)
    GPIOC->OTYPER |= GPIO_OTYPER_OT0;
    GPIOC->OTYPER |= GPIO_OTYPER_OT1;
    GPIOC->OTYPER |= GPIO_OTYPER_OT2;
    GPIOC->OTYPER |= GPIO_OTYPER_OT3;

    //set pull-up resistors (01)
    GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR0;
    GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR1;
    GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR2;
    GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR3;

}