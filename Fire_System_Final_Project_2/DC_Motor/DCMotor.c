#include "DCMotor.h"


void DCMotor_init()
{
	GPIO_setupPortDirection(PORTDCMOTOR_ID, PORT_OUTPUT);
	GPIO_writePort(PORTDCMOTOR_ID, 0);
}
void DCMotor_rotate(DCMotor_state state)
{
	GPIO_writePin(PORTDCMOTOR_ID, PINDCMOTOR_EN_ID, 1);
	//Activates the enable pin
	switch(state)
	{
		case stop:
			GPIO_writePin(PORTDCMOTOR_ID, PINDCMOTOR_IN1_ID, 0);
			GPIO_writePin(PORTDCMOTOR_ID, PINDCMOTOR_IN2_ID, 0);
			break;

		case CW:
			GPIO_writePin(PORTDCMOTOR_ID, PINDCMOTOR_IN1_ID, 1);
			GPIO_writePin(PORTDCMOTOR_ID, PINDCMOTOR_IN2_ID, 0);
			break;

		case ACW:
					GPIO_writePin(PORTDCMOTOR_ID, PINDCMOTOR_IN1_ID, 0);
					GPIO_writePin(PORTDCMOTOR_ID, PINDCMOTOR_IN2_ID, 1);
					break;
	}

}

