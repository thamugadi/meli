RAM=1G
QEMU=qemu-system-i386 -m $(RAM)
KERNEL=-kernel mel.elf
CCFLAGS= -c -w -m32 -fno-stack-protector -fno-pie -masm=intel -O0
LINKER=linker.ld
LDFLAGS= -z noexecstack -m elf_i386 -T $(LINKER)
ASFLAGS= --32

SRC_BOOT = boot/boot.s
SRC_C = $(shell find -name "*.c")
SRC_S = $(shell find -name "*.s" -not -name "boot.s")

OBJ_BOOT = bin/boot.elf
OBJ_C = $(patsubst %.c, bin/%.elf, $(SRC_C))
OBJ_S = $(patsubst $(filter-out boot/boot.s, %.s), bin/%_s.elf, $(SRC_S))

OBJS = $(OBJ_BOOT) $(OBJ_C) $(OBJ_S)

mel.elf : dirs $(OBJS)
	@ld $(LDFLAGS) $(OBJS) -o mel.elf

$(OBJ_BOOT) : $(SRC_BOOT)
	@as --32 $(SRC_BOOT) -o $(OBJ_BOOT)

dirs :
	@mkdir -p $(dir $(OBJS))

bin/%.elf: %.c
	@gcc $(CCFLAGS) $< -o $@

bin/%_s.elf : %.s
	@as $(ASFLAGS) $< -o $@
clean: 
	@rm -rf bin 
	@rm *.elf
run:
	$(QEMU) $(KERNEL)
kvm:
	$(QEMU) --enable-kvm $(KERNEL)
debug:
	$(QEMU) $(KERNEL) -d in_asm
cpu:
	$(QEMU) $(KERNEL) -d cpu
int:
	$(QEMU) $(KERNEL) -d int
gdb:
	$(QEMU) -s -S $(KERNEL)
all:
	make clean && make && make run
mel.iso : mel.elf
	cp mel.elf iso/boot/mel.elf
	strip iso/boot/mel.elf
	grub-mkrescue -o mel.iso iso
	rm iso/boot/mel.elf
