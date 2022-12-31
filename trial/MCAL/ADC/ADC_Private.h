/*
 * AD_Private.h
 *
 * Created: 9/30/2022 11:40:20 AM
 *  Author: User
 */ 


#ifndef AD_PRIVATE_H_
#define AD_PRIVATE_H_

#include "ADC_Configuration.h"

void ADC_Initialization(ADC_PRE prescalar , ADC_VREF refrence);
uint16_t ADC_READ(ADC_Channel channel);



#endif /* AD_PRIVATE_H_ */