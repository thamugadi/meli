.intel_syntax noprefix
.section .ring3text
.globl kbd_read
.globl scr_write
.globl brk_user
.globl unbrk_user
.globl getpid_user
.globl fork_user
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
getpid_user:
mov eax, 4
mov ebx, dword ptr [esp+0x4]
int 0x30
ret
fork_user:
mov eax, 5
mov ebx, dword ptr [esp]
int 0x30
ret
