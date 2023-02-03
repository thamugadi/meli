unsigned int  __attribute__((section(".ring3data"))) test_data = 11;
unsigned int __attribute__((section(".ring3bss"))) test_bss; 
void user_test(void) __attribute__((section(".ring3text")));
void read(char* buf, int n) __attribute__((section(".ring3text")));
void write(char* buf, int n) __attribute__((section(".ring3text")));

// This is the first program to be runned in usermode.

void user_test(void)
{
//	test_data=1;
//	char buf[0x40];
	asm("jmp $");
}

void read(char* buf, int n)
{
	asm("xor eax, eax");
	asm("pop ebx");
	asm("pop ecx");
	asm("jmp $");
        asm("int 0x30");
}

void write(char* buf, int n)
{
	asm("mov eax, 1");
	asm("pop ebx");
	asm("pop ecx");
	asm("jmp $");
        asm("int 0x30");
}
