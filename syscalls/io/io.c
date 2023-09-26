void sys_kbd_read(char* buf, int n)
{
	unsigned char k = 0xff;
	for (int i = 0; i < n; i++)
	{
		unsigned char read;
        	do 
        	{
                	read = input(0x64);
        	} 
        	while (!(read & 1));
        	do
		{
			read = input(0x60);
		}
		while((read & 0x80));

		if (read == 0x36 || read == 0x1C)
		{
			break;
		}

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
