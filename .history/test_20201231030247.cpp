#include <stdio.h>
struct m
{
int i;
};
int main()
{
	struct m* item = (struct m*) (4024);
	item++;
	item->i = 12;
}
