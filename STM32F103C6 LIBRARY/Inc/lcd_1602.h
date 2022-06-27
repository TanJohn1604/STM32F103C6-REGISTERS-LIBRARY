/*
 * lcd_1602.h
 *
 *  Created on: 27 thg 6, 2022
 *      Author: ad
 */

#ifndef LCD_1602_H_
#define LCD_1602_H_

#include "gpio.h"
#include "system_clock.h"
#include "stm32f1xx.h"

void pin_output(unsigned char start, unsigned char end);
void lcd_rs(unsigned char LOW_HIGH);
void lcd_rw(unsigned char LOW_HIGH);
void lcd_e(unsigned char LOW_HIGH);
void lcd_data(unsigned char data);
void lcd_cmd(unsigned char data);
void lcd_init(void);
void lcd_send( char str[]);
void lcd_msg(unsigned char line_1_2, unsigned char pos_0_16, char msg[]);

#endif /* LCD_1602_H_ */

