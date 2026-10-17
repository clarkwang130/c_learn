#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void fatal_error(const char* message)
{
    fprintf(stderr, "Fatal error: %s", message);
    exit(1);
}
int is_in(char c, const char* str)
{
    while (*str != '\0' && c != *str)
        ++str;
    return *str == '\0' ? 0 : 1;
}
int match(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int main(){
    int c;
    stack* s = make_stack(1000);

    while ((c = getchar()) != '@' && c != EOF){
        if (is_in(c, "([{")){   // is open bracket
            if (is_full(s)){
                fatal_error("Stack overflow");
            }

            push(s, c);
        }

        if (is_in(c, ")]}")){   // is close bracket
            if (is_empty(s)){
                fatal_error("Stack underflow");
            }
            
            int open = top(s);           
            
            if (match(open, c)){
                pop(s);
            }
            else{
                fatal_error("Mismatched brackets");
            }
        }
    }

    if (is_empty(s))
        printf("YES");
    else
        printf("NO");
    
    destroy_stack(s);

    return 0;

}