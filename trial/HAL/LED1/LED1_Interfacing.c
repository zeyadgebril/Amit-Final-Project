/*
 * LED1_Interfacing.c
 *
 * Created: 9/21/2022 3:03:12 PM
 *  Author: User
 */ 
#include "LED1_Private.h"

void LED1_Initialize(void)
{
	DIO_SETPIN_DIRECTION(LED1_PRT,LED1,DIO_OUTPUT);
}
void LED1_ON(void)
{
	DIO_SETPIN_VALUE(LED1_PRT,LED1,DIO_HIGH);
}
void LED1_OFF(void)
{
	DIO_SETPIN_VALUE(LED1_PRT,LED1,DIO_LOW);
	
}
void LED1_TGL(void)
{
	DIO_TOGPIN_VALUE(LED1_PRT,LED1);
}