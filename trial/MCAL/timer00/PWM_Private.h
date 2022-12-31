/*
 * PWM_Private.h
 *
 * Created: 11/26/2022 5:19:19 PM
 *  Author: User
 */ 


#ifndef PWM_PRIVATE_H_
#define PWM_PRIVATE_H_



#include "PWM_Configuration.h"

void PWM_Fast_Initialize(void);
void PWM_Fast_Start(void);
void PWM_Fast_Stop(void);
//void PWM_Fast_SetDutyCycle(uint8_t dutycycle);

void PWM_PhaseCorrect_Initialize(void);
void PWM_PhaseCorrect_Start(void);
void PWM_PhaseCorrect_Stop(void);
//void PWM_PhaseCorrect_SetDutyCycle(uint8_t dutycycle);

#endif /* PWM_PRIVATE_H_ */