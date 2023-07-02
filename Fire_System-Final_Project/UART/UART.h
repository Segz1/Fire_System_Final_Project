#ifndef UART_UART_H_
#define UART_UART_H_


#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "../gpio.h"
#include "../std_types.h"

//#define F_CPU 1000000
#define UART_BAUD_RATE 14400
#define BAUD_Prescale (F_CPU/(8*UART_BAUD_RATE)) - 1

#define PORTUART_ID PORTD_ID
#define RXD PIN0_ID
#define TXD PIN1_ID




//functions
void UART_init();
void UART_sendByte(uint8 data);
char UART_recieveByte();
void UART_sendString(uint8* str);
void UART_recieveString(uint8 str[]);
void UART_sendInteger(uint8 data);
uint8 UART_receiveInteger();




#endif /* UART_UART_H_ */
