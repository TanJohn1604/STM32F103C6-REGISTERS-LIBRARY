/*
 * spi.h
 *
 *  Created on: 29 thg 6, 2022
 *      Author: ad
 */

#ifndef SPI_H_
#define SPI_H_


void spi_init(unsigned short spi);
void spi_tx(unsigned short spi, char tx_char);
void spi_msg(unsigned short spi, char str[]);


#endif /* SPI_H_ */
