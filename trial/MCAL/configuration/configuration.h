/*
 * configuration.h
 *
 * Created: 9/18/2022 12:54:01 PM
 *  Author: User
 */ 


#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#undef  F_CPU
#define F_CPU 8000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "BIT_Math.h"
#include "STD_Types.h"
#include "AVR_Address.h"
#include "DIO_Private.h"
#include "SPI_Private.h"
#include "EXT_INTERRUPT_Private.h"
#include "SEVSEG_Private.h"
#include "Seven_Segment2_Private.h"
#include "LED0_Private.h"
#include "LED1_Private.h"
#include "LED2_Private.h"
#include "BUZZER_Private.h"
#include "RELAY_Private.h"
#include "LCD_Private.h"
#include "ADC_Private.h"
#include "Button1_Private.h"
#include "Keypad_Private.h"
#include "MOTOR_Private.h"
#include "SERVO_Private.h"
#include "TIMER_Private.h"
#include "PWM_Private.h"
#include "WDT_Private.h"
#include "TWI_Private.h"
#include "UART_Private.h"
#include "LM35_Private.h"



#endif /* CONFIGURATION_H_ */