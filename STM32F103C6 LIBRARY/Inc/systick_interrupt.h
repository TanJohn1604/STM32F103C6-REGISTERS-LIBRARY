/*
 * systick_interrupt.h
 *
 *  Created on: 11 thg 6, 2022
 *      Author: ad
 */

#ifndef SYSTICK_INTERRUPT_H_
#define SYSTICK_INTERRUPT_H_
#include"stm32f1xx.h"
void init_systick_interrupt();
void SysTick_Handler();

#endif /* SYSTICK_INTERRUPT_H_ */