#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
    char name[32][35];
    int amo[32];
    int N;  scanf("%d", &N);
    int i;
    for(i = 0; i < N; i++){
        scanf("%s%d",name[i], &amo[i]);
    }
    char com[200];
    while(fgets(com, 200, stdin) != NULL){
        char s[3][35];
        int cnt = 0;
        char del[] = " \n";
        char *start = strtok(com,del);
        while(start != NULL){
            strcpy(s[cnt], start);
            cnt++;
            start = strtok(NULL, del);
        }
        int flag = 0;
        int p;
        for(i = 0; i < N; i++){
            if(strcmp(s[0], name[i]) == 0){
                p = i;
                flag = 1;
                break;
            }
        }
        if(!flag){
            continue;
        }
        if(strstr(s[1], "earns") != NULL){
            int len = strlen(s[2]);
            int num = 0;
            int ten = 1;
            int j;
            for(j = len - 1; j >= 0; j--, ten*= 10){
				num += (s[2][j] - '0') * ten;
            }
            //printf("%d\n",num);
            amo[p] += num;
        }
        else if(strstr(s[1], "spends") != NULL){
            int len = strlen(s[2]);
            int num = 0;
            int ten = 1;
            int j;
            for(j = len - 1; j >= 0; j--, ten*= 10){
                num += (s[2][j] - '0') * ten;
            }
            if(amo[p] >= num){
                amo[p] -= num;
            }
        }
        else if(strstr(s[1], "gives") != NULL){
            int p2;
            int f = 0;
            int k;
            for(k = 0; k < N; k++){
                if(strcmp(s[2] ,name[k]) == 0){
                    p2 = k;
                    f = 1;
                    break;
                }
            }
            if(f){
                int len = strlen(s[3]);
                int num = 0;
                int ten = 1;
                int j;
                for(j = len - 1;j >= 0; j--, ten*= 10){
                    num += (s[3][j] - '0')* ten;
                 }
                if(amo[p] >= num){
                    amo[p] -= num;
                    amo[p2] += num;
                }
            }
        }
        else if(strstr(s[1], "becomes") != NULL){
            int len = strlen(s[2]);
            int num = 0;
            int ten = 1;
            int j;
            for(j = len - 1; j >= 0; j--, ten*= 10){
                num += (s[2][j] - '0') * ten;
            }
            amo[p] = num;
        }
    }
    for( i = 0; i < N; i++){
    	printf("%s %d\n",name[i], amo[i]);
	}
}

