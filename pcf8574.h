#include <util/delay.h>
#include <avr/io.h>

void pcf8574_init(void);
unsigned char pcf8574_send_add_rw (unsigned char, unsigned char);
unsigned char pcf8574_get_inputs (unsigned char );
void pcf8574_set_outputs (unsigned char , unsigned char);
