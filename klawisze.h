#include "usart.h"
#include "pcf8574.h"
#include "lcdvtwi.h"
#include <stdio.h>
#include <stdlib.h>


void note_on(char nutka,char channel_number);
void note_off(char nutka, char channel_number);
unsigned long int skanowanie(void);
void change(void);
