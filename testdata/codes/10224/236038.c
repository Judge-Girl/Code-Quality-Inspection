#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
int main()
{
    int N;
    scanf("%d", &N);
    char userName[32][32];
    int balance[32];
    for (int i = 0; i < N; i++) {
        scanf("%s %d", userName[i], &balance[i]);
    }
    char name[32];
    char instr[32];
    char garbage[128];
    while(scanf("%s %s", name, instr) != EOF) {
        int flag = 0;
        int nameNumber = -1;
        for (int i = 0; i < N; i++) {
            if (strcmp(name, userName[i]) == 0)
                nameNumber = i;
        }
        if (nameNumber == -1) {
            fgets(garbage, 128, stdin);
            continue;
        }
 
        for (int i = 0; i < strlen(instr); i++) {
            if (strncmp(instr + i, "earns", 5) == 0) {
                flag = 1;
                int amount;
                scanf("%d", &amount);
                balance[nameNumber] += amount;
            }
            if (strncmp(instr + i, "gives", 5) == 0) {
                flag = 1;
                int amount;
                char second_name[32];
                scanf("%s %d", second_name, &amount);
                int nameNumber2 = -1;
                for (int j = 0; j < N; j++) {
                    if (strcmp(second_name, userName[j]) == 0)
                        nameNumber2 = j;
                }
 
                if (nameNumber2 == -1)
                    continue;
                if (balance[nameNumber] - amount < 0)
                    continue;
                balance[nameNumber] -= amount;
                balance[nameNumber2] += amount;
            }
            if (strncmp(instr + i, "spends", 6) == 0) {
                flag = 1;
                int amount;
                scanf("%d", &amount);
 
                if (balance[nameNumber] - amount < 0)
                    continue;
                balance[nameNumber] -= amount;
            }
            if (strncmp(instr + i, "becomes", 7) == 0) {
                flag = 1;
                int amount;
                scanf("%d", &amount);
                balance[nameNumber] = amount;
            }
        }
        if (flag == 0) {
            fgets(garbage, 128, stdin);
        }
 
    }
    for (int i = 0; i < N; i++) {
        printf("%s %d\n", userName[i], balance[i]);
    }
    return 0;
}
