/*
 * usart_rx_interrupt.h
 *
 *  Created on: 13 thg 6, 2022
 *      Author: ad
 */

#ifndef USART_RX_INTERRUPT_H_
#define USART_RX_INTERRUPT_H_
#include"stm32f1xx.h"
#include "usart.h"

void init_usart_rx_interrupt(uint8_t usart_x);
void usart_get_string_isr(uint8_t * signal, uint8_t * counter, uint8_t str[],uint8_t detect_char);

#endif /* USART_RX_INTERRUPT_H_ */