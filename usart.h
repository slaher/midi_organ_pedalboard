#include <avr/io.h>
#include <util/delay.h>
#define CLOCK 1000000 
#define CYCLES_PER_US ((CLOCK+500000)/1000000)       // cpu cykli na mikrosekunde


void InitUSART( unsigned long int baud );
void TransmitUSART( unsigned char data );
unsigned char USART_received(void);