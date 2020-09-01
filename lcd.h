#include "usart.h"
#include "pcf8574.h"
#include "lcdvtwi.h"
#include <stdio.h>
#include <avr/interrupt.h>
#include <stdlib.h>


extern unsigned char select;
extern unsigned char tone_number;
extern unsigned char channel_number;
extern signed char key_number;

void LCD_tone(char tone_number, char channel_number);
void LCD_channel(char channel_number);
void LCD_key(signed char key_number);