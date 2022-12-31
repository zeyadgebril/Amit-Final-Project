/*
 * UART_Interface.c
 *
 * Created: 11/26/2022 5:42:37 PM
 *  Author: User
 */ 
#include "UART_Private.h"

/*
	switch (mode)
	{
		case Asynchronous:
		break;
		case Synchronous:
		break;
	}
	switch (parity)
	{
		case Disable:
		CLR_BIT(UCSRC, UPM1);CLR_BIT(UCSRC, UPM0);
		break;
		case Even:
		SET_BIT(UCSRC, UPM1);CLR_BIT(UCSRC, UPM0);
		break;
		case Odd:
		SET_BIT(UCSRC, UPM1);SET_BIT(UCSRC, UPM0);
		break;
	}
	switch (stop)
	{
		case Bit_1:
		break;
		case Bit_2:
		break;
	}
	switch (data)
	{
		case Bits_5:
		break;
		case Bits_6:
		break;
		case Bits_7:
		break;
		case Bits_8:
		break;
		case Bits_9:
		break;
	}
*/

void UART_Initialize(UART_Mode mode, UART_Parity parity, UART_StopBits stop, UART_DataMode data)
{
	uint16_t UBRR_Val = 0;	
	DDRD &=~(1<<PD0);//CLR_BIT(DDRD, PD0);//Define direction for RX pin as input	
	DDRD |= (1<<PD1);//SET_BIT(DDRD, PD1);//Define direction for TX pin as output DDRD |= 0x02;//0000 0010	
	UCSRB |= (1<<RXEN) | (1<<TXEN);//Enable receive, transmit //USCRB = 0x18;
	UCSRC |= (1<<URSEL) | (1 << UCSZ1) | (1 << UCSZ0);//Enable UCSRC, Choose 8 bit mode //UCSRC = 0x86;
	UBRR_Val = ((8000000) / (16 * BaudRate)) - 1;//Calculate Baud Rate register value
	UBRRL = UBRR_Val;
	UBRRH = UBRR_Val >> 8;
	
	/*UCSRA &=~(1<<1);
	UCSRB |=(3<<3);
	UCSRC&= ~ (3<<4);
	UCSRC&= ~(1<<3);
	UCSRC&=~(1<<6);
	UCSRC|=(1<<7);
	uint16_t UBRR_Val = 0;
	UBRR_Val = (uint16_t)(1000000/(2 * 8 * 9600ul)-1);
	UBRRL  &=~(1<<15);
	
	UBRRL = (uint8_t)UBRR_Val;
	UBRRH =(UBRR_Val >> 8);*/
	
	
	
}
void UART_Transmit(uint8_t dataTransmit)
{
	UDR = dataTransmit;
	while(GET_BIT(UCSRA, TXC) != 1);
}
uint8_t UART_Received(void)
{
	uint8_t dataReceived = 0;
	while(GET_BIT(UCSRA, RXC) != 1);
	dataReceived = UDR;
	return dataReceived;
}



void UART_SENDSTRING(const char* data)
{
	while(*data !='\0')
	{
		
	
	while(!((UCSRA>>UDRE)&1));
	UDR = *data;
	data++;
	}
}
Uint8_t UART_RECEIVESTRING(Uint8_t * sent_data )
{
	uint8_t data , index ,terminate ;
	
	while(!((UCSRA>>RXC)&1));
	terminate = UDR;
	
	while(1)
	{
		while(!((UCSRA>>RXC)&1));
		data = UDR ;
		
		if (data = terminate)
		{
			sent_data[index] = '\0';
			break;
		}
		
		sent_data[index]=data;
		index++;
	}
	return data ; 
}


void uart_ini(void)
{
	UCSRA&=~(1<<1);
	UCSRB|=(3<<3);
	UCSRC&=~ (3<<4);
	UCSRC&=~(1<<3);
	UCSRC&=~(1<<6);
	UCSRC|=(1<<7);
	uint16_t UBRR_Val = 0;
	UBRR_Val=(uint16_t)(8000000/(2 * 8 * 9600)-1);
	UBRRL  &=~(1<<15);
	
	UBRRL = (uint8_t)UBRR_Val;
	UBRRH =(UBRR_Val >> 8);	
}

void uart_sendchar(uint8_t * data)
{
	while(!((UCSRA>>UDRE)&1));
	UDR = data;
}


unsigned char uart_recieve (void)
{
	while(!(UCSRA) & (1<<RXC));           // wait while data is being received
	return UDR;                             // return 8-bit data
}