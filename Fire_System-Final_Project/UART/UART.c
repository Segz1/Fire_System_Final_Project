#include "UART.h"


void UART_init()
{
	GPIO_setupPinDirection(PORTUART_ID, RXD, PORT_INPUT);
	GPIO_setupPinDirection(PORTUART_ID, TXD, PORT_OUTPUT);
	//Sets up RXD as input pin and TXD as out put pin
	UCSRB |= (1 << RXEN);
	UCSRB |= (1 << TXEN);
	//Enables Receive and Transmit pins

	//UCSRC |= (1 << URSEL); //URSEL = 1, accessing UCSRC
	//UCSRC = 0xA6;   //10100110 ***** Even Parity | 1-bit Stop bit | 8-bit character size | Asynchronous

	UBRRH |= (0 << URSEL); //URSEL = 0, Accessing UBRR
	UBRRL = 51; //load 8 lower bits
	UBRRH |= (51 >> 8); //Load 8 upper bits
}

void UART_sendByte(uint8 data)
{
	while(!(UCSRA & (1 << UDRE))); // wait for empty transmit buffer
	UDR = data;
}

char UART_recieveByte()
{
	while(!(UCSRA & (1 << RXC))); //if Receive Interrupt complete = 1 the loop breaks
	return UDR;
}

void UART_sendString(uint8 str[])
{
	int i = 0;
	int size = 0;
	while(str[i] != '\0')
	{
		size++;
		i++;
	}
	UART_sendByte(size);
	i = 0;
	_delay_ms(100);

	while(str[i] != '\0')
	{
		UART_sendByte(str[i]);
		i++;
		_delay_ms(100);
	}
}

void UART_recieveString(uint8 str[])
{
	uint8 size = 0;
	size = UART_recieveByte();
	for(int i = 0; i < size; i++)
	{
		str[i] = UART_recieveByte();
	}
}

void UART_sendInteger(uint8 data)
{
	while(!(UCSRA & (1 << UDRE))); // wait for empty transmit buffer
	UDR = data;
}

uint8 UART_receiveInteger()
{
	while(!(UCSRA & (1 << RXC))); //if Receive Interrupt complete = 1 the loop breaks
	return UDR;
}








