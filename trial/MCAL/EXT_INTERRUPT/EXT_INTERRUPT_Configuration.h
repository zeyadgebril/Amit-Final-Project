/*
* EXT_INTERRUPT_Configuration.h
*
* Created: 9/24/2022 12:00:38 PM
*  Author: User
*/


#ifndef EXT_INTERRUPT_CONFIGURATION_H_
#define EXT_INTERRUPT_CONFIGURATION_H_

#include "configuration.h"


typedef enum
{
	LOW=0,
	HIGH=1,
	FAILING=2,
	RISING=3
}EXT_INT_SENSE;
typedef enum
{
	EXT_INT0=0,
	EXT_INT1=1,
	EXT_INT2=2
}EXT_INT;



#endif /* EXT_INTERRUPT_CONFIGURATION_H_ */