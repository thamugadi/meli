extern void user_test(void) __attribute__((section(".ring3")));

void main()
{
        free_vram();
        knextpage();

        kprint("Mel.\n", 10);
        kprint("Press any key to continue.\n\n", 13);
        
        read_keyboard();

        init_gdt();
        init_32bit_paging(0); // directory 0
	init_idt();
	init_pic();

	set_usermode(&user_test); // run our first usermode program.
	while(1);
}
