unsigned char current_key;

void irq_handler(int irq)
{
	char buf[4];
	itoa(irq, buf);
	if (irq)
	{
		kprint("IRQ ", 14);
		kprint(buf, 14);
		kprint("\n", 14);
	}

	if (irq == 1)
	{
		current_key = read_keyboard();
	}
}
