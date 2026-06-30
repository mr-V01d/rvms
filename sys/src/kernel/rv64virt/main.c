#include <stdint.h>
#include "devuart.h"
#include "mem.h"

char test;

void
main(void)
{
	inituart((uint8_t*)UARTADDR);
	uartprint((uint8_t*)UARTADDR, "KERNEL ONLINE\n\r");
	char c;
	for(;;){
		c = UARTGETC((uint8_t*)UARTADDR);
		if(c == '\r') {
			UARTPUTC((uint8_t*)UARTADDR, '\n');
			UARTPUTC((uint8_t*)UARTADDR, '\r');
		} else {
			UARTPUTC((uint8_t*)UARTADDR, c);
		}
	}
}