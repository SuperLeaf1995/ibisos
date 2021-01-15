#include <malloc/malloc.h>
#include <memset/memset.h>
#include <memcpy/memcpy.h>
#include <stdint.h>

inline int get_exponent(unsigned int size)
{
    if(size < (1 << MIN_EXP))
        return -1;
    int shift = MIN_EXP;
    while(shift < MAX_EXP)
    {
        if((1 << shift) > size) break;
        shift++;
    }
    return shift - 1;
}

void insert_tag(struct boundary_tag* tag, int index)
{
    //Real index for boundary tag
    int real_index;
    //Is the index < 0?
}