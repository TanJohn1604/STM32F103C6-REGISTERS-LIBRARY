/*
 * i2c.h
 *
 *  Created on: 28 thg 6, 2022
 *      Author: ad
 */

#ifndef I2C_H_
#define I2C_H_


#include "stm32f1xx.h"
#include "gpio.h"


#define i2c_FM 0x2d
#define i2c_SM 0xB4


void i2c_init(char i2c,unsigned short speed_mode);
void i2c_write(char i2c, char address,char data[]);

#endif /* I2C_H_ */
