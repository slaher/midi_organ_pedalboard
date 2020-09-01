#include "lcd.h"

unsigned char tone_number=19;
unsigned char channel_number=2;
signed char key_number=0;
unsigned char select=1;
char bufor[100];


void LCD_tone(char tone_number, char channel_number)	//poprogram wyœwietlaj¹cy numer barwy tonu
{
	select=1;
	
	pcf8574_set_outputs (1, 0xff);
	pcf8574_set_outputs (2, 0xff);
   
    lcdvtwi_clear(); 
	lcdvtwi_set_cursor(0, 0);
	lcdvtwi_write_text("TONE: ");
	
	if(tone_number<100)
		lcdvtwi_write_text("0");
	
	if(tone_number<10)
		lcdvtwi_write_text("0");

	itoa(tone_number,bufor,10);
	lcdvtwi_write_text(bufor);
			
	TransmitUSART(channel_number+191);
	TransmitUSART(0x00);
	TransmitUSART(tone_number);   
}



void LCD_channel(char channel_number)	//poprogram wyœwietlaj¹cy numer kana³u
{
	select=2;
	
	pcf8574_set_outputs (1, 0xff);
	pcf8574_set_outputs (2, 0xff);
   
	lcdvtwi_clear(); 
	lcdvtwi_set_cursor(0, 0);
	lcdvtwi_write_text("CHANNEL: ");
	itoa(channel_number,bufor,10);
	lcdvtwi_write_text(bufor);
}
	


void LCD_key(signed char key_number)	//poprogram wyœwietlaj¹cy wysokoœæ transpozycji
{
	select=3;
	
	pcf8574_set_outputs (1, 0xff);
	pcf8574_set_outputs (2, 0xff);
   
   	lcdvtwi_clear(); 
	lcdvtwi_set_cursor(0, 0);
	lcdvtwi_write_text("KEY: ");
	itoa(key_number,bufor,10);
	lcdvtwi_write_text(bufor);
}