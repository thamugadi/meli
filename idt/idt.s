.intel_syntax noprefix
.global load_idt
load_idt:
mov eax, dword ptr [esp+4]
lidt [eax]
ret
