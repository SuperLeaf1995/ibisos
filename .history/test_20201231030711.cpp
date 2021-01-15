#include <stdio.h>
struct m
{
int i;
};

void *malloc(size_t size)
{
}
int main()
{
	struct m* item = new m();
	item->i = 121;
}
