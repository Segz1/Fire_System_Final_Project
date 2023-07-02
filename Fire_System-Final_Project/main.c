//Transmitting uP

#include "ADC\ADC.h"
#include "LCD\LCD.h"
#include "UART\UART.h"
#include "DC_Motor\DCMotor.h"

int Temp(int digitalValue)
{
	return ((digitalValue*150*2.56) /(1.5*1023)) * 2 - 1;
}

int main()
{
	ADC_ConfigType* ConfigType = {Internal_2_56V, EIGHT}; //ADC Vref = 2.56 internal, PreScalar = 8
	int digVal = 0;
	int temp = 0;

	UART_init();
	LCD_init();
	ADC_init(ConfigType);


	while(1)
	{
		digVal = ADC_Read(0);
		temp = Temp(digVal);
		UART_sendInteger(temp);
		_delay_ms(1000);
	}


}
