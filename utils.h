#ifndef UTILS_H
#define UTILS_H 1

char * clear(char *line);

char * readline(char *line);

void print(char *s);

int startsWith(char *tg, char c);

int isNumber(char n);

int isSpace(char s);

int isLetter(char l);

int sameSize(char *a, char *b);

int size(char *str);

void cutstring(char *str, int eindx, char *target);

void rcutString(char *orig, int bindx, char *target);

void cloneString(char *orig, char *targ);

void substring(char *orig, int bindx, int eindx, char *target);

int equals(char *a, char *b);

char * toUpperCase(char *s);

int indexOf(char *source, char target);

#endif
