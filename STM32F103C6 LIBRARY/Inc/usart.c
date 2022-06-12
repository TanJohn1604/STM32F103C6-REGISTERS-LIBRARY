/*
 * usart.c
 *
 *  Created on: 12 thg 6, 2022
 *      Author: ad
 */

#include "usart.h"
#include "gpio.h"

void init_usart(uint8_t usart_x,uint16_t baudrate){
//--------------------------------------------------------
// usart : 8 bit data, 1 stop bit, none parity
// clock phải được cấu hình 8Mhz, thông qua config_clock()
//--------------------------------------------------------
// USART2 -> PA2 (Tx) and PA3(Rx)
// USART1 -> PA9 (Tx) and PA10(Rx)

	// bật afio để cho phép chức năng thay thế trên pin
	RCC->APB2ENR |= 1;

	unsigned long BRR_Cal;
	BRR_Cal = usartdiv_baudrate(baudrate);

	if(usart_x == 1)
	{
	//cấp clock cho usart
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	init_GP(PA,9,OUT50,O_AF_PP);
	init_GP(PA,10,IN,I_PP);
	// cài đặt baudrate cho thanh ghi
	USART1->BRR = BRR_Cal;
	// bật chân transmit
	USART1->CR1 |= USART_CR1_TE;
	// bật chân recive
	USART1->CR1 |= USART_CR1_RE;
	// bật Uart
	USART1->CR1 |= USART_CR1_UE;
	}
	else if (usart_x == 2)
	{		//-----------Init UART ------------///
	//cấp clock cho usart
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	init_GP(PA,2,OUT50,O_AF_PP);
	init_GP(PA,3,IN,I_PP);
	// cài đặt baudrate cho thanh ghi
	USART2->BRR = BRR_Cal;
	// bật chân transmit
	USART2->CR1 |= USART_CR1_TE;
	// bật chân recive
	USART2->CR1 |= USART_CR1_RE;
	// bật Uart
	USART2->CR1 |= USART_CR1_UE;
	}

}

uint32_t usartdiv_baudrate(uint32_t baudrate){

unsigned long div = 8000000UL;
unsigned long dec;
unsigned long final;
double frac = 8000000.00;
double frac2 = 1.00;
div = div / (baudrate*16);
frac = 16*((frac / (baudrate*16))-div);
dec = frac;
frac2 = 100*(frac-dec);
if(frac2>50)
{
	dec ++;
	if(dec == 16)
	{
		dec = 0;
		div ++;
	}
}
final = (div<<4);
final += dec;
return final;
}

void usart_send_char(uint8_t a){
	if(RCC->APB2ENR & RCC_APB2ENR_USART1EN){
		while( !(USART1->SR & USART_SR_TC ));
			USART1->DR=a;
	}
	else{
		while( !(USART2->SR & USART_SR_TC ));
			USART2->DR=a;
	}
}

uint8_t usart_get_char(){
	uint8_t a;
	if(RCC->APB2ENR & RCC_APB2ENR_USART1EN){
			while( !(USART1->SR & USART_SR_RXNE ));
			a=USART1->DR;
		}
		else{
			while( !(USART2->SR & USART_SR_RXNE ));
			a=USART2->DR;
		}
	return a;
}

void usart_send_string(uint8_t *string){


	while(*string){
		usart_send_char(*string++);

	}

}