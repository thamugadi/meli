.intel_syntax noprefix
.global load_idt
.global exception
load_idt:
cli
mov eax, dword ptr [esp+4]
lidt [eax]
sti
ret
