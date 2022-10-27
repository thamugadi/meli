void irq_handler(int irq)
{
	asm("mov ax, ss");
	asm("mov ds, ax");
	asm("mov es, ax");
	asm("mov fs, ax");
	asm("mov gs, ax");
	char buf[4];
	itoa(irq, buf);
	kprint("IRQ ", 14);
	kprint(buf, 14);
	kprint("\n", 14);
	asm("jmp $");
}
