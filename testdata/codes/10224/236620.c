#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 32

int main(){
	int N, balance[MAXN];
	scanf("%d", &N);
	char userName[MAXN][MAXN], ins[MAXN];
	for(int i=0;i<N;i++) scanf("%s%d", userName[i], &balance[i]);
	gets(ins);
	while(scanf("%s", ins) != EOF){
		for(int i=0;i<N;i++){
			if(strcmp(ins, userName[i])==0){
				char action[32];
				int money;
				scanf("%s", action);
				if(strcmp(action, "earns")==0 || strstr(action, "earns")!=0){
					scanf("%d", &money);
					balance[i]+=money;
				} else if(strcmp(action, "spends")==0 || strstr(action, "spends")!=0){
					scanf("%d", &money);
					if(balance[i]>=money) balance[i]-=money;
				} else if(strcmp(action, "gives")==0 || strstr(action, "gives")!=0){
					char to[32];
					scanf("%s", to);
					for(int j=0;j<N;j++){
						if(strcmp(to, userName[j])==0){
							scanf("%d", &money);
							if(balance[i]>=money){
								balance[i]-=money;
								balance[j]+=money;
							}
							
						}
					}
				} else if(strcmp(action, "becomes")==0 || strstr(action, "becomes")!=0){
					scanf("%d", &money);
					balance[i]=money;
				}
				//printf("%s %d\n", userName[i], balance[i]);
			}
		}
		
	}
	for(int i=0;i<N;i++) printf("%s %d\n", userName[i], balance[i]);
	return 0;
}
