/*
* KEYPAD_Interface.c
*
* Created: 9/23/2022 11:47:48 AM
*  Author: karim
*/


#include "KEYPAD_Private.h"

const uint8_t keypad[4][4] =
{
	{'7', '8','9', '/'},
	
	{'4','5','6', '*'},
	
	{'1', '2', '3', '-'},
	
	{'c', '0', '=', '+'}
};
void KEYPAD_Initialize(void)
{
	

	//Define direction for pins
		DIO_SETPIN_DIRECTION(KEYPAD_PRT, KEYPAD_PIN_OUT0, KEYPAD_OUT);
		DIO_SETPIN_DIRECTION(KEYPAD_PRT, KEYPAD_PIN_OUT1, KEYPAD_OUT);
		DIO_SETPIN_DIRECTION(KEYPAD_PRT, KEYPAD_PIN_OUT2, KEYPAD_OUT);
		DIO_SETPIN_DIRECTION(KEYPAD_PRT, KEYPAD_PIN_OUT3, KEYPAD_OUT);
	//Set logic to high
	DIO_SETPIN_VALUE(KEYPAD_PRT, KEYPAD_PIN_OUT0, KEYPAD_HIGH);
	DIO_SETPIN_VALUE(KEYPAD_PRT, KEYPAD_PIN_OUT1, KEYPAD_HIGH);
	DIO_SETPIN_VALUE(KEYPAD_PRT, KEYPAD_PIN_OUT2, KEYPAD_HIGH);
	DIO_SETPIN_VALUE(KEYPAD_PRT, KEYPAD_PIN_OUT3, KEYPAD_HIGH);
	//Define direction for pins
	DIO_SETPIN_DIRECTION(KEYPAD_PRT, KEYPAD_PIN_INP0, KEYPAD_INP);
	DIO_SETPIN_DIRECTION(KEYPAD_PRT, KEYPAD_PIN_INP1, KEYPAD_INP);
	DIO_SETPIN_DIRECTION(KEYPAD_PRT, KEYPAD_PIN_INP2, KEYPAD_INP);
	DIO_SETPIN_DIRECTION(KEYPAD_PRT, KEYPAD_PIN_INP3, KEYPAD_INP);
	//Activate internal pull up
	DIO_SETPIN_PULLUP(KEYPAD_PRT, KEYPAD_PIN_INP0);
	DIO_SETPIN_PULLUP(KEYPAD_PRT, KEYPAD_PIN_INP1);
	DIO_SETPIN_PULLUP(KEYPAD_PRT, KEYPAD_PIN_INP2);
	DIO_SETPIN_PULLUP(KEYPAD_PRT, KEYPAD_PIN_INP3);
	
}

uint8_t KEYPAD_Read(void)
{
	uint8_t val = 0;
	uint8_t btn = 0;
	uint8_t Row_Loc = 0;
	uint8_t Col_Loc = 0;
	for (Col_Loc = KEYPAD_COL_START; Col_Loc <= KEYPAD_COL_END; Col_Loc++)
	{
		DIO_SETPIN_VALUE(KEYPAD_PRT, Col_Loc, KEYPAD_LOW);
		for (Row_Loc = KEYPAD_ROW_START; Row_Loc <= KEYPAD_ROW_END; Row_Loc++)
		{
			val = DIO_READPIN_VALUE(KEYPAD_PRT, Row_Loc);
			if(val == KEYPAD_PRESSED)
			{
				btn = keypad[Row_Loc - KEYPAD_ROW_START][Col_Loc - KEYPAD_COL_START];
				while (val == KEYPAD_PRESSED)
				{
					val = DIO_READPIN_VALUE(KEYPAD_PRT, Row_Loc);
				}
				_delay_ms(10);
			}
		}
		DIO_SETPIN_VALUE(KEYPAD_PRT, Col_Loc, KEYPAD_HIGH);
	}
	return btn;
}