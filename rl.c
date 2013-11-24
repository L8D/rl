#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACKTYPE float
#define STACKLEN 256
#include "rlwords.c"

#define WHITESPACE " \t\n\v\f\r"
#define OPER(op) n = pop(st); push(st, pop(st) op n); return
#define BOOLOPER(op) n = pop(st); push(st, pop(st) op n ? -1 : 0); return

void interpret(char *word, stack *st) {
    float n = 0;
    char *r;

    sscanf(word, "%g", &n);
    if(n != 0 || *word == '0') {
        push(st, n);
        return;
    }

    if(word[1] == 0)
    switch(*word) {
        case '+': OPER(+);
        case '-': OPER(-);
        case '*': OPER(*);
        case '/': OPER(/);

        case '>': BOOLOPER(>);
        case '<': BOOLOPER(<);
        case '&': BOOLOPER(&&);
        case '|': BOOLOPER(||);
        case '!': push(st, !pop(st) ? -1 : 0);
        case '=': BOOLOPER(==);

        case '_':
            n = pop(st);
            push(st, n); push(st, n);
            return;

        case ',':
            pop(st);
            return;

        case '.':
            printf("%g\n", pop(st));
            return;

        case '?':
            n = pop(st);
            r = strtok(NULL, WHITESPACE);
            while(r != NULL) {
                if(*r == ':' && r[1] == 0) break;
                if(n) interpret(r, st);
                r = strtok(NULL, WHITESPACE);
            }

            while(r != NULL) {
                if(*r == ';' && r[1] == 0) break;
                if(!n) interpret(r, st);
                r = strtok(NULL, WHITESPACE);
            }
            return;
    }

    RLfind(word, st);
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

    if(argc == 1) {
        char input[1024];
        while(fgets(input, 1024, stdin) != NULL) {
            eval(input, &stack);
        }
    }
}
