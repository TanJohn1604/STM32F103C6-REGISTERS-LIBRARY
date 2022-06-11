/*
 * Interrupt_PA0.c
 *
 *  Created on: Jun 11, 2022
 *      Author: ad
 */
#include"interrupt_PA0.h"
#include "system_clock.h"
//extern int interrupt_PA0;
void init_interrupt_PA0(){
	AFIO->EXTICR[0] =0;
		EXTI->IMR |=1;
		EXTI->RTSR|=1;
		__disable_irq();
		NVIC_EnableIRQ(EXTI0_IRQn);
		__enable_irq();
}
void EXTI0_IRQHandler(){
	//xóa bit nhớ sự kiện ngắt
	EXTI->PR |=1;
	delay_ms(50);

//		if(interrupt_PA0){
//			interrupt_PA0=0;
//			}else{
//				interrupt_PA0=1;
//			}


}
