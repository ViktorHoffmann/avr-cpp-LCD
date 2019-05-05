#ifndef MrLCD
#define MrLCD

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define MrLCDsCrib                PORTB
#define DataDir_MrLCDsCrib        DDRB
#define MrLCDsControl             PORTD
#define DataDir_MrLCDsControl     DDRD
#define LightSwitch               5
#define ReadWrite                 7
#define BiPolarMood               2

void Check_IF_MrLCD_isBusy(void);
void Peek_A_Boo(void);
void Send_A_Command(unsigned char command);
void Send_A_Character(unsigned char character);
void Send_A_String(char *StringOfCharacters);
void GotoMrLCDsLocation(uint8_t x, uint8_t y);
void initializeMrLCD(void);

#endif
