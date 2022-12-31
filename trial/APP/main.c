/*
* D34.c
*
* Created: 9/18/2022 12:41:07 PM
* Author : User
*/


#include "main.h"
int main(void)
{
/**********************************************Intialization_Section********************************************/
	LCD_Initialize();
	UART_Initialize(Asynchronous,Disable,Bit_1,Bits_8);
	 LED0_Initialize();
	 BUZZER_Initialize();
	 Motor_Initialize();
	 EXT_INTERRUPT_Initialization(EXT_INT0 ,HIGH);
	 EXT_INTERRUPT_Initialization(EXT_INT1 , HIGH);
	 ADC_Initialization(ADC_PR16,AVCC);
/***************************************************************************************************************/
/**********************************************Global_Variables*************************************************/
	uint16_t temp=0;   /*Global Variable Used to take the value of LM35 Sensors*/
	uint8_t x=0;       /*Temporary Variable to take the USART Value from Virtual Terminal */
	uint8_t user_id=0; /*Variable Used To take The User ID From USART*/
	uint8_t data= 0 ;  /*Temporary Variable To take Users Commands*/
	uint8_t flag= 0 ;  /*A Flag Variable That Indicates Every Password Character is Right*/
	uint8_t count= 3 ; /*A Variable Used To Count How many Times did the user enter his Password (limit 3 times)*/
	uint8_t enter_system=1;/*A Variable Flag Used To know if the users entered the system or not*/
	uint8_t pass = 0 ; /*A Variable used to save Password char by char */
/****************************************************************************************************************/
/**********************************************System Start up***************************************************/
	LCD_Write_Command(0X84);
	LCD_Write_string("LOGIN Mode");
	LCD_Write_Command(0XC0);
	LCD_Write_string("ENTER DATA");
	UART_SENDSTRING("1:-user1\r\n");
	UART_SENDSTRING("2:-user2\r\n");
	UART_SENDSTRING("3:-Admin \r\n");
	UART_SENDSTRING("enter your choice");
	x =  UART_Received();
	user_id = x ; 
	UART_SENDSTRING("user");
	uart_sendchar(user_id);
	UART_SENDSTRING("\r\n");
/****************************************************************************************************************/
/***********************************************Infinite_Loop_System*********************************************/
	while(1)
	{
		switch(user_id)/*Switching between The user*/
		{
			case '1':
			UART_SENDSTRING("welcome user 1 enter your password digit by digit");
			pass = UART_Received();
			UART_SENDSTRING(pass);/*Entering The First Password Character*/
			UART_SENDSTRING("\r\n");
			if (pass == '1')
			{
				/*Making Sure that the first char is 1*/
				UART_SENDSTRING("enter second digit");
				pass = UART_Received();
				UART_SENDSTRING(pass);
				UART_SENDSTRING("\r\n");
				if (pass == '2')
				{
				/*Making Sure that the first char is 2*/

					UART_SENDSTRING("enter third digit");
					pass = UART_Received();
					UART_SENDSTRING(pass);
					UART_SENDSTRING("\r\n");
					if (pass == '3')
					{
				/*Making Sure that the first char is 3 and Entering the System */
						
						UART_SENDSTRING("WELCOME");
						LCD_Write_string("Welcome User 1 ");
						_delay_ms(300);
						LCD_ClearScreen();
						/*Displaying the User Menu*/
						UART_SENDSTRING("Welcome User1 Home \r\n");
						UART_SENDSTRING("Enter your choice please \r\n");
						UART_SENDSTRING("1:On/Off light \r\n");
						UART_SENDSTRING("2:Temp \r\n");
						UART_SENDSTRING("3:Open/Close DOOR \r\n");
						UART_SENDSTRING("4:Open Oven \r\n");
						UART_SENDSTRING("5:Close Oven \r\n");
						UART_SENDSTRING("6:Open Air Conditional \r\n");
						UART_SENDSTRING("7:Close Air Conditional \r\n");
						UART_SENDSTRING("8:Open Bathrooms \r\n");
						UART_SENDSTRING("9:Open Kitchen \r\n");
						flag = 1 ;/*Indicating that the user is Verified*/
					}
					else
					{
						UART_SENDSTRING("NOO");
						count -- ;
					}
				}
				else
				{
					UART_SENDSTRING("NOO");
					count -- ;
				}
			}
			else
			{
				UART_SENDSTRING("NOO");
				count -- ;
			}
			break;
			case '2':
				UART_SENDSTRING("welcome user 2 enter your password digit by digit");
				pass = UART_Received();
				UART_SENDSTRING(pass);
				UART_SENDSTRING("\r\n");
				if (pass == '4')
				{
					UART_SENDSTRING("enter second digit");
					pass = UART_Received();
					UART_SENDSTRING(pass);
					UART_SENDSTRING("\r\n");
					if (pass == '5')
					{
						UART_SENDSTRING("enter third digit");
						pass = UART_Received();
						UART_SENDSTRING(pass);
						UART_SENDSTRING("\r\n");
						if (pass == '6')
						{
							UART_SENDSTRING("WELCOME");
							LCD_Write_string("Welcome User 2 ");
							_delay_ms(300);
							LCD_ClearScreen();
							UART_SENDSTRING("Welcome User2 Home \r\n");
							UART_SENDSTRING("Enter your choice please \r\n");
							UART_SENDSTRING("1:On/Off light \r\n");
							UART_SENDSTRING("2:Temp \r\n");
							UART_SENDSTRING("3:Open/Close DOOR \r\n");
							UART_SENDSTRING("4:Open Oven \r\n");
							UART_SENDSTRING("5:Close Oven \r\n");
							UART_SENDSTRING("6:Open Air Conditional \r\n");
							UART_SENDSTRING("7:Close Air Conditional \r\n");
							UART_SENDSTRING("8:Open Bathrooms \r\n");
							UART_SENDSTRING("9:Open Kitchen \r\n");
							flag = 1 ;
						}
						else
						{
							UART_SENDSTRING("NOO");
							count -- ;
						}
					}
					else
					{
						UART_SENDSTRING("NOO");
						count -- ;
					}
				}
				else
				{
					UART_SENDSTRING("NOO");
					count -- ;
				}
			break;
			case '3':
				UART_SENDSTRING("welcome Admin enter your password digit by digit");
				pass = UART_Received();
				UART_SENDSTRING(pass);
				UART_SENDSTRING("\r\n");
				if (pass == '7')
				{
					UART_SENDSTRING("enter second digit");
					pass = UART_Received();
					UART_SENDSTRING(pass);
					UART_SENDSTRING("\r\n");
					if (pass == '8')
					{
						UART_SENDSTRING("enter third digit \r\n");
						pass = UART_Received();
						UART_SENDSTRING(pass);
						UART_SENDSTRING("\r\n");
						if (pass == '9')
						{
							UART_SENDSTRING("WELCOME \r\n");
							LCD_Write_string("Welcome ADMIN ");
							_delay_ms(300);
							LCD_ClearScreen();
							UART_SENDSTRING("Welcome User3 Home \r\n");
							UART_SENDSTRING("Enter your choice please \r\n");
							UART_SENDSTRING("1:On/Off lights \r\n");
							UART_SENDSTRING("2:Temps \r\n");
							UART_SENDSTRING("3:Open/Close DOORs \r\n");
							UART_SENDSTRING("4:Open Oven \r\n");
							UART_SENDSTRING("5:Close Oven \r\n");
							UART_SENDSTRING("6:Open Air Conditional \r\n");
							UART_SENDSTRING("7:Close Air Conditional \r\n");	
							UART_SENDSTRING("8:Open Bathrooms \r\n");
							UART_SENDSTRING("9:Open Kitchen \r\n");
							flag = 1 ;
						}	
						else
						{
							UART_SENDSTRING("NOO");
							count -- ;
						}
					}
					else
					{
						UART_SENDSTRING("NOO");
						count -- ;
					}
					
				}
				else
				{
					UART_SENDSTRING("NOO");
					count -- ;
				}
			break;
			default:
			break;
		}
		if (count == 0) /*If the User Entered the Password Wrong 3 Times*/
		{ 
			/*Closing The system and Requires to Restart it Again*/
			UART_SENDSTRING("blocked \r\n");
			DIO_SETPIN_VALUE(DIO_PORTD,DIO_PIN0,DIO_LOW);
			DIO_SETPIN_VALUE(DIO_PORTD,DIO_PIN1,DIO_LOW);
			BUZZER_ON();
			_delay_ms(3000);
			BUZZER_OFF();
			enter_system=0;
		}
		if (flag == 1)
		{
			break;
		}
	}
	/*Enter The Smart Home Successfully*/
	while (enter_system == 1)
	{
		LCD_ClearScreen();
		LCD_Write_string("WELCOME TO SYSTEM");
		_delay_ms(300);
		LCD_ClearScreen();
		switch(user_id)
		{
			case  '1':
			data = UART_Received();
				if (data == '1')
				{
					LED0_TGL();
					LCD_ClearScreen();
					LCD_Write_string("LED 1 toggled");
					_delay_ms(300);
				}
				else if (data == '2')
				{
				temp=First_LM35_read();
				LCD_Write_string("Temp Room1 is :");
				LCD_Write_Command(0XC0);
					LCD_Write_Number(temp/10);
					_delay_ms(3000);
					LCD_ClearScreen();
				}
				else if (data == '3') 
				{					
						
					Motor_ON(clockwise, enable1);
					_delay_ms(3000);
					Motor_OFF(enable1);
					LCD_Write_string("DOOR 1 :");
					_delay_ms(3000);
					LCD_ClearScreen();
				}
				else if (data == '4')
				{
					DIO_SETPIN_DIRECTION(DIO_PORTC , DIO_PIN2 ,DIO_OUTPUT);
					DIO_SETPIN_VALUE(DIO_PORTC , DIO_PIN2 , DIO_HIGH);
					LCD_Write_string("Heater On");
					_delay_ms(3000);
					LCD_ClearScreen();
				}
				else if (data == '5')
				{
					DIO_SETPIN_DIRECTION(DIO_PORTC , DIO_PIN2 ,DIO_OUTPUT);
					DIO_SETPIN_VALUE(DIO_PORTC , DIO_PIN2 , DIO_LOW);
					LCD_Write_string("Heater Off");
					_delay_ms(3000);
					LCD_ClearScreen();
				}
				else if (data == '6')
				{
					DIO_SETPIN_DIRECTION(DIO_PORTC , DIO_PIN3 ,DIO_OUTPUT);
					DIO_SETPIN_VALUE(DIO_PORTC , DIO_PIN3 , DIO_HIGH);
					LCD_Write_string("AIR CONDITIONAL ON");
					_delay_ms(3000);
					LCD_ClearScreen();
				}
				else if (data == '7')
				{
					DIO_SETPIN_DIRECTION(DIO_PORTC , DIO_PIN3 ,DIO_OUTPUT);
					DIO_SETPIN_VALUE(DIO_PORTC , DIO_PIN3 , DIO_LOW);
					LCD_Write_string("AIR CONDITIONAL  Off");
					_delay_ms(3000);
					LCD_ClearScreen();
				}
				else if (data == '8')
				{
					DIO_SETPIN_DIRECTION(DIO_PORTC,DIO_PIN7,DIO_OUTPUT);
					DIO_TOGPIN_VALUE(DIO_PORTC,DIO_PIN7);
					LCD_Write_string("Bathroom TGL");
					_delay_ms(3000);
					LCD_ClearScreen();
				}
				else if ( data ==  '9')
				{
					DIO_SETPIN_DIRECTION(DIO_PORTC,DIO_PIN6,DIO_OUTPUT);
					DIO_TOGPIN_VALUE(DIO_PORTC,DIO_PIN6);
					LCD_Write_string("Kitchen TGL");
					_delay_ms(3000);
					LCD_ClearScreen();
				}
			break;
			case  '2':
					data = UART_Received();
					if (data == '1')
					{
						LED1_TGL();
						LCD_ClearScreen();
						LCD_Write_string("LED 2 toggled");
						_delay_ms(300);
					}
					else if (data == '2')
					{
						temp=Second_LM35_read();
						LCD_Write_string("Temp Room2 is :");
						LCD_Write_Command(0XC0);
						LCD_Write_Number(temp/10);
						_delay_ms(3000);
						LCD_ClearScreen();
					}
					else if (data == '3')
					{
						Motor_ON(clockwise, enable2);
						_delay_ms(3000);
						Motor_OFF(enable2);
						LCD_Write_string("DOOR 2 :");
						_delay_ms(3000);
						LCD_ClearScreen();
					}
					else if (data == '4')
					{
						DIO_SETPIN_DIRECTION(DIO_PORTC , DIO_PIN2 ,DIO_OUTPUT);
						DIO_SETPIN_VALUE(DIO_PORTC , DIO_PIN2 , DIO_HIGH);
						LCD_Write_string("Heater On");
						_delay_ms(3000);
						LCD_ClearScreen();
					}
					else if (data == '5')
					{
						DIO_SETPIN_DIRECTION(DIO_PORTC , DIO_PIN2 ,DIO_OUTPUT);
						DIO_SETPIN_VALUE(DIO_PORTC , DIO_PIN2 , DIO_LOW);
						LCD_Write_string("Heater Off");
						_delay_ms(3000);
						LCD_ClearScreen();
					}
					else if (data == '6')
					{
						DIO_SETPIN_DIRECTION(DIO_PORTC , DIO_PIN3 ,DIO_OUTPUT);
						DIO_SETPIN_VALUE(DIO_PORTC , DIO_PIN3 , DIO_HIGH);
						LCD_Write_string("AIR CONDITIONAL ON");
						_delay_ms(3000);
						LCD_ClearScreen();
					}
					
					else if (data == '7')
					{
						DIO_SETPIN_DIRECTION(DIO_PORTC , DIO_PIN3 ,DIO_OUTPUT);
						DIO_SETPIN_VALUE(DIO_PORTC , DIO_PIN3 , DIO_LOW);
						LCD_Write_string("AIR CONDITIONAL OFF");
						_delay_ms(3000);
						LCD_ClearScreen();
					}
					
					else if (data == '8')
					{
						DIO_SETPIN_DIRECTION(DIO_PORTC,DIO_PIN7,DIO_OUTPUT);
						DIO_TOGPIN_VALUE(DIO_PORTC,DIO_PIN7);
						LCD_Write_string("Bathroom TGL");
						_delay_ms(3000);
						LCD_ClearScreen();
					}
					else if ( data ==  '9')
					{
						DIO_SETPIN_DIRECTION(DIO_PORTC,DIO_PIN6,DIO_OUTPUT);
						DIO_TOGPIN_VALUE(DIO_PORTC,DIO_PIN6);
						LCD_Write_string("Kitchen TGL");
						_delay_ms(3000);
						LCD_ClearScreen();
					}
			break;
			case '3':
			data = UART_Received();
			if (data == '1')
			{
				
					LED1_TGL();
					LED0_TGL();
					DIO_TOGPIN_VALUE(DIO_PORTC,DIO_PIN6);
					DIO_TOGPIN_VALUE(DIO_PORTC,DIO_PIN7);
			}
			else if (data =='2')
			{
					uint16_t temp1 , temp2;
					temp1=First_LM35_read();
					temp2=Second_LM35_read();
					LCD_Write_Command(0X84);
					LCD_Write_Number(temp1/10);
					LCD_Write_Command(0XC0);
					LCD_Write_Number(temp2/10);
					_delay_ms(3000);
					LCD_ClearScreen();
			}
			else if (data == '3')
			{
				Motor_ON(clockwise, enable1);
				Motor_ON(clockwise, enable2);
				_delay_ms(3000);
				Motor_OFF(enable1);
				Motor_OFF(enable2);
			}
			else if (data == '4')
			{
				DIO_SETPIN_DIRECTION(DIO_PORTC , DIO_PIN2 ,DIO_OUTPUT);
				DIO_SETPIN_VALUE(DIO_PORTC , DIO_PIN2 , DIO_HIGH);	
			}
			else if (data == '5')
			{
				DIO_SETPIN_DIRECTION(DIO_PORTC , DIO_PIN2 ,DIO_OUTPUT);
				DIO_SETPIN_VALUE(DIO_PORTC , DIO_PIN2 , DIO_LOW);
			}
			else if (data == '6')
			{
				DIO_SETPIN_DIRECTION(DIO_PORTC , DIO_PIN3 ,DIO_OUTPUT);
				DIO_SETPIN_VALUE(DIO_PORTC , DIO_PIN3 , DIO_HIGH);
			}
			else if (data == '7')
			{
				DIO_SETPIN_DIRECTION(DIO_PORTC , DIO_PIN3 ,DIO_OUTPUT);
				DIO_SETPIN_VALUE(DIO_PORTC , DIO_PIN3 , DIO_LOW);
			}
			else if (data == '8')
			{
				DIO_SETPIN_DIRECTION(DIO_PORTC,DIO_PIN7,DIO_OUTPUT);
				DIO_TOGPIN_VALUE(DIO_PORTC,DIO_PIN7);
			}
			else if (data == '9')
			{
				DIO_SETPIN_DIRECTION(DIO_PORTC,DIO_PIN6,DIO_OUTPUT);
				DIO_TOGPIN_VALUE(DIO_PORTC,DIO_PIN6);
			}
			break;
		}
	}	
}
/****************************************************************************************************************/
/************************************************External_Interrupt_(ISR FUNCTION)*******************************/
ISR(INT0_vect)
{
	/*This Interrupt Is used For Emergency */
	BUZZER_ON();
	LED2_ON();
	_delay_ms(3000);
	LCD_Write_string("Emergency Alarm");
	DIO_SETPIN_DIRECTION(DIO_PORTD, DIO_PIN1 , DIO_INPUT);
	DIO_SETPIN_VALUE(DIO_PORTD,DIO_PIN0,DIO_LOW);
	DIO_SETPIN_VALUE(DIO_PORTD,DIO_PIN1,DIO_LOW);
}
ISR (INT1_vect)
{
		/*This Interrupt Is used For Dimmer Circuit to save Power */
	LED0_OFF();
	LED1_OFF();
	DIO_SETPIN_VALUE(DIO_PORTC,DIO_PIN6 , DIO_LOW);
	DIO_SETPIN_VALUE(DIO_PORTC,DIO_PIN7 , DIO_LOW);
}
/***Last Modified************Name**********Hour***************************************************************************************/
/*  12/28/2022               Mohanad Wael  6:23 */
/****************************************************************************************************************/



/*
  Names                          Emails 

Mohanad Wael Elsaeed            mbk000.000@gmail.com
Hossam Waleed Elsaeed           Hoswaleed88@gmail.com
Abdallah Gamal Assad            abdo.gego.2000@gmail.com
Zeyad Saad Gebril               Zeyadgebril176@gmail.com
Abdelrahmam abdelkhalek ali     engabdelrhman56@gmail.com
Mostafa Elhanash                hadaf231@gmail.com

*/