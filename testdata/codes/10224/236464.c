#include <stdio.h>
#include<string.h>
int main(){
    int N;
    char user[32][32];
    int account[32];
    scanf("%d", &N);
    int n;
    char INS[4][8];
    char earns[6] = "earns";
    char spends[7] = "spends";
    char gives[6] = "gives";
    char becomes[8] = "becomes";
 
 
    for(n = 0; n < N; n ++){
        scanf("%s", user[n]);
        scanf("%d", &account[n]);
    }
    char tar1[32];
    char tar2[32];
    while(scanf("%s", tar1) != EOF){
        int t1 = -1, t2 = -1;
        for(t1 = 0; t1 < N; t1 ++){
            if(strcmp(tar1, user[t1]) == 0)
                break;
        }
        if(t1 == N)
        	continue;
        char ins[32];
        int INS = -1;
        int amount;
        scanf("%s", ins);
        if(strstr(ins, earns) != NULL){
            scanf("%d", &amount);
            account[t1] += amount;
        }
 
        else if(strstr(ins, spends) != NULL){
            scanf("%d", &amount);
            if(account[t1] >= amount)
                account[t1] -= amount;
        }
        else if(strstr(ins, gives) != NULL){
            scanf("%s", tar2);
            for(t2 = 0; t2 < N; t2 ++){
                if(strcmp(tar2, user[t2]) == 0)
                    break;
            }
            if(t2 == N)
        		continue;
            scanf("%d", &amount);
            if(account[t1] >= amount){
                account[t1] -= amount;
                account[t2] += amount;
            }
        }
        else if(strstr(ins, becomes) != NULL){
            scanf("%d", &amount);
            account[t1] = amount;
        }
 
    }
     for(n = 0; n < N; n ++){
            printf("%s ", user[n]);
            printf("%d", account[n]);
            if(n != N-1)
                printf("\n");
     }
}
