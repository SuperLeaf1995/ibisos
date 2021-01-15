#ifndef SBRK_H
#define SBRK_H
extern "C" void memory_stack_top();
extern "C" void memory_stack_bottom();
void *heap = (void*) 0;
extern void *sbrk(int num_bytes);
#endif