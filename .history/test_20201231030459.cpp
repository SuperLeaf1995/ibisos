#include <stdio.h>
struct m
{
int i;
};
int main()
{
	struct m* item = new m();
	item->i = 121;
}
