#include <malloc/malloc.h>
#include <memset/memset.h>
#include <memcpy/memcpy.h>

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