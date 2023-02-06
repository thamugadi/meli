unsigned char  __attribute__((section(".ring3data"))) test_data[0x20] = "Hello from user mode!\n";
unsigned int __attribute__((section(".ring3bss"))) test_bss; 
void user_test(void) __attribute__((section(".ring3text")));

// This is the first program to be runned in usermode.
// This way of loading is temporary.

void user_test(void)
{
	char buf[0x40];
	buf[0] = 'A';
	buf[1] = 'B';
	buf[2] = 'C';
	buf[3] = '\n';
	buf[4] = 0;
	write(&test_data, 32);
	asm("jmp $");
}
