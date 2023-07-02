#ifndef BUZZER_BUZZER_H_
#define BUZZER_BUZZER_H_

#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include "../gpio.h"
#include "../std_types.h"

#define PORT_BUZZER_ID PORTA_ID
#define PIN_BUZZER_ID PIN1_ID

void buzzer_init();
void buzzer_turnOn();
void buzzer_turnOff();




#endif /* BUZZER_BUZZER_H_ */
