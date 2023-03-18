.intel_syntax noprefix

.globl syscall_handler

.extern sys_kbd_read
.extern sys_scr_write
.extern brk
.extern unbrk
.extern current_pid

syscall_handler:
push ebp
pushad
cli
cmp eax, 0
je tr_read
cmp eax, 1
je tr_write
cmp eax, 2
je tr_brk
cmp eax, 3
je tr_unbrk
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
tr_brk:
push ebx
push current_pid
call brk
jmp end
tr_unbrk:
push ebx
push current_pid
call unbrk
jmp end
end:
add esp, 0x8
popad
pop ebp
sti
iret
