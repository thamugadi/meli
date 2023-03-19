unsigned char current_key;

void irq_handler(int irq)
{
	asm volatile("push eax");
	asm volatile("mov ax, 0x10");
	asm volatile("mov ds, ax");
	asm volatile("mov es, ax");
	asm volatile("mov fs, ax");
	asm volatile("mov gs, ax");
	asm volatile("pop eax");
	char buf[4];
	itoa(irq, buf);

	if (!irq)
	{
//		asm("push esp");
//		context_switch();
	}

	if (irq)
	{
//		kprint("IRQ ", 14);
//		kprint(buf, 14);
//		kprint("\n", 14);
	}

	if (irq == 1)
	{
		current_key = read_keyboard();
	}
	asm volatile("push eax");
	asm volatile("mov ax, 0x23");
        asm volatile("mov ds, ax");
        asm volatile("mov es, ax");
        asm volatile("mov fs, ax");
        asm volatile("mov gs, ax");
	asm volatile("pop eax");
}

