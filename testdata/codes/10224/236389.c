#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int n,money;
	scanf("%d",&n);
	int bal[n];
	char name[n][32],ins[32]="";
	for(int i=0;i<n;i++)
		scanf("%s%d",name[i],&bal[i]);
	while(scanf("%s",ins)!=EOF){
		int who=0;
		while(who<n){
			if(strcmp(ins,name[who])==0)
				break;
			who++;
		}
		if(who==n){
			char ignore[1000]="";
			int ig=0;
			while(1){
				scanf("%c",&ignore[ig]);
				if(ignore[ig]=='\n');
					break;
				ig++;
			}
			continue;
		}
			
		scanf("%s",ins);
		char *ptr=&ins[0];
		for(int i=0;i<strlen(ins);i++){
			if(strncmp(ptr,"earns",5)==0){
				scanf("%d",&money);
				bal[who]+=money;
				break;
			}
			if(strncmp(ptr,"spends",6)==0){
				scanf("%d",&money);
				if(bal[who]-money>=0)
					bal[who]-=money;
				break;
			}
			if(strncmp(ptr,"gives",5)==0){
				scanf("%s%d",ins,&money);
				int who2=0;
				while(who2<n){
					if(strcmp(ins,name[who2])==0)
						break;
					who2++;
				}
				if(who2==n)
					break;
				if(bal[who]-money>=0){
					bal[who]-=money;
					bal[who2]+=money;
				}
				break;
			}
			if(strncmp(ptr,"becomes",7)==0){
				scanf("%d",&money);
				bal[who]=money;
				break;
			}
			ptr++;
		}
	}
	for(int i=0;i<n;i++)
		printf("%s %d\n",name[i],bal[i]);
	return 0;
}
