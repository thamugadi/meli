extern unsigned char current_key;

void sys_read(char* buf, int n)
{
	// Working on keyboard driver first.
}

void sys_write(char* buf, int n)
{
	int i = 0;
	for (i = 0; i < n; i++) putchar(buf[i], 13);
}
