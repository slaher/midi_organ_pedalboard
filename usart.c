#include "usart.h"


void InitUSART( unsigned long int baud )	//inicjalizacja USART
{
	UBRRH = (unsigned char)(((CLOCK/(16UL*baud))-1)>>8);
	UBRRL = (unsigned char)((CLOCK/(16UL*baud))-1);
	UCSRB = (1<<RXEN)|(1<<TXEN)|(1<<RXC);      
	UCSRA=0; 
	UCSRC = (1<<URSEL)|(1<<USBS)|(1<<UCSZ1)|(1<<UCSZ0); // 8 bitów, 1 bit stopu
}


void TransmitUSART( unsigned char data )	//funkcja wysy³aj¹ca dane
{
   while ( !( UCSRA & (1<<UDRE)) );
   UDR = data;
}


unsigned char USART_received(void)
{
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}