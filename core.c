#include <stdio.h>
#include <string.h>
#include "utils.c"
typedef enum { false, true } bool;
void print(char *args)
{
	printf("%s\n", args);
}
typedef struct integer{
	char name[9];
	int value;
} INT;
typedef struct string{
	char name[9];
	char value[100];
} STRING;
typedef struct boolean{
	
	char name[9];
	bool value;
} BOOL;

void parse(char *line)
{
	printf("LINE = ");
	printf(line);
	printf(", SIZE = %i\n",sizeof(line));
	char l = line[0];
	if(isLetter(l))
	{
		printf("%i Is a Letter", l);
	}
	else
	{
		printf("%i isn't a Letter", l);
	}
}
void *char readline()
{
	char line[255];
	char c;
	while(1)
	{
		c = getchar();
		if(c == '\n') break;
		
	}
}
void interpreter()
{
	
	print("INTERPRETER MODE. COMMANDS: [HELP, LIST, CLEAR, EXIT]");
	
	
}

int main()
{
	interpreter();	
	return 0;
}
