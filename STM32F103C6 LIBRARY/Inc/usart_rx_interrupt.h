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
void usart_get_string_isr(uint16_t usart_manager[], uint8_t usart_data[]);

#endif /* USART_RX_INTERRUPT_H_ */
