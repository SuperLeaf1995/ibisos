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
        //Create a new block
        memory_block *block = (memory_block*) ((unsigned int) size + MAX_BLOCK_SIZE + sizeof(memory_block));
        //Change last block to new block
        blocks[block_count - 1] = block;
        //Current block is null
        blocks[block_count] = NULL;
    }
}