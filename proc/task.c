char processes[16] = {0};
char processes_n = 1;
extern int current_pid;
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
