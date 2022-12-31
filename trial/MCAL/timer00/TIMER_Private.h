/*
 * TIMER_Private.h
 *
 * Created: 11/26/2022 5:17:28 PM
 *  Author: User
 */ 


#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


#include "PWM_Private.h"
#include "Timer_Configuration.h"

void Timer0_OVF_WithoutInterrupt_Intialize(Timer0_Mode modes);
void Timer0_OVF_WithoutInterrupt_Start(Timer0_Prescaler prescaler);
void Timer0_OVF_WithoutInterrupt_Stop(Timer0_Prescaler prescaler);
void Timer0_OVF_WithoutInterrupt_setDelay(uint32_t delay);

void Timer0_CTC_WithoutInterrupt_Intialize(Timer0_Mode modes, CTC0_Mode ctcmode);
void Timer0_CTC_WithoutInterrupt_Start(Timer0_Prescaler prescaler);
void Timer0_CTC_WithoutInterrupt_Stop(Timer0_Prescaler prescaler);
void Timer0_CTC_WithoutInterrupt_setDelay(uint32_t delay, uint8_t OCRValue);



void Timer0_OVF_WithInterrupt_Intialize(Timer0_Mode modes);
void Timer0_OVF_WithInterrupt_Start(Timer0_Prescaler prescaler);
void Timer0_OVF_WithInterrupt_Stop(Timer0_Prescaler prescaler);
void Timer0_OVF_WithInterrupt_setDelay(uint32_t delay);

void Timer0_CTC_WithInterrupt_Intialize(Timer0_Mode modes, CTC0_Mode ctcmode);
void Timer0_CTC_WithInterrupt_Start(Timer0_Prescaler prescaler);
void Timer0_CTC_WithInterrupt_Stop(Timer0_Prescaler prescaler);
void Timer0_CTC_WithInterrupt_setDelay(uint32_t delay, uint8_t OCRValue);


#endif /* TIMER_PRIVATE_H_ */