#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACKTYPE float
#include "stack.c"

#define WHITESPACE " \t\n\v\f\r"
#define OPER(op) n = pop(st); push(st, pop(st) op n); return;

void interpret(char *word, stack *st) {
    float n = 0;

    sscanf(word, "%g", &n);
    if(n != 0 || *word == '0') {
        push(st, n);
        return;
    }

    switch(*word) {
        case '+': OPER(+)
        case '-': OPER(-)
        case '*': OPER(*)
        case '/': OPER(/)

        case '.':
            printf("%g\n", pop(st));
            return;

        default:
            push(st, 0);
            return;
    }
}

void eval(char input[], stack *st) {
    char *r = NULL;
    r = strtok(input, WHITESPACE);

    while(r != NULL) {
        interpret(r, st);
        r = strtok(NULL, WHITESPACE);
    }
}

int main(int argc, char *argv[]) {
    stack stack;
    stack.len = 0;

    char input[1024];
    printf("> ");
    while(fgets(input, 1024, stdin) != NULL) {
        eval(input, &stack);
        printf("> ");
    }
}
