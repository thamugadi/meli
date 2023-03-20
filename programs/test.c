void program1(void) __attribute__((section(".ring3text_")));
void program1(void) __attribute__((naked));

void program1_main(void) __attribute__((section(".ring3text_")));

void program1(void)
{
	asm("mov ebp, esp");
	program1_main();
}
void program1_main(void)
{
        char buffer[0x10];
        brk_user_(3);
        scr_write_("Hello from PID 1.\n",18);

        asm("jmp $");
}
