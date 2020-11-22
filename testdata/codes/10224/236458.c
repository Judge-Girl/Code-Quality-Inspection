#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char spend[] = "spends";
char earn[] = "earns";
char give[] = "gives";
char become[] = "becomes";


int main()
{
    //freopen("strong2.in","r",stdin);
    int n;
    scanf("%d",&n);
    char name[n][32];
    int bank[n];
    int i;
    for(i = 0;i<n;i++){
        scanf("%s",name[i]);
        scanf("%d",&bank[i]);
    }
    char obj[32];
    while(scanf("%s",obj) != -1){
        for(i = 0;i<n;i++){
            if(strcmp(obj,name[i]) == 0)break;
        }
        if(i == n)continue;
        char order[32];
        scanf("%s",order);
        char *tmp;
        tmp = strstr(order,spend);
        if(tmp != 0){
            int in;
            scanf("%d",&in);
            if(bank[i] - in >= 0){
                bank[i] -= in;
                continue;
            }
        }
        tmp = strstr(order,earn);
        if(tmp != 0){
            int in;
            scanf("%d",&in);
            if(bank[i] + in >= 0){
                bank[i] += in;
                continue;
            }
        }
        tmp = strstr(order,give);
        if(tmp != 0){
            char get[32];
            scanf("%s",get);
            int j;
            for(j = 0;j<n;j++){
                if(strcmp(get,name[j]) == 0)break;
            }
            if(j == n)continue;
            int in;
            scanf("%d",&in);
            if(bank[i] - in < 0){continue;}
            bank[i] -= in;
            bank[j] += in;
        }
        tmp = strstr(order,become);
        if(tmp != 0){
            int in;
            scanf("%d",&in);
            bank[i] = in;
        }
    }
    for(i = 0;i<n;i++){
        printf("%s %d\n",name[i],bank[i]);
    }
}
