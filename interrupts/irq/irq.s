.intel_syntax noprefix
.global irq_handler
irq_handler:
cli
push 9
push offset text
call kprint
jmp $
text:
.asciz "Interrupt request.\nTODO: irq handler"
