/*
 * systick_interrupt.c
 *
 *  Created on: 11 thg 6, 2022
 *      Author: ad
 */
#include "systick_interrupt.h"
#include "gpio.h"

void init_systick_interrupt(uint32_t time_ms){
	//CLOCK AHB BẮT BUỘC PHẢI LÀ 8MHZ
	//reset thanh ghi
	SysTick->CTRL = 0;
	//cai dat gia tri đích cho bộ đếm có 3byte tối đa
	SysTick->LOAD= time_ms*8000;
	//cài đặt giá trị cho thanh ghi đếm
	SysTick->VAL=0;
	//lấy clock từ AHB
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
	//BẬT NGẮT SYSTICK
	SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
	//BẬT THANH GHI
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;

}

void SysTick_Handler(){
	toggle_GP(PC, 13);
}
