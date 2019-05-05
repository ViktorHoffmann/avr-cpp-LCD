#include <avr/io.h>
#include <util/delay.h>
#include "MrLCD.h"

int main(void)
{
	initializeMrLCD();
	GotoMrLCDsLocation(8,1);
	_delay_ms(50);
	Send_A_String("Test");
	_delay_ms(50);
	Send_A_Character(0x31);
	_delay_ms(50);
	while(1)
	{
	}
	Send_A_Command(0x01);
	_delay_ms(2);
}
