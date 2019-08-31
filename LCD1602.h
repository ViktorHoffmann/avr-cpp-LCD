#ifndef LCD1602
#define LCD1602

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define LCD_address_location		PORTB
#define LCD_DDR_location			DDRB
#define LCD_address_control			PORTD
#define LCD_DDR_control				DDRD
#define LCD_enable					5
#define LCD_R_W						7
#define LCD_RS						2

void LCD_state_check(void);
void LCD_state_poll(void);
void LCD_command(unsigned char command);
void LCD_char(unsigned char character);
void LCD_string(char *StringOfCharacters);
void LCD_coord(uint8_t x, uint8_t y);
void LCD_init(void);

#endif
