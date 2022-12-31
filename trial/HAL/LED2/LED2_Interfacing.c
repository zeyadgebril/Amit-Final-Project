/*
 * LED2_Interfacing.c
 *
 * Created: 9/21/2022 3:13:05 PM
 *  Author: User
 */ 
#include "LED2_Private.h"

void LED2_Initialize(void)
{
	DIO_SETPIN_DIRECTION(LED2_PRT,LED2,DIO_OUTPUT);
}
void LED2_ON(void)
{
	DIO_SETPIN_VALUE(LED2_PRT,LED2,DIO_HIGH);
}
void LED2_OFF(void)
{
	DIO_SETPIN_VALUE(LED2_PRT,LED2,DIO_LOW);
	
}
void LED2_TGL(void)
{
	DIO_TOGPIN_VALUE(LED2_PRT,LED2);
}

