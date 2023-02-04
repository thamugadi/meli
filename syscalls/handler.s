.intel_syntax noprefix

.globl syscall_handler

.extern sys_read
.extern sys_write

syscall_handler:
pushad
cli
###eax
cmp eax, 0
je tr_read
cmp eax, 1
je tr_write
jmp $
tr_read:
push ecx
push ebx
call sys_read
jmp end
tr_write:
push ecx
push ebx
call sys_write
jmp end
end:
add esp, 0x8
popad
sti
iret
