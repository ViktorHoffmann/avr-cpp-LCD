#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include "LCD1602.h"

int main(void)
{
	LCD_init();
	LCD_coord(8,1);
	_delay_ms(50);
	LCD_string("Test");
	_delay_ms(50);
	LCD_char(0x31);
	_delay_ms(50);
	while(1)
	{
	}
	LCD_command(0x01);
	_delay_ms(2);
}
