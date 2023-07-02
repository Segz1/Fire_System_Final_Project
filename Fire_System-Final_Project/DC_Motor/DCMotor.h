#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "../gpio.h"
#include "../std_types.h"

typedef enum{stop, CW, ACW} DCMotor_state;

#define PORTDCMOTOR_ID PORTB_ID
#define PINDCMOTOR_IN1_ID PIN0_ID
#define PINDCMOTOR_IN2_ID PIN1_ID
#define PINDCMOTOR_EN_ID PIN2_ID

void DCMotor_init();
void DCMotor_rotate(DCMotor_state state);


#endif /* DC_MOTOR_DCMOTOR_H_ */
