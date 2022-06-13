void main()
{
        free_vram();
        nextpage();

        print("Mel.\n", 10);
        print("Press any key to continue.\n\n", 13);
        
        read_keyboard();
        init_gdt();
        init_32bit_paging();
        __asm__("mov esp, 0x20000000");
        while(1);
}
