.intel_syntax noprefix
.global set_usermode 
.extern user_test

set_usermode:

mov ax, 0x20 
mov ds, ax
mov es, ax 
mov fs, ax 
mov gs, ax 

mov eax, 0x30000000
push 0b00100011
push eax 
pushf 
push 0b00011011
push offset user_test 
iret
