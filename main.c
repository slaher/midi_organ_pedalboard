
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "lcdvtwi.h"
#include "lcd.h"
#include "klawisze.h"
#include "twi.h"
#include "usart.h"
#include "pcf8574.h"
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/io.h>
#include <util/delay.h>
#include "przerwania.h"
   
		
volatile unsigned char zmienna;
volatile unsigned char n;
volatile unsigned char nutka;
volatile unsigned char temp=0;
volatile unsigned char receive=0;
		


int main(void)
{
	pcf8574_init (); //inicjalizacja PCF8574
		
	
	MCUCR|=(1<<ISC01)|(0<<ISC00)|(1<<ISC11)|(0<<ISC10); //ustawienia przerwañ
	GICR|=(1<<INT1)|(1<<INT0);
	InitUSART(31250);      // bitrate MIDI = 31250 bps
     
			
	lcdvtwi_init();		//wyœwietlenie komunikatu powitalnego
	lcdvtwi_clear(); 
	lcdvtwi_set_cursor(0, 0);
	lcdvtwi_write_text(" STEROWNIK MIDI");
	lcdvtwi_set_cursor(0, 1);
	lcdvtwi_write_text("  slawek_herok  ");
	
	TransmitUSART(channel_number+191);
	TransmitUSART(0x00);
	TransmitUSART(tone_number);
	
	_delay_ms(1300);
		
	LCD_tone(tone_number, channel_number);
	
	sei(); //odblokowanie przerawñ
	

\
	while(1)	//g³ówna pêtla programowa
	{
		change();
	}
		 
}



  
    
SIGNAL(SIG_UART_RECV)	//przerwanie od UART
{
	cli();
	receive=UDR;
	TransmitUSART(receive);
	sei();
}  

 
SIGNAL(SIG_INTERRUPT0)	//przerwanie INT0
{
	cli();
	pcf8574_get_inputs(1);	//odczyt PCF 1
	temp=~TWDR;
	przerwanie0(temp);
} 

  
SIGNAL(SIG_INTERRUPT1)
{
	cli();
	pcf8574_get_inputs(2);	//odczyt PCF 2
	temp=~TWDR;
	przerwanie1(temp);
} 


