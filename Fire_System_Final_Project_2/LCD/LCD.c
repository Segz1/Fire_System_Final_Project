#include "LCD.h"


void LCD_init()
{
	//port C is set to output for the data pins of the LCD
	GPIO_setupPortDirection(PORT_DATA_ID, PORT_OUTPUT);

	//PORT D is set to output for the RS and Enable pins of the LCD
	GPIO_setupPortDirection(PORT_RS_ID, PORT_OUTPUT);

	_delay_ms(20);

	LCD_sendCommand(LCD_2Lines_8Bit_Command);
	LCD_sendCommand(LCD_CursorOn_Command);
	LCD_clearScreen();
}

void LCD_sendCommand(uint8 command)
{
	GPIO_writePin(PORT_RS_ID, PIN_RS_ID, 0); //RS = 0, Command Register;
	_delay_ms(10);
	GPIO_writePin(PORT_EN_ID, PIN_EN_ID, 1); //Enable pulse = 1
	_delay_ms(10);
	GPIO_writePort(PORT_DATA_ID, command); //Command sent to data pins
	_delay_ms(10);
	GPIO_writePin(PORT_EN_ID, PIN_EN_ID, 0); //Enable = 0
}

void LCD_clearScreen()
{
	LCD_sendCommand(LCD_Clear_Command);
	_delay_ms(3);
}

void LCD_moveCursor(uint8 row, uint8 col)
{

	uint8 LCD_memory_address;

	switch(row)
	{
	case 0:
		LCD_memory_address = col;
		break;
	case 1:
		LCD_memory_address = col + 0x40;
		break;
	case 2:
		LCD_memory_address = col + 0x10;
		break;
	case 3:
		LCD_memory_address = col + 0x50;
		break;
	}

	LCD_sendCommand(LCD_memory_address | LCD_CursortoLine1_Command);
}

void LCD_displayCharacter(uint8 data)
{
	GPIO_writePin(PORT_RS_ID, PIN_RS_ID, 1); //RS = 1, Data register
	_delay_ms(10);
	GPIO_writePin(PORT_EN_ID, PIN_EN_ID, 1); //EN = 1
	_delay_ms(10);
	GPIO_writePort(PORT_DATA_ID, data); //Sends data to LCD to be displayed
	_delay_ms(10);
	GPIO_writePin(PORT_EN_ID, PIN_EN_ID, 0);
}

void LCD_displayString(const char *Str)
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
}


void LCD_displayStringRowColumn(uint8 row, uint8 col, const char* Str)
{
	LCD_moveCursor(row, col);
	LCD_displayString(Str);
}

void LCD_integerToString(int data)
{
	int len = 0 , num = data;
	int absolute = abs(data);
	static char ch[16];

	if(num == 0)
		len = 1;
	else
	{
	while(num != 0)
	{
		num /= 10;
		len++;
	}
	}

	num = absolute;

	for(int i = len - 1; i >= 0; i--)
	{
		num = absolute%10;
		absolute /= 10;
		ch[i] = num + '0';
	}
	ch[len] = '\0';
	//Turning the integer into string
	if(data >= 0)
		LCD_displayString(ch);
	else if(data < 0)
	{
		LCD_displayCharacter('-');
		LCD_displayString(ch);
	}
	//displays the new string
}


