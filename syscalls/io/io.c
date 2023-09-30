void sys_kbd_read(char* buf, int n)
{
	unsigned char read;
	unsigned char k = 0xff;
	int i;
	for (i = 0; i < n; i++)
	{
		if (i != n-1) read = read_keyboard(0);
		else read = read_keyboard(1);
		k = k2ascii(read, 0);
		buf[i] = k;
		putchar(k, 13);
	}
	buf[i] = 0;
	asm("leave");
	asm("ret");
}

void sys_scr_write(char* buf, int n)
{
	int i = 0;
	for (i = 0; i < n; i++) putchar(buf[i], 13);
}
