#include <stdio.h>
#include "utils.h"
#include "globals.h"

int running;

int isBasicType(char *line)
{
	char *com[3] = {"BOOL", "INT", "STRING"};
	for(int i = 0; i < 3; i++)
	{
		//printf("Checking against %s\n",com[i]);
		if(equals(line, com[i]))
			return 1;
	}
	return 0;
}

int isExecutableType(char *line)
{
	char *com[4] = {"FUNC", "FUNCX", "VOID", "VOIDX"};
	for(int i = 0; i < 4; i++)
	{
		//printf("Checking against %s\n",com[i]);
		if(equals(line, com[i]))
			return 1;
	}
	return 0;
}

int isCallType(char *line)
{
	char *com[4] = {"CALL", "CALLX", "RETURN", "RETURNX"};
	for(int i = 0; i < 4; i++)
	{
		//printf("Checking against %s\n",com[i]);
		if(equals(line, com[i]))
			return 1;
	}
	return 0;
}

int isValidType(char *line)
{
	if(isBasicType(line))
		return 1;
	if(isExecutableType(line))
		return 1;
	if(isCallType(line))
		return 1;
	return 0;
}

int isCommand(char *line)
{
	char *com[4] = {"EXIT", "CLEAR", "HELP", "LIST"};
	for(int i = 0; i < 4; i++)
	{
		//printf("Checking against %s\n",com[i]);
		if(equals(line, com[i]))
			return 1;
	}
	return 0;
}

void runCommand(char *com)
{
	if(equals(com, "EXIT"))
	{
		print("Bye~");
		running = 0;
	}
	if(equals(com, "CLEAR"))
		running = 0;
}

int containRefs(char *s)
{
	for(int i = 0; i < size(s); i++)
	{
		if(s[i] == '$')
		{
			return 1;
		}
	}
	return 0;
}

void solveRefs(char *r)
{
	
