#include <avr/io.h>
#include <util/delay.h>
#include "MrLCD.h"

int main(void)
{
	initializeMrLCD();
	
	DDRC &= ~(1<<PINC0);
	PORTC |= 1<<PINC0;
	
	char positionString [4];
	
	while(1)
	{		
		while(bit_is_clear(PINC,0))
		{
			for (int y = 1; y <= 2; y++)
			{
				for (int x = 1; x <= 16; x++)
				{
					
					itoa(x, positionString, 10);
					GotoMrLCDsLocation(8, 1);
					Send_A_String("X = ");
					Send_A_String(positionString);
					
					itoa(y, positionString, 10);
					GotoMrLCDsLocation(8, 2);
					Send_A_String("Y = ");
					Send_A_String(positionString);
					
					GotoMrLCDsLocation(x, y);
					Send_A_String("x");
					
					_delay_ms(200);
					
					GotoMrLCDsLocation(x, y);
					Send_A_String(" ");
					
					itoa(x, positionString, 10);
					GotoMrLCDsLocation(8, 1);
					Send_A_String("      ");
					
					itoa(y, positionString, 10);
					GotoMrLCDsLocation(8, 2);
					Send_A_String("      ");
				}
			}
		}
		
		while(bit_is_set(PINC,0))
		{
			for (int y = 1; y <= 2; y++)
			{
				for (int x = 1; x <= 16; x++)
				{
					
					itoa(x, positionString, 10);
					GotoMrLCDsLocation(8, 1);
					Send_A_String("X = ");
					Send_A_String(positionString);
					
					itoa(y, positionString, 10);
					GotoMrLCDsLocation(8, 2);
					Send_A_String("Y = ");
					Send_A_String(positionString);
					
					GotoMrLCDsLocation(x, y);
					Send_A_String("x");
					
					_delay_ms(500);
					
					GotoMrLCDsLocation(x, y);
					Send_A_String(" ");
					
					itoa(x, positionString, 10);
					GotoMrLCDsLocation(8, 1);
					Send_A_String("      ");
					
					itoa(y, positionString, 10);
					GotoMrLCDsLocation(8, 2);
					Send_A_String("      ");
				}
			}
		}
		Send_A_Command(0x01);
		_delay_ms(2);
	}
}
