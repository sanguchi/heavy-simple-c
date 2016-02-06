#include <stdio.h>
#include "utils.h"
#include "types.c"
#include "globals.h"
#include "commands.h"

int running;


void parse(char *line)
{
	//ignore empty lines, AKA press enter because fun.
	if(size(line) == 0)
		return;
	//ignore comments.
	if(startsWith(line, ';'))
		return;
	line = toUpperCase(line);
	//printf("parsing %s\n", line);
	if(isCommand(line))
	{
		//print("COM FOUND");
		runCommand(line);
		return;
	}
	//line syntax =  <TYPE> <NAME> = EXPR
	//char build[255];
	char name[9];
	char type[9];
	int i = 0;
	
	if(!isLetter(line[i])){
		printf("LETTER EXPECTED, NOT %c\n", line[i]);
		return;
	}
	//current char to analyze.
	char c = line[i];
	while(i < size(line) && isLetter(c))
	{
		c = line[i];
		i++;
	}
	//space char expected next to type declaration.
	if(!isSpace(c)){
		printf("INVALID CHARACTER [%c]\n", c);
		return;
	}
	//here we obtain the type.
	cloneString(line, type);
	cutstring(line, i-1, type);
	if(!isValidType(type)){
		printf("INVALID TYPE [%s]\n", type);
		return;
	}
	while(isSpace(line[i]))
		i++;
	if(line[i] == '='){
		print("NAME NOT DEFINED");
		return;
	}
	c = line[i];
	//printf("CHAR  = %c", c);
	if(!isLetter(c)){
		printf("NAMES MUST START WITH LETTERS, NOT [%c]\n", c);
		return;
	}
	//advance over name's letters.
	int ii = 0;
	ii = i;
	printf("ii = %i, i = %i\n", ii, i);
	while(i < size(line) && isLetter(c))
	{
		c = line[i];
		i++;
	}
	printf("ii = %i, i = %i\n", ii, i);
	printf("call substring with parameters : BINDX = %i, EINDX = %i\n",ii , i);
	//here we obtain the type.
	cloneString(line, name);
	substring(line, ii, i, name);
	printf("NAME = [%s]\n", name);
}
