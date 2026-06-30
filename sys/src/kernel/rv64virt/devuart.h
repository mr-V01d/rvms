void inituart(uint8_t*);
void uartprint(uint8_t*, char*);
#define UARTPUTC(addr, c)(*addr=(char)c)
#define UARTGETC(addr)((char)*addr)