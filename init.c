unsigned char  __attribute__((section(".ring3data"))) test_data[0x20] = "Hello from user mode!\n";
unsigned int __attribute__((section(".ring3bss"))) test_bss; 
unsigned char __attribute__((section(".ring3bss"))) buffer[0x100]; 

void user_test(void) __attribute__((section(".ring3text")));

// This is the first program to be runned in usermode.
void user_test(void)
{
        kbd_read(buffer, 12);
        scr_write("\nYou wrote:\n", 12);
	scr_write(buffer, 12);
	asm("jmp $");
}
