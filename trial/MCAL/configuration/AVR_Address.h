/*
* AVR_Address.h
*
* Created: 9/18/2022 1:01:45 PM
*  Author: User
*/


#ifndef AVR_ADDRESS_H_
#define AVR_ADDRESS_H_
/*DIO*/
#define PORTA (*(volatile uint8_t*)(0X3B))
#define DDRA  (*(volatile uint8_t*)(0X3A))
#define PINA  (*(volatile uint8_t*)(0X39))
#define PORTB (*(volatile uint8_t*)(0X38))
#define DDRB  (*(volatile uint8_t*)(0X37))
#define PINB  (*(volatile uint8_t*)(0X36))
#define PORTC (*(volatile uint8_t*)(0X35))
#define DDRC  (*(volatile uint8_t*)(0X34))
#define PINC  (*(volatile uint8_t*)(0X33))
#define PORTD (*(volatile uint8_t*)(0X32))
#define DDRD  (*(volatile uint8_t*)(0X31))
#define PIND  (*(volatile uint8_t*)(0X30))
/*DIO*/

/*INTERRUPT*/
#define SREG  (*(volatile uint8_t*)(0X5F))
#define GICR  (*(volatile uint8_t*)(0X5B))
#define GIFR  (*(volatile uint8_t*)(0X5A))
#define MCUCR  (*(volatile uint8_t*)(0X55))
#define MCUCSR  (*(volatile uint8_t*)(0X54))
/*INTERRUPT*/
/*ADC*/
#define ADMUX  (*(volatile uint8_t*)(0X27))
#define ADCSRA  (*(volatile uint8_t*)(0X26))
#define ADCL  (*(volatile uint8_t*)(0X24))
#define ADCH  (*(volatile uint8_t*)(0X25))
#define SFIOR (*(volatile uint8_t*)(0X50))
#define ADC_DATA (*(volatile uint16_t*)(0x24))
/*ADC*/

/*SPI*/
#define SPDR (*(volatile uint8_t*)(0X2F))
#define SPSR (*(volatile uint8_t*)(0X2E))
#define SPCR (*(volatile uint8_t*)(0X2D))

/*SPI*/


#endif /* AVR_ADDRESS_H_ */