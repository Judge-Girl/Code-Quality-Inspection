#include <stdio.h>
#include <string.h>


char ans[100000];
unsigned long long int input[12500];
char fin[100000] = {0};

void zero(char ans[100000])
{
    int len = strlen(ans);
    //printf("len %d\n", len);

    unsigned long long int tran = 0, sub = 0;
    int i = 0;

    for (i = 0; i < len; i++) {
        int n = i % 8;
        sub = 0;
        sub = ans[i];
        sub <<= (7 - n) * 8;
        tran |= sub;
        if (i % 8 == 7 || i == len - 1) {
            printf("%llu\n", tran);
            tran = 0;
        }
    }
    if (len % 8 ==0)
        printf("0");
}
void one(unsigned long long int input, char fin[1000000])
{
    unsigned long long int sub = 0;
    char out[9] = {0};
    int i;
    for (i = 0; i < 8; i++) {
        sub = input;
        sub >>= (7 - i) * 8;
        out[i] = sub;
        //printf("i %d out %c\n", i, out[i]);
        if (sub == 0) {
            out[i] = '\0';
            break;
        }

    }

    //printf("fun %s\n", out);
    strcat(fin, out);
}
int main()
{
    int T;
    scanf("%d", &T);
    if (T == 0) {
        scanf("%s", ans);
        zero(ans);
    }
    else if (T == 1) {
        int num;
        scanf("%d", &num);
        int i;
        for (i = 0; i < num; i++) {
            scanf("%llu", &input[i]);
            one(input[i], fin);
        }
        printf("%s", fin);
    }
}

