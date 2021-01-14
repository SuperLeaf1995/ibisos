#include <malloc/malloc.h>
#include <system.h>
#include <vesa/vesa.h>
extern "C" void initiate_mini_kernel(unsigned int *multiboot_struct);
void initiate_mini_kernel(unsigned int *multiboot_struct)
{
    //Initialize the GDT
    init_gdt();
    //Initialize the IDT
    init_idt();
    //Initialize vesa mode
    init_vesa(multiboot_struct);
}