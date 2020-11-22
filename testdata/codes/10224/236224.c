#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(void) {
    int N, money[32], user, tran, user2;
    char name[32][32], insname[32], ins[32], insname2[32];
    char stins[4][32]= {"earns\0", "spends\0", "gives\0", "becomes\0"};
    scanf("%d", &N);
    int i, j;
    for(i = 0; i < N; i++){
        scanf("%s", name[i]);
        scanf("%d", &money[i]);
    }
    while(scanf("%s", insname) != EOF){
        user = -1;
        for(i = 0; i < N; i++){
            if(strcmp(insname, name[i]) == 0){
                user = i;
                break;
            }
        }
        if(user == -1){
            continue;
        }
        else{
            scanf("%s", ins);
            if(strstr (ins, stins[0]) !=NULL){
                scanf("%d", &tran);
                money[user] += tran;
            }
            else if(strstr(ins, stins[1]) != NULL){
                scanf("%d", &tran);
                if(money[user] >= tran){
                    money[user] -= tran;
                }
            }
            else if(strstr(ins, stins[2]) != NULL){
            	
                scanf("%s", insname2);
                scanf("%d", &tran);
                
                if(money[user] >= tran){
                    user2 = -1;
                for(i = 0; i < N; i++){
                    if(strcmp(name[i], insname2)==0){
                        user2 = i;
                        break;
                    }
                }
                if(user2 == -1) continue;
                else{
                    money[user] -= tran;
                    money[user2] += tran; 
                    }
                }
                else continue;
            }
            else if(strstr(ins, stins[3]) != NULL){
                scanf("%d", &tran);
                money[user] = tran;
            }
        }
    }
    for(i = 0; i < N ; i++){
        printf("%s ", name[i]);
        printf("%d\n", money[i]);
    }
}

