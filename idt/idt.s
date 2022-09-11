.intel_syntax noprefix
.global load_idt
load_idt:
cli
mov eax, dword ptr [esp+4]
lidt [eax]
ret
