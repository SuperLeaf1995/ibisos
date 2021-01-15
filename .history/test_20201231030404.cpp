#include <stdio.h>
struct m
{
int i;
};
int main()
{
	struct m* item = (struct m*) ((int*)4024);
	item->i = 121;
}
