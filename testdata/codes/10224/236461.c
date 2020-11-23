#include <stdio.h>
#include <string.h>
char username[35][32];
int balance[35];
int main(void){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){scanf("%s %d",username[i],&balance[i]);}
    char user1[32],user2[32],action[32];
    int amount=0;
    while(scanf("%s %s",user1,action)!=EOF){
        int i,j,chose=0;
        for(i=0;i<N;i++){
            if(strcmp(username[i],user1)==0)break;
        }
        if(strstr(action,"earns")!=NULL){chose=1;}
        if(strstr(action,"spends")!=NULL){chose =2;}
        if(strstr(action,"gives")!=NULL){chose =3;}
        if(strstr(action,"becomes")!=NULL){chose =4;}
        if(chose == 0 || i==N){
            char trash[32],trash2;
            scanf("%s%c",trash,&trash2);
            if(trash2!='\n')scanf("%s",trash);
        }
        else if(chose == 3){
            scanf("%s %d",user2,&amount);
            if(amount < 0)continue;
            for(j=0;j<N;j++){
                if(strcmp(username[j],user2)==0)break;
            }
            if(j==N)continue;
            if(i==j)continue;
            if(balance[i]-amount >=0){
                balance[i] -= amount;
                balance[j] += amount;
            }
        }
        else{
            scanf("%d", &amount);
            if(amount < 0)continue;
            if(chose==1){
                balance[i]+= amount;
            }
            else if(chose==2){
                if(balance[i]-amount>=0){
                    balance[i] -= amount; 
                }
            }
            else if(chose==4){
                balance[i] = amount;
            }
        }
    }
    for(int k=0;k<N;k++){
        printf("%s %d\n",username[k],balance[k]);
    }
}
