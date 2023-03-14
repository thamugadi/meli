.intel_syntax noprefix
.section .ring3text
.globl kbd_read
.globl scr_write
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
