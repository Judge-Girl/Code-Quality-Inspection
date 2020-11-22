#include<stdio.h>
#include<string.h>
int main(){
    int n;    scanf("%d",&n);
    char name[32][50];
    int bank[50] = {0};
    for(int i = 0; i < n; i++){
        scanf("%s%d",name[i],&bank[i]);
    }
    char name1[35];
    char name2[35];
    char command[35];
    int money;
    while(scanf("%s%s",name1,command)!=EOF){
        if(strstr(command,"earns")!=NULL){
            scanf("%d",&money);
            for(int i = 0; i < n; i++)
                if(strcmp(name[i],name1) == 0){
                    bank[i] += money;
                }
        }
        else if(strstr(command,"spends")!=NULL){
            scanf("%d",&money);
            for(int i = 0; i < n; i++)
                if(strcmp(name[i],name1) == 0){
                    if(bank[i] - money >= 0)
                        bank[i] -= money;
                }
        }
        else if(strstr(command,"gives")!=NULL){
            scanf("%s",name2);
            scanf("%d",&money);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(strcmp(name[i],name1) == 0 && strcmp(name[j],name2) == 0){
                        if(bank[i] - money >=0){
                            bank[i] -= money;
                            bank[j] += money;
                        }
                        break;
                    }
                }
            }
        }
        else if(strstr(command,"becomes")!=NULL){
            scanf("%d",&money);
            for(int i = 0; i < n; i++){
                if(strcmp(name[i],name1) == 0){
                    if(money >= 0)
                        bank[i] = money;
                    break;
                }
            }
        }
        else{
        	scanf("%d",&money);
        }
    }
    for(int i = 0; i < n; i++){
        printf("%s %d\n",name[i],bank[i]);
    }
    return 0;
}
