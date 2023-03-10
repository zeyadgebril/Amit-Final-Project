/*
 * MOTOR_Configuration.h
 *
 * Created: 11/26/2022 4:00:56 PM
 *  Author: User
 */ 


#ifndef MOTOR_CONFIGURATION_H_
#define MOTOR_CONFIGURATION_H_

#include "configuration.h"

#define H_BRIDGE_ENABLE_PRT   DIO_PORTC
#define H_BRIDGE_ENABLE1      DIO_PIN1
#define H_BRIDGE_ENABLE2      DIO_PIN0

#define H_BRIDGE_A_PRT        DIO_PORTD
#define H_BRIDGE_A1		      DIO_PIN7
#define H_BRIDGE_A2		      DIO_PIN4
#define H_BRIDGE_A3		      DIO_PIN5
#define H_BRIDGE_A4           DIO_PIN6
#define H_BRIDGE_STATE        DIO_OUTPUT

#define H_BRIDGE_HIGH  DIO_HIGH
#define H_BRIDGE_LOW   DIO_LOW

typedef enum{
	clockwise,
	anticlockwise
}motor_direction;

typedef enum{
	enable1,
	enable2
}motor_enable;





#endif /* MOTOR_CONFIGURATION_H_ */