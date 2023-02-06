void sys_read(char* buf, int n)
{
	int i = 0;
	unsigned char r = read_wait();

	for (i = 0; i < n*2; i++)
	{
		if (r == 0x1C) break;
		buf[i] = k2ascii(r,0);
		putchar(buf[i], 13);
                r = read_wait();

	}
	buf[i]=0;
}

void sys_write(char* buf, int n)
{
	int i = 0;
	for (i = 0; i < n; i++) putchar(buf[i], 13);
}
