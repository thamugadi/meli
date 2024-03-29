int current_pid = 0;
extern char scheduling;
extern void user_test(void) __attribute__((section(".ring3text")));
#define DATA  0x40
#define CODE  0x80
#define STACK 0xa0

#define KERNEL 3
#define USER   7 
extern char processes[16];
void main()
{
        free_vram();
        knextpage();

        kprint("Mel.\n", 10);
        kprint("Press any key to continue.\n\n", 13);
        
        read_keyboard();

        init_gdt();

	init_idt();
	init_pic();

        init_memory(0, 0x00, 0x00000000, 0x10000, KERNEL); 

	change_directory(0);
	enable_32bit_paging();

	new_process(0x10000000, 0x10001000, 0x10002000, 1, 1, 1);

	set_usermode(0x20000000, 0x28000000, 0x1000); // run our first usermode program.
	
	while(1);
}
