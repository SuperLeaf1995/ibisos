#include <malloc/malloc.h>
//An array of memory blocks
memory_block blocks[MAX_BLOCK_SIZE];
//Amount of blocks
int block_count = 0;
void *malloc(size_t size)
{
    //The result to be returned
    void *result;
    //Check if size exceeds max memory block size
    if(size >= MAX_BLOCK_SIZE)
    {
        //Remove last block
    }
}