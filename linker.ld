OUTPUT_FORMAT(elf32-i386)
ENTRY(_start)

SECTIONS
{
        . = 0x00100000;
        .text BLOCK(4K) : ALIGN(4K)
        {
                *(.text)
        }
	. = 0x00200000;
        .data BLOCK(4K) : ALIGN(4K)
        {
                *(.data)
        }
        .bss BLOCK(4K) : ALIGN(4K)
        {
                *(.bss)
        }
        . = 0x20000000;
        .ring3 BLOCK(4K) : ALIGN(4K)
        {
                *(.ring3)
        }

}
