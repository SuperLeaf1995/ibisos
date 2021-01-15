#include <malloc/sbrk.h>
extern void *sbrk(int num_bytes);
extern "C" void stack_top();
extern "C" void stack_bottom();
void *heap = (void*) 0;

void *sbrk(int num_bytes)
{
    void *alloc;
    if(!heap) heap = &stack_top;
    alloc = heap;
    heap = heap + num_bytes;
    if(heap >= &stack_bottom)
        return (void*) -1;
    return alloc;
}