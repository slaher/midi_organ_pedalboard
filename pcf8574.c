#include "pcf8574.h"
#include "twi.h"


void pcf8574_init (void)	//inicjalizacja transmisji PCF8574
{
	TWSR =0b00000000;
	TWBR = 0x02;
}


unsigned char pcf8574_send_add_rw(unsigned char address, unsigned char rw)		//uastawienia adresu PCF8574 i funkcji odczyt/zapis
{
	unsigned char addr_byte = 0;
	addr_byte = address << 1;
	addr_byte |= rw;
	addr_byte |= 0b01110000;
	TWDR = addr_byte;
	TWCR = (1<<TWINT) | (1<<TWEN);
	while (!(TWCR & (1<<TWINT)));
	return TWSR;
}


unsigned char pcf8574_get_inputs(unsigned char address)	//odczytywanie wartoœci z PCF8574
{
	pcf8574_init ();
	twi_start ();
	pcf8574_send_add_rw (address, 1);
	twi_read ();
	twi_stop ();
	return TWDR;
}


void pcf8574_set_outputs(unsigned char address, unsigned char byte)	//wysy³anie danych do PC8574
{
	pcf8574_init ();
	twi_start ();
	pcf8574_send_add_rw (address, 0);
	twi_write (byte);
	twi_stop ();
}