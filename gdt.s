.intel_syntax noprefix
.global load_gdt
load_gdt:
cli
mov eax, dword ptr [esp+4]
lgdt [eax]
jmp 0x8:longjump
longjump:
mov eax, 0x10
mov ds, eax
mov es, eax
mov fs, eax
mov gs, eax
mov ss, eax
ret
