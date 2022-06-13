.intel_syntax noprefix
.global load_gdt
load_gdt:
mov eax, dword ptr [esp+4]
lgdt [eax]
mov eax, 0x10
mov ds, eax
mov es, eax
mov fs, eax
mov gs, eax
mov ss, eax
jmp 0x8:.l_jump
.l_jump:
ret
