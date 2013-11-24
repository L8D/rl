#include "rlwords.h"

void RLdrop(stack *st) {
    pop(st);
}

// if these are not in alphabetical order, the interpret will fail
static RLword RLwordlist[] = {
    {"DROP", RLdrop}
};

void RLfind(char *word, stack *st) {
    int n;
    for(int i = 0; i < sizeof(RLwordlist)/sizeof(*RLwordlist); i++) {
        n = strcasecmp(word, RLwordlist[i].word);
        if(n < 0) break;

        if(n == 0) (*(RLwordlist[i].func))(st);
    }
}
