extern char current_pid;

void getpid(char* addr)
{
	*addr = current_pid;
}
