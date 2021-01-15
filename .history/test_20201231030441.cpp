#include <stdio.h>
struct m
{
int i;
};
int main()
{
	struct m* item = new (struct m*);
	item->i = 121;
}
