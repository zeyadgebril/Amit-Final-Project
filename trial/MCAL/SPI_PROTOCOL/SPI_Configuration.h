/*
* SPI_Configuration.h
*
* Created: 10/23/2022 12:25:47 AM
*  Author: User
*/


#ifndef SPI_CONFIGURATION_H_
#define SPI_CONFIGURATION_H_

#include "configuration.h"
typedef enum
{
	SPI_2=0,
	SPI_4=1,
	SPI_8=2,
	SPI_16=3,
	SPI_32=4,
	SPI_64=5,
	SPI_64_=6,
	SPI_128=7
}SPI_SCK_FRQ;

#define MOSI_PRT DIO_PORTB
#define MOSI DIO_PIN5
#define MISO_PRT DIO_PORTB
#define MISO DIO_PIN6
#define SS_PRT DIO_PORTB
#define SS DIO_PIN4
#define SCK_PRT DIO_PORTB
#define SCK DIO_PIN7

typedef enum
{
	SPI_SLAVE0=0,
	SPI_SLAVE1=1,
	SPI_SLAVE2=2,
	SPI_SLAVE3=3,
	SPI_SLAVE4=4,
	SPI_SLAVE5=5,
	SPI_SLAVE6=6
}SPI_SLAVE;


#endif /* SPI_CONFIGURATION_H_ */