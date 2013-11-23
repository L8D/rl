#include "stack.h"

void push(stack *st, float n) {
    st->arr[st->len] = n;
    st->len++;
}

float pop(stack *st) {
    if(st->len == 0)
        return 0;

    st->len--;
    STACKTYPE n = st->arr[st->len];
    st->arr[st->len] = 0;
    return n;
}
