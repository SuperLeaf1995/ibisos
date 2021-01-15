#include <malloc/malloc.h>
extern "C" void *malloc(unsigned num_bytes);
extern "C" void free(void *ptr);

void *malloc(unsigned num_bytes)
{
    union header *p, *q;
    unsigned size = (num_bytes + sizeof(union header) - 1) / (sizeof(union header) + 1);
}

void free(void *ptr)
{

}