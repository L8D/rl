#include "stack.h"

void push(stack *st, STACKTYPE n) {
    if(st->len == STACKLEN) {
        fprintf(stderr, "stack overflow\n");
        return;
    }

    st->arr[st->len] = n;
    st->len++;
}

STACKTYPE pop(stack *st) {
    if(st->len == 0)
        return (item) {0};

    st->len--;
    STACKTYPE n = st->arr[st->len];
    st->arr[st->len] = (item) {0};
    return n;
}
