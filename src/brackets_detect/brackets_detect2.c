#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void fatal_error(const char* message)
{
    fprintf(stderr, "Fatal error: %s", message);
    exit(1);
}

int main(){
    int c;
    stack* s = make_stack(1000);

    while ((c = getchar()) != '@' && c != EOF){
        if (c == '(' || c == '[' || c == '{'){
            if (is_full(s)){
                fatal_error("Stack overflow");
            }

            push(s, c);
        }

        if (c == ')' || c == ']' || c == '}'){
            if (is_empty(s)){
                fatal_error("Stack underflow");
            }
            
            int t = top(s);           
            
            if ((c == ')' && t == '(') || 
                (c == ']' && t == '[') ||
                (c == '}' && t == '{') ){
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