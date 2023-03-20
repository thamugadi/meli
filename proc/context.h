struct process_context
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
} __attribute__((packed));

