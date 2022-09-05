void main()
{
        free_vram();
        nextpage();

        print("Mel.\n", 10);
        print("Press any key to continue.\n\n", 13);
        
        read_keyboard();

        init_gdt();
        init_32bit_paging();
	init_idt();
	init_pic();
        while(1);
}
