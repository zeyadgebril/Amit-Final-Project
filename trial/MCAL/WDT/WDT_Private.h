/*
 * WDT_Private.h
 *
 * Created: 11/26/2022 6:09:38 PM
 *  Author: User
 */ 


#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_



#include "WDT_Configuration.h"

void WDT_Initialization(void);
void WDT_Start(WDT_Voltage volt, WDT_Prescaler_3V pre_3V, WDT_Prescaler_5V pre_5V);
void WDT_Timer_Refresh(void);

#endif /* WDT_PRIVATE_H_ */