#include <malloc/malloc.h>

void *malloc(size_t size)
{
    if(size > MAX_MEMORY_SIZE)
        return NULL;
}