extern void set_32bit_cr3(unsigned int cr3_phdr); 
extern void enable_32bit_paging();

unsigned int page_directories[0x10][0x400]; 
unsigned int page_tables[0x10][0x400][0x400];

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
	kprint("Mapped 256 MiB for kernel: 0x00000000-0x0fffffff\n", 15);
}

void init_user_memory(int dir, int block, unsigned int paddr, int pages)
{
	int i,j;
	int entries = block + pages/0x400;
	unsigned int current_paddr;
	for (i = block; i < entries; i++)
	{
	        page_directories[dir][i] = (unsigned int)page_tables[dir][i] | 7;
		for (j = 0; j < 0x400; j++)
		{
			current_paddr = paddr + (i - block)*0x400000 + j*0x1000;
			page_tables[dir][i][j] = current_paddr | 7;
		}
	}
	for (j = 0; j < pages%0x400; j++)
	{
                page_directories[dir][i] = (unsigned int)page_tables[dir][i] | 7;
		current_paddr = paddr + (i - block)*0x400000 + j*0x1000;
		page_tables[dir][i][j] = current_paddr | 7;
	}
}

void change_directory(int dir)
{
	set_32bit_cr3(page_directories[dir]);
}

