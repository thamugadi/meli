unsigned int  __attribute__((section(".ring3data"))) test_data = 11;
unsigned int __attribute__((section(".ring3bss"))) test_bss; 
void user_test(void) __attribute__((section(".ring3text")));

// This is the first program to be runned in usermode.

void user_test(void)
{
	test_data=1;
	char buf[0x40];
	read(buf, 8);
	asm("jmp $");
	asm volatile("mov ebx, %[buf]" :: [buf]"r"(buf));
        asm volatile("mov ecx, 8");
	asm volatile("xor eax, eax");
	asm volatile("int 0x30");
	asm("jmp $");
}
