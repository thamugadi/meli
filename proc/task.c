#define ASSIGN_REG(n) *(unsigned int*)(0x007fffbc+n)
char __attribute__((section(".data"))) processes[16]; 
char processes_n = 1;
extern int current_pid;
extern unsigned int** context_save;
typedef struct process_context
{
	unsigned int eip;
	unsigned int eflags;
	unsigned int cs;
	unsigned int eax;
	unsigned int ecx;
	unsigned int edx;
	unsigned int ebx;
	unsigned int esp;
	unsigned int ebp;
	unsigned int esi;
	unsigned int edi;
} __attribute__((packed)) process_context;

process_context __attribute__((section(".data"))) contexts[16];

void context_switch()
{
	//if (!(processes_n)) return;
	contexts[current_pid].eip = *(unsigned int*)(0x007fffbc + 0x30);
        contexts[current_pid].eflags = *(unsigned int*)(0x007fffbc + 0x38);
        contexts[current_pid].cs = *(unsigned int*)(0x007fffbc + 0x34);
        contexts[current_pid].eax = *(unsigned int*)(0x007fffbc + 0x1c);
        contexts[current_pid].ebx = *(unsigned int*)(0x007fffbc + 0x10); 
        contexts[current_pid].ecx = *(unsigned int*)(0x007fffbc + 0x18); 
        contexts[current_pid].edx = *(unsigned int*)(0x007fffbc + 0x14); 
        contexts[current_pid].edi = *(unsigned int*)(0x007fffbc + 0x00); 
        contexts[current_pid].esi = *(unsigned int*)(0x007fffbc + 0x04); 
        contexts[current_pid].ebp = *(unsigned int*)(0x007fffbc + 0x2c); 
        contexts[current_pid].esp = *(unsigned int*)(0x007fffbc + 0x3c);

	do
	{
		current_pid = (current_pid + 1) % 16;
	} while(!(processes[current_pid]));

        change_directory(current_pid);


	ASSIGN_REG(0x30) = contexts[current_pid].eip;
	ASSIGN_REG(0x38) = contexts[current_pid].eflags; 
        ASSIGN_REG(0x34) = contexts[current_pid].cs; 
        ASSIGN_REG(0x1C) = contexts[current_pid].eax; 
        ASSIGN_REG(0x10) = contexts[current_pid].ebx; 
        ASSIGN_REG(0x18) = contexts[current_pid].ecx; 
        ASSIGN_REG(0x14) = contexts[current_pid].edx; 
        ASSIGN_REG(0x00) = contexts[current_pid].edi; 
        ASSIGN_REG(0x04) = contexts[current_pid].esi; 
        ASSIGN_REG(0x2C) = contexts[current_pid].ebp; 
        ASSIGN_REG(0x3C) = contexts[current_pid].esp; 

}
