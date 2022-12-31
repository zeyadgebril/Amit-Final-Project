/*
 * LCD_Interfacing.c
 *
 * Created: 10/1/2022 12:59:59 AM
 *  Author: User
 */ 
#include "LCD_Private.h"


#include <stdio.h>
#include <math.h>

void reverse(char* str, int len)
{
	int i = 0, j = len - 1, temp;
	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}
int intToStr(int x, char str[], int d)
{
	int i = 0;
	while (x) {
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	
	// If number of digits required is more, then
	// add 0s at the beginning
	while (i < d)
	str[i++] = '0';
	
	reverse(str, i);
	str[i] = '\0';
	return i;
}
void ftoa(float n, char* res, int afterpoint)
{
	// Extract integer part
	int ipart = (int)n;
	
	// Extract floating part
	float fpart = n - (float)ipart;
	
	// convert integer part to string
	int i = intToStr(ipart, res, 0);
	
	// check for display option after point
	if (afterpoint != 0) {
		res[i] = '.'; // add dot
		
		// Get the value of fraction part upto given no.
		// of points after dot. The third parameter
		// is needed to handle cases like 233.007
		fpart = fpart * pow(10, afterpoint);
		
		intToStr((int)fpart, res + i + 1, afterpoint);
	}
}

void LCD_Initialize(void)
{
	/* Define direction of pins*/
	DIO_SETPIN_DIRECTION(LCD_CNTRL_PRT, LCD_RS, DIO_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_CNTRL_PRT, LCD_RW, DIO_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_CNTRL_PRT, LCD_EN, DIO_OUTPUT);
	
	DIO_SETPIN_DIRECTION(LCD_DATA_PRT, LCD_D4, DIO_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_DATA_PRT, LCD_D5, DIO_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_DATA_PRT, LCD_D6, DIO_OUTPUT);
	DIO_SETPIN_DIRECTION(LCD_DATA_PRT, LCD_D7, DIO_OUTPUT);
	/* Send commands*/
	LCD_Write_Command(0x33);
	LCD_Write_Command(0x32);
	LCD_Write_Command(0x28);
	LCD_Write_Command(0x01);
	LCD_Write_Command(0x02);
	LCD_Write_Command(0x0C);
	LCD_Write_Command(0x06);
}
void LCD_Write_Command(uint8_t command)
{
	/* Register select will select command register*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PRT, LCD_RS, DIO_LOW);
	/* Write on LCD*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PRT, LCD_RW, DIO_LOW);
	/* Set enable by low*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PRT, LCD_EN, DIO_LOW);
	/* Send High Nibble of command*/
	LCD = (command & 0xF0);
	/* Send high to low pulse of enable*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PRT, LCD_EN, DIO_HIGH);
	_delay_ms(1);
	DIO_SETPIN_VALUE(LCD_CNTRL_PRT, LCD_EN, DIO_LOW);
	/* Send low nibble of command*/
	LCD = ((command & 0x0F) << 4);
	/* Send high to low pulse of enable*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PRT, LCD_EN, DIO_HIGH);
	_delay_ms(1);
	DIO_SETPIN_VALUE(LCD_CNTRL_PRT, LCD_EN, DIO_LOW);
	_delay_ms(5);
}
void LCD_Write_Character(uint8_t character)
{
	/* Register select will select command register*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PRT, LCD_RS, DIO_HIGH);
	/* Write on LCD*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PRT, LCD_RW, DIO_LOW);
	/* Set enable by low*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PRT, LCD_EN, DIO_LOW);
	/* Send High Nibble of character*/
	LCD = (character & 0xF0);
	/* Send high to low pulse of enable*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PRT, LCD_EN, DIO_HIGH);
	_delay_ms(1);
	DIO_SETPIN_VALUE(LCD_CNTRL_PRT, LCD_EN, DIO_LOW);
	/* Send low nibble of character*/
	LCD = ((character & 0x0F) << 4);
	/* Send high to low pulse of enable*/
	DIO_SETPIN_VALUE(LCD_CNTRL_PRT, LCD_EN, DIO_HIGH);
	_delay_ms(1);
	DIO_SETPIN_VALUE(LCD_CNTRL_PRT, LCD_EN, DIO_LOW);
	_delay_ms(5);
}
void LCD_Write_string(uint8_t* str)
{
	while (*str != '\0')
	{
		LCD_Write_Character(*str);
		_delay_ms(10);
		str++;
	}
}
void LCD_Write_Number(uint32_t number)
{
	uint8_t num[10];
	ltoa(number, (uint8_t*)num, 10);
	LCD_Write_string(num);
}
void LCD_Write_Float(fint32_t Fnumber)
{
	uint8_t Fnum[10];
	ftoa(Fnumber, (uint8_t*)Fnum, 3);
	LCD_Write_string(Fnum);
}
void LCD_Location(uint8_t row, uint8_t column)
{
	uint8_t Loc_Row0 = 0x80;
	uint8_t Loc_Row1 = 0xC0;
	switch(row)
	{
		case 0:
		Loc_Row0 += column;
		LCD_Write_Command(Loc_Row0);
		break;
		case 1:
		Loc_Row1 += column;
		LCD_Write_Command(Loc_Row1);
		break;
		default:
		Loc_Row0 += column;
		LCD_Write_Command(Loc_Row0);
		break;
	}
}
void LCD_ClearScreen(void)
{
	LCD_Write_Command(0x01);
}


void LCD_WriteCustomChar(uint8_t  CGRAM_LOC,uint8_t *icon)  //here i dont actually write when i call the function i only give it the cgram address to save the custom char the i have t call the lcd write char and give it the char number in the cgram to display it  
{
	uint8_t i;
	if(CGRAM_LOC < 8)
	{
		LCD_Write_Command((0x40 + (CGRAM_LOC*8)));// Command 0x40 and onwards forces
		for( i = 0 ; i < 8 ; i++)//the device to point CGRAM address
		{
			LCD_Write_Character(icon[i]);// Write 8 byte for generation of 1 character
		}

	}
}