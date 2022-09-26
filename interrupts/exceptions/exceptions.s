.intel_syntax noprefix
.global exception_handler
exception_handler:
cli
push 12
push offset text
call kprint
jmp $
text:
.asciz "An exception has occured.\nTODO: exception handler"
