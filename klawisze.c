#include "klawisze.h"


unsigned char tone_number;
unsigned char channel_number;
signed char key_number;
int i;
unsigned long int nr;
volatile unsigned long int aktualny_stan_klawiszy;	
unsigned long int nowy_stan_klawiszy;



static signed char numer_klawisza[] = {67,66,65,64,63,62,61,60, //tablica numerów klawiszy
										59,58,57,56,55,54,53,52,
										51,50,49,48,47,46,45,44,
										43,42,41,40,39,38,37,36};




void note_on(char nutka,char channel_number) //komunikat NOTE ON
	{
		 
		TransmitUSART(144+channel_number-1);
		TransmitUSART(nutka+key_number);
		TransmitUSART(0x40);		
	}


void note_off(char nutka, char channel_number) //komunikat NOTE OFF
	{
		
		TransmitUSART(127+channel_number);
		TransmitUSART(nutka+key_number);
		TransmitUSART(0x40);	
	}



unsigned long int skanowanie(void) //sprwdzanie stanu klawiszy
	{
		nr=0;
		

		for (i = 4; i < 8; i++) {
			PORTC &= ~(1<<i);
			nr = nr << 8;
			nr |= (PINA>>0) & 0xfF;  
			PORTC |= 0xf0;	
		}
		
		return nr;
	}



void change(void)
	{
		PORTA |= 0xFF;	
		PORTC |= 0xf0;	
		DDRC  |= 0xf0;

		nowy_stan_klawiszy = skanowanie();

		for (i = 0; i < 32; i++)
			{
			
				if ((nowy_stan_klawiszy & (unsigned long int)1<<i) != 
					(aktualny_stan_klawiszy & (unsigned long int)1<<i))	
					{
						aktualny_stan_klawiszy ^= (unsigned long int)1<<i;
						
						if (nowy_stan_klawiszy & (unsigned long int)1<<i)	
								note_off(numer_klawisza[i],channel_number);
						
					
						else
							note_on(numer_klawisza[i], channel_number);
								
					}
			}
	}

