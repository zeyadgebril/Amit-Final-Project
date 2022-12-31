/*
 * TIMER_Address.h
 *
 * Created: 11/26/2022 5:10:42 PM
 *  Author: User
 */ 


#ifndef TIMER_ADDRESS_H_
#define TIMER_ADDRESS_H_


#define OCR0  (*(volatile uint8_t*)(0x5C))
#define TIMSK (*(volatile uint8_t*)(0x59))
#define TIFR  (*(volatile uint8_t*)(0x58))
#define TCCR0 (*(volatile uint8_t*)(0x53))
#define TCNT0 (*(volatile uint8_t*)(0x52))


#endif /* TIMER_ADDRESS_H_ */