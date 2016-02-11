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
	char name[255];
	char type[255];
	char expr[255];
	int i = 0;
	if(!isLetter(line[i])){
		printf("LETTER EXPECTED, NOT %c\n", line[i]);
		return;
	}
	//current char to analyze.
	char c = line[i];
	while(i <= size(line) && isLetter(c))
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
	//printf("starting letters at %i\n", i);
	int r = 0;
	while(i < size(line))
	{
		c = line[i];
		if(!isLetter(c))
			break;
		i++;
		r++;
	}
	//here we obtain the name.
	cloneString(line, name);
	cutstring(line, i,name);
	//printf("cutstring to name: %s\n", name);
	char temp[255];
	cloneString(name, temp);
	rcutString(temp,i - r, name);
	if(size(name) > 7){
		print("NAME SIZE MUST BE LESS THAN 8 CHARACTERS");
		printf("ACTUAL SIZE = %i\n", size(name));
		printf("NAME = [%s]\n", name);
		return;
	}
	
	//now we have the name, we'll obtain the expression. but first, we must search the '=' sign.
	while(isSpace(line[i]))
		i++;
	if(line[i] != '='){
		print("CHARACTER '=' BEFORE NAME");
		return;
	}
	i++;
	while(isSpace(line[i]))
		i++;
	if(i >= size(line)){
		print("EXPRESSION EXPECTED BEFORE '='");
		return;
	}
	cloneString(line , expr);
	rcutString(line, i, expr);
	printf("TYPE = [%s]\n", type);
	printf("NAME = [%s]\n", name);
	printf("EXPR = [%s]\n", expr);
}
