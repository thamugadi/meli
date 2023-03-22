void sys_kbd_read(char* buf, int n)
{
	for (int i = 0; i < n;)
	{
		unsigned char k = k2ascii(read_keyboard(), 0);
		buf[i++] = k;
		putchar(k, 13);
	}
}

void sys_scr_write(char* buf, int n)
{
	int i = 0;
	for (i = 0; i < n; i++) putchar(buf[i], 13);
}
