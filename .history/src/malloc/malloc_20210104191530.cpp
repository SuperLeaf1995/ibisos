#include <malloc/malloc.h>
//Page count
int page_count = 0;
//Page
mem_block block_page[MAX_MEMORY_BLOCK_SIZE];

//Initialization for a block of memory
void __malloc_initialize()
{
    //Set size of block pages
    free_list->size - MAX_MEMORY_BLOCK_SIZE - sizeof(struct mem_block);
    //Set free to 1
    free_list->free = 1;
    //Empty out the next block
    free_list->next = NULL;
}
//Splits a block
void __malloc_split(struct mem_block *block, size_t size)
{
    //Create a new block
    struct mem_block *new_block = (void *)((void *) block + size + sizeof(struct mem_block));
    //Set the size
    new_block->size = (block->size) - size + sizeof(struct mem_block);
    //Set free to 1
    new_block->free = 1;
    //Set the next block
    new_block->next = block->next;
    //Set the block size
    block->size = size;
    //Set block free to 0
    block->free = 0;
    //Set the next block for block to be new block
    block->next = new_block;
}

//Merges a block
void __malloc_merge()
{
    //Current and previous memory block
    struct mem_block *current, *previous;
    //Set current block to free list
    current = free_list;
    //Loop until the next block is null
    while((current->next) != NULL)
    {
        //Check if current and next block is free
        if((current->free) && (current->next->free))
        {
            //Update the size of current block
            current->size += (current->next->size) + sizeof(struct mem_block);
            //Set the next block to next block's next block
            current->next = current->next->next;
        }
        //Set the previous block to the current block
        previous = current;
        //Move to the next block
        current = current->next;
    }
}

//Memory allocator
void *malloc(size_t size)
{
    
}