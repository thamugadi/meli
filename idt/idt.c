extern void end_interrupt(int n);

#define FILL_IDT_ENTRY(n, base, ss1, type1) \
                idt[n].base_0_15 = base & 0xffff; \
                idt[n].ss = ss1; \
                idt[n].z = 0; \
                idt[n].type = type1; \
                idt[n].base_16_31 = (base >> 16) & 0xffff;

#define HANDLE(n) \
	asm volatile("cli"); \
	asm volatile("push ebp"); \
	asm volatile ("pushad"); \
	irq_handler(n); \
	end_interrupt(n); \
	asm volatile("popad"); \
	asm volatile("add esp, 0xc"); \
	asm volatile("pop ebp"); \
	asm volatile("sti"); \
	asm volatile("iret");
struct IDT
{
	unsigned short base_0_15;
	unsigned short ss;
	unsigned char  z;
	unsigned char  type;
	unsigned short base_16_31;
} __attribute__((packed));


struct IDT_PTR
{
	unsigned short idt_size;  // limit size of all IDT segments
	struct IDT* idt_addr;  // base address of the first IDT segment
} __attribute__((packed));

void irq0() {HANDLE(0);}
void irq1() {HANDLE(1);} 
void irq2() {HANDLE(2);} 
void irq3() {HANDLE(3);} 
void irq4() {HANDLE(4);} 
void irq5() {HANDLE(5);} 
void irq6() {HANDLE(6);} 
void irq7() {HANDLE(7);} 
void irq8() {HANDLE(8);} 
void irq9() {HANDLE(9);} 
void irq10() {HANDLE(10);} 
void irq11() {HANDLE(11);} 
void irq12() {HANDLE(12);} 
void irq13() {HANDLE(13);} 
void irq14() {HANDLE(14);} 
void irq15() {HANDLE(15);} 

void ex0() {exception_handler(0); }
void ex1() {exception_handler(1); }
void ex2() {exception_handler(2); }
void ex3() {exception_handler(3); }
void ex4() {exception_handler(4); }
void ex5() {exception_handler(5); }
void ex6() {exception_handler(6); }
void ex7() {exception_handler(7); }
void ex8() {exception_handler(8); }
void ex9() {exception_handler(9); }
void ex10() {exception_handler(10); }
void ex11() {exception_handler(11); }
void ex12() {exception_handler(12); }
void ex13() {exception_handler(13); }
void ex14() {exception_handler(14); }
void ex15() {exception_handler(15); }
void ex16() {exception_handler(16); }
void ex17() {exception_handler(17); }
void ex18() {exception_handler(18); }
void ex19() {exception_handler(19); }
void ex20() {exception_handler(20); }
void ex21() {exception_handler(21); }
void ex22() {exception_handler(22); }
void ex23() {exception_handler(23); }
void ex24() {exception_handler(24); }
void ex25() {exception_handler(25); }
void ex26() {exception_handler(26); }
void ex27() {exception_handler(27); }
void ex28() {exception_handler(28); }
void ex29() {exception_handler(29); }
void ex30() {exception_handler(30); }
void ex31() {exception_handler(31); }

extern void syscall_handler();

struct IDT idt[256];
struct IDT_PTR idt_ptr;
void init_idt()
{
	FILL_IDT_ENTRY(0x00,  (unsigned int)&ex0,   0x8, 0x8F);
	FILL_IDT_ENTRY(0x01,  (unsigned int)&ex1,   0x8, 0x8F);
	FILL_IDT_ENTRY(0x02,  (unsigned int)&ex2,   0x8, 0x8F);
	FILL_IDT_ENTRY(0x03,  (unsigned int)&ex3,   0x8, 0x8F);
	FILL_IDT_ENTRY(0x04,  (unsigned int)&ex4,   0x8, 0x8F);
	FILL_IDT_ENTRY(0x05,  (unsigned int)&ex5,   0x8, 0x8F);
	FILL_IDT_ENTRY(0x06,  (unsigned int)&ex6,   0x8, 0x8F);
	FILL_IDT_ENTRY(0x07,  (unsigned int)&ex7,   0x8, 0x8F);
	FILL_IDT_ENTRY(0x08,  (unsigned int)&ex8,   0x8, 0x8F);
	FILL_IDT_ENTRY(0x09,  (unsigned int)&ex9,   0x8, 0x8F);
	FILL_IDT_ENTRY(0x0A,  (unsigned int)&ex10,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x0B,  (unsigned int)&ex11,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x0C,  (unsigned int)&ex12,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x0D,  (unsigned int)&ex13,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x0E,  (unsigned int)&ex14,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x0F,  (unsigned int)&ex15,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x10,  (unsigned int)&ex16,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x11,  (unsigned int)&ex17,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x12,  (unsigned int)&ex18,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x13,  (unsigned int)&ex19,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x14,  (unsigned int)&ex20,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x15,  (unsigned int)&ex21,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x16,  (unsigned int)&ex22,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x17,  (unsigned int)&ex23,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x18,  (unsigned int)&ex24,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x19,  (unsigned int)&ex25,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x1A,  (unsigned int)&ex26,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x1B,  (unsigned int)&ex27,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x1C,  (unsigned int)&ex28,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x1D,  (unsigned int)&ex29,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x1E,  (unsigned int)&ex30,  0x8, 0x8F);
	FILL_IDT_ENTRY(0x1F,  (unsigned int)&ex31,  0x8, 0x8F);

	FILL_IDT_ENTRY(0x20,  (unsigned int)&irq0,  0x8, 0x8E);
	FILL_IDT_ENTRY(0x21,  (unsigned int)&irq1,  0x8, 0x8E);
        FILL_IDT_ENTRY(0x22,  (unsigned int)&irq2,  0x8, 0x8E);
        FILL_IDT_ENTRY(0x23,  (unsigned int)&irq3,  0x8, 0x8E);
        FILL_IDT_ENTRY(0x24,  (unsigned int)&irq4,  0x8, 0x8E);
        FILL_IDT_ENTRY(0x25,  (unsigned int)&irq5,  0x8, 0x8E);
        FILL_IDT_ENTRY(0x26,  (unsigned int)&irq6,  0x8, 0x8E);
        FILL_IDT_ENTRY(0x27,  (unsigned int)&irq7,  0x8, 0x8E);
        FILL_IDT_ENTRY(0x28,  (unsigned int)&irq8,  0x8, 0x8E);
        FILL_IDT_ENTRY(0x29,  (unsigned int)&irq9,  0x8, 0x8E);
        FILL_IDT_ENTRY(0x2A,  (unsigned int)&irq10, 0x8, 0x8E);
        FILL_IDT_ENTRY(0x2B,  (unsigned int)&irq11, 0x8, 0x8E);
        FILL_IDT_ENTRY(0x2C,  (unsigned int)&irq12, 0x8, 0x8E);
        FILL_IDT_ENTRY(0x2D,  (unsigned int)&irq13, 0x8, 0x8E);
        FILL_IDT_ENTRY(0x2E,  (unsigned int)&irq14, 0x8, 0x8E);
        FILL_IDT_ENTRY(0x2F,  (unsigned int)&irq15, 0x8, 0x8E);

        FILL_IDT_ENTRY(0x30,  (unsigned int)&syscall_handler, 0x8, 0xEE);

        idt_ptr.idt_size = sizeof(idt) - 1;
        idt_ptr.idt_addr = (struct IDT*)&idt;
        load_idt((struct IDT*)&idt_ptr);
        kprint("Loaded IDT.\n", 15);

}
