#include <avr/io.h>

unsigned char twi_start(void);
void twi_stop(void);
void twi_write(char data);
char twi_read(void);
