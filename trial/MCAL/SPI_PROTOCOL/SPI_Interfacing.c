/*
* SPI_Interfacing.c
*
* Created: 10/23/2022 12:26:08 AM
*  Author: User
*/
#include "SPI_Private.h"

void SPI_MASTER_Initialize(SPI_SCK_FRQ prescalar)
{
	// as master u determine every thing so SS , MOSI , SCK must be output and MISO must be input
	/*ALL OUTPUTS*/
	DIO_SETPIN_DIRECTION(SS_PRT,SS,DIO_OUTPUT);
	DIO_SETPIN_DIRECTION(MOSI_PRT,MOSI,DIO_OUTPUT);
	DIO_SETPIN_DIRECTION(SCK_PRT,SCK,DIO_OUTPUT);
	/*ALL OUTPUTS*/
	/*ALL INPUTS*/
	DIO_SETPIN_DIRECTION(MISO_PRT,MISO,DIO_INPUT);   // 0 1 0 1 0 0 1 1
	/*ALL INPUTS*/
	CLR_BIT(SPCR,SPIE); // clear this bit to disable spi interrupt
	SET_BIT(SPCR,SPE); // set spi enable
	CLR_BIT(SPCR,DORD); // clear this bit to send data from most to least
	SET_BIT(SPCR,MSTR); //  Set this bit to make this mcu a master noice!!!!! the ss pin must be ouput
	CLR_BIT(SPCR,CPOL); // clear this bit to make the polarity of the clock is rising edge
	CLR_BIT(SPCR,CPHA); // clear this bit to make clock phase is sample

	switch(prescalar)
	{
		case SPI_2:
		SET_BIT(SPSR,SPI2X);   CLR_BIT(SPCR,SPR1);   CLR_BIT(SPCR,SPR0);
		break;
		
		case SPI_4:
		CLR_BIT(SPSR,SPI2X);   CLR_BIT(SPCR,SPR1);   CLR_BIT(SPCR,SPR0);

		break;
		
		case SPI_8:
		SET_BIT(SPSR,SPI2X);   CLR_BIT(SPCR,SPR1);   SET_BIT(SPCR,SPR0);

		break;
		
		case SPI_16:
		CLR_BIT(SPSR,SPI2X);   CLR_BIT(SPCR,SPR1);   SET_BIT(SPCR,SPR0);

		break;
		
		case SPI_32:
		SET_BIT(SPSR,SPI2X);   SET_BIT(SPCR,SPR1);   CLR_BIT(SPCR,SPR0);

		break;
		
		case SPI_64:
		CLR_BIT(SPSR,SPI2X);   SET_BIT(SPCR,SPR1);   CLR_BIT(SPCR,SPR0);

		break;
		
		case SPI_64_:
		SET_BIT(SPSR,SPI2X);   SET_BIT(SPCR,SPR1);   SET_BIT(SPCR,SPR0);

		break;
		
		case SPI_128:
		CLR_BIT(SPSR,SPI2X);   SET_BIT(SPCR,SPR1);   SET_BIT(SPCR,SPR0);

		break;
	}
	
	

}
void SPI_SLAVE_Initialize(void)
{
	// as Slave u take every thing so SS , MOSI , SCK must be input and MISO must be ouput
	/*ALL OUTPUTS*/
	DIO_SETPIN_DIRECTION(SS_PRT,SS,DIO_INPUT);
	DIO_SETPIN_DIRECTION(MOSI_PRT,MOSI,DIO_INPUT);
	DIO_SETPIN_DIRECTION(SCK_PRT,SCK,DIO_INPUT);
	/*ALL OUTPUTS*/
	/*ALL INPUTS*/
	DIO_SETPIN_DIRECTION(MISO_PRT,MISO,DIO_OUTPUT);   // 0 1 0 0 0 0 1 1
	/*ALL INPUTS*/
	CLR_BIT(SPCR,SPIE); // clear this bit to disable spi interrupt
	SET_BIT(SPCR,SPE); // set spi enable
	CLR_BIT(SPCR,DORD); // clear this bit to send data from most to least
	CLR_BIT(SPCR,MSTR); //  Set this bit to make this mcu a master noice!!!!! the ss pin must be ouput
	CLR_BIT(SPCR,CPOL); // clear this bit to make the polarity of the clock is rising edge
	CLR_BIT(SPCR,CPHA); // clear this bit to make clock phase is sample


	// We can define it in one line

	SPCR=0b01000000;

	// the last 2 bits have no effect on slave mode
	
	
	
	
}

uint8_t SPI_Receive(void)
{
	while(GET_BIT(SPDR,SPIF)!=1); // wait till the handshake flag is raised to complete the Receive

	return SPDR; // returning the data to the data register
	// notice that the SPDR is used for both send and receive
}
/*void SPI_SlaveSelect(SPI_SLAVE slave)
{

}*/
uint8_t SPI_Transive(uint8_t data)
{
	
	SPDR = data ; // this part sends the data
	while(GET_BIT(SPDR,SPIF)!=1);// wait till the handshake flag is raised to complete the Transive
	return SPDR; // this part recieves data
	
	
}

void SPI_Transmit(uint8_t data)
{
	SPDR = data ;                  // we put the data we want to transmit in the data register
	while(GET_BIT(SPDR,SPIF)!=1);  // wait till the handshake flag is raised to complete the transmit
}

void SPI_SlaveSelect(uint8_t slave)
{
	//Six Lines
	switch (slave)
	{
		case SPI_SLAVE0:
		PORTB |= 0x1F;
		PORTB &=~(1<<SS);
		break;
		case SPI_SLAVE1:
		PORTB |= 0x1F;
		PORTB &=~(1<<SS);
		break;
		case SPI_SLAVE2:
		PORTB |= 0x1F;
		PORTB &=~(1<<SS);
		break;
		case SPI_SLAVE3:
		PORTB |= 0x1F;
		PORTB &=~(1<<SS);
		break;
		case SPI_SLAVE4:
		PORTB |= 0x1F;
		PORTB &=~(1<<SS);
		break;
	}
}
