RAM=1G

mel.elf : main.o print.o gdt.o keyboard.o paging.o gdt_s.elf keyboard_s.elf paging_s.elf linker.ld boot.elf
	ld -m elf_i386 -T linker.ld main.o boot.elf print.o paging.o gdt.o keyboard.o gdt_s.elf keyboard_s.elf paging_s.elf -o mel.elf
%.o : %.c
	gcc -c -w -m32 -masm=intel $<
paging_s.elf : paging.s
	as --32 paging.s -o paging_s.elf
keyboard_s.elf : keyboard.s
	as --32 keyboard.s -o keyboard_s.elf
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
