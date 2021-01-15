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
    //Is the index negative?
    if(index < 0)
    {
        //Get the real index of the tag by exponent
        real_index = get_exponent(tag->real_size - sizeof(struct boundary_tag));
        //Check if the real index is less than the minimum of exponent
        if(real_index < MIN_EXP)    real_index = MIN_EXP;
    }
    else
        //Set real index to index
        real_index = index;
    //Check if the number of free pages is not empty
    if(free_pages[real_index] != NULL)
    {
        
    }
}