.intel_syntax noprefix
.global irq_handler
.extern print
irq_handler:
cli
push 9
push offset text
call print
jmp $
text:
.asciz "TODO: irq handler"
