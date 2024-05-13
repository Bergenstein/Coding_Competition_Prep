#include <ctype.h>
#define MAX_LEN 1000
#define EMPTY - 1 
#define FULL (MAX_LEN - 1)

typedef struct stack 
{
    char s[MAX_LEN];
    int top;
} stack;

void reset(stack* stk);
void push(char c, stack* stk);
char pop(stack* stk);
char top(const stack* stk);
int is_empty(const stack* stk);
int is_full(const stack* stk);
