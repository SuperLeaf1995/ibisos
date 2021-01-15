#include <malloc/malloc.h>
void *malloc(size_t size)
{
    struct memory_block *curr, *prev;
    void* result;
    if(!(free_blocks->size))
    {
        //Initialize memory
        free_blocks->size = MAX_BLOCK_SIZE - sizeof(struct memory_block);
        free_blocks->free = 1;
        free_blocks->prev = NULL;
        free_blocks->next = NULL;
    }

    curr = free_blocks;
    while(((curr->size) < size) || ((curr->free == 0)&&(curr->next != NULL)))
    {
        prev = curr;
        curr = curr->next;
    }

    if(curr->size == size)
    {
        curr->free = 0;
        result = (void*) ++curr;
        return result;
    }
    else if((curr->size) > (size + sizeof(struct memory_block)))
    {
        struct memory_block *new_block = (void*)((void*) curr + size + sizeof(struct memory_block));
        new_block->size = (curr->size) - size - sizeof(struct memory_block);
        new_block->free = 1;
        new_block->next = curr->next;
        curr->size = size;
        curr->free = 0;
        curr->next = new_block;
        result = (void*)(++curr);
        return result;
    }
}

void free(void* ptr)
{
    if(((void *) memory <= ptr) && (ptr <= (void*)(memory + MAX_BLOCK_SIZE)))
    {
        struct memory_block *curr = ptr;
        --curr;
        curr->free = 1;
        struct memory_block *merge_curr, *merge_prev;
        merge_curr = free_blocks;
        while((merge_curr->next) != NULL)
        {
            if((merge_curr->free) && (merge_curr->next->free))
            {
                merge_curr->size += (merge_curr->next->size) + sizeof(struct memory_block);
            }
        }
    }
}