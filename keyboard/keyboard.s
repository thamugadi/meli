.intel_syntax noprefix
.global input
input:
mov edx, dword ptr [(esp+4)]
in al, dx
ret
