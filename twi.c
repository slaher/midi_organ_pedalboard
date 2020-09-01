#include "twi.h"


unsigned char twi_start(void)	// procedura transmisji sygna³u START
{
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
	return TWSR;	
}


void twi_stop(void)		// procedura transmisji sygna³u STOP
{
	TWCR = (1 << TWINT) | (0 << TWEN) | (1 << TWSTO);
}


void twi_write(char data)	// procedura transmisji bajtu danych
{
	TWDR = data;
	TWCR = (1 << TWINT) | (1 << TWEN);
	while (!(TWCR & (1 << TWINT)));
}


char twi_read(void)		//procedura odczytu bajtu danych
{
   TWCR = (1<<TWINT) | (1<<TWEA) | (1<<TWEN);
   while (!(TWCR & (1<<TWINT)));
   return TWDR;
}