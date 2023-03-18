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
        char buffer[0x10];
	brk_user(3);
        kbd_read(buffer, 12);
        scr_write("\nYou wrote:\n", 12);
        scr_write(buffer, 12);

	asm("jmp $");
}
