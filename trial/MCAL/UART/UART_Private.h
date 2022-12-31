/*
 * UART_Private.h
 *
 * Created: 11/26/2022 5:42:24 PM
 *  Author: User
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_


#include "UART_Configuration.h"


void UART_Initialize(UART_Mode mode, UART_Parity parity, UART_StopBits stop, UART_DataMode data);
void UART_Transmit(uint8_t dataTransmit);
uint8_t UART_Received(void);

void UART_SENDSTRING(const char* data);
Uint8_t UART_RECEIVESTRING(Uint8_t * data );

void uart_ini(void);
void uart_sendchar(uint8_t * data);
void UART_SENDSTRING(const char* data);
Uint8_t UART_RECEIVESTRING(Uint8_t * data );
unsigned char uart_recieve (void);






#endif /* UART_PRIVATE_H_ */