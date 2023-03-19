#define REG(n) *(unsigned int*)(0x007fffbc+n)
char __attribute__((section(".data"))) processes[16]; 
char processes_n = 1;
extern int current_pid;
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
	contexts[current_pid].eip = REG(0x30);
        contexts[current_pid].eflags = REG(0x38);
        contexts[current_pid].cs = REG(0x34);
        contexts[current_pid].eax = REG(0x1c);
        contexts[current_pid].ebx = REG(0x10); 
        contexts[current_pid].ecx = REG(0x18); 
        contexts[current_pid].edx = REG(0x14); 
        contexts[current_pid].edi = REG(0x00); 
        contexts[current_pid].esi = REG(0x04); 
        contexts[current_pid].ebp = REG(0x2c); 
        contexts[current_pid].esp = REG(0x3c);

	do
	{
		current_pid = (current_pid + 1) % 16;
	} while(!(processes[current_pid]));

        change_directory(current_pid);


	REG(0x30) = contexts[current_pid].eip;
	REG(0x38) = contexts[current_pid].eflags; 
        REG(0x34) = contexts[current_pid].cs; 
        REG(0x1C) = contexts[current_pid].eax; 
        REG(0x10) = contexts[current_pid].ebx; 
        REG(0x18) = contexts[current_pid].ecx; 
        REG(0x14) = contexts[current_pid].edx; 
        REG(0x00) = contexts[current_pid].edi; 
        REG(0x04) = contexts[current_pid].esi; 
        REG(0x2C) = contexts[current_pid].ebp; 
        REG(0x3C) = contexts[current_pid].esp; 

}
