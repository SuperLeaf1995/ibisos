#include <malloc/malloc.h>
extern "C" void initiate_mini_kernel();
typedef struct block
{
    char* t;
};
void initiate_mini_kernel()
{
    block* b = (block*) malloc(sizeof(block));
    //Kernel loop
    while(true)
    {
    
    }
}