#include <stdio.h>
struct m
{
int i;
};

void *malloc(size_t size)
{
	void* item = (void*)(8094);
	return item + 1;
}
int main()
{
	struct m* item = new m();
	item->i = 121;
}
