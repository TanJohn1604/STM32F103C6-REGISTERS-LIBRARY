/*
 * systick_interrupt.c
 *
 *  Created on: 11 thg 6, 2022
 *      Author: ad
 */
#include "systick_interrupt.h"
#include "gpio.h"

void init_systick_interrupt(uint16_t time_ms){
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
/* uint16_t usart_manager[]
 * 0 - count_char
 * 1 - signal
 * 2 - mode ( 1 : systick interrupt time ; 0 : char terminator )
 * 3 - char terminator
 * 4 - time
 * 5 - temp cnt time
 */
void systick_interrupt_time_usart(uint16_t usart_manager[]){
	if(usart_manager[5]==0){
		usart_manager[1]=1;
		usart_manager[0]=0;
		//TẮT NGẮT SYSTICK
		SysTick->CTRL &=~ SysTick_CTRL_TICKINT_Msk;
	}
	else{
		usart_manager[5]--;
	}
}
//hàm ngắt của systick interrupt
//void SysTick_Handler(){
//	toggle_GP(PC, 13);
//}
