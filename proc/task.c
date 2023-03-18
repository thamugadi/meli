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
} process_context[16];

void context_switch()
{
	if (processes_n == 1) return;
	
	do
	{
		current_pid = (current_pid + 1) % 16;
	} while(!(processes[current_pid]));


        change_directory(current_pid);
	// TO BE DONE: saving registers
}
