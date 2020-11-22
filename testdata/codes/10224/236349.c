#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(){
	int N;
	scanf("%d",&N);
	char name[32][35];
	int money[32];
	for (int i = 0; i < N; ++i)
	{
		scanf("%s",name[i]);
		scanf("%d",&money[i]);
	}

	char cmd[35];
	while(scanf("%s",cmd)!=EOF){
		int fp=-1,sp=-1;
		for(int i=0;i<N;i++)
			if(strcmp(cmd,name[i])==0)
				fp=i;
		if(fp==-1)
			continue;
		
		scanf("%s",cmd);
		int cmony;
		char *ptr;
		if(strstr(cmd,"earns")!=NULL){
			scanf("%d",&cmony);
			money[fp]+=cmony;
		}

		if(strstr(cmd,"spends")!=NULL){
			scanf("%d",&cmony);
			if(money[fp]>=cmony){
				money[fp]-=cmony;
			}
		}

		if(strstr(cmd,"gives")!=NULL){
			scanf("%s",cmd);
			for(int i=0;i<N;i++)
				if(strcmp(cmd,name[i])==0)
					sp=i;
			if(sp==-1)
				continue;

			scanf("%d",&cmony);
			if(money[fp]>=cmony){
				money[fp]-=cmony;
				money[sp]+=cmony;
			}	
		}

		if(strstr(cmd,"becomes")!=NULL){
			scanf("%d",&cmony);
			money[fp]=cmony;
		}
		
		/*for(int i=0;i<N;i++)
			printf("%s %d\n",name[i],money[i]);*/

	}
	
	for(int i=0;i<N;i++)
		printf("%s %d\n",name[i],money[i]);
	

	return 0;
}
