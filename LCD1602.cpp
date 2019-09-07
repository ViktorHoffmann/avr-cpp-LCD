#include "LCD1602.h"

void LCD_state_check()
{
	LCD_DDR_location = 0;
	LCD_address_control |= 1<<LCD_R_W;
	LCD_address_control &= ~1<<LCD_RS;

	while (LCD_address_location >= 0x80)
	{
		LCD_state_poll();
	}
	LCD_DDR_location = 0xFF;
}

void LCD_state_poll()
{
	LCD_address_control |= 1<<LCD_enable;
	asm volatile ("nop");
	asm volatile ("nop");
	LCD_address_control &= ~1<<LCD_enable;
}

void LCD_command(unsigned char command)
{
	LCD_state_check();
	LCD_address_location = command;
	LCD_address_control &= ~ ((1<<LCD_R_W)|(1<<LCD_RS));
	LCD_state_poll();
	LCD_address_location = 0;
}

void LCD_char(unsigned char character)
{
	LCD_state_check();
	LCD_address_location = character;
	LCD_address_control &= ~ (1<<LCD_R_W);
	LCD_address_control |= 1<<LCD_RS;
	LCD_state_poll();
	LCD_address_location = 0;
}

void LCD_string(char *StringOfCharacters)
{
	while(*StringOfCharacters > 0)
	{
		LCD_char(*StringOfCharacters++);
	}
}

char firstColumnPositionForMrLCD[2] = {0, 64};	//For use with a 16x04 LCD change to [...] "[4] = {0, 64, 20, 84};"

void LCD_coord(uint8_t x, uint8_t y)
{
	LCD_command(0x80 + firstColumnPositionForMrLCD[y-1] + (x-1));
}

void LCD_init()
{
	LCD_DDR_control |= 1<<LCD_enable | 1<<LCD_R_W | 1<<LCD_RS;
	_delay_ms(15);

	LCD_command(0x01);
	_delay_ms(2);
	LCD_command(0x38);
	_delay_us(50);
	LCD_command(0b00001110);
	_delay_us(50);
}
