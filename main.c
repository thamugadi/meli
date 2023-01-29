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

        map_directory(0, DEBUG); 
			    
	change_directory(0);
	
	enable_32bit_paging();
	init_idt();
	init_pic();
	set_usermode(&user_test); // run our first usermode program.
	while(1);
}
