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
    struct mem_block *new_block = (void *)((void *) block + size  + sizeof(struct mem_block));
}
//Merges a block
void __malloc_merge();
//Memory allocator
void *malloc(size_t size)
{

}