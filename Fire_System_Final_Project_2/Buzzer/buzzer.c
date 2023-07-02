#include "buzzer.h"

void buzzer_init()
{
	GPIO_setupPinDirection(PORT_BUZZER_ID, PIN_BUZZER_ID, PIN_OUTPUT);
	GPIO_writePort(PORT_BUZZER_ID, 0);
}

void buzzer_turnOn()
{
	GPIO_writePin(PORT_BUZZER_ID, PIN_BUZZER_ID, 1);
	_delay_ms(1);
}

void buzzer_turnOff()
{
	GPIO_writePin(PORT_BUZZER_ID, PIN_BUZZER_ID, 0);
	_delay_ms(1);
}
