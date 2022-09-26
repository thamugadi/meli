.intel_syntax noprefix
.global init_pic
.global end_interrupt

.macro .init_master icw4_needed cascade call_addr_interval8 level_triggered
mov al, (\icw4_needed | (\cascade<<1) | (\call_addr_interval8<<2) | (\level_triggered<<3) | (1<<4))
out 0x20, al
.endm
.macro .init_slave icw4_needed cascade call_addr_interval8 level_triggered
mov al, (\icw4_needed | (\cascade<<1) | (\call_addr_interval8<<2) | (\level_triggered<<3) | (1<<4))
out 0xA0, al
.endm

.macro .remap_master_irq int
mov al, \int
out 0x21, al
.endm
.macro .remap_slave_irq int
mov al, \int
out 0xA1, al
.endm

init_pic:
push ebp
mov ebp, esp
.init_master 0 0 0 0
.init_slave 0 0 0 0
.remap_master_irq 0x20
.remap_slave_irq 0x28
push 15
push offset text
call kprint
sti
leave
ret

end_interrupt:
push ebp
mov ebp, esp
mov al, 0x20
cmp byte ptr [esp+4], 8
jle ms
out 0xA0, al
ms:
out 0x20, al 
leave
ret

text:
.asciz "Initialized PIC.\n"
