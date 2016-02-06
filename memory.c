#include "types.c"
#include "utils.h"
struct integer ints[30];
struct string strings[30];
struct boolean bools[30];

int exists(char *n)
{
	for(int i = 0; i < sizeof(ints); i++)
	{
		if(equals(n, ints[i].name))
			return i+1;
	}
	return 0;
}
void intDelete(int i)
{
	
}
void addInt(char *n, int v)
{
	//if(exists(n))
		
}
