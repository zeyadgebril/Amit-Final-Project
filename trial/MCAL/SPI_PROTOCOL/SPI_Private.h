/*
 * SPI_Private.h
 *
 * Created: 10/23/2022 12:25:30 AM
 *  Author: User
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#include "SPI_Configuration.h"

void SPI_MASTER_Initialize(SPI_SCK_FRQ prescalar);
void SPI_SLAVE_Initialize(void);
void SPI_Transmit(uint8_t data);
uint8_t SPI_Receive(void);
void SPI_SlaveSelect(SPI_SLAVE slave);
uint8_t SPI_Transive(uint8_t data);



#endif /* SPI_PRIVATE_H_ */