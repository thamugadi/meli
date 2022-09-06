#define FILL_IDT_ENTRY(n, base, ss1, type1) \
                idt[n].base_0_15 = base & 0xffff; \
                idt[n].ss = ss1; \
                idt[n].z = 0; \
                idt[n].type = type1; \
                idt[n].base_16_31 = (base >> 16) & 0xffff;

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

void exception(){
	print("An exception has occured.", 12);
	while(1);
}

void isr0() {irq_handler(0); }
void isr1() {irq_handler(1); }
void isr2() {irq_handler(2); }
void isr3() {irq_handler(3); }
void isr4() {irq_handler(4); }
void isr5() {irq_handler(5); }
void isr6() {irq_handler(6); }
void isr7() {irq_handler(7); }
void isr8() {irq_handler(8); }
void isr9() {irq_handler(9); }
void isr10(){irq_handler(10);}
void isr11(){irq_handler(11);}
void isr12(){irq_handler(12);}
void isr13(){irq_handler(13);}
void isr14(){irq_handler(14);}
void isr15(){irq_handler(15);}

struct IDT idt[256];
struct IDT_PTR idt_ptr;
void init_idt()
{
	int i;
	for (i = 0; i < 0x20; i++)
	{
		FILL_IDT_ENTRY(i, (unsigned int)&exception, 0x8, 0x8E);
	}

	FILL_IDT_ENTRY(0x20,  (unsigned int)&isr0,  0x8, 0x8E);
	FILL_IDT_ENTRY(0x21,  (unsigned int)&isr1,  0x8, 0x8E);
        FILL_IDT_ENTRY(0x22,  (unsigned int)&isr2,  0x8, 0x8E);
        FILL_IDT_ENTRY(0x23,  (unsigned int)&isr3,  0x8, 0x8E);
        FILL_IDT_ENTRY(0x24,  (unsigned int)&isr4,  0x8, 0x8E);
        FILL_IDT_ENTRY(0x25,  (unsigned int)&isr5,  0x8, 0x8E);
        FILL_IDT_ENTRY(0x26,  (unsigned int)&isr6,  0x8, 0x8E);
        FILL_IDT_ENTRY(0x27,  (unsigned int)&isr7,  0x8, 0x8E);
        FILL_IDT_ENTRY(0x28,  (unsigned int)&isr8,  0x8, 0x8E);
        FILL_IDT_ENTRY(0x29,  (unsigned int)&isr9,  0x8, 0x8E);
        FILL_IDT_ENTRY(0x2A,  (unsigned int)&isr10, 0x8, 0x8E);
        FILL_IDT_ENTRY(0x2B,  (unsigned int)&isr11, 0x8, 0x8E);
        FILL_IDT_ENTRY(0x2C,  (unsigned int)&isr12, 0x8, 0x8E);
        FILL_IDT_ENTRY(0x2D,  (unsigned int)&isr13, 0x8, 0x8E);
        FILL_IDT_ENTRY(0x2E,  (unsigned int)&isr14, 0x8, 0x8E);
        FILL_IDT_ENTRY(0x2F,  (unsigned int)&isr15, 0x8, 0x8E);

        idt_ptr.idt_size = sizeof(idt) - 1;
        idt_ptr.idt_addr = (struct IDT*)&idt;
        load_idt((struct IDT*)&idt_ptr);
        print("Loaded IDT.\n", 15);

}
