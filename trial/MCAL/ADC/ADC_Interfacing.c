/*
* ADC_Interfacing.c
*
* Created: 9/30/2022 11:41:13 AM
*  Author: User
*/

#include "ADC_Private.h"
void ADC_Initialization(ADC_PRE prescalar , ADC_VREF refrence)
{
	switch(refrence)
	{
		case AREF:
		CLR_BIT(ADMUX,REFS0); 		CLR_BIT(ADMUX,REFS1);
		break;
		
		case AVCC:
		SET_BIT(ADMUX,REFS0); 		CLR_BIT(ADMUX,REFS1);
		break;
		
		case RESERVED:
		CLR_BIT(ADMUX,REFS0); 		SET_BIT(ADMUX,REFS1);
		break;
		
		case INTERNAL:
		SET_BIT(ADMUX,REFS0); 			SET_BIT(ADMUX,REFS1);
		break;
	}
	
	switch(prescalar)
	{
		case ADC_PR1:
		CLR_BIT(ADCSRA,ADPS2) ; CLR_BIT(ADCSRA,ADPS1) ; CLR_BIT(ADCSRA,ADPS0) ;
		break;
		case ADC_PR2:
		CLR_BIT(ADCSRA,ADPS2) ; CLR_BIT(ADCSRA,ADPS1) ; SET_BIT(ADCSRA,ADPS0) ;
		break;
		case ADC_PR4:
		CLR_BIT(ADCSRA,ADPS2) ; SET_BIT(ADCSRA,ADPS1) ; CLR_BIT(ADCSRA,ADPS0) ;
		break;
		case ADC_PR8:
		CLR_BIT(ADCSRA,ADPS2) ; SET_BIT(ADCSRA,ADPS1) ; SET_BIT(ADCSRA,ADPS0) ;
		break;
		case ADC_PR16:
		SET_BIT(ADCSRA,ADPS2) ; CLR_BIT(ADCSRA,ADPS1) ; CLR_BIT(ADCSRA,ADPS0) ;
		break;
		case ADC_PR32:
		SET_BIT(ADCSRA,ADPS2); CLR_BIT(ADCSRA,ADPS1); SET_BIT(ADCSRA,ADPS0);
		break;
		case ADC_PR64:
		SET_BIT(ADCSRA,ADPS2); SET_BIT(ADCSRA,ADPS1); CLR_BIT(ADCSRA,ADPS0);
		break;
		case ADC_PR128:
		SET_BIT(ADCSRA,ADPS2); SET_BIT(ADCSRA,ADPS1); SET_BIT(ADCSRA,ADPS0);
		break;
	}
		// ADC Enable
		SET_BIT(ADCSRA, ADEN);
		// ADC interrupt disable
		CLR_BIT(ADCSRA, ADIE);
		// ADC auto trigger enable
		SET_BIT(ADCSRA, ADATE);
		// ADC Right adjust
		CLR_BIT(ADMUX, ADLAR);
}
uint16_t ADC_READ( ADC_Channel channel)
{
	uint16_t value = 0 ;
	
	switch(channel)
	{
		case ADC_CH0:
		CLR_BIT(ADMUX,MUX4); 		CLR_BIT(ADMUX,MUX3); 		CLR_BIT(ADMUX,MUX2); 		CLR_BIT(ADMUX,MUX1); 		CLR_BIT(ADMUX,MUX0);
		break;
		case ADC_CH1:
		CLR_BIT(ADMUX,MUX4); 		CLR_BIT(ADMUX,MUX3); 		CLR_BIT(ADMUX,MUX2); 		CLR_BIT(ADMUX,MUX1); 		SET_BIT(ADMUX,MUX0);
		break;
		case ADC_CH2:
		CLR_BIT(ADMUX,MUX4); 		CLR_BIT(ADMUX,MUX3); 		CLR_BIT(ADMUX,MUX2); 		SET_BIT(ADMUX,MUX1); 		CLR_BIT(ADMUX,MUX0);		
		break;
		case ADC_CH3:
		CLR_BIT(ADMUX,MUX4); 		CLR_BIT(ADMUX,MUX3); 		CLR_BIT(ADMUX,MUX2); 		SET_BIT(ADMUX,MUX1); 		SET_BIT(ADMUX,MUX0);		
		break;
		case ADC_CH4:
		CLR_BIT(ADMUX,MUX4); 		CLR_BIT(ADMUX,MUX3); 		SET_BIT(ADMUX,MUX2); 		CLR_BIT(ADMUX,MUX1); 		CLR_BIT(ADMUX,MUX0);		
		break;
		case ADC_CH5:
		CLR_BIT(ADMUX,MUX4); 		CLR_BIT(ADMUX,MUX3); 		SET_BIT(ADMUX,MUX2); 		CLR_BIT(ADMUX,MUX1); 		SET_BIT(ADMUX,MUX0);		
		break;
		case ADC_CH6:
		CLR_BIT(ADMUX,MUX4); 		CLR_BIT(ADMUX,MUX3); 		SET_BIT(ADMUX,MUX2); 		SET_BIT(ADMUX,MUX1); 		CLR_BIT(ADMUX,MUX0);		
		break;
		case ADC_CH7:
		CLR_BIT(ADMUX,MUX4); 		CLR_BIT(ADMUX,MUX3); 		SET_BIT(ADMUX,MUX2); 		SET_BIT(ADMUX,MUX1); 		SET_BIT(ADMUX,MUX0);
		break;
	}
	SET_BIT(ADCSRA,ADSC);
	
	while(GET_BIT(ADCSRA,ADIF) != 1);
	
	value = ADC_DATA;
	
	return value ; 
	
}