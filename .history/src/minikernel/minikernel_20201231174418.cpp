#include <malloc/malloc.h>
extern "C" void initiate_mini_kernel();
void initiate_mini_kernel()
{
    char* screen = (char*) 0xA0000;
    for(int x = 0; x < 300; x++)
    {
        for(int y = 0; y < 200; y++)
        {
            unsigned index = x * 3 + y * 2400;
            screen[index] = 4 & 255;
            screen[index + 1] = (4 >> 8) & 255;
            screen[index + 2] = (4 >> 16) & 255;
        }
    }
    //Kernel loop
    while(true)
    {
    
    }
}