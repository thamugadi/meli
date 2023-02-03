void sys_read(char* buf, int n)
{
	int i = 0;
	asm("jmp $");
	// Will be removed:
	unsigned char r = read_keyboard();
	while (r != 0x1C && i < n)
	{
		if (r)
		{
			buf[i] = k2ascii(r,0);
			kprint(&buf[i],13);
			r = read_keyboard();
			i++;
		}
	}
	buf[i]=0;
}

void sys_write(char* buf, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		kprint(&buf[i], 3);
}
