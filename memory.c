#include "types.c"
//#include "utils.h"
#include <stdio.h>

struct object list[20];
int i = 0;

void addToken(struct object t)
{
	if(i > 19)
		printf("MEMORY FULL");
	list[i] = t;
	i++;
}
struct integer t;
char n[] = "testint";
char ty[] = "INTEGER";

struct object test;

struct integer it;

int main()
{
	int val = 15;
	t.value = &val;
	test.name = n;
	test.type = ty;
	test.value = &t;
	printf("val = %i\n",*t.value);
	it = *((struct integer *)&test.value);
	int vv = *it.value;
	printf("name = %s\ntype = %s\nvalue = %i\n", test.name, test.type, vv);
	return 0;
}
