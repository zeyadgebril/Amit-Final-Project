/*
 * LCD_Private.h
 *
 * Created: 10/1/2022 12:59:26 AM
 *  Author: User
 */ 


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#include "LCD_Configuration.h"

void LCD_Initialize(void);
void LCD_Write_Command(uint8_t command);
void LCD_Write_Character(uint8_t character);
void LCD_Write_string(uint8_t* str);
void LCD_Write_Number(uint32_t number);
void LCD_Write_Float(fint32_t Fnumber);
void LCD_Location(uint8_t row, uint8_t column);
void LCD_ClearScreen(void);
void LCD_WriteCustomChar(uint8_t  CGRAM_LOC,uint8_t *icon);



#endif /* LCD_PRIVATE_H_ */