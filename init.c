unsigned char  __attribute__((section(".ring3data"))) test_data[0x20] = "Hello from user mode!\n";
unsigned int __attribute__((section(".ring3bss"))) test_bss; 
//unsigned char __attribute__((section(".ring3bss"))) buffer[0x100]; 



void user_test(void) __attribute__((section(".ring3text")));
void user_test(void) __attribute__((naked));

void func(void) __attribute__((section(".ring3text")));

void user_test(void)
{
	asm("mov ebp, esp");
	func();
}

void func(void)
{
	asm("mov eax, 0xdead1");
	asm("mov ebx, 0xdead2");
	asm("mov ecx, 0xdead3");
	asm("mov edx, 0xdead4");
	asm("mov edi, 0xdead5");
	asm("mov esi, 0xdead6");

	asm("mov ebp, 0xdead7");
	asm("mov esp, 0xdead8");

/*        char buffer[0x10];
	brk_user(3);
        kbd_read(buffer, 12);
        scr_write("\nYou wrote:\n", 12);
        scr_write(buffer, 12);
*/
	asm("jmp $");
}
