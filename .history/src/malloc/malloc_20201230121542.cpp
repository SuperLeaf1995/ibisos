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
        //Set the previous instance of free page to tag
        free_pages[real_index]->prev = tag;
        //Set the next instance to current free page
        tag->next = free_pages[real_index];
    }
    //Set the current free page instance to tag
    free_pages[real_index] = tag;
}

void remove_tag(struct boundary_tag* tag)
{
    //Check if free page at tag's index is the same as tag
    if(free_pages[tag->index] == tag) free_pages[tag->index] = tag->next;
    //Check if the previous instance is not null
    if(tag->prev != NULL) tag->prev->next = tag->next;
    //Check if the next instance is not null
    if(tag->next != NULL) tag->next->prev = tag->prev;
}