#ifndef TYPES_H
#define TYPES_H 1
typedef enum {true = 1, false = 0} state;

struct object{
	char *name;
	void *value;
	char *type;
};

struct string{
	char *value;
};


struct integer{
	int *value;
};



struct boolean{
	state value;
};

struct config{
	state running;
	int lines;
};

typedef struct {
	struct list *t;
	int asize;
	int maxSize;
} array;

#endif
