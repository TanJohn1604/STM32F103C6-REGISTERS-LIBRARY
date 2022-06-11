/*
 * systick_delay.h
 *
 *  Created on: Jun 11, 2022
 *      Author: ad
 */

#ifndef SYSTICK_DELAY_H_
#define SYSTICK_DELAY_H_
#include "stm32f1xx.h"
//CLOCK AHB BẮT BUỘC PHẢI LÀ 8MHZ
void init_systick_delay();
void delayus();
void delayms();


#endif /* SYSTICK_DELAY_H_ */
