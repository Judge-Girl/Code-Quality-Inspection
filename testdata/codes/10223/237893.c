#include <stdio.h>
#include <string.h>
#define MAXN 10001
 
int is_vowel (char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main () {
    char buf[MAXN];
    while (scanf("%s", buf) != EOF) {
        int I, J;
        scanf ("%d%d", &I, &J);
        int I_start, I_end, J_start, J_end;
        int head = 0, n = 0;
        int nn = strlen(buf);
 
        for (int i = 0; i < nn; ++i) {
            if (buf[i] == 'a' || buf[i] == 'e' || buf[i] == 'i' || buf[i] == 'o' || buf[i] == 'u') {
                if (n == I) {
                    I_start = head; 
                    I_end = i;
                }
                else if (n == J) {
                    J_start = head;
                    J_end = i;
                }
                ++n;
                head = i + 1;
                if (n > I && n > J) {
                    break;
                }
            }
        }
        char output[MAXN];
        output[nn] = '\0';
 
        for (int i = 0; i < nn; ++i) {
            if (i >= I_start && i <= I_end) {
                output[i] = buf[i];
            }
            else output[i] = '+';
        }
        printf("%s\n", output);
        for (int i = 0; i < nn; ++i) {
            if (i >= J_start && i <= J_end) {
                output[i] = buf[i];
            }
            else output[i] = '+';
        }
        printf("%s\n", output);
        /*
        for (int i = 0; i < nn; ++i) {
            if (i >= J_start && i <= J_end) {
                used[i] = 1;
                printf("%c", buf[i]);
            }
            else printf("+");
        }
        */
        for (int i = 0; i < nn; ++i) {
            if (!(i >= J_start && i <= J_end) && !(i >= I_start && i <= I_end)) {
                output[i] = buf[i];
            }
            else output[i] = '+';
        }
        printf("%s\n", output);
    }
    return 0;
}
