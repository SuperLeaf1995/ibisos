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

inline void insert_tag(struct boundary_tag* tag, int index)
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

inline void remove_tag(struct boundary_tag* tag)
{
    //Check if free page at tag's index is the same as tag
    if(free_pages[tag->index] == tag) free_pages[tag->index] = tag->next;
    //Check if the previous instance is not null
    if(tag->prev != NULL) tag->prev->next = tag->next;
    //Check if the next instance is not null
    if(tag->next != NULL) tag->next->prev = tag->prev;

    //Erase any evidence of this tag existing by setting next tag to null
    tag->next = NULL;
    //And the previous instance
    tag->prev = NULL;
    //And then set the index to -1
    tag->index = -1;
}

//For patching split pages
inline struct boundary_tag *melt_left(struct boundary_tag* tag)
{
    //Get left split of tag
    struct boundary_tag *left = tag->split_left;
    //Update real size of left
    left->real_size += tag->real_size;
    //Set the right split
    left->split_right = tag->split_right;
    //Check if the right split os not null
    if(tag->split_right != NULL) tag->split_right->split_left = left;
    //Return the left split
    return left;
}

inline struct boundary_tag *absorb_right(struct boundary_tag* tag)
{
    //Set the right tag split
    struct boundary_tag *right = tag->split_right;
    //Remove the right tag
    remove_tag(right);
    //Update the real size
    tag->real_size += right->real_size;
    //Set the right split
    tag->split_right = right->split_right;
    //Check if the right split is not null
    if(right->split_right != NULL) right->split_right->split_left = tag;
    //Return the tag
    return tag;
}

inline struct boundary_tag *split_tag(struct boundary_tag* tag)
{
    //Get the remainder of tag size, boundary_tag size, and real size of tag
    unsigned int remainder = tag->real_size - sizeof(struct boundary_tag) - tag->size;
    //Create a new tag
    struct boundary_tag* new_tag = (struct boundary_tag*)((unsigned int) tag + sizeof(struct boundary_tag) + tag->size);
    //Set the magic of new tag
    new_tag->magic = ALLOCATOR_MAGIC;
    //Set the real size
    new_tag->real_size = remainder;
    //Set the next instance of a tag
    new_tag->next = NULL;
    //Set the previous instance of a tag
    new_tag->prev = NULL;
    //Set the left split
    new_tag->split_left = tag;
    //Set tje right split
    new_tag->split_right = tag->split_right;
    //Check if right split is not null
    if(new_tag->split_right != NULL) new_tag->split_right->split_left = new_tag;
    //Set split right to new tag
    tag->split_right = new_tag;
    //Set real size
    tag->real_size = new_tag->real_size;
    //Add the new tag
    insert_tag(new_tag, -1);
    //Return the new tag
    return new_tag;
}

struct boundary_tag *allocate_new_tag(unsigned int size)
{
    //Number of pages
    unsigned int pages;
    //How much space is needed
    unsigned int usage;
    struct boundary_tag *tag;
    usage = size + sizeof(struct boundary_tag);
    //Perfect the amount of space
    pages = usage / page_size;
}