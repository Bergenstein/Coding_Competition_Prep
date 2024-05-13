#include "data_structures.h"

void reset(stack* stk) {stk->top = EMPTY;}

void push(char c, stack* stk)
{
    stk -> top++; //increment the top
    stk ->s[stk->top]=c; //stick c unto stk's new top
}

char pop(stack* stk) {return (stk -> s[stk->top--]);}

char top(const stack* stk) {return stk->s[stk->top];}

int is_empty(const stack* stk) {return stk->top == EMPTY;}

int is_ful(const stack* stk) {return stk->top == FULL;}
