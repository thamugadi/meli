extern void set_32bit_cr3(unsigned int cr3_phdr); 
extern void enable_32bit_paging();

unsigned int page_directories[1024][1024]; 
unsigned int page_tables[16][1024][1024];

int current_d = 0;

void map_table(unsigned int paddr, unsigned int vaddr, int flags)
{
        unsigned int directory_e = vaddr >> 22;
        unsigned int page = (paddr/0x00400000);
        unsigned int i;
        for (i = 0; i < 1024; i++)
        {
                page_tables[current_d][directory_e][i] = ((page*1024 + i)*0x1000) | flags;
        }
        page_directories[current_d][directory_e] = (unsigned int)page_tables[current_d][directory_e] | flags;
}


void map_tables(unsigned int paddr, unsigned int vaddr, int flags, int n)
{
        int i;
        for (i = 0; i < n; i++)
        {
                map_table(paddr+(i*0x400000), vaddr+(i*0x400000), flags);
        }
}

void map_user_tables(unsigned int paddr, unsigned int vaddr, int n)
{
        map_tables(paddr,vaddr,7,n);
}
void map_kernel_tables(unsigned int paddr, unsigned int vaddr, int n)
{
        map_tables(paddr,vaddr,3,n);
}

void init_32bit_paging()
{
        map_kernel_tables(0, 0, 128);
        print("Mapped 128 tables for kernel mode.\n", 15);
        map_user_tables(0x400000*128, 0x400000*128, 128);
        print("Mapped 128 tables for user mode.\n", 15);
        set_32bit_cr3(page_directories[0]);
        enable_32bit_paging();
        print("Enabled paging.\n", 15);
}
