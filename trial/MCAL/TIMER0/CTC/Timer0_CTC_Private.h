/*
* Timer0_Private.h
*
* Created: 18/03/2022 17:41:24
*  Author: shahe
*/


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#include "Timer0_CTC_Configuration.h"

void Timer0_CTC_WithoutInterrupt_Intialize(CTC0_Mode ctcmode);
void Timer0_CTC_WithoutInterrupt_Start(Timer0_CTC_Prescaler prescaler);
void Timer0_CTC_WithoutInterrupt_Stop(Timer0_CTC_Prescaler prescaler);
void Timer0_CTC_WithoutInterrupt_setDelay(uint32_t delay, uint8_t OCRValue);

void Timer0_CTC_WithInterrupt_Intialize(CTC0_Mode ctcmode);
void Timer0_CTC_WithInterrupt_Start(Timer0_CTC_Prescaler prescaler);
void Timer0_CTC_WithInterrupt_Stop(Timer0_CTC_Prescaler prescaler);
void Timer0_CTC_WithInterrupt_setDelay(uint32_t delay, uint8_t OCRValue);



#endif /* TIMER0_PRIVATE_H_ */