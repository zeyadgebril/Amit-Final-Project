/*
* Timer0_Interface.c
*
* Created: 18/03/2022 17:42:07
*  Author: shahe
*/
#include "Timer0_CTC_Private.h"

void Timer0_CTC_WithoutInterrupt_Intialize(CTC0_Mode ctcmode)
{
	cli();//Clear global interrupt, Disable global interrupt
	/*
	switch (mode)//Choose Mode
	{
	case OVF:
	break;
	case Phase_Correct_PWM:
	break;
	case CTC:
	break;
	case Fast_PWM:
	break;
	}
	*/
	SET_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);//Choose CTC
	CLR_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);//Disconnect OC0 pin
	CLR_BIT(TIMSK, OCIE0);//Disable peripheral interrupt
	sei();//Set global interrupt, Enable global interrupt
}
void Timer0_CTC_WithoutInterrupt_Start(Timer0_CTC_Prescaler prescaler)
{
	/*
	switch (prescaler)//Choose prescaler
	{
		
	}
	*/
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);//Choose Pre-scaler 1024
}
void Timer0_CTC_WithoutInterrupt_Stop(Timer0_CTC_Prescaler prescaler)
{
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);//Choose Pre-scaler 0
}
void Timer0_CTC_WithoutInterrupt_setDelay(uint32_t delay, uint8_t OCRValue)
{
	uint32_t counter = 0;
	uint8_t Tick = ((1 * PRESCALER) / FREQUENCY);
	uint32_t Count = ((delay * MICROSECOND) / Tick);
	uint32_t No_CTC = (Count / OCRValue);
	OCR0 = OCRValue;
	No_CTC++;
	while (counter != No_CTC)//Polling Mode (Blocking Delay)
	{
		while (GET_BIT(TIFR, OCF0) != 1);//Wait until flag raise
		SET_BIT(TIFR, OCF0);//Clear flag manually in disable interrupt mode
		counter++;
	}
}

uint32_t Number_CTC = 0;

void Timer0_CTC_WithInterrupt_Intialize(CTC0_Mode ctcmode)
{
	cli();//Clear global interrupt, Disable global interrupt
	/*
	switch (mode)//Choose Mode
	{
	case OVF:
	break;
	case Phase_Correct_PWM:
	break;
	case CTC:
	break;
	case Fast_PWM:
	break;
	}
	*/
	SET_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);//Choose CTC
	CLR_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);//Disconnect OC0 pin
	SET_BIT(TIMSK, OCIE0);//Disable peripheral interrupt
	sei();//Set global interrupt, Enable global interrupt
}
void Timer0_CTC_WithInterrupt_Start(Timer0_CTC_Prescaler prescaler)
{
	/*
	switch (prescaler)//Choose prescaler
	{
		
	}
	*/
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);//Choose Pre-scaler 1024
}
void Timer0_CTC_WithInterrupt_Stop(Timer0_CTC_Prescaler prescaler)
{
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);//Choose Pre-scaler 0
}
void Timer0_CTC_WithInterrupt_setDelay(uint32_t delay, uint8_t OCRValue)
{
	uint8_t Tick = ((1 * PRESCALER) / FREQUENCY);
	uint32_t Count = ((delay * MICROSECOND) / Tick);
	Number_CTC = (Count / OCRValue);
	OCR0 = OCRValue;
	Number_CTC++;
}

