/*
 * lcd_1602.c
 *
 *  Created on: 27 thg 6, 2022
 *      Author: ad
 */

#include "lcd_1602_mode8_4.h"

/*
 *
Pin setup:8
PA8 -> RS
PA9 -> RW
PA10-> E
PA0 -> DB0
PA1 -> DB1
PA2 -> DB2
PA3 -> DB4
PA4 -> DB4
PA5 -> DB5
PA6 -> DB6
PA7 -> DB7
*/

/*
Pin setup : 4
PA8 -> RS
PA9 -> RW
PA10-> E
PA0
PA1
PA2
PA3
PA4 -> DB4
PA5 -> DB5
PA6 -> DB6
PA7 -> DB7
*/

void pin_output(unsigned char start, unsigned char end)
{
char i;
	for(i=start;i<end;i++)
	{
		Digital_Output(PA,i);
	}
}

void lcd_rs(unsigned char LOW_HIGH)
{
	W_GP(PA,8,LOW_HIGH);
}
void lcd_rw(unsigned char LOW_HIGH)
{
	W_GP(PA,9,LOW_HIGH);
}
void lcd_e(unsigned char LOW_HIGH)
{
	W_GP(PA,10,LOW_HIGH);
}

void lcd_data(unsigned char data)
{
	pin_output(0,11);
	lcd_rs(HIGH);
	lcd_rw(LOW);
	delay_us(10);
	lcd_e(HIGH);
	delay_us(5);
	GPIOA->ODR &= 0xff00;
	GPIOA->ODR |= data;
	delay_us(10);
	lcd_e(LOW);
}
void lcd_cmd(unsigned char data)
{
	pin_output(0,11);
	lcd_rs(LOW);
	lcd_rw(LOW);
	delay_us(10);
	lcd_e(HIGH);
	delay_us(5);
	GPIOA->ODR &= 0xff00;
	GPIOA->ODR |= data;
	delay_us(10);
	lcd_e(LOW);
}
void lcd_init(void)
{
	pin_output(0,11);
	delay_ms(20);
	lcd_cmd(0x3C); // 8 bit mode / 2 lines
	delay_ms(5);
	lcd_cmd(0x0C); // Bat hien thi man hinh
	delay_ms(5);
	lcd_cmd(0x01); // Xoa man hinh
	delay_ms(5);
	lcd_cmd(0x02); // Dua con tro ve vi tri ban dau
	delay_ms(5);
}


void lcd_data_4(unsigned char data){
	pin_output(4,11);
	lcd_rs(HIGH);
	lcd_rw(LOW);
	delay_us(10);
	lcd_e(HIGH);
	delay_us(5);
	GPIOA->ODR &= 0xff0f;
	GPIOA->ODR |= (data & 0x00f0);
	delay_us(10);
	lcd_e(LOW);

	delay_us(20);

	lcd_e(HIGH);
	delay_us(5);
	GPIOA->ODR &= 0xff0f;
	GPIOA->ODR |= ((data << 4) & 0x00f0);
	delay_us(10);
	lcd_e(LOW);
}
void lcd_cmd_4(unsigned char data)
{
	pin_output(4,11);
	lcd_rs(LOW);
	lcd_rw(LOW);
	delay_us(10);
	lcd_e(HIGH);
	delay_us(5);
	GPIOA->ODR &= 0xff0f;
	GPIOA->ODR |= (data & 0x00f0);
	delay_us(10);
	lcd_e(LOW);

	delay_us(20);

	lcd_e(HIGH);
	delay_us(5);
	GPIOA->ODR &= 0xff0f;
	GPIOA->ODR |= ((data << 4) & 0x00f0);
	delay_us(10);
	lcd_e(LOW);
//	delay_us(20);
}
void lcd_init_4(void)
{
	pin_output(4,11);
	delay_ms(20);
	lcd_rs(LOW);
	lcd_rw(LOW);
	delay_us(10);
	lcd_e(HIGH);
	delay_us(5);
	GPIOA->ODR &= 0xff0f;
	GPIOA->ODR |= 0x30; // 8 bit mode
	delay_us(10);
	lcd_e(LOW);

	delay_ms(10);

	lcd_rs(LOW);
	lcd_rw(LOW);
	delay_us(10);
	lcd_e(HIGH);
	delay_us(5);
	GPIOA->ODR &= 0xff0f;
	GPIOA->ODR |= 0x30; // 8 bit mode
	delay_us(10);
	lcd_e(LOW);

	delay_ms(1);

	lcd_rs(LOW);
	lcd_rw(LOW);
	delay_us(10);
	lcd_e(HIGH);
	delay_us(5);
	GPIOA->ODR &= 0xff0f;
	GPIOA->ODR |= 0x30;// 8 bit mode
	delay_us(10);
	lcd_e(LOW);

	delay_ms(1);

	lcd_rs(LOW);
	lcd_rw(LOW);
	delay_us(10);
	lcd_e(HIGH);
	delay_us(5);
	GPIOA->ODR &= 0xff0f;
	GPIOA->ODR |= 0x20; // 4 bit mode
	delay_us(10);
	lcd_e(LOW);


	lcd_cmd_4(0x2C); // 4 bit communication mode / 2 lines
	delay_ms(5);
	lcd_cmd_4(0x0C); // Bat man hinh
	delay_ms(5);
	lcd_cmd_4(0x01); // Xoa man hinh
	delay_ms(5);
	lcd_cmd_4(0x02); // Tro ve vi tri ban dau
	delay_ms(5);
}

void lcd_send( char str[])
{
	int i = 0;
		while(str[i])
		{
			lcd_data(str[i]);
			i++;
			delay_us(100);
		}

}
void lcd_msg(unsigned char line_1_2, unsigned char pos_0_16, char msg[])
{
	short pos = 0;
	if(line_1_2==1)
	{
		pos = 0;
	}
	else if(line_1_2==2)
	{
		pos = 0x40;
	}
	lcd_cmd(0x80 +pos + pos_0_16);
	delay_us(100);
	lcd_send(msg);
}


void lcd_send_4( char str[])
{
	int i = 0;
		while(str[i])
		{
			lcd_data_4(str[i]);
			i++;
			delay_us(100);
		}

}
void lcd_msg_4(unsigned char line_1_2, unsigned char pos_0_16, char msg[])
{
	short pos = 0;
	if(line_1_2==1)
	{
		pos = 0;
	}
	else if(line_1_2==2)
	{
		pos = 0x40;
	}
	lcd_cmd_4(0x80 +pos + pos_0_16);
	delay_us(100);
	lcd_send_4(msg);
}
