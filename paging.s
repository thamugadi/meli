.intel_syntax noprefix
.global set_32bit_cr3
.global get_cr3
.global enable_32bit_paging
enable_32bit_paging:
mov eax, cr0
or eax, 0x80000001
mov cr0, eax
ret
set_32bit_cr3:
mov eax, dword ptr [esp+4]
mov cr3, eax
ret
get_cr3:
mov eax, cr3
ret
