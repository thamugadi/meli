void reverse(char* addr)
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

void itoa(int i, char* addr)
{
        int j = i;
        int m = 10; 
        int c = 0;
        do addr[c++] = "0123456789"[(j%((m*=10)/10)) / (m/100)]; while (i/=10);
}

void memset(void* addr, int c, int n) {
	unsigned char *ptr = (unsigned char*)addr;
	while(n--) *ptr++ = c;
}

