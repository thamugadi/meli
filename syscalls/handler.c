void syscall_handler() {
	asm("cli");
	asm("cmp edi, 1");
	asm("je write");
	kprint("TODO: implement syscalls", 5);
	asm("jmp $");
}
void write()
{
	kprint("TODO: implement write syscall", 6);
	asm("jmp $");
}
