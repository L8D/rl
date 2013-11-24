#include "rlwords.h"

void RLdrop(stack *st) {
    pop(st);
}

void RLtype(stack *st) {
    printf("%s\n", pop(st).s);
}

void RLlshift(stack *st) {
    if(st->len == 0 || st->len == 1) return;

    STACKTYPE n = st->arr[0];
    st->len--;
    for(int i = 1; i <= st->len; i++) {
        st->arr[i - 1] = st->arr[i];
    }

    push(st, n);
}

void RLrshift(stack *st) {
    if(st->len == 0 || st->len == 1) return;

    STACKTYPE n = pop(st);
    for(int i = st->len; i >= 0; i--) {
        st->arr[i + 1] = st->arr[i];
    }

    st->len++;
    st->arr[0] = n;
}

void RLdebug(stack *st) {
    if(st->len == 0) return;

    printf("%g", st->arr[0].f);
    for(int i = 1; i < st->len; i++) {
        printf(", %g", st->arr[i].f);
    }

    printf("\n");
}

// if these are not in alphabetical order, the interpret will fail
static RLword RLwordlist[] = {
    {"..", RLdebug},
    {"<<", RLlshift},
    {">>", RLrshift},
    {"drop", RLdrop},
    {"type", RLtype}
};

void RLfind(char *word, stack *st) {
    int n;
    for(int i = 0; i < sizeof(RLwordlist)/sizeof(*RLwordlist); i++) {
        n = strcasecmp(word, RLwordlist[i].word);
        if(n < 0) break;

        if(n == 0) (*(RLwordlist[i].func))(st);
    }
}
