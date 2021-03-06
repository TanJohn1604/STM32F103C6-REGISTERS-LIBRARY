/*
 * gpio.h
 *
 *  Created on: Jun 11, 2022
 *      Author: ad
 */

#ifndef GPIO_H_
#define GPIO_H_

#define RCC_APB2ENR     (*((volatile unsigned long *) 0x40021018))

#define GPIO_A          (*((volatile unsigned long *) 0x40010800))
#define GPIO_B          (*((volatile unsigned long *) 0x40010C00))
#define GPIO_C          (*((volatile unsigned long *) 0x40011000))

/// Danh sách port
#define PA 1
#define PB 2
#define PC 3

/// mode
#define IN 0
#define OUT10 1
#define OUT2  2
#define OUT50 3
/// cấu hình input
#define I_AN 0
#define I_F  1
#define I_PP 2

/// cấu hình output
#define O_GP_PP 0
#define O_GP_OD 1
#define O_AF_PP 2
#define O_AF_OD 3

///trạng thái pin
#define LOW  0
#define HIGH 1



void init_GP(unsigned short port, unsigned short pin, unsigned short dir, unsigned short opt);

int R_GP(unsigned short port, unsigned short pin);

void W_GP(unsigned short port, unsigned short pin, unsigned short state);

void toggle_GP(unsigned short port, unsigned short pin);

void Digital_Input(unsigned short PORT,unsigned short PIN);
void Digital_Output(unsigned short PORT,unsigned short PIN);
#endif /* GPIO_H_ */
