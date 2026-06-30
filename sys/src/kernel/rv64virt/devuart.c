#include <stdint.h>

uint8_t
inituart(uint8_t* uart)
{
	uart[1] = 0x00;	/* Disable interrupts (for now)*/
	uart[3] = 0x80;	/* Set clock speed */
	uart[0] = 0x03;
	uart[1] = 0x00;
	uart[3] = 0x03;
	uart[2] = 0xC7;
	uart[4] = 0x0B;
	uart[4] = 0x1E;
	uart[0] = 0xAE;
	
	/* Chekings is it faluty */
	if(uart[0] != 0xAE) {
		return 1;
	}

	uart[4] = 0x0F;
	return 0;
}

void
uartprint(uint8_t* uart, char* str)
{
	while (*str != '\0'){
		*uart = *str;
		str++;
	}
}