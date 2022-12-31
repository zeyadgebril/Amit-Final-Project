/*
* Timer0_Private.h
*
* Created: 18/03/2022 17:41:24
*  Author: shahe
*/


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_


#include "Timer0_OVF_Configuration.h"

void Timer0_OVF_WithoutInterrupt_Intialize(void);
void Timer0_OVF_WithoutInterrupt_Start(Timer0_OVF_Prescaler prescaler);
void Timer0_OVF_WithoutInterrupt_Stop(Timer0_OVF_Prescaler prescaler);
void Timer0_OVF_WithoutInterrupt_setDelay(uint32_t delay);

void Timer0_OVF_WithInterrupt_Intialize(void);
void Timer0_OVF_WithInterrupt_Start(Timer0_OVF_Prescaler prescaler);
void Timer0_OVF_WithInterrupt_Stop(Timer0_OVF_Prescaler prescaler);
void Timer0_OVF_WithInterrupt_setDelay(uint32_t delay);




#endif /* TIMER0_PRIVATE_H_ */