#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "malloc.cpp"
int main()
{
	void* item = (void*) smalloc(sizeof(void*));
	void* mitem = (void*) malloc(sizeof(void*));
	printf("smalloc size: %i", sizeof(item));
	printf("malloc size: %i", sizeof(mitem));
}
