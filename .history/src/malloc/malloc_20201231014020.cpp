#include <malloc/malloc.h>

void *malloc(size_t size)
{
    //Create a new memory block
    struct memory_block *block = (memory_block*) size + block_count + sizeof(struct memory_block)
    //Reduce free space
    block->free_space = MAX_ALLOC_MEMORY - size;
    //Set the size
    block->size = size;
    //Create an item given size and block count
    //Check if asked for size is > allocatable memory
    if(size > MAX_ALLOC_MEMORY)
    {
        //Reduce block count by 1
        block_count = block_count - 1;    
        //Set the index
        block->block_index = block_count;
        //Replace last block with a new one
        blocks[block_count] = block;
        //Set the next block identified by previous block to block
        blocks[block_count]->prev_block->next_block = block;
    }
    else
    {
        //Set the block index
        block->block_index = block_count;
        //Set the block at block_count
        blocks[block_count] = block;
    }
    //Update block count
    block_count++;
}