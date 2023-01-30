extern void set_32bit_cr3(unsigned int cr3_phdr); 
extern void enable_32bit_paging();

unsigned int page_directories[16][1024]; 
unsigned int page_tables[16][1024][1024];

void map_kernel_directory(int dir)
{
	int i;
	int j;
        for (i = 0; i < 0x40; i++)
	{
		page_directories[dir][i] = (unsigned int)page_tables[dir][i] | 3;
		for (j = 0; j < 0x400; j++)
		{
			page_tables[dir][i][j] = (i*0x400000+j*0x1000) | 3;
		}
	}
	kprint("Mapped 256 MiB for kernel: 0x00000000-0x0fffffff \n", 15);
}

void init_user_data(int dir, unsigned int paddr, int blocks)
{
	if (blocks > 0x10000)
		kprint("Cannot allocate more than 256MiB for user data\n", 12);
	else
	{
		page_directories[dir][0x40] = (unsigned int)page_tables[dir][0x40] | 7;
		int i,j;
		int entries = 0x40 + blocks/0x400;
		unsigned int current_paddr;
		for (i = 0x40; i < entries; i++)
		{
			for (j = 0; j < 0x400; j++)
			{
				current_paddr = paddr + (i - 0x40)*0x400000 + j*0x1000;
				page_tables[dir][i][j] = current_paddr | 7;
			}
		}
		for (j = 0; j < blocks%0x400; j++)
		{
			current_paddr = paddr + (i - 0x40)*0x400000 + j*0x1000;
			page_tables[dir][i][j] = current_paddr | 7;
		}
	}
}


void init_user_code(int dir, unsigned int paddr, int blocks)
{
        if (blocks > 0x8000)
                kprint("Cannot allocate more than 128MiB for user code\n", 12);
        else
        {
                page_directories[dir][0x80] = (unsigned int)page_tables[dir][0x80] | 7;
                int i,j;
                int entries = 0x80 + blocks/0x400;
                unsigned int current_paddr;
                for (i = 0x80; i < entries; i++)
                {
                        for (j = 0; j < 0x400; j++)
                        {       
                                current_paddr = paddr + (i - 0x80)*0x400000 + j*0x1000;
                                page_tables[dir][i][j] = current_paddr | 7;              
                        }
                }
                for (j = 0; j < blocks%0x400; j++)
                {
                        current_paddr = paddr + (i - 0x80)*0x400000 + j*0x1000;
                        page_tables[dir][i][j] = current_paddr | 7;              
                }
	}
}
void init_user_stack(int dir, unsigned int paddr, int blocks)
{
        if (blocks > 0x10000)
                kprint("Cannot allocate more than 256MiB for user stack\n", 12);
        else
        {
                page_directories[dir][0xa0] = (unsigned int)page_tables[dir][0xa0] | 7;
                int i,j;
                int entries = 0xa0 + blocks/0x400;
                unsigned int current_paddr;
                for (i = 0xa0; i < entries; i++)
                {
                        for (j = 0; j < 0x400; j++)
                        {       
                                current_paddr = paddr + (i - 0xa0)*0x400000 + j*0x1000;
                                page_tables[dir][i][j] = current_paddr | 7;              
                        }
                }
                for (j = 0; j < blocks%0x400; j++)
                {
                        current_paddr = paddr + (i - 0xa0)*0x400000 + j*0x1000;
                        page_tables[dir][i][j] = current_paddr | 7;              
                }
        }
}

void change_directory(int dir)
{
	set_32bit_cr3(page_directories[dir]);
}

