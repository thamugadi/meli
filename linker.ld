OUTPUT_FORMAT(elf32-i386)
ENTRY(_start)

SECTIONS
{
        . = 0x00100000;
        .text BLOCK(4K) : ALIGN(4K)
        {
                *(.text)
        }
        .data BLOCK(4K) : ALIGN(4K)
        {
                *(.data)
        }
        .bss BLOCK(4K) : ALIGN(4K)
        {
                *(.bss)
        }
}
