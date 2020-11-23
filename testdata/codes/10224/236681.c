#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    char name[n][32];
    int money[n];
    for(int i = 0; i < n ; i++){
        scanf("%s%d",name[i],&money[i]);
    }
    char inname[32];
    char work[32];
    while(scanf("%s%s",inname,work) != EOF){
        int who = n;
        for(int i = 0; i < n;i++){
            if(strcmp(inname,name[i]) == 0){
                who = i;
                break;
            }
        }
        if(who == n) {
            char ass1[32];
            scanf("%s",ass1);
            if(isdigit(ass1[0])){
                continue;
            }
            else{
                int shit;
                scanf("%d",&shit);
                continue;
            }
        }
        char *ptr;
        ptr = strstr(work,"earns");
        char *ptr1;
        ptr1 = strstr(work,"spends");
        char *ptr2;
        ptr2 = strstr(work,"gives");
        char *ptr3;
        ptr3 = strstr(work,"becomes");
        if(ptr != NULL){
            int money1;
            scanf("%d",&money1);
            money[who] += money1;
        }
        else if(ptr1 != NULL){
            int money2;
            scanf("%d",&money2);
            if((money[who] - money2) < 0) {
                continue;
            }
            money[who] -= money2;
        }
        else if(ptr2 != NULL){
            int money3;
            char name2[32];
            scanf("%s%d",name2,&money3);
            int who2 = n;
            for(int i = 0; i < n;i++){
                if(strcmp(name2,name[i]) == 0){
                    who2 = i;
                    break;
                }
            }
            if(who2 == n) {
                continue;
            }
            if(money[who]-money3 < 0) {
                continue;
            }
            money[who] -= money3;
            money[who2] += money3;
        }
        else if(ptr3 != NULL){
            int money4;
            scanf("%d",&money4);
            money[who] = money4;
        }
        else{
            char fuck[500];
            scanf("%s",fuck);
            if(isdigit(fuck[0])){
                continue;
            }
            else{
                int d;
                scanf("%d",&d);
                continue;
            }
        }
    }
    for(int i = 0; i < n;i++){
        printf("%s %d\n",name[i],money[i]);
    }
}
