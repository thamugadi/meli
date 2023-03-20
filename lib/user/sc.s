.intel_syntax noprefix
.section .ring3text
.globl kbd_read
.globl scr_write
.globl brk_user
kbd_read:
xor eax, eax
mov ebx, dword ptr [esp+0x4]
mov ecx, dword ptr [esp+0x8]
int 0x30
ret
scr_write:
mov eax, 1
mov ebx, dword ptr [esp+0x4]
mov ecx, dword ptr [esp+0x8]
int 0x30
ret
brk_user:
mov eax, 2
mov ebx, dword ptr [esp+0x4]
int 0x30
ret
unbrk_user:
mov eax, 3
mov ebx, dword ptr [esp+0x4]
int 0x30
ret


###temporary dirty way:
.section .ring3text_
.globl kbd_read_
.globl scr_write_
.globl brk_user_
kbd_read_:
xor eax, eax
mov ebx, dword ptr [esp+0x4]
mov ecx, dword ptr [esp+0x8]
int 0x30
ret
scr_write_:
mov eax, 1
mov ebx, dword ptr [esp+0x4]
mov ecx, dword ptr [esp+0x8]
int 0x30
ret
brk_user_:
mov eax, 2
mov ebx, dword ptr [esp+0x4]
int 0x30
ret
unbrk_user_:
mov eax, 3
mov ebx, dword ptr [esp+0x4]
int 0x30
ret

