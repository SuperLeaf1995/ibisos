#include <stdio.h>
struct m
{
int i;
};
int main()
{
	struct m* item = new m(12);
	item->i = 121;
}
