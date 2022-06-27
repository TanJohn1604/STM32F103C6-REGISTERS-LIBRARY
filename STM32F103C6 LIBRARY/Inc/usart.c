/*
 * usart.c
 *
 *  Created on: 12 thg 6, 2022
 *      Author: ad
 */

#include "usart.h"
#include "gpio.h"

void init_usart(uint8_t usart_x,uint16_t baudrate){
/*--------------------------------------------------------
*usart : 8 bit data, 1 stop bit, none parity
*chỉ bật 1 usart trong 1 chương trình, nếu muốn bật nhiêu thì phải sữa lại hàm gửi và đọc data
*clock phải được cấu hình 8Mhz, thông qua config_clock()
*--------------------------------------------------------
* USART2 -> PA2 (Tx) and PA3(Rx)
* USART1 -> PA9 (Tx) and PA10(Rx)
*/
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

void usart_send_char(uint8_t usart_x,uint8_t a){
	if((RCC->APB2ENR & RCC_APB2ENR_USART1EN) && usart_x==1){
		while( !(USART1->SR & USART_SR_TC ));
			USART1->DR=a;
	}
	else if((RCC->APB1ENR & RCC_APB1ENR_USART2EN) && usart_x==2){
		while( !(USART2->SR & USART_SR_TC ));
			USART2->DR=a;
	}

}

uint8_t usart_get_char(uint8_t usart_x){
	uint8_t a;
	if((RCC->APB2ENR & RCC_APB2ENR_USART1EN) && (usart_x==1)){
			while( !(USART1->SR & USART_SR_RXNE ));
			a=USART1->DR;
		}
	else if((RCC->APB1ENR & RCC_APB1ENR_USART2EN) && (usart_x==2)){
			while( !(USART2->SR & USART_SR_RXNE ));
			a=USART2->DR;
		}
	return a;
}

void usart_send_string(uint8_t usart_x,uint8_t *string){


	while(*string){
		usart_send_char(usart_x,*string++);

	}

}


/*
 *
#include <stdint.h>
#include "gpio.h"
#include "system_clock.h"
//#include"interrupt_PA0.h"
//#include "systick_delay.h"
//#include "systick_interrupt.h"
#include "usart.h"
#include "usart_rx_interrupt.h"

//int interrupt_PA0 =0;

uint16_t usart1_manager[]={0,0,0,'z',5000,0,1};
uint16_t usart2_manager[]={0,0,0,'z',5000,0,2};

uint8_t usart1_data[255]="";
uint8_t usart2_data[255]="";

int main(void)
{
	//cấu hình clock ngoại 8Mhz, bộ chia của các bus cấu hình bằng 1
	//bắt buộc phải config_clock();
	//---------------------------------------xxx-------------------------------------------------------
	config_clock();
	//---------------------------------------xxx-------------------------------------------------------
	init_GP(PC,13,OUT50,O_GP_PP);
	W_GP(PC, 13,HIGH);
//	init_GP(PA,0,IN,I_PP);
//	init_interrupt_PA0();
//	init_systick_delay();
//	init_systick_interrupt(1000);
	init_usart(1, 9600);
	init_usart_rx_interrupt(1);

	init_usart(2, 9600);
	init_usart_rx_interrupt(2);



	while(1){

		if(usart1_manager[1]==1){
			usart_send_string(2, usart1_data);
			usart1_manager[1]=0;
		}
		if(usart2_manager[1]==1){
			usart_send_string(1, usart2_data);
			usart2_manager[1]=0;
		}



	}
}


void USART1_IRQHandler(){
	 usart_get_string_isr(usart1_manager,usart1_data);
}
void USART2_IRQHandler(){
	 usart_get_string_isr(usart2_manager,usart2_data);
}
//void SysTick_Handler(){
//	systick_interrupt_time_usart(usart_manager);
//}
 *
 */
