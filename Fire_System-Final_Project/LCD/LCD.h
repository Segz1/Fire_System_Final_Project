#ifndef LCD_LCD_H_
#define LCD_LCD_H_

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "../gpio.h"
#include "../std_types.h"

#define LCD_Clear_Command  0x01
#define LCD_GoHome_Command 0x02
#define LCD_2Lines_8Bit_Command 0x38
#define LCD_2Lines_4Bit_Command 0x28
#define LCD_CursorOFF_Command 0x0C
#define LCD_CursorOn_Command 0x0E
#define LCD_CursortoLine1_Command 0x80
#define LCD_CursortoLine2_Command 0xC0
#define LCD_ShiftCursorLeft_Command 0x10
#define LCD_ShiftCursorRight_Command 0x14
#define LCD_ShiftDisplayLeft_Command 0x07
#define LCD_ShiftDisplayRight_Command 0x08


#define PORT_RS_ID PORTD_ID
#define PORT_DATA_ID PORTC_ID
#define PORT_EN_ID PORTD_ID

#define PIN_RS_ID PIN4_ID
#define PIN_EN_ID PIN5_ID







void LCD_init();
void LCD_sendCommand(uint8 command);
void LCD_clearScreen();
void LCD_moveCursor(uint8 row, uint8 col);
void LCD_displayCharacter(uint8 data);
void LCD_displayString(const char* Str);
void LCD_displayStringRowColumn(uint8 row, uint8 col, const char* Str);
void LCD_integerToString(int data);






#endif /* LCD_LCD_H_ */
