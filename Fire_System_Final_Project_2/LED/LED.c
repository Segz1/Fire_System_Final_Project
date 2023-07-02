#include "LED.h"

void LED_init()
{
	GPIO_setupPinDirection(PORT_LED_ID, PIN_LED_ID, PIN_OUTPUT);
	GPIO_writePin(PORT_LED_ID, PIN_LED_ID, 0);
}

void LED_turnOn()
{
	GPIO_writePin(PORT_LED_ID, PIN_LED_ID, 1);
	_delay_ms(1);
}

void LED_turnOff()
{
	GPIO_writePin(PORT_LED_ID, PIN_LED_ID, 0);
	_delay_ms(1);
}

