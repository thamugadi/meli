.intel_syntax noprefix
.section .ring3text
.globl read
.globl write
read:
xor eax, eax
mov ebx, dword ptr [esp+0x4]
mov ecx, dword ptr [esp+0x8]
jmp $
int 0x30
ret
write:
mov eax, 1
mov ebx, dword ptr [esp+0x4]
mov ecx, dword ptr [esp+0x4]
jmp $
int 0x30
ret
