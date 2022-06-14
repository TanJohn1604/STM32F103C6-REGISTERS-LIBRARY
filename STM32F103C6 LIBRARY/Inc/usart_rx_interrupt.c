/*
 * usart_rx_interrupt.c
 *
 *  Created on: 13 thg 6, 2022
 *      Author: ad
 */
#include"usart_rx_interrupt.h"
#include "systick_interrupt.h"

void init_usart_rx_interrupt(uint8_t usart_x){
//--------------------------------------------------------
// phải cấu hình init_usart trước
// clock phải được cấu hình 8Mhz, thông qua config_clock()
//--------------------------------------------------------
// USART2 -> PA2 (Tx) and PA3(Rx)
// USART1 -> PA9 (Tx) and PA10(Rx)

	if(usart_x == 1)
	{
		__disable_irq();
		USART1->CR1 |= USART_CR1_RXNEIE;
		NVIC_EnableIRQ(USART1_IRQn);
		__enable_irq();
	}
	else if (usart_x == 2)
	{
		__disable_irq();
		USART2->CR1 |= USART_CR1_RXNEIE;
		NVIC_EnableIRQ(USART2_IRQn);
		__enable_irq();
	}

}
/* uint16_t usart_manager[]
 * 0 - count_char
 * 1 - signal
 * 2 - mode ( 1 : systick interrupt time ; 0 : char terminator )
 * 3 - char terminator
 * 4 - time
 * 5 - temp cnt time
 * 6 - get data from usart_x
 */
void usart_get_string_isr(uint16_t usart_manager[], uint8_t usart_data[])
{
//đặt trong hàm ngắt của usart tương ứng
//ex : void USART1_IRQHandler()

usart_data[usart_manager[0]] = usart_get_char((uint8_t)usart_manager[6]);
if(usart_manager[2]==0){
	if(usart_data[usart_manager[0]] == usart_manager[3])
	{
		usart_data[usart_manager[0]]='\0';
		usart_manager[0] = 0;
		usart_manager[1] = 1;

	}
	else
	{
		usart_manager[0]++;

	}
}
else{
	usart_manager[0]++;
	usart_manager[5]=usart_manager[4];

	__disable_irq();
	SysTick->CTRL = 0;
	//cai dat gia tri đích cho bộ đếm có 3byte tối đa
	SysTick->LOAD= 8000-1;
	//cài đặt giá trị cho thanh ghi đếm
	SysTick->VAL=0;
	//lấy clock từ AHB
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
	//BẬT NGẮT SYSTICK
	SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
	//BẬT THANH GHI
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	__enable_irq();
}

}



//void SysTick_Handler(){
//
//}

