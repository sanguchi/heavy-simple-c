#include <stdio.h>
#include "utils.h"
#include "parser.h"
#include "types.c"
#include "globals.h"	

int running;
int lines;


void interpreter()
{	
	print("INTERPRETER MODE. COMMANDS: [HELP, LIST, CLEAR, EXIT]");
	running = 1;
	lines = 0;
	char line[255];
	while(running)
	{
		readline(line);
		parse(line);
		clear(line);
	}
}

int main()
{
	interpreter();	
	return 0;
}
