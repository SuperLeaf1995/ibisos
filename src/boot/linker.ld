/*Start execution at entry point */
ENTRY(_start)
/*Tells where various sections of objects are in*/
SECTIONS
{
    . = 1M;
    .text BLOCK(4K) : ALIGN(4K)
    {
        *(.text)
        *(.multiboot)
    }

    .rodata BLOCK(4K) : ALIGN(4K)
    {
        *(.rodata)
    }

    .data BLOCK(4K) : ALIGN(4K)
    {
        *(.data)
    }

    .bss BLOCK(4K) : ALIGN(4K)
    {
        *(COMMON)
        *(.bss)
    }
    
}