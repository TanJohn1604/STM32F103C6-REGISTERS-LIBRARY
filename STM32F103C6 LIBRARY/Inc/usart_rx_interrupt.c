/*
 * usart_rx_interrupt.c
 *
 *  Created on: 13 thg 6, 2022
 *      Author: ad
 */
#include"usart_rx_interrupt.h"

void init_usart_rx_interrupt(uint8_t usart_x){
//--------------------------------------------------------
// usart : 8 bit data, 1 stop bit, none parity
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
void usart_get_string_isr(uint8_t * signal, uint8_t * counter, uint8_t str[],uint8_t detect_char)
{
//đặt trong hàm ngắt của usart tương ứng
//ex : void USART1_IRQHandler()

str[*counter] = usart_get_char();
if(str[*counter] == detect_char)
{
	str[*counter]='\0';
	*counter = 0;
	*signal = 1;

}
else
{
	*counter = *counter +1;

}
}

