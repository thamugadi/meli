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

		*(.rodata)
                *(.data)
        }
        .bss BLOCK(4K) (NOLOAD) : ALIGN(4K)
        {
		page_directories = .;
		. += 0x4000;
		page_tables = .;
		. += 0x1000000;
                *(.bss)
        }

	/* This is temporary:*/
        . = 0x10000000;
	
        .ring3data BLOCK(4K) : ALIGN(4K)
        {
                *(.ring3data)
		*(.ring3bss)
        }
	. = 0x10001000;
	.ring3text BLOCK(4K) : ALIGN(4K)
	{
		*(.ring3text)
	}
	
        . = 0x10010000;

        .ring3data_ BLOCK(4K) : ALIGN(4K)
        {
                *(.ring3data_)
                *(.ring3bss_)
        }
        . = 0x10011000;
        .ring3text_ BLOCK(4K) : ALIGN(4K)
        {
                *(.ring3text_)
        }

}
