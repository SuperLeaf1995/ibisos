#include <malloc/malloc.h>
//Page count
int page_count = 0;
//Pages
mem_block *block_pages[MAX_MEMORY_BLOCK_SIZE];

//Initialization for a block of memory
void __malloc_initialize();
//Splits a block
void __malloc_split(struct mem_block *block, size_t size);
//Merges a block
void __malloc_merge();
//Memory allocator
void *malloc(size_t size)
{
    
}