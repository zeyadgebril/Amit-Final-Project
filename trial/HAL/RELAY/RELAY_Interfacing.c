/*
 * RELAY_Interfacing.c
 *
 * Created: 9/21/2022 4:19:47 PM
 *  Author: User
 */ 
#include "RELAY_Private.h"

void RELAY_Initialize(void)
{
	DIO_SETPIN_DIRECTION(RELAY_PRT,RELAY,DIO_OUTPUT);
}
void RELAY_ON(void)
{
	DIO_SETPIN_VALUE(RELAY_PRT,RELAY,DIO_HIGH);
}
void RELAY_OFF(void)
{
	DIO_SETPIN_VALUE(RELAY_PRT,RELAY,DIO_LOW);
	
}
void RELAY_TGL(void)
{
DIO_TOGPIN_VALUE(RELAY_PRT,RELAY);	
}