#include <stdio.h>
#include <string.h>

int main(){
        int n;
        scanf("%d", &n);
        char name[32][32];
        int money[32];
        for(int i = 0; i < n; i++){
                scanf("%s %d", name[i], money+i);
        }
        char tmps[32];
        while(scanf("%s", tmps) != EOF){
                for(int i = 0; i < n; i++){
                        if(strcmp(tmps, name[i]) == 0){
                                char cmd[32];
                                scanf("%s", cmd);
                                if(strstr(cmd, "earns") != NULL){
                                        int price;
                                        scanf("%d", &price);
                                        money[i] += price;
                                }
                                else if(strstr(cmd, "spends") != NULL){
                                        int price;
                                        scanf("%d", &price);
                                        if (price <= money[i])
                                                money[i] -= price;
                                }
                                else if(strstr(cmd, "gives") != NULL){
                                        char tmp2[32];
                                        scanf("%s", tmp2);
                                        for(int j = 0; j < n; j++){
                                                if(strcmp(tmp2, name[j]) == 0){
                                                        int price;
                                                        scanf("%d", &price);
                                                        if (price <= money[i]){
                                                                money[i] -= price;
                                                                money[j] += price;
                                                        }
                                                        break;
                                                }
                                        }
                                }
                                else if(strstr(cmd, "becomes") != NULL){
                                        int price;
                                        scanf("%d", &price);
                                        if (price >= 0)
                                                money[i] = price;
                                }
                                break;
                        }
                }
        }
        for(int i = 0; i < n; i++){
                printf("%s %d\n", name[i], money[i]);
        }
        return 0;
}

