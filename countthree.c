#include <stdio.h>
#include <string.h>

int mygetline(char *s, int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
int i;
i = 0;
while ((to[i] = from[i]) != '\0')
++i;
}

int main(){
    int len, a;
    char line[1000];
    char all[1000];
    a = 0;
    

    while ((len = mygetline(line, 1000)) > 0){
    
        for (int i = 0; i < len; i++){
            if (line[i] == ' ' && line[i + 1] == ' ')
                continue;
            all[a++] = line[i];
        }

    }
    all[a] = '\0';
    printf("%s", all);
    
    return 0;
}