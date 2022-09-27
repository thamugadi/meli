void irq_handler(int irq)
{
	asm("pusha");
	char buf[4];
	itoa(irq, buf);
	kprint("IRQ ", 14);
	kprint(buf, 14);
	kprint("\n", 14);
	while(1);
}
