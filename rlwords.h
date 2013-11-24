#include <string.h>
#include "stack.c"

typedef struct {
    char *word;
    void (*func)(stack *);
} RLword;
