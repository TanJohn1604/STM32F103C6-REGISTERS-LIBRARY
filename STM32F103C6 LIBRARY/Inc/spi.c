/*
 * spi.c
 *
 *  Created on: 29 thg 6, 2022
 *      Author: ad
 */


/*
Actual setup
SPI - 1
-->
PA4 --> SS
PA5 --> SCLK
PA6 --> MISO
PA7 --> MOSI


SP2 - 2
PB12 --> SS
PB13 --> SCLK
PB14 --> MISO
PB15 --> MOSI
*/


#include "stm32f1xx.h"
#include "gpio.h"
#include "spi.h"

void spi_init(unsigned short spi){
RCC->APB2ENR |= 1; // Bật cờ AFIO

if(spi ==1)
{

	RCC->APB2ENR |= 0x1000; //Bật clock spi 1
	// Cấu hình 4 chân của spi1
	init_GP(PA,4,OUT50,O_GP_PP);
	init_GP(PA,5,OUT50,O_AF_PP);
	init_GP(PA,6,IN,I_PP);
	init_GP(PA,7,OUT50,O_AF_PP);

	//cài đặt cấu hình
	SPI1->CR1 |= 0x4; // Master Mode
	SPI1->CR1 |= 0x00; // fclk / 2
	SPI1->CR2 |= 0x4;
	SPI1->CR1 |= 0x40; // Bật spi1
	W_GP(PA,4,HIGH);
}
//else if(spi == 2){
//	RCC->APB1ENR |= 0x4000; //Bật clock spi 2
//	// Cấu hình 4 chân của spi2
//	init_GP(PB,12,OUT50,O_GP_PP);
//	init_GP(PB,13,OUT50,O_AF_PP);
//	init_GP(PB,14,IN,I_PP);
//	init_GP(PB,15,OUT50,O_AF_PP);
//
//	//cài đặt cấu hình
//	SPI2->CR1 |= 0x4; // Master Mode
//	SPI2->CR1 |= 0x00; // fclk / 2
//	SPI2->CR2 |= 0x4;
//	SPI2->CR1 |= 0x40; // Bật spi2
//	W_GP(PB,12,HIGH);
//}



}


void spi_tx(unsigned short spi, char tx_char)
{
	if (spi ==1 )
	{
		W_GP(PA,4,LOW);

		SPI1->DR = tx_char;
		while(SPI1->SR & SPI_SR_BSY){}
		W_GP(PA,4,HIGH);
	}
//	else if (spi ==2 )
//	{
//		W_GP(PB,12,LOW);
//		SPI2->DR = tx_char;
//		while(SPI2->SR & 0x80){}
//		W_GP(PB,12,HIGH);
//	}
}

char spi_rx(unsigned short spi)
{char temp;
	if (spi ==1 )
	{



		W_GP(PA,4,LOW);


		while(SPI1->SR & 0x80){}
		SPI1->DR=0;
		while(!(SPI1->SR & 0x1));
		temp = SPI1->DR;

		W_GP(PA,4,HIGH);
	}
//	else if (spi ==2 )
//	{
//		W_GP(PB,12,LOW);
//		SPI2->DR = tx_char;
//		while(SPI2->SR & 0x80){}
//		W_GP(PB,12,HIGH);
//	}
	return (char)temp;
}

void spi_1tx_1rx(unsigned short spi){
	static char temptx;
	static char temprx;


		if (spi ==1 )
		{
			W_GP(PA,4,LOW);


			while(SPI1->SR & 0x80){}
			SPI1->DR=temptx;
			while(!(SPI1->SR & 0x1));
			temprx = SPI1->DR;

			temptx=temprx;

			W_GP(PA,4,HIGH);
		}
}

void spi_msg(unsigned short spi, char str[])
{
int i =0;
	if (spi==1)
	{
	W_GP(PA,4,LOW);
	while(str[i])
	{
		SPI1->DR = str[i];
		while(SPI1->SR & SPI_SR_BSY){}
		i++;
	}
	W_GP(PA,4,HIGH);
	}
//	else if (spi==2)
//	{
//	W_GP(PB,12,LOW);
//	while(str[i])
//	{
//		SPI2->DR = str[i];
//		while(SPI2->SR & 0x80){}
//		i++;
//	}
//	W_GP(PB,12,HIGH);
//	}
}
