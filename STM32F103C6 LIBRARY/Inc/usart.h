/*
 * init_usart.h
 *
 *  Created on: 12 thg 6, 2022
 *      Author: ad
 */

#ifndef USART_H_
#define USART_H_
#include "stm32f1xx.h"
//--------------------------------------------------------
// clock phải được cấu hình 8Mhz, thông qua config_clock()
//--------------------------------------------------------
void init_usart(uint8_t usartx,uint16_t baudrate);
uint32_t usartdiv_baudrate(uint32_t baudrate);
void usart_send_char(uint8_t usart_x,uint8_t a);
uint8_t usart_get_char(uint8_t usart_x);
void usart_send_string(uint8_t usart_x,uint8_t *string);
#endif /* USART_H_ */
