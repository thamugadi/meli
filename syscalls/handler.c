void sys_read()
{
        register char* buf_ asm("ecx");
        register int n_ asm("edx");

	char* buf = buf_;
	int n = n_;

	int i = 0;
	unsigned char r = read_keyboard();
	while (r != 0x1C && i < n)
	{
		if (1)
		{
			buf[i] = k2ascii(r,0);
			kprint(&buf[i],13);
			r = read_keyboard();
			i++;
		}
	}
}

void sys_write()
{
	register char* buf_ asm("ecx");
	register int n_ asm("edx");

	char* buf = buf_;
	int n = n_;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		kprint(&buf[i], 3);
	}
}
