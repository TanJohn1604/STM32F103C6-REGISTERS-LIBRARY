/*
 * Interrupt_PA0.h
 *
 *  Created on: Jun 11, 2022
 *      Author: ad
 */

#ifndef INTERRUPT_PA0_H_
#define INTERRUPT_PA0_H_
//--------------------------------------------------------
// clock phải được cấu hình 8Mhz, thông qua config_clock()
//--------------------------------------------------------
#include <stm32f1xx.h>
void init_interrupt_PA0();
void EXTI0_IRQHandler();
#endif /* INTERRUPT_PA0_H_ */
