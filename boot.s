.intel_syntax noprefix
.extern main
.global load_gdt
.global _start
.section .text
.align 4
.long 0x1badb002
.long 0x00000000
.long -0x1badb002
_start:
jmp main
