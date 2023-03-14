.intel_syntax noprefix

.globl syscall_handler

.extern sys_kbd_read
.extern sys_scr_write

syscall_handler:
push ebp
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
call sys_kbd_read
jmp end
tr_write:
push ecx
push ebx
call sys_scr_write
jmp end
end:
add esp, 0x8
popad
pop ebp
sti
iret
