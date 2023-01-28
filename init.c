void user_test(void) __attribute__((section(".ring3")));

// This is the first program to be runned in usermode.

void user_test(void)
{
	write(2, 30);
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
