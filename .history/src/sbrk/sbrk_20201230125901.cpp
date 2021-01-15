#include <sbrk/sbrk.h>
extern "C" void memory_stack_top();
extern "C" void memory_stack_bottom();
void *heap = (void*) 0;
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