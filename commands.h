#ifndef COMMANDS_H
#define COMMANDS_H 1

void runCommand(char *com);

int isCommand(char *line);

int isBasicType(char *line);

int isCallType(char *line);

int isExecutableType(char *line);

int isValidType(char *line);

#endif
