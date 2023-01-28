.intel_syntax noprefix

.globl syscall_handler

.extern sys_read
.extern sys_write

syscall_handler:
cli
push ecx
push edx

cmp edi, 0
je tr_read
cmp edi, 1
je tr_write
jmp $
tr_read:
call sys_read
jmp end
tr_write:
call sys_write
jmp end

end:
pop ecx
pop edx
sti
iret
