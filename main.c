extern void user_test(void) __attribute__((section(".ring3")));
#define DATA  0x40
#define CODE  0x80
#define STACK 0xa0

#define KERNEL 3
#define USER   7 
void main()
{
        free_vram();
        knextpage();

        kprint("Mel.\n", 10);
        kprint("Press any key to continue.\n\n", 13);
        
        read_keyboard();

        init_gdt();

	init_memory(0, 0x00,  0x00000000, 0x400000, KERNEL); 
	
	init_memory(0, DATA,  0x10000000, 1, USER);
        init_memory(0, CODE,  0x20000000, 1, USER);
        init_memory(0, STACK, 0x28000000, 1, USER);
	change_directory(0);

	enable_32bit_paging();

	init_idt();
	init_pic();
	
	set_usermode(&user_test); // run our first usermode program.
	
	while(1);
}
