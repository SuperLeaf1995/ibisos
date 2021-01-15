#include <malloc/malloc.h>

void *malloc(size_t size)
{
    //Check if asked for size is > allocatable memory
    if(size > MAX_ALLOC_MEMORY)
    {
        //The new block
        struct memory_block *block = (memory_block*) size + block_count;
        //Reduce block count by 1
        block_count = block_count - 1;
        //Replace last block with a new one
        blocks[block_count] = block;
        //Set the next block identified by previous block to block
        blocks[block_count]->prev_block->next_block = block;
    }
}