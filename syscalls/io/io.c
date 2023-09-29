void sys_kbd_read(char* buf, int n)
{
	unsigned char k = 0xff;
	for (int i = 0; i < n; i++)
	{
		unsigned char read = read_keyboard();

		k = k2ascii(read, 0);
		buf[i] = k;
		putchar(k, 13);
	}
}

void sys_scr_write(char* buf, int n)
{
	int i = 0;
	for (i = 0; i < n; i++) putchar(buf[i], 13);
}
