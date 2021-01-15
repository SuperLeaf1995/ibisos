#include <malloc/malloc.h>
extern "C" void initiate_mini_kernel();
void initiate_mini_kernel()
{
    char* screen = (char*) 0xA0000;
    for(int x = 0; x < 800; x++)
    {
        for(int y = 0; y < 600; y++)
        {
            unsigned index = x * 3 + y * 2400;
            screen[where] = 4 & 255;
        }
    }
    //Kernel loop
    while(true)
    {
    
    }
}