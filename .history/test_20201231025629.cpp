#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "malloc.cpp"
typedef struct sample
{
	int num1;
	char c1;
};
int main()
{
	sample* msample = (sample*) malloc(sizeof(sample*));
	sample* ssample = (sample*) smalloc(sizeof(sample*));
	msample->num1 = 12;
	ssample->num1 = 12;
	printf("smalloc size: %i", sizeof(ssample));
	printf("malloc size: %i", sizeof(msample));
}
