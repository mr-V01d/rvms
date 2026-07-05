#include <stdint.h>
#include <stdarg.h>
#include "devuart.h"

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

void
uartprintf(uint8_t* uart, char* fmt,  ...)
{
	va_list args;
	va_start(args, fmt);

	char conv[] = "0123456789ABCDEF";
	while (*fmt) {
		if (*fmt != '%') {
			UARTPUTC(uart, *fmt);
		} else {
			fmt++;
			uint8_t base = 10;
			switch (*fmt) {
				case 'x':
					base = 16;
				case 'd':
				case 'i':
					int d = va_arg(args, int);
					if (d < 0) {
						UARTPUTC(uart, '-');
						d = ~d + 1;
					}
					if (d < base) {
						UARTPUTC(uart, conv[d]);
						break;
					}
					int t = base;
					while (d / t >= base) 
						t *= base;
					while (t > 0) {
						UARTPUTC(uart, conv[(d / t) % base]);
						t /= base;
					}				
				break;
				case '%':
					UARTPUTC(uart, '%');
				break;
			}
		}
		fmt++;
		va_end(args);
	}
}