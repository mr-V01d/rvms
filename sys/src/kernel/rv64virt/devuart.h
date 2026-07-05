uint8_t inituart(uint8_t*);
void uartprint(uint8_t*, char*);
void uartprintf(uint8_t*, char*, ...);
#define UARTPUTC(addr, c)(*(char*)addr =c)
#define UARTGETC(addr)(*(char*)addr)