/*
 * gpio.c
 *
 *  Created on: Jun 11, 2022
 *      Author: ad
 */
#include "gpio.h"

void init_GP(unsigned short port, unsigned short pin, unsigned short dir, unsigned short opt)
{
	//examble  =  init_GP(PA,0,OUT50,O_GP_PP);
 volatile unsigned long * CR;
 unsigned short tPIN = pin;
 unsigned short offset = 0x00;

	if(pin > 7)
		{
			tPIN -= 8;
			offset = 0x01;
		}

	if(port == 1)
		{
			RCC_APB2ENR |= 4; // Bật clock cho port A
			CR = (volatile unsigned long *) (&GPIO_A + offset);
		}
	else if(port == 2)
		{
			RCC_APB2ENR |= 8; // Bật clock cho port B
			CR = (volatile unsigned long *) (&GPIO_B + offset);
		}
	else if(port == 3)
		{
			RCC_APB2ENR |= 0x10; // Bật clock cho port C
			CR = (volatile unsigned long *) (&GPIO_C + offset);
		}

		*CR &= ~(0xf<<(tPIN)*4); //Reset cấu hình của pin
		*CR |= ((dir <<(tPIN*4)) | (opt<<(tPIN*4+2))); //cấu hình pin
}

int R_GP(unsigned short port, unsigned short pin)
{
	volatile unsigned long * IDR;
	unsigned long offset = 0x02;
	int state;

	if(port == 1)
		{
			IDR = (volatile unsigned long *) (&GPIO_A + offset);
		}
	else if(port == 2)
		{
			IDR = (volatile unsigned long *) (&GPIO_B + offset);
		}
	else if(port == 3)
	{
		IDR = (volatile unsigned long *) (&GPIO_C + offset);
	}
	state = ((*IDR & (1<<pin))>>pin);
	return state;
}

void W_GP(unsigned short port, unsigned short pin, unsigned short state)
{
		volatile unsigned long * ODR;
		unsigned long offset = 0x03;


	if(port == 1)
		{
			ODR = (volatile unsigned long *) (&GPIO_A + offset);
		}
	else if(port == 2)
		{
			ODR = (volatile unsigned long *) (&GPIO_B + offset);
		}
	else if(port == 3)
	{
		ODR = (volatile unsigned long *) (&GPIO_C + offset);
	}
	state ? (*ODR |= (state<<pin)) : (*ODR &= ~(1<<pin));
}

void toggle_GP(unsigned short port, unsigned short pin)
{
	if (R_GP(port,pin))
		{
			W_GP(port,pin,0);
		}
	else
		{
			W_GP(port,pin,1);
		}
}


void Digital_Input(unsigned short PORT,unsigned short PIN)
{
	init_GP(PORT, PIN,IN,I_PP);
}

void Digital_Output(unsigned short PORT,unsigned short PIN)
{
	init_GP(PORT, PIN,OUT50,O_GP_PP);
}
