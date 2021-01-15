#include <malloc/malloc.h>
//An array of memory blocks
memory_block *blocks[MAX_BLOCK_SIZE];
//Amount of blocks
int block_count = 0;
void *malloc(size_t size)
{
    //Create a new block
    memory_block *block = (memory_block*) ((unsigned int) size + MAX_BLOCK_SIZE + sizeof(memory_block));
    //The result to be returned
    void *result;
    //Check if size exceeds max memory block size
    if(size >= MAX_BLOCK_SIZE)
    {
        //Change last block to new block
        blocks[block_count - 1] = block;
        //Current block is null
        blocks[block_count] = NULL;
        //Remove 1 from count
        block_count--;
    }
    else
    {
        //Set current block to new block
        blocks[block_count] = block;
    }
    //Set free space to max block - size
    blocks[block_count]->free = (MAX_BLOCK_SIZE - size);
    //Set current block index
    blocks[block_count]->index = block_count;
    //Set the size
    blocks[block_count]->size = size;
    //Set result
    result = (void*)((unsigned int) size + MAX_BLOCK_SIZE);
}