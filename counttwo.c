#include <stdio.h>
//编写一个统计空格、制表符与换行符个数的程序。




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
int is_lower(char c){
    return (c >= 'a' && c <= 'z');
}

int is_upper(char c){
    return (c >= 'A' && c <= 'Z');
}

int is_number(char c){
    return (c >= '0' && c <= '9');
}

int is_white(char c){
    return (c == ' ' || c == '\n' || c == '\t');
}

int count(char *s,int len, int (*fun)(char)){
    int ct;
    ct = 0;
    for(int i = 0; i < len ; i++){
        if (fun(s[i]))
            ++ct;
    }
    return ct;
}

int main(){
    int c;
    int whitespace, t, n;
    char line[1000];
    int len;
    int al_white, al_lower, al_upper, al_number;
    

    al_white = 0;
    al_lower = 0;
    al_upper = 0;
    al_number = 0;
    whitespace = 0;
    t = 0;
    n = 0;

    while ((len = mygetline(line, 1000)) > 0){
        al_white += count(line, len, is_white);
        al_lower += count(line, len, is_lower);
        al_upper += count(line, len, is_upper);
        al_number += count(line, len, is_number);
    }
    printf("%d\n%d\n%d\n%d", al_white, al_lower, al_upper, al_number);
    //printf("white%d", whitespace + t + n);

    while ((c = getchar()) != EOF){
        if (c == ' ')
            ++whitespace;
        if (c == '\t')
            ++t;
        if (c == '\n')
            ++n;
    }
    //printf("\\t%d,\\n%d,whitespace%d", t, n, whitespace);
}