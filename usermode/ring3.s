.intel_syntax noprefix
.global set_usermode 
.extern user_test

set_usermode:

mov ax, 0b00100011 
mov ds, ax
mov es, ax 
mov fs, ax 
mov gs, ax 

mov eax, 0x30000000
push 0b00100011
push eax 
pushf
pop ebx
or ebx, 0b1000000000 ##(to enable interrupts in usermode)
push ebx
push 0b00011011
mov ebx, dword ptr [esp+0x14]
push ebx
iret
