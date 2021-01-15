#include "malloc.h"
#include <stddef.h>
#define MAX 4049
struct memory_block* blocks[4049];

void *malloc(size_t size)
{
    void* item = (void*) size + sizeof(size) + MAX;
}