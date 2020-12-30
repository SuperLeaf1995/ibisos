#ifndef MALLOC_H
#define MALLOC_H
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif

#define ALLOCATOR_MAGIC     0xC001C0DE
#define MAX_COMPLETE        5

#define MAX_EXP             32
#define MIN_EXP             8

#define MODE_BEST           0
#define MODE_INSTANT        1
#define MODE                MODE_BEST

struct boundary_tag
{
    unsigned int magic;
    unsigned int size;
    unsigned int real_size;
    int index;
    struct boundary_tag *split_left;
    struct boundary_tag *split_right;
    struct boundary_tag *next;
    struct boundary_tag *prev;
};

extern int lock_allocator();
extern int unlock_allocator();
extern void *alloc(int);
extern int alloc_free(void *, int);

void *malloc(size_t);
void *realloc(void *, size_t);
void *calloc(size_t, size_t);
void free(void *);

struct boundary_tag *free_pages[MAX_EXP];
int complete_pages[MAX_EXP];
int flag_initialized = 0;
int page_size = 4096;
int page_count = 16;
#ifdef __cplusplus
}
#endif
#endif