#include <stdio.h>

#ifndef STACKTYPE
#define STACKTYPE int
#endif

#ifndef STACKLEN
#define STACKLEN 256
#endif

typedef struct {
    STACKTYPE arr[STACKLEN];
    int len;
} stack;

void push(stack *, STACKTYPE);
STACKTYPE pop(stack *);
