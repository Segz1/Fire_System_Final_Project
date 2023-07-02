#include "ADC.h"

void ADC_init(ADC_ConfigType* Config_ptr)
{
	/*DDRA=0x0;			// Make ADC port as input
	ADCSRA = 0x87;			// Enable ADC, fr/128  0b10000111
	ADMUX = 0x40;			// Vref: Avcc, ADC channel: 0 0b01000000 */

	DDRA = 0x0;  //ADC Port input

	switch(Config_ptr->ref_volt)
	{
		case AREF:
			ADMUX = 0x0; // Vref = AREF, ADC Channel 0
;			break;

		case AVCC:
			ADMUX = 0x40; //Vreg = AVCC, ADC Channel 0
			break;

		case Internal_2_56V:
			ADMUX = 0xC0; //Vref = Internal 2.56V, ADC Channel 0
			break;
	}

	switch(Config_ptr->prescalar)
	{
		case TWO:
			ADCSRA = 0x81; //ADC Enable, PreScalar = 2
			break;

		case FOUR:
			ADCSRA = 0x82; //ADC Enable. PreScalar = 4
			break;

		case EIGHT:
			ADCSRA = 0x83; //ADC Enable, PreScalar = 8
			break;

		case SIXTEEN:
			ADCSRA = 0x84; //ADC Enable, PreScalar = 16
			break;

		case THIRTY_TWO:
			ADCSRA = 0x85; //ADC Enable, PreScalar = 32
			break;

		case SIXTY_FOUR:
			ADCSRA = 0x86; //ADC Enable, PreScalar = 64
			break;

		case ONE_TWENTY_EIGHT:
			ADCSRA = 0x87; //ADC Enable, PreScalar = 128
			break;

	}

}

int ADC_Read(char channel)
{
	int Ain,AinLow;

	ADMUX=ADMUX|(channel & 0x0f);	/* Set input channel to read */ // 	1000 0000 | 0011 0010 & 0000 1111 = 10000010

	ADCSRA |= (1<<ADSC);		/* Start conversion */
	while((ADCSRA&(1<<ADIF))==0);	/* Monitor end of conversion interrupt */

	_delay_us(10);
	AinLow = (int)ADCL;		/* Read lower byte*/
	Ain = (int)ADCH*256;		/* Read higher 2 bits and
					Multiply with weight */
	Ain = Ain + AinLow;
	return(Ain);			/* Return digital value*/
}













