#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    char S[100];
    int i, M, digit;
    scanf("%d", &N);
    char name[N][100];
    int bal[N];
    for (i = 0; i < N; i++){
        scanf("%s %d", S, &M);
        strcpy(name[i], S);
        bal[i] = M;
    }
    char ins[100], *num, *temp;
    int k = 0, n1 = -1, n2 = -1;
    char a[6] = "earns", b[7] = "spends", c[6] = "gives", d[8] = "becomes";
    while (scanf("%s",ins)!= EOF) {
        n1 = -1;
        n2 = -1;
        for (i = 0; i < N; i++){
            if (strstr(ins, name[i]) != NULL&&strcmp(ins, name[i])==0){
                n1 = i;
                break;
            }
        }
        if (n1 == -1)
            continue;
        scanf("%s", ins);
        if((strstr(ins, a)) != NULL){
            scanf("%d", &digit);
            if(digit >= 0)
                bal[n1] += digit;
        }
        else if((strstr(ins, b)) != NULL){
            scanf("%d", &digit);
            if(bal[n1] >= digit&&digit >= 0)
                bal[n1] -= digit;
        }
        else if((strstr(ins, c)) != NULL){
            scanf("%s", ins);
            for (i = 0; i < N; i++) {
                if (strstr(ins, name[i]) != NULL&&strcmp(ins, name[i])==0){
                    n2 = i;
                    break;
                }
            }
            if(n2 != -1){
                scanf("%d", &digit);
                if(bal[n1] >= digit&&digit >= 0){
                    bal[n1] -= digit;
                    bal[n2] += digit;
                }
            }
        }
        else if((strstr(ins, d)) != NULL){
            scanf("%d", &digit);
            if (digit >= 0)
                bal[n1] = digit;
        }
    }
    for (i = 0; i < N; i++){
        printf("%s ", name[i]);
        printf("%d\n", bal[i]);
    }
    return 0;
}
