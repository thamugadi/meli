#define DEBUG 1

extern void user_test(void) __attribute__((section(".ring3")));

void main()
{
        free_vram();
        knextpage();

        kprint("Mel.\n", 10);
        kprint("Press any key to continue.\n\n", 13);
        
        read_keyboard();

        init_gdt();

        map_kernel_directory(0); 
	init_user_data (0, 0x10000000, 1);
        init_user_code (0, 0x20000000, 1);
        init_user_stack(0, 0x28000000, 1);

	change_directory(0);
	
	enable_32bit_paging();

	init_idt();
	init_pic();
	
	set_usermode(&user_test); // run our first usermode program.
	
	while(1);
}
