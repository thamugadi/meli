RAM=2G
CCFLAGS= -c -w -m32 -fno-stack-protector -masm=intel
mel.elf : main.o init.o kprint.o lib.o gdt.o idt.o keyboard.o paging.o gdt_s.elf idt_s.elf irq.o exceptions.o ring3.elf keyboard_s.elf paging_s.elf pic.elf linker.ld boot.elf
	ld -m elf_i386 -T linker.ld main.o init.o boot.elf kprint.o lib.o paging.o idt.o gdt.o keyboard.o gdt_s.elf idt_s.elf irq.o pic.elf exceptions.o ring3.elf keyboard_s.elf paging_s.elf -o mel.elf

main.o : main.c
	gcc $(CCFLAGS) -O2 main.c
init.o : usermode/init.c
	gcc $(CCFLAGS) -O2 usermode/init.c
lib.o : lib/lib.c
	gcc $(CCFLAGS) lib/lib.c
kprint.o : lib/kprint.c
	gcc $(CCFLAGS) lib/kprint.c
gdt.o : gdt/gdt.c gdt/gdt.h gdt/tss.h
	gcc $(CCFLAGS) gdt/gdt.c
idt.o : idt/idt.c
	gcc $(CCFLAGS) idt/idt.c
keyboard.o : keyboard/keyboard.c
	gcc $(CCFLAGS) keyboard/keyboard.c
paging.o : paging/paging.o
	gcc $(CCFLAGS) paging/paging.c
paging_s.elf : paging/paging.s
	as --32 paging/paging.s -o paging_s.elf
keyboard_s.elf : keyboard/keyboard.s
	as --32 keyboard/keyboard.s -o keyboard_s.elf
ring3.elf : usermode/ring3.s
	as --32 usermode/ring3.s -o ring3.elf
pic.elf : 8259_PIC/pic.s
	as --32 8259_PIC/pic.s -o pic.elf
irq.o : interrupts/irq/irq.c
	gcc $(CCFLAGS) interrupts/irq/irq.c
exceptions.o : interrupts/exceptions/exceptions.c
	gcc $(CCFLAGS) interrupts/exceptions/exceptions.c
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
kvm:
	qemu-system-i386 -m $(RAM) --enable-kvm -kernel mel.elf
debug:
	qemu-system-i386 -m $(RAM) -kernel mel.elf -d in_asm
debug_cpu:
	qemu-system-i386 -m $(RAM) -kernel mel.elf -d cpu
debug_int:
	qemu-system-i386 -m $(RAM) -kernel mel.elf -d int -M smm=off 
gdb:
	qemu-system-i386 -m $(RAM) -s -S -kernel mel.elf
all:
	make clean && make && make run
