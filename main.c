extern void init_gdt();
void main()
{
        free_vram();
        nextpage();


        print("Mel.\n", 10);
        print("Press any key to continue.\n\n", 13);
        read_wait();
        init_gdt();
        init_32bit_paging();
        while(1);
}