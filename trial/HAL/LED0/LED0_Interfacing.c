/*
 * LED0_Interfacing.c
 *
 * Created: 9/21/2022 2:27:54 PM
 *  Author: User
 */ 
#include "LED0_Private.h"

void LED0_Initialize(void)
{
	DIO_SETPIN_DIRECTION(LED0_PRT,LED0 , DIO_OUTPUT);
}
void LED0_ON(void)
{
	DIO_SETPIN_VALUE(LED0_PRT,LED0,DIO_HIGH);
}
void LED0_OFF(void)
{
	DIO_SETPIN_VALUE(LED0_PRT,LED0,DIO_LOW);
	
}
void LED0_TGL(void)
{
	DIO_TOGPIN_VALUE(LED0_PRT,LED0);
}