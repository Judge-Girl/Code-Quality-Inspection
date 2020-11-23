#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char name[32][32];
int money[32];
char buffer[1010];
int main(){
    int n;
    scanf("%d", &n);
    int nsize = n;
    for(int i = 0; i < n; i++){
        scanf("%s", name[i]);
        scanf("%d", &money[i]);
        //printf("%s %d\n",name[i], money[i]);
    }

    while(gets(buffer)){
        char *part[32];
        char * ptr;
        ptr = strtok(buffer, " ");
        int k = 0;
        while(ptr!=NULL){
            part[k++] = ptr;
            ptr = strtok(NULL, " ");
        }
        //for(int i = 0; i < k; i++) printf("%s\n", part[i]);

        //    printf("%d\n",k);
        if(k==3){
            int ok = 0;
            int index = 0;
            for(int i = 0; i < n; i++){
                //printf("%s %s\n", name[i], part[0]);
                if(strncmp(name[i], part[0], strlen(name[i]))==0){
                    ok = 1;
                    index = i;
                }
            }
            if(!ok) continue;
            int valid = 0;
            int type = 0;
            for(int i = 0; i+5<=strlen(part[1]); i++){
                if(strncmp(part[1]+i, "earns", 5)==0){
                    //printf("%s\n", part[1]);
                    type = 1;
                    valid = 1;
                    break;
                }
                else if(i+6<=strlen(part[1])&&strncmp(part[1]+i, "spends", 6)==0){
                    type = 2;
                    valid = 1;
                    break;
                }
                else if(i+7<=strlen(part[1])&&strncmp(part[1]+i, "becomes", 7)==0){
                    type = 3;
                    valid = 1;
                    break;
                }
            }
            if(!valid) continue;
            else{
                if(type==1){
                    int num = atoi(part[2]);
                    money[index] += num;
                }
                else if(type==2){
                    int num = atoi(part[2]);

                    if(money[index]-num<0) continue;
                    money[index] -= num;
                }
                else if(type==3){
                    int num = atoi(part[2]);
                    money[index] = num;
                }
            }
        }
        else if(k==4){
            int ok1 = 0, ok2 = 0;
            int index1 = 0, index2 = 0;
            for(int i = 0; i < n; i++){
                if(strncmp(name[i], part[0], strlen(name[i]))==0){
                    ok1 = 1;
                    index1 = i;
                }
                if(strncmp(name[i], part[2], strlen(name[i]))==0){
                    ok2 = 1;
                    index2 = i;
                }
            }
            if(!ok1||!ok2) continue;
            int valid = 0;
            for(int i = 0; i+5<=strlen(part[1]); i++){
                if(strncmp(part[1]+i, "gives", 5)==0){
                    valid = 1;
                }
            }
            if(!valid) continue;
            else{
                int num = atoi(part[3]);
                if(money[index1]-num<0) continue;
                money[index1]-=num;
                money[index2]+=num;
            }

        }
        /*for(int i = 0; i < n; i++){
            printf("%s %d\n", name[i], money[i]);
        }*/
        memset(buffer, 0, sizeof(buffer));

    }
    for(int i = 0; i < n; i++){
        printf("%s %d\n", name[i], money[i]);
    }
    return 0;
}

