#include <stdio.h>
#include <ctype.h>

void print(char *s)
{
	printf("%s\n", s);
}

int size(char *str)
{
	int sz = 0;
	while(str[sz] != '\0')
		sz++;
	return sz;
}

int startsWith(char *tg, char c)
{
	if(tg[0] == c)
		return 1;
	return 0;
}

char * clear(char *line)
{
	int sz = size(line);
	//printf("Size of line = %i\n", sz);
	for(int i = 0; i < sz; i++)
	{
		line[i] = '\0';
	}
	return line;
}

char * readline(char *line)
{
	char c;
	int i = 0;
	while(1)
	{
		c = getchar();
		if(c == '\n') break;
		line[i] = c;
		i++;
	}
	//i++;
	line[i] = '\0';
	return line;
}

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

int sameSize(char *a, char *b)
{
	int as = size(a);
	int bs = size(b);
	//printf("a size = %i - b size = %i\n", as, bs);
	if(as != bs)
		return 0;
	else
		return 1;
}

void cutstring(char *str, int eindx, char *target)
{
	if(eindx > size(str))
	{
		print("END INDEX IS GREATER THAN SIZE OF STRING");
		return;
	}
	if(eindx < 0)
	{
		print("END INDEX CAN'T BE LESS THAN ZERO");
		return;
	}
	if(!sameSize(str, target))
	{
		print("TARGET STRING SIZE MUST BE EQUAL TO ORIGIN STRING");
		return;
	}
	int i = 0;
	for(; i < eindx; i++)
	{
		target[i] = str[i];
	}
	
	target[i] = '\0';
}

void rcutString(char *orig, int bindx, char *target)
{
	if(bindx > size(orig))
	{
		print("BEGIN INDEX IS GREATER THAN SIZE OF STRING");
		return;
	}
	if(bindx < 0)
	{
		print("BEGIN INDEX CAN'T BE LESS THAN ZERO");
		return;
	}
	if(!sameSize(orig, target))
	{
		print("TARGET STRING SIZE MUST BE EQUAL TO ORIGIN STRING");
		return;
	}
	int i = 0;
	for(; bindx + i < size(orig); i++)
	{
		target[i] = orig[bindx + i];
	}
	target[i] = '\0';
}

void cloneString(char *orig, char *targ)
{
	if(sizeof orig != sizeof targ)
	{
		print("SIZE OF ORIGIN AND TARGET STRING MUST BE EQUALS");
		return;
	}
	int i = 0;
	for(; i < size(orig); i++)
	{
		targ[i] = orig[i];
	}
	//printf("size of targ = %i\n", size(targ));
	targ[i] = '\0';
}

void substring(char *orig, int bindx, int eindx, char *target)
{
	printf("args = %s,%i,%i,%s\n", orig, bindx, eindx, target);
	if(sizeof orig != sizeof target)
	{
		print("SIZE OF ORIGIN AND TARGET STRING MUST BE EQUALS");
		return;
	}
	if(bindx < 0){
		print("BEGIN INDEX MUST BE GREATER THAN 0 OR EQUAL");
		return;
	}
	if(eindx > size(orig)){
		print("END INDEX CAN'T BE GREATER THAN SIZE OF ORIGIN STRING");
		return;
	}
	if(eindx < bindx){
		print("END INDEX MUST BE GREATER THAN BEGIN INDEX");
		printf("EINDX = %i, BINDX = %i\n", eindx, bindx);
		return;
	}
	if(eindx < 1){
		print("END INDEX MUST BE GREATER THAN 1 OR EQUAL");
		return;
	}
	int i = 0;
	for(;bindx + i < eindx; i++)
	{
		printf("Copying %c to target at index %i\n", orig[bindx+i], i);
		target[i] = orig[bindx+i];
	}
	target[i] = '\0';
}

int equals(char *a, char *b)
{
	//check for same size.
	if(!sameSize(a,b))
		return 0;
	//here we know what the size of both string are equal
	for(int i = 0; i < size(a); i++)
	{
		//printf("check %c != %c\n", a[i], b[i]);
		if(a[i] != b[i])
			return 0;
	}
	return 1;
}
char * toUpperCase(char *s)
{
	for(int i = 0; i < size(s); i++)
	{
		s[i] = toupper(s[i]);
	}
	return s;
}

int indexOf(char *source, char target)
{
	for(int i = 0; i < size(source); i++)
	{
		if(source[i] == target)
		{
			return i;
		}
	}
	return -1;
}
