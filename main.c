#include "data_structures.c"
#include <stdio.h>

int main(void)
{
    stack stack_of_char;
    char *str = "Things we do for love!";
    char str_back[20];
    int i=0;
    reset(&stack_of_char);
    printf("the original is: %s\n", str);
    while(str[i]!='\0'){
        printf("%c\n", str[i]);
        push(str[i++], &stack_of_char);
    }
    i=0;
    while(!is_empty(&stack_of_char)&& i<20)
        str_back[i++] = pop(&stack_of_char);
    printf("reverse is: %s\n", str_back);
    printf("\n\n");

}