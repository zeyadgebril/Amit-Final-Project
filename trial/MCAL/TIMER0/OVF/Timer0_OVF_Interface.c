/*
* Timer0_Interface.c
*
* Created: 18/03/2022 17:42:07
*  Author: shahe
*/
#include "Timer0_OVF_Private.h"

void Timer0_OVF_WithoutInterrupt_Intialize(void)
{
	cli();//Clear global interrupt, Disable global interrupt
	CLR_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);//Choose OVF
	CLR_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);//Disconnect OC0 pin
	CLR_BIT(TIMSK, TOIE0);//Disable peripheral interrupt
	sei();//Set global interrupt, Enable global interrupt
}
void Timer0_OVF_WithoutInterrupt_Start(Timer0_OVF_Prescaler prescaler)
{
	/*
	switch (prescaler)//Choose prescaler
	{
		
	}
	*/
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);//Choose Pre-scaler 1024
}
void Timer0_OVF_WithoutInterrupt_Stop(Timer0_OVF_Prescaler prescaler)
{
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);//Choose Pre-scaler 0
}
void Timer0_OVF_WithoutInterrupt_setDelay(uint32_t delay)
{
	uint32_t counter = 0;
	uint8_t Tick = ((1 * PRESCALER) / FREQUENCY);
	uint32_t Count = ((delay * MICROSECOND) / Tick);
	uint32_t No_OVF = (Count / BITS);
	uint8_t InitialValue_TCNT0 = (BITS - (Count % BITS));
	TCNT0 = InitialValue_TCNT0;
	No_OVF++;
	while (counter != No_OVF)//Polling Mode (Blocking Delay)
	{
		while (GET_BIT(TIFR, TOV0) != 1);//Wait until flag raise
		SET_BIT(TIFR, TOV0);//Clear flag manually in disable interrupt mode
		counter++;
	}
}

uint8_t Initial_Value = 0;
uint32_t Number_OVF = 0;

void Timer0_OVF_WithInterrupt_Intialize(void)
{
	cli();//Clear global interrupt, Disable global interrupt
	CLR_BIT(TCCR0, WGM01);CLR_BIT(TCCR0, WGM00);//Choose OVF
	CLR_BIT(TCCR0, COM01);CLR_BIT(TCCR0, COM00);//Disconnect OC0 pin
	SET_BIT(TIMSK, TOIE0);//Enable peripheral interrupt
	sei();//Set global interrupt, Enable global interrupt
}
void Timer0_OVF_WithInterrupt_Start(Timer0_OVF_Prescaler prescaler)
{
	/*
	switch (prescaler)//Choose prescaler
	{
		
	}
	*/
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);//Choose Pre-scaler 1024
}
void Timer0_OVF_WithInterrupt_Stop(Timer0_OVF_Prescaler prescaler)
{
	SET_BIT(TCCR0, CS02);CLR_BIT(TCCR0, CS01);SET_BIT(TCCR0, CS00);//Choose Pre-scaler 0
}
void Timer0_OVF_WithInterrupt_setDelay(uint32_t delay)
{
	uint8_t Tick = ((1 * PRESCALER) / FREQUENCY);
	uint32_t Count = ((delay * MICROSECOND) / Tick);
	Number_OVF = (Count / BITS);
	Initial_Value = (BITS - (Count % BITS));
	Number_OVF++;
}


