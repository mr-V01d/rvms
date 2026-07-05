#include <stdint.h>
#include "devuart.h"
#include "mem.h"

char test;

void
main(void)
{
	inituart((uint8_t*)UARTADDR);
	uartprint((uint8_t*)UARTADDR, "KERNEL ONLINE\n\r");
	uartprint((uint8_t*)UARTADDR, "Formated print test\n\r");
	for (uint8_t i = 0; i < 255; i++) {
		uartprintf((uint8_t*)UARTADDR, "DEC: %d\tHEX: %x\n\r", i, i);
	}
	for (;;)
		;
}