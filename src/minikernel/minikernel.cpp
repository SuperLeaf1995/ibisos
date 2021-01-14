#include <malloc/malloc.h>
#include <system.h>
extern "C" void initiate_mini_kernel();
void initiate_mini_kernel()
{
    //Initialize the GDT
    init_gdt();
    //Initialize the IDT
    init_idt();
}