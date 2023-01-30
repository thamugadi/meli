unsigned int  __attribute__((section(".ring3data"))) test_data = 11;
unsigned int __attribute__((section(".ring3bss"))) test_bss; 
void user_test(void) __attribute__((section(".ring3text")));

// This is the first program to be runned in usermode.

void user_test(void)
{
	test_data=1;
	asm("jmp $");
	char buf[0x40];
	asm("jmp $");
}

void read(char* buf, int n)
{
        register int edi asm("edi") = 0;
        register char* buf_ asm("ecx") = buf;
        register char* n_ asm("edx") = n;
        asm("int 0x30");
}

void write(char* buf, int n)
{
        register int edi asm("edi") = 1;
        register char* buf_ asm("ecx") = buf;
        register char* n_ asm("edx") = n;
        asm("int 0x30");
}
