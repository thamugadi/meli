void sys_read(char* buf, int n)
{
	int i = 0;
	unsigned char r = read_keyboard();

	for (i = 0; i < n; i++)
	{
		if (r == 0x1C) break;
		buf[i] = k2ascii(r,0);
		putchar(buf[i], 13);
		r = read_keyboard();
	}
	buf[i]=0;
}

void sys_write(char* buf, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		kprint(&buf[i], 3);
}
