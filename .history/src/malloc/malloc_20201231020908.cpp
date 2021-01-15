#include <malloc/malloc.h>
extern "C" void *malloc(unsigned num_bytes);
extern "C" void free(void *ptr);

void *malloc(unsigned num_bytes)
{
    union header *p, *q;
    unsigned size = (num_bytes + sizeof(union header) - 1) / (sizeof(union header) + 1);
    q = freep;
    do
    {
        p = q->s.link;
        if(p->s.size > size)
        {
            p->s.size -= size;
            p += p->s.size;
            p->s.size = size;
            freep = q;
            return p + 1;
        }
        else if(p->s.size == size)
        {
            q->s.link = p->s.link;
            freep = q;
            return p + 1;
        }
        q = p;
    }
    while(p != freep);
    if(size < MAX_BLOCK) size = MAX_BLOCK;
    p = (header*) sbrk(size * sizeof(*p));
    if(p == (void*) -1) return 0;
    p->s.size = size;
    p->s.link = freep->s.link;
    return malloc(num_bytes);
}

void free(void *ptr)
{
    union header *bp = (union header*) ptr - 1, *p;
    if(ptr == 0) return;
    for(p = freep; p = p->s.link)
        if((bp > p && bp < p->s.link) || (p >= p->s.link && (bp > p || bp < p)))
}