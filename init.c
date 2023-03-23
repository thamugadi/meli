void user_test(void) __attribute__((section(".ring3text")));
void user_test(void) __attribute__((naked));

void func(void) __attribute__((section(".ring3text")));
void u_reverse(char* addr) __attribute__((section(".ring3text")));
void u_itoa(int i, char* addr) __attribute__((section(".ring3text")));



void user_test(void)
{
	asm("mov ebp, esp");
	func();
}

void func(void)
{
        char buffer[0x10];
	brk_user(3);
	char pid;
	getpid_user(&pid);
	u_itoa((int)pid, &buffer);
	scr_write("Hello from PID ",15);
	scr_write(buffer, 1);
	scr_write("\n", 1);
	asm("jmp $");
}

void u_reverse(char* addr)
{
        char tmp;
        char* ptr = addr;
        char* ptr_end = addr;
        while (*ptr_end++);
        int len = ptr_end - ptr - 1;
        int i;
        for (i = 0; i < len/2; i++)
        {
                tmp = ptr[i];
                ptr[i] = ptr[len-i-1];
                ptr[len-i-1]=tmp;
        }
}

void u_itoa(int i, char* addr)
{
        int j = i;
        int m = 10; 
        int c = 0;
	volatile char num[] = "0123456789";
        do addr[c++] = num[(j%((m*=10)/10)) / (m/100)]; while (i/=10);
        addr[c++]=0;
        u_reverse(addr);
}


