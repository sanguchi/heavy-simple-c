#include <stdio.h>
#include <ctype.h>
int isNumber(char n)
{
	char numbers[] = "1234567890";
	for(int j = 0; j < sizeof(numbers);j++)
	{
		if(numbers[j] == n)
			return 1;
	}
	return 0;
}
int isSpace(char s)
{
	if(s == ' ')
		return 1;
	return 0;
}
int isLetter(char l)
{
	char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(int i = 0; i < sizeof(letters);i++)
	{
		if(letters[i] == toupper(l))
			return 1;
	}
	return 0;
}
