#include <sbrk/sbrk.h>
void *sbrk(int num_bytes)
{
    void *alloc;
    if(!heap) heap = &memory_stack_top;
    alloc = heap;
    heap = heap + num_bytes;
    if(heap >= &memory_stack_bottom)
        return (void*) -1;
    return alloc;
}