#include <malloc/malloc.h>
void *malloc(size_t size)
{
    struct memory_block *curr, *prev;
    void* result;
    if(!(free_blocks->size))
    {
        //Initialize memory
        free_blocks->size = MAX_BLOCK_SIZE - sizeof(struct memory_block);
    }
}