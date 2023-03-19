char processes[16] = {0};
char processes_n = 1;
extern int current_pid;
extern unsigned int* context_save;
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
} process_context;

process_context contexts[16] = {0};

void context_switch()
{
//        if (processes_n == 1) return;   
	asm("jmp $");
	do
	{
		current_pid = (current_pid + 1) % 16;
	} while(!(processes[current_pid]));

        change_directory(current_pid);
}
