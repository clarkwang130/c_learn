#include <stdio.h>

int main(){
    char s[1000];
    char* top = s - 1;
    char c;

    while ((c = getchar()) != '@' && c != EOF){
        if (c == '(' || c == '[' || c == '{'){
            *(++top) = c;
        }

        if (c == ')' || c == ']' || c == '}'){
            if (top < s) {
                printf("NO\n"); 
                return 0;
            }

            if ((c == ')' && *top == '(') || (c == ']' && *top == '[') || (c == '}' && *top == '{')){
                --top;
            }
            else{
                printf("NO");
                return 0;
            }

        }
    }

    if (top == s - 1)
        printf("YES");
    else
        printf("NO");
    
    return 0;

}