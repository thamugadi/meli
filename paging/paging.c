extern void set_32bit_cr3(unsigned int cr3_phdr); 
extern void enable_32bit_paging();

unsigned int page_directories[16][1024]; 
unsigned int page_tables[16][1024][1024];

void map_kernel_directory(dir)
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

#define INIT_DIR(dir, table, block) \
	page_directories[dir][block] = (unsigned int)page_tables[dir][block] | 7; \
	page_tables[dir][block][0] = (block*0x400000+table*0x1000) | 7;

void init_user_directory(dir, table)
{
	INIT_DIR(dir, table, 0x40);
	INIT_DIR(dir, table, 0x80);
	INIT_DIR(dir, table, 0xa0);
}

void change_directory(int dir)
{
	set_32bit_cr3(page_directories[dir]);
}

