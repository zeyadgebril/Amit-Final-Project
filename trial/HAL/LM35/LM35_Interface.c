/*
 * LM35_Interface.c
 *
 * Created: 12/23/2022 6:49:57 PM
 *  Author: dutzr
 */ 



#include "LM35_Private.h"




uint16_t First_LM35_read(void)
{
	uint16_t adc = ADC_READ(ADC_CH0);
	uint16_t volt = ((uint32_t)5000*adc)/1024;
	uint16_t temp = volt ;
	return temp ;
}
uint16_t Second_LM35_read(void)
{
	uint16_t adc = ADC_READ(ADC_CH1);
	uint16_t volt = ((uint32_t)5000*adc)/1024;
	uint16_t temp = volt ;
	return temp ;
}
uint16_t Third_LM35_read(void)
{
	uint16_t adc = ADC_READ(ADC_CH2);
	uint16_t volt = ((uint32_t)5000*adc)/1024;
	uint16_t temp = volt ;
	return temp ;
}


