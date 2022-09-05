RAM=1G

mel.elf : main.o print.o gdt.o idt.o keyboard.o paging.o gdt_s.elf idt_s.elf irq.elf ring3.elf keyboard_s.elf paging_s.elf pic.elf linker.ld boot.elf
	ld -m elf_i386 -T linker.ld main.o boot.elf print.o paging.o idt.o gdt.o keyboard.o gdt_s.elf idt_s.elf irq.elf pic.elf ring3.elf keyboard_s.elf paging_s.elf -o mel.elf
%.o : %.c
	gcc -c -w -m32 -masm=intel $<
paging_s.elf : paging.s
	as --32 paging.s -o paging_s.elf
keyboard_s.elf : keyboard.s
	as --32 keyboard.s -o keyboard_s.elf
ring3.elf : ring3.s
	as --32 ring3.s -o ring3.elf
pic.elf : pic.s
	as --32 pic.s -o pic.elf
irq.elf : irq.s
	as --32 irq.s -o irq.elf
idt_s.elf:
	as --32 idt.s -o idt_s.elf
gdt_s.elf : gdt.s
	as --32 gdt.s -o gdt_s.elf
boot.elf : boot.s
	as --32 boot.s -o boot.elf
clean: 
	rm *.o *.elf 
run:
	qemu-system-i386 -m $(RAM) -kernel mel.elf
debug:
	qemu-system-i386 -m $(RAM) -kernel mel.elf -d in_asm
debug_cpu:
	qemu-system-i386 -m $(RAM) -kernel mel.elf -d cpu
gdb:
	qemu-system-i386 -m $(RAM) -s -S -kernel mel.elf
all:
	make clean && make && make run
