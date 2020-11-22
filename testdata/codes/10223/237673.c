#include <stdio.h>
#include <string.h>

char word[10010];
char sy[10010];
int index[10010];
int visited[10010] = {0};

int main(void)
{
    while (scanf("%s", word) != EOF) {
        int visited[10010] = {0};
        int word_len = strlen(word);
        int sy_len = 0;
        int t = 0;
        int i;
        for (i = 0; i < word_len; i++) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u') {
                index[t] = i;
                t++;
            }
        }
        int ind1, ind2;
        scanf("%d%d", &ind1, &ind2);
        for (i = 0; i < word_len; i++) {
            if (ind1 - 1 >= 0) {
                if (i > index[ind1 - 1] && i <= index[ind1]) {
                    printf("%c", word[i]);
                    visited[i] = 1;
                }
                else {
                    printf("+");
                }
            }
            else {
                if (i <= index[ind1]) {
                    printf("%c", word[i]);
                    visited[i] = 1;
                }
                else {
                    printf("+");
                }
            }
        }
        printf("\n");

        for (i = 0; i < word_len; i++) {
            if (ind2 - 1 >= 0) {
                if (i > index[ind2 - 1] && i <= index[ind2]) {
                    printf("%c", word[i]);
                    visited[i] = 1;
                }
                else {
                    printf("+");
                }
            }
            else {
                if (i <= index[ind2]) {
                    printf("%c", word[i]);
                    visited[i] = 1;
                }
                else {
                    printf("+");
                }
            }
        }
        printf("\n");

        for (i = 0; i < word_len; i++) {
            if (visited[i] == 0)
                printf("%c", word[i]);
            else
                printf("+");
        }
        printf("\n");




    }
}

