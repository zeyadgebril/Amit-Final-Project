/*
 * TWI_Address.h
 *
 * Created: 11/26/2022 6:05:28 PM
 *  Author: User
 */ 


#ifndef TWI_ADDRESS_H_
#define TWI_ADDRESS_H_



#define TWAR (*(volatile uint8_t*)(0x22))
#define TWBR (*(volatile uint8_t*)(0x20))
#define TWCR (*(volatile uint8_t*)(0x))
#define TWDR (*(volatile uint8_t*)(0x23))
#define TWSR (*(volatile uint8_t*)(0x21))

#endif /* TWI_ADDRESS_H_ */