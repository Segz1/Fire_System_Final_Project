#ifndef ADC_ADC_H_
#define ADC_ADC_H_

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "../gpio.h"
#include "../std_types.h"

typedef enum {AREF, AVCC, Internal_2_56V}ADC_Reference_Voltage;
typedef enum {TWO, FOUR, EIGHT,SIXTEEN, THIRTY_TWO, SIXTY_FOUR, ONE_TWENTY_EIGHT}ADC_Prescalar;

typedef struct
{
	ADC_Reference_Voltage ref_volt;
	ADC_Prescalar prescalar;
}ADC_ConfigType;


void ADC_init(ADC_ConfigType* Config_ptr);
/*
 * Initializes The ADC peripheral
*/

int ADC_Read(char channel);










#endif /* ADC_ADC_H_ */
