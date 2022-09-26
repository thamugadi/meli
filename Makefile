RAM=1G

mel.elf : main.o kprint.o lib.o gdt.o idt.o keyboard.o paging.o gdt_s.elf idt_s.elf irq.elf exceptions.elf ring3.elf keyboard_s.elf paging_s.elf pic.elf linker.ld boot.elf
	ld -m elf_i386 -T linker.ld main.o boot.elf kprint.o lib.o paging.o idt.o gdt.o keyboard.o gdt_s.elf idt_s.elf irq.elf pic.elf exceptions.elf ring3.elf keyboard_s.elf paging_s.elf -o mel.elf
main.o : main.c
	gcc -c -w -m32 -masm=intel main.c
lib.o : lib/lib.c
	gcc -c -w -m32 -masm=intel lib/lib.c
kprint.o : lib/kprint.c
	gcc -c -w -m32 -masm=intel lib/kprint.c
gdt.o : gdt/gdt.c
	gcc -c -w -m32 -masm=intel gdt/gdt.c
idt.o : idt/idt.c
	gcc -c -w -m32 -masm=intel idt/idt.c
keyboard.o : keyboard/keyboard.c
	gcc -c -w -m32 -masm=intel keyboard/keyboard.c
paging.o : paging/paging.o
	gcc -c -w -m32 -masm=intel paging/paging.c
paging_s.elf : paging/paging.s
	as --32 paging/paging.s -o paging_s.elf
keyboard_s.elf : keyboard/keyboard.s
	as --32 keyboard/keyboard.s -o keyboard_s.elf
ring3.elf : usermode/ring3.s
	as --32 usermode/ring3.s -o ring3.elf
pic.elf : 8259_PIC/pic.s
	as --32 8259_PIC/pic.s -o pic.elf
irq.elf : interrupts/irq/irq.s
	as --32 interrupts/irq/irq.s -o irq.elf
exceptions.elf : interrupts/exceptions/exceptions.s
	as --32 interrupts/exceptions/exceptions.s -o exceptions.elf
idt_s.elf: idt/idt.s
	as --32 idt/idt.s -o idt_s.elf
gdt_s.elf : gdt/gdt.s
	as --32 gdt/gdt.s -o gdt_s.elf
boot.elf : boot/boot.s
	as --32 boot/boot.s -o boot.elf
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
