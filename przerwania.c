#include "przerwania.h"

volatile unsigned char a=0;
volatile unsigned char b=0;
volatile unsigned char c=0;
volatile unsigned char tone_wsk=0;

char bufor[100];



void przerwanie0(unsigned char temp)	//obs³uga przerwania INT0; klawisze: 0, 1, 2, 3, 4, 5, 6, 7
{

switch(temp)
{ 	
	case 1: 
		temp=0;
		
		if(select==1)
			{
				tone_wsk++;
		
				if(tone_wsk==1)
					{
						a=temp;
						lcdvtwi_clear(); 
						itoa(temp,bufor,10);
						lcdvtwi_write_text("TONE: ");
						lcdvtwi_write_text(bufor);
						lcdvtwi_write_text("--");
						break;
					}
			
		
				if(tone_wsk==2)
					{
						b=temp;
						itoa(temp,bufor,10);
						lcdvtwi_set_cursor(7, 0);
						lcdvtwi_write_text(bufor);
						break;
					}
		
				if(tone_wsk==3)
					{
						tone_wsk=0;
						c=temp;
						itoa(temp,bufor,10);
						lcdvtwi_set_cursor(8, 0);
						lcdvtwi_write_text(bufor);
			
						tone_number=100*a+10*b+c;
						
						
  
	   TransmitUSART(channel_number+191);
		 TransmitUSART(0x00);
		  TransmitUSART(tone_number);   //wybór barwy
			
						break;
					}
			}
		
		break;
		
		
	case 2: 
		temp=1;
		
		if(select==1)
			{
				tone_wsk++;
					
				if(tone_wsk==1)
					{
						a=temp;
						lcdvtwi_clear(); 
						itoa(temp,bufor,10);
						lcdvtwi_write_text("TONE: ");
						lcdvtwi_write_text(bufor);
						lcdvtwi_write_text("--");
						break;
					}
			
		
				if(tone_wsk==2)
					{
						b=temp;
						itoa(temp,bufor,10);
						lcdvtwi_set_cursor(7, 0);
						lcdvtwi_write_text(bufor);
						break;
					}
		
				if(tone_wsk==3)
					{
						tone_wsk=0;
						c=temp;
						itoa(temp,bufor,10);
						lcdvtwi_set_cursor(8, 0);
						lcdvtwi_write_text(bufor);
						
						tone_number=100*a+10*b+c;
						
						

	   TransmitUSART(channel_number+191);
		 TransmitUSART(0x00);
		  TransmitUSART(tone_number);   //wybór barwy
			
						break;
					}
			}
		
		break;
		
		
	case 4: 
		temp=2;
		if(select==1)
		{
			tone_wsk++;
		
			if(tone_wsk==1)
			{
			tone_wsk--;
			break;
			}
			
		
		if(tone_wsk==2)
			{
			
			b=temp;
			itoa(temp,bufor,10);
			lcdvtwi_set_cursor(7, 0);
			lcdvtwi_write_text(bufor);
			break;
			}
		
		if(tone_wsk==3)
			{
			tone_wsk=0;
			c=temp;
			itoa(temp,bufor,10);
			lcdvtwi_set_cursor(8, 0);
			lcdvtwi_write_text(bufor);
			
			tone_number=100*a+10*b+c;
			
	   TransmitUSART(channel_number+191);
		 TransmitUSART(0x00);
		  TransmitUSART(tone_number);   //wybór barwy
			
			break;
			}
		}
		
	break;
	case 8: 
		temp=3;
			if(select==1)
		{
			tone_wsk++;
		
			if(tone_wsk==1)
			{
			tone_wsk--;
			break;
			}
			
		
		if(tone_wsk==2)
			{
			if(a==1)
			{
			tone_wsk--;
			break;
			}
			b=temp;
			itoa(temp,bufor,10);
			lcdvtwi_set_cursor(7, 0);
			lcdvtwi_write_text(bufor);
			break;
			}
		
		if(tone_wsk==3)
			{
			tone_wsk=0;
			c=temp;
			itoa(temp,bufor,10);
			lcdvtwi_set_cursor(8, 0);
			lcdvtwi_write_text(bufor);
			
			tone_number=100*a+10*b+c;
			
	   TransmitUSART(channel_number+191);
		 TransmitUSART(0x00);
		  TransmitUSART(tone_number);   //wybór barwy
			
			break;
			}
		}
		
	break;
	case 16: 
		temp=4;
  if(select==1)
		{
			tone_wsk++;
		
			if(tone_wsk==1)
			{
			tone_wsk--;
			break;
			}
			
		if(tone_wsk==2)
			{
			if(a==1)
			{
			tone_wsk--;
			break;
			}
			b=temp;
			itoa(temp,bufor,10);
			lcdvtwi_set_cursor(7, 0);
			lcdvtwi_write_text(bufor);
			break;
			}
		
		if(tone_wsk==3)
			{
			tone_wsk=0;
			c=temp;
			itoa(temp,bufor,10);
			lcdvtwi_set_cursor(8, 0);
			lcdvtwi_write_text(bufor);
			
			tone_number=100*a+10*b+c;
			
	   TransmitUSART(channel_number+191);
		 TransmitUSART(0x00);
		  TransmitUSART(tone_number);   //wybór barwy
			
			break;
			}
		}
		
	break;
	
	case 32: 
		temp=5;
			if(select==1)
		{
			tone_wsk++;
		
			if(tone_wsk==1)
			{
			tone_wsk--;
			break;
			}
			
		
		if(tone_wsk==2)
			{
			if(a==1)
			{
			tone_wsk--;
			break;
			}
			b=temp;
			itoa(temp,bufor,10);
			lcdvtwi_set_cursor(7, 0);
			lcdvtwi_write_text(bufor);
			break;
			}
		
		if(tone_wsk==3)
			{
			tone_wsk=0;
			c=temp;
			itoa(temp,bufor,10);
			lcdvtwi_set_cursor(8, 0);
			lcdvtwi_write_text(bufor);
			
			tone_number=100*a+10*b+c;
			
	   TransmitUSART(channel_number+191);
		 TransmitUSART(0x00);
		  TransmitUSART(tone_number);   //wybór barwy
			
			break;
			}
		}
		
	break;
	
	case 64: 
	temp=6;
		if(select==1)
		{
			tone_wsk++;
		
			if(tone_wsk==1)
			{
			tone_wsk--;
			break;
			}
			
		
		if(tone_wsk==2)
			{
			if(a==1)
			{
			tone_wsk--;
			break;
			}
			b=temp;
			itoa(temp,bufor,10);
			lcdvtwi_set_cursor(7, 0);
			lcdvtwi_write_text(bufor);
			break;
			}
		
		if(tone_wsk==3)
			{
			tone_wsk=0;
			c=temp;
			itoa(temp,bufor,10);
			lcdvtwi_set_cursor(8, 0);
			lcdvtwi_write_text(bufor);
			
			tone_number=100*a+10*b+c;
			
	   TransmitUSART(channel_number+191);
		 TransmitUSART(0x00);
		  TransmitUSART(tone_number);   //wybór barwy
			
			break;
			}
		}
		
	break;
	case 128: 
		temp=7;
		if(select==1)
		{
			tone_wsk++;
		
			if(tone_wsk==1)
			{
			tone_wsk--;
			break;
			}
			
		
		if(tone_wsk==2)
			{
			if(a==1)
			{
			tone_wsk--;
			break;
			}
			b=temp;
			itoa(temp,bufor,10);
			lcdvtwi_set_cursor(7, 0);
			lcdvtwi_write_text(bufor);
			
			
			break;
			}
		
		if(tone_wsk==3)
			{
			tone_wsk=0;
			c=temp;
			itoa(temp,bufor,10);
			lcdvtwi_set_cursor(8, 0);
			lcdvtwi_write_text(bufor);
			
			tone_number=100*a+10*b+c;
			
	   TransmitUSART(channel_number+191);
		 TransmitUSART(0x00);
		  TransmitUSART(tone_number);   //wybór barwy
			
			break;
			}
		}
		
	break;
	default: 
		break;
	}
	
_delay_ms(200);
		
	pcf8574_set_outputs (1, 0xff);
	pcf8574_set_outputs (2, 0xff);
	GIFR|=1<<INTF0;
	sei();
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
void przerwanie1(unsigned char temp)	////obs³uga przerwania INT1; klawisze: +, -, A, B, C, D, 8, 9
{
	switch(temp)
{ 	
	case 1: 
	tone_wsk=0;
		if(select==1)
		{
			
			
		if(tone_number<127)
			tone_number++;
			lcdvtwi_clear(); 
			
			itoa(tone_number,bufor,10);
			lcdvtwi_write_text("TONE: ");
			if(tone_number<100)
				lcdvtwi_write_text("0");
				if(tone_number<10)
				lcdvtwi_write_text("0");
			lcdvtwi_write_text(bufor);

	   TransmitUSART(channel_number+191);
		 TransmitUSART(0x00);
		  TransmitUSART(tone_number); 
			break;
		}
		
	
		if(select==2)
		{
		TransmitUSART(175+channel_number);   
		TransmitUSART(123);
		TransmitUSART(0);
			if(channel_number<16)
			channel_number++;
			lcdvtwi_clear(); 
			
			itoa(channel_number,bufor,10);
			lcdvtwi_write_text("CHANNEL: ");
			lcdvtwi_write_text(bufor);
			break;
		}
		
				
		if(select==3)
		
		{
		TransmitUSART(175+channel_number);   
		TransmitUSART(123);
		TransmitUSART(0);
			if(key_number<12)
			key_number++;
			lcdvtwi_clear(); 
			
			itoa(key_number,bufor,10);
			lcdvtwi_write_text("KEY: ");
			lcdvtwi_write_text(bufor);
			break;
		}
		
		
		
	case 2: 
	tone_wsk=0;
		if(select==1)
		{
			if(tone_number>0)
			tone_number--;
			lcdvtwi_clear(); 
			
			itoa(tone_number,bufor,10);
			lcdvtwi_write_text("TONE: ");
			if(tone_number<100)
				lcdvtwi_write_text("0");
				if(tone_number<10)
				lcdvtwi_write_text("0");
			lcdvtwi_write_text(bufor);
			
	   TransmitUSART(channel_number+191);
		 TransmitUSART(0x00);
		  TransmitUSART(tone_number);   
			
			break;
		}
		
		
		
		if(select==2)
		{
		TransmitUSART(175+channel_number);   
		TransmitUSART(123);
		TransmitUSART(0);
			if(channel_number>1)
			channel_number--;
			lcdvtwi_clear(); 
			
			itoa(channel_number,bufor,10);
			lcdvtwi_write_text("CHANNEL: ");
			lcdvtwi_write_text(bufor);
			break;
		}
		
		
		
		if(select==3)
		{
		TransmitUSART(175+channel_number);   
		TransmitUSART(123);
		TransmitUSART(0);
			if(key_number>-12)
			key_number--;
			lcdvtwi_clear(); 
			
			itoa(key_number,bufor,10);
			lcdvtwi_write_text("KEY: ");
			lcdvtwi_write_text(bufor);
			break;
		}
		
		
		
	case 4: 
	tone_wsk=0;
		LCD_tone(tone_number,channel_number);
		break;
	case 8: 
	tone_wsk=0;
		LCD_channel(channel_number);
		break;
		
	case 16: 
	tone_wsk=0;
		LCD_key(key_number);
  
		break;
	case 32: 
		temp=60;
		break;
	case 64: 
		temp=8;
		if(select==1)
		{
			tone_wsk++;
		
			if(tone_wsk==1)
			{
			tone_wsk--;
			break;
			}
			
		
	if(tone_wsk==2)
			{
			if(a==1)
			{
			tone_wsk--;
			break;
			}
			b=temp;
			itoa(temp,bufor,10);
			lcdvtwi_set_cursor(7, 0);
			lcdvtwi_write_text(bufor);
			break;
			}
		
		if(tone_wsk==3)
			{
			if(a==1)
			{
			if(b>1)
			{
			tone_wsk--;
			break;
			}
			}
			tone_wsk=0;
			c=temp;
			itoa(temp,bufor,10);
			lcdvtwi_set_cursor(8, 0);
			lcdvtwi_write_text(bufor);
			
			tone_number=100*a+10*b+c;
			
			
	   TransmitUSART(channel_number+191);
		 TransmitUSART(0x00);
		  TransmitUSART(tone_number);   
			break;
			}
		}
		
	break;
	case 128: 
		temp=9;
		if(select==1)
		{
			tone_wsk++;
		
			if(tone_wsk==1)
			{
			tone_wsk--;
			break;
			}
			
		
		if(tone_wsk==2)
			{
			if(a==1)
			{
			tone_wsk--;
			break;
			}
			b=temp;
			itoa(temp,bufor,10);
			lcdvtwi_set_cursor(7, 0);
			lcdvtwi_write_text(bufor);
			

			
			break;
			}
		
		if(tone_wsk==3)
			{
			if(a==1)
			{
		
			if(b>1)
			{tone_wsk--;
			break;
			}
			}
			tone_wsk=0;
			c=temp;
			itoa(temp,bufor,10);
			lcdvtwi_set_cursor(8, 0);
			lcdvtwi_write_text(bufor);
			
			tone_number=100*a+10*b+c;
			
			

	   TransmitUSART(channel_number+191);
		 TransmitUSART(0x00);
		  TransmitUSART(tone_number);  
			
			break;
			}
		}
		
	break;
	default: 
		break;
	}
	_delay_ms(200);
	pcf8574_set_outputs (1, 0xff);
	pcf8574_set_outputs (2, 0xff);
	GIFR|=1<<INTF1;
	sei();
  }
	
	
	
	
	
	
	