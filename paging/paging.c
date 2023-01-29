extern void set_32bit_cr3(unsigned int cr3_phdr); 
extern void enable_32bit_paging();

unsigned int page_directories[16][1024]; 
unsigned int page_tables[16][1024][1024];

void map_directory(dir)
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
	for (i = 0x40; i < 0xc0; i++)
	{
		page_directories[dir][i] = (unsigned int)page_tables[dir][i] | 7;
		for (j = 0; j < 0x400; j++)
		{
			page_tables[dir][i][j] = (i*0x400000+j*0x1000) | 7;
		}
	}
        kprint("Mapped 512 MiB for user: 0x10000000-0x2fffffff\n", 15);

}

void change_directory(int dir)
{
	set_32bit_cr3(page_directories[dir]);
}

