/*
 * Button1_interfacing.c
 *
 * Created: 10/7/2022 6:06:25 PM
 *  Author: User
 */ 
#include "Button1_Configuration.h"

void BTN2_Initialization(void)
{
	DIO_SETPIN_DIRECTION(BTN2_PRT,BTN2_PIN,DIO_INPUT);
	// Activate internal pull up 
	DIO_SETPIN_PULLUP(BTN2_PRT,BTN2_PIN);	
}

uint8_t BTN2_Read(void)
{
	uint8_t BTN_VAL = DIO_LOW;
	uint8_t val = 0 ; // the value of ??????
	_delay_ms(10);
	BTN_VAL = DIO_READPIN_VALUE(BTN2_PRT,BTN2_PIN);	
	return BTN_VAL;
}

