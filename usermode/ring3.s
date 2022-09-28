.intel_syntax noprefix
.global jump_usermode
.extern user_test
jump_usermode:
mov ax, (4 * 8) | 3 
mov ds, ax
mov es, ax 
mov fs, ax 
mov gs, ax 

mov eax, 0x30000000
push (4 * 8) | 3 
push eax 
pushf 
push (3 * 8) | 3
push offset user_test 
iret
