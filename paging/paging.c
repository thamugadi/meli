extern void set_32bit_cr3(unsigned int cr3_phdr); 
extern void enable_32bit_paging();

unsigned int page_directories[16][1024]; 
unsigned int page_tables[16][1024][1024];

void map_table(int dir, unsigned int paddr, unsigned int vaddr, int flags)
{
        unsigned int directory_e = vaddr >> 22;
        unsigned int page = (paddr/0x00400000);
        unsigned int i;
        for (i = 0; i < 1024; i++)
        {
                page_tables[dir][directory_e][i] = ((page*1024 + i)*0x1000) | flags;
        }
        page_directories[dir][directory_e] = (unsigned int)page_tables[dir][directory_e] | flags;
}

void map_tables(int dir, unsigned int paddr, unsigned int vaddr, int flags, int n)
{
        int i;
        for (i = 0; i < n; i++)
        {
                map_table(dir, paddr+(i*0x400000), vaddr+(i*0x400000), flags);
        }
}
#define map_user_tables(dir, paddr, vaddr, n) map_tables(dir, paddr, vaddr, 7, n)
#define map_kernel_tables(dir, paddr, vaddr, n) map_tables(dir, paddr, vaddr, 3, n) 
#define T 1024 
void map_directory(int dir, int debug)
{
        map_kernel_tables(dir, 0, 0, T);
        if (debug) kprint("Mapped 128 tables for kernel mode.\n", 15);
        map_user_tables(dir, 0x400000*T, 0x400000*T, T);
        if (debug) kprint("Mapped 128 tables for user mode.\n", 15);
}

void change_directory(int dir)
{
	set_32bit_cr3(page_directories[dir]);
}

