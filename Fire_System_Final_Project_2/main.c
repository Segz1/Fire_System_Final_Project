//Receiving uP
#include "UART\UART.h"
#include "LED\LED.h"
#include "buzzer\buzzer.h"
#include "LCD\LCD.h"
#include "DC_Motor\DCMotor.h"

int main()
{
	//Initialization of peripherals

	LED_init();
	buzzer_init();
	LCD_init();
	UART_init();
	DCMotor_init();

	int reset_flag = 1;
	int burning_flag = 0;
	int temp = 0;

	/*LCD_moveCursor(0, 2);
	LCD_displayString("FAN is OFF");
	LCD_moveCursor(1, 2);
	LCD_displayString("Temp = ");*/

	while(1)
	{
		temp = UART_receiveInteger();
		if(temp >= 60 && !burning_flag) //BURNING RESPONSE
		{
			//DISPLAY
			LCD_clearScreen();
			LCD_moveCursor(0, 2);
			LCD_displayString("7AREE2AA!");

			//LED ON
			LED_turnOn();
			//BUZZER ON
			//buzzer_turnOn();
			//FAN ON
			DCMotor_rotate(CW);

			//FLAGS
			reset_flag = 1;
			burning_flag = 1;
			continue;
		}

		if(temp >= 60)
		{
			continue;
		}

		if(reset_flag) //RESET RESPONSE
		{
			//DISPLAY
			LCD_clearScreen();
			LCD_moveCursor(0, 3);
			LCD_displayString("FAN is OFF");
			LCD_moveCursor(1, 2);
			LCD_displayString("Temp =");

			//LED
			LED_turnOff();
			///Buzzer
			buzzer_turnOff();
			//FAN
			DCMotor_rotate(stop);

			//flags reset
			reset_flag = 0;
			burning_flag = 0;
		}

		LCD_moveCursor(1, 9);
		LCD_integerToString(temp);
		LCD_displayString(" C");
	}




}
