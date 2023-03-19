#define DATA  0x40
#define CODE  0x80
#define STACK 0xa0
extern char processes[16];
extern char processes_n;
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


        init_memory(pid, DATA, data, sdata,  7);
        init_memory(pid, CODE, code, scode,  7);
        init_memory(pid, STACK,stack,sstack, 7);
}
