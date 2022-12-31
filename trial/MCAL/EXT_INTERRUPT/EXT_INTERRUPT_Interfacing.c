/*
 * EXT_INTERRUPT_Interfacing.c
 *
 * Created: 9/24/2022 12:00:54 PM
 *  Author: User
 */ 
#include "EXT_INTERRUPT_Private.h"

void EXT_INTERRUPT_Initialization(EXT_INT interrupt , EXT_INT_SENSE sense)
{
	/*Disable global interrupt while initialization*/
	CLR_BIT(SREG,7);
	switch(interrupt)
	{
		case EXT_INT0:
		switch(sense)
		{
			case LOW:
			CLR_BIT(MCUCR,ISC01);  CLR_BIT(MCUCR,ISC00);
			break;
			
			case HIGH:
			CLR_BIT(MCUCR,ISC01);  SET_BIT(MCUCR,ISC00);
			break;
			
			case FAILING:
			SET_BIT(MCUCR,ISC01);  CLR_BIT(MCUCR,ISC00);
			break;
			
			case RISING:
			SET_BIT(MCUCR,ISC01);  SET_BIT(MCUCR,ISC00);
			break;
		}
		/*Enable preiphral interrupt*/
		SET_BIT(GICR,INT0);
		
		break;
		
		case EXT_INT1:
		switch(sense)
		{
			case LOW:
			CLR_BIT(MCUCR,ISC11);  CLR_BIT(MCUCR,ISC10);
			break;
			
			case HIGH:
			CLR_BIT(MCUCR,ISC11);  SET_BIT(MCUCR,ISC10);
			break;
			
			case FAILING:
			SET_BIT(MCUCR,ISC11);  CLR_BIT(MCUCR,ISC10);
			break;
			
			case RISING:
			SET_BIT(MCUCR,ISC11);  SET_BIT(MCUCR,ISC10);
			break;
		}
		/*Enable peripheral interrupt*/
			SET_BIT(GICR,INT1);
		break;
		
		case EXT_INT2:
		break;
	}
	
	
	/*Enable global interrupt after initialization*/
	SET_BIT(SREG,7);
}
