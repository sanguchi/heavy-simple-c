#ifndef TYPES_H
#define TYPES_H 1
typedef enum {true = 1, false = 0} state;

struct integer{
	char name[9];
	int value;
};

struct string{
	char name[9];
	char value[255];
};

struct boolean{
	char name[9];
	state value;
};

struct config{
	state running;
	int lines;
};

typedef struct {
	struct type *t;
	int asize;
	int maxSize;
} array;

#endif
