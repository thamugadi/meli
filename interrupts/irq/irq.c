unsigned char current_key;
//23 1b 08 10
void irq_handler(int irq)
{
	asm("pushad");
	asm("mov ax, 0x10");
	asm("mov ds, ax");
	asm("mov es, ax");
	asm("mov fs, ax");
	asm("mov gs, ax");
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
	asm("mov ax, 0x23");
        asm("mov ds, ax");
        asm("mov es, ax");
        asm("mov fs, ax");
        asm("mov gs, ax");
	asm("popad");
}
