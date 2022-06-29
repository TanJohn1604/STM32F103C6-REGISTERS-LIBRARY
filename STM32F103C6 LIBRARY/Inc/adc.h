/*
 * adc.h
 *
 *  Created on: 29 thg 6, 2022
 *      Author: ad
 */

#ifndef ADC_H_
#define ADC_H_

#include "gpio.h"
#include "stm32f1xx.h"
#include "system_clock.h"

#define adc1          1
#define adc2          2

char adc_init(char adc, short port, short pin);
char adc_check(char adc, short port, short pin);
int adc_rx(char adc, short port, short pin);

#endif /* ADC_H_ */
