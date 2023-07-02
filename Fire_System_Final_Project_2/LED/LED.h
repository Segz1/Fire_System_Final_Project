#ifndef LED_LED_H_
#define LED_LED_H_

#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "../gpio.h"
#include "../std_types.h"


#define PORT_LED_ID PORTA_ID
#define PIN_LED_ID PIN0_ID


void LED_init();
void LED_turnOn();
void LED_turnOff();



#endif /* LED_LED_H_ */
