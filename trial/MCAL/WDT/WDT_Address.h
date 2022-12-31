/*
 * WDT_Address.h
 *
 * Created: 11/26/2022 6:10:07 PM
 *  Author: User
 */ 


#ifndef WDT_ADDRESS_H_
#define WDT_ADDRESS_H_


#define WDTCR  (*(volatile uint8_t*)(0x41))
#define MCUCSR (*(volatile uint8_t*)(0x54))


#endif /* WDT_ADDRESS_H_ */