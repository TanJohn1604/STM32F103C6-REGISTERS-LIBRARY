/*
 * systick_deay.c
 *
 *  Created on: Jun 11, 2022
 *      Author: ad
 */


#include "systick_delay.h"

void init_systick_delay(){
//CLOCK AHB BẮT BUỘC PHẢI LÀ 8MHZ
//reset thanh ghi
SysTick->CTRL =0;
////cai dat gia tri đích cho bộ đếm có 3byte tối đa
SysTick->LOAD=0x00FFFFFF;
//cài đặt giá trị cho thanh ghi đếm
SysTick->VAL=0;
//bật thanh ghi và lấy clock từ AHB
SysTick->CTRL=5;
}

void delayus(){
	SysTick->LOAD=8000-1;
	SysTick->VAL=0;
	while( ((SysTick->CTRL) & SysTick_CTRL_COUNTFLAG_Msk)==0 );
}

void delayms(uint32_t ms){
	for(;ms>0;ms--){
		delayus();
	}
}
