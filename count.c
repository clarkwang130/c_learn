#include <stdio.h>

int main() {
    int c;
    int letter[26];

    for (int i = 0; i < 26; ++i){
        letter[i] = 0;
    }
    for (int c = getchar(); c != EOF; c = getchar())
    /*while ((c = getchar()) != EOF)*/ {
        if (c >= 'a' && c <= 'z') {
            ++letter[c-'a'];
        }
        else if (c >= 'A' && c<= 'Z') {
            ++letter[c-'A'];
        }
        
    }

    for (int i = 0; i < 26; ++i) {
        printf("%c / %c \t| ", i + 'a', i + 'A');
        for (int j = 0; j < letter[i]; ++j) {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}