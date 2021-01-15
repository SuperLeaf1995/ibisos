#include <stdio.h>
struct m
{
int i;
};
int main()
{
	struct m* item = (struct m*) (12+3+2);
	item++;
	item->i = 12;
}
