char processes[16] = {0};
char processes_n = 1;
extern int current_pid;

typedef struct process_context
{
	unsigned int eip;
	unsigned int eflags;
	unsigned int eax;
	unsigned int ecx;
	unsigned int edx;
	unsigned int ebx;
	unsigned int esp;
	unsigned int ebp;
	unsigned int esi;
	unsigned int edi;
} process_context;

process_context contexts[16];

void context_switch(unsigned int eip, unsigned int eflags, unsigned int eax, unsigned int ebx, unsigned int ecx, unsigned int edx, unsigned int esp, unsigned int ebp, unsigned int esi, unsigned int edi)
{
	contexts[current_pid].eip = eip;
        contexts[current_pid].eflags = eflags;
        contexts[current_pid].eax = eax;
        contexts[current_pid].ebx = ebx;
        contexts[current_pid].ecx = ecx;
        contexts[current_pid].edx = edx;
        contexts[current_pid].esp = esp;
        contexts[current_pid].ebp = ebp;
        contexts[current_pid].esi = esi;
        contexts[current_pid].edi = edi;

	if (processes_n == 1) return;
	
	do
	{
		current_pid = (current_pid + 1) % 16;
	} while(!(processes[current_pid]));


        change_directory(current_pid);
	// TO BE DONE: loading registers
}
