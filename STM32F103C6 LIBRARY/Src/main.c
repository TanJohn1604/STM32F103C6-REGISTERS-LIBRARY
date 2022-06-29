/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */


#include <stdint.h>
#include "gpio.h"
#include "system_clock.h"
//#include"interrupt_PA0.h"
//#include "systick_delay.h"
//#include "systick_interrupt.h"
//#include "usart.h"
//#include "usart_rx_interrupt.h"
//#include "i2c.h"
#include "lcd_1602_mode8_4.h"
//#include "spi.h"
#include"adc.h"
#include "string_func.h"

//int interrupt_PA0 =0;

//uint16_t usart1_manager[]={0,0,0,'z',5000,0,1};
//uint16_t usart2_manager[]={0,0,0,'z',5000,0,2};
//
//uint8_t usart1_data[255]="";
//uint8_t usart2_data[255]="";
char chuoi[20]="";
int a;
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
//	init_usart(1, 9600);
//	init_usart_rx_interrupt(1);
//	lcd_init();
	lcd_init_4();
//	i2c_init(1, i2c_SM);
//	spi_init(1);
	adc_init(1, PA, 0);



	while(1){
		delay_ms(500);
		if(adc_check(adc1, PA, 0))
		{
			a=adc_rx(1, PA, 0);
			int2char(a, chuoi);
			lcd_cmd_4(0x01);
			delay_ms(5);
			lcd_msg_4(1, 0, chuoi);
		}
	}
}



