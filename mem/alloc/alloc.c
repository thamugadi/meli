unsigned char alloc[0x100*0x400] = {0};
unsigned int brk_vaddr[0x10] = {0};

void brk(int pid, int n)
{
	int pages = 0;
	for (int i = 0; i < 0x40000; i++)
	{
		if (pages >= n) break;
		if (!(alloc[i]))
		{
			alloc[i] = (pid << 4) | 1;
			pages++;
			init_memory(pid, 0xc0+(brk_vaddr[pid]%0x400000), 0x30000000+i*0x1000,1,7);
			brk_vaddr[pid] += 0x1000;
		}
	}
}

void unbrk(int pid, int n)
{
	int pages = 0;
	for (int i = 0; i < 0x40000; i++)
	{
		if (pages >= n) break;
		if ((alloc[i] << 4) == pid)
		{
			alloc[i] = 0;
			pages++;
			brk_vaddr[pid] -= 0x1000;
		}
	}
}
