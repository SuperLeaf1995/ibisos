#include <malloc/malloc.h>

void *malloc(size_t size)
{
    //Check if the size exceeds maximum allocatable memory
    if(size <= MAX_MEMORY_SIZE)
    {
        void* item = (void*) size;
        memory_block* current_block = (memory_block*) size;
        current_block->index = block_count;
        current_block->item = 
    }
}