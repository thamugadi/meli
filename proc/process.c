#include "context.h"

#define DATA  0x40
#define CODE  0x80
#define STACK 0xa0
extern char processes[16];
extern struct process_context contexts[16]; 
char processes_n = 0;
extern int current_pid;

int new_process(unsigned int data, unsigned int code, unsigned int stack, 
		unsigned int sdata, unsigned int scode, unsigned int sstack)
{
	if (processes_n == 15) return -1;
	processes_n++;
	int pid;
	for (int i = 0; i < 16; i++)
	{
		if (!processes[i])
		{
			pid = i;
			processes[i] = 1;
			break;
		}
	}

        init_memory(pid, 0x00, 0x00000000, 0x10000, 3);

        init_memory(pid, DATA, data, sdata,  7);
        init_memory(pid, CODE, code, scode,  7);
        init_memory(pid, STACK,stack,sstack, 7);

	contexts[pid].cs = 0x1b; 
	contexts[pid].eflags = 0x200;

	contexts[pid].eip = 0x20000000;
	contexts[pid].esp = 0x28000000+sstack*0x1000;
	contexts[pid].ebp = 0x28000000+sstack*0x1000;

}
