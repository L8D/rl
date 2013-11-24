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
        return 0;

    st->len--;
    STACKTYPE n = st->arr[st->len];
    st->arr[st->len] = 0;
    return n;
}

void rshift(stack *st) {
    if(st->len == 0 || st->len == 1) return;

    STACKTYPE n = pop(st);
    for(int i = st->len - 1; i >= 0; i--) {
        st->arr[i + 1] = st->arr[i];
    }

    st->arr[0] = n;
}
