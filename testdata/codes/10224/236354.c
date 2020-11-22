#include <stdio.h>
#include <string.h>
typedef struct n{
    char name[32];
    int money;
}Name;
Name people[32];
int main(){
    int N;
    scanf("%d",&N);
    for(int i = 0; i < N; i++){
        scanf("%s%d",people[i].name,&people[i].money);
    }
    char s[128];
    while(fgets(s,128,stdin) != NULL){
        char cmd[32],usr[32],usr2[32];
        int M;
        sscanf(s,"%s %s",usr,cmd);
        int plus = strlen(usr) + strlen(cmd) + 2;
        for(int i = 0; i < N; i++){
            if(strcmp(usr,people[i].name) == 0){
                char *ptr = strstr(cmd,"earns");
		        if(ptr != NULL){
		            sscanf(s + plus,"%d",&M);
		            people[i].money += M;
		        }
		        ptr = strstr(cmd,"spends");
		        if(ptr != NULL){
		            sscanf(s + plus,"%d",&M);
		            if(people[i].money >= M){
		                people[i].money -= M;
		            }
		        }
		        ptr = strstr(cmd,"gives");
		        if(ptr != NULL){
		            int idx2 = -1, flag2 = 0;
		            sscanf(s + plus,"%s %d",usr2,&M);
		           if(people[i].money >= M){
		           		for(int j = 0; j < N; j++){
		           			if(strcmp(usr2,people[j].name) == 0){
		           				people[i].money -= M;
		           				people[j].money += M;
							}	
					    }
				   }
		        }
		        ptr = strstr(cmd,"becomes");
		        if(ptr != NULL){
		            sscanf(s + plus,"%d",&M);
		            people[i].money = M;
		        }
		        break;
            }
        }
    }
    for(int i = 0; i < N; i++){
        printf("%s %d\n",people[i].name,people[i].money);
    }
}
