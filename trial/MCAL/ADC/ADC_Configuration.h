/*
* ADC_Configuration.h
*
* Created: 9/30/2022 11:40:59 AM
*  Author: User
*/


#ifndef ADC_CONFIGURATION_H_
#define ADC_CONFIGURATION_H_

#include "configuration.h"

typedef enum
{
	AREF=0,
	AVCC=1,
	RESERVED=2,
	INTERNAL=3
}ADC_VREF;

typedef enum
{
	ADC_CH0=0,
	ADC_CH1=1,
	ADC_CH2=2,
	ADC_CH3=3,
	ADC_CH4=4,
	ADC_CH5=5,
	ADC_CH6=6,
	ADC_CH7=7
}ADC_Channel;


typedef enum
{
	ADC_PR1=0,
	ADC_PR2=1,
	ADC_PR4=2,
	ADC_PR8=3,
	ADC_PR16=4,
	ADC_PR32=5,
	ADC_PR64=6,
	ADC_PR128=7
}ADC_PRE;



#endif /* ADC_CONFIGURATION_H_ */