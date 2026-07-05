char*
dofmt(Fmt* f, char* fmt)
{
	uchar r;
	char buf[9];
	char* p_buf = buf;
	while(r = *uchar*(*uchar)fmt){
		if(r == '%'){
			fmt++;
			switch(*fmt){
				case 'd':
				int n = va_arg(f->arg, int);
				if(n < 0){
					*f->to = '-';
					n = ~n + 1;
				}
				while(n){
					*p_buf = '0' + n%10;
					n/=10;
					p_buf++;
				}
				while(p_buf != buf) {
					*f->to = *p_buf;
					p_buf--;
					*f->to++;
				}
				break;
			}
		}
		f->to++;
		fmt++;
	}
}
