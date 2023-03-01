extern void set_32bit_cr3(unsigned int cr3_phdr); 
extern void enable_32bit_paging();

extern unsigned int page_directories[0x10][0x400]; 
extern unsigned int page_tables[0x10][0x400][0x400];

// 1 block = 4MiB
// 1 page  = 4KiB

void init_memory(int dir, int block, unsigned int paddr, int pages, int perms)
{
	int i,j;
	int entries = block + pages/0x400;
	unsigned int current_paddr;
	for (i = block; i < entries; i++)
	{
	        page_directories[dir][i] = (unsigned int)page_tables[dir][i] | perms;
		for (j = 0; j < 0x400; j++)
		{
			current_paddr = paddr + (i - block)*0x400000 + j*0x1000;
			page_tables[dir][i][j] = current_paddr | perms;
		}
	}
	for (j = 0; j < pages%0x400; j++)
	{
                page_directories[dir][i] = (unsigned int)page_tables[dir][i] | perms;
		current_paddr = paddr + (i - block)*0x400000 + j*0x1000;
		page_tables[dir][i][j] = current_paddr | perms;
	}
}

void change_directory(int dir)
{
	set_32bit_cr3(page_directories[dir]);
}

