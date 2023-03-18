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
        contexts[current_pid].eip = eax;
        contexts[current_pid].eip = ebx;
        contexts[current_pid].eip = ecx;
        contexts[current_pid].eip = edx;
        contexts[current_pid].eip = esp;
        contexts[current_pid].eip = ebp;
        contexts[current_pid].eip = esi;
        contexts[current_pid].eip = edi;

	if (processes_n == 1) return;
	
	do
	{
		current_pid = (current_pid + 1) % 16;
	} while(!(processes[current_pid]));


        change_directory(current_pid);
	// TO BE DONE: loading registers
}
