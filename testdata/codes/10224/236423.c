#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	char name[64];
	int money;
}User;
User u[64];
int n;
char instruct[30][64],tmp;
int find(char na[]){
	for(int i=0;i<n;i++)if(strcmp(na,u[i].name)==0)return i;
	return -1;
}
void compute(){
	int index=find(instruct[0]);
	if(index<0)return;
	char *ptr=NULL;
	ptr=strstr(instruct[1],"earns");
	if(ptr){
		u[index].money+=atoi(instruct[2]);
		return;
	}ptr=strstr(instruct[1],"spends");
	if(ptr){
		int k=atoi(instruct[2]);
		if(u[index].money-k>=0)
		u[index].money-=k;
		return;
	}ptr=strstr(instruct[1],"becomes");
	if(ptr){
		u[index].money=atoi(instruct[2]);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%s%d",u[i].name,&u[i].money);
	int err=0,now=0;
	while(scanf("%s%c",instruct[now++],&tmp)!=EOF){
		if(tmp=='\n'){
			if(now==3){
				compute();
			}else if(now==4){
				int p1=find(instruct[0]),p2=find(instruct[2]);
				if(p1>=0&&p2>=0){
					char *ptr=NULL;
					ptr=strstr(instruct[1],"gives");
					if(ptr){
						int m=atoi(instruct[3]);
						if(u[p1].money>=m){
							u[p1].money-=m;
							u[p2].money+=m;
						}
					}
				}
			}
			now=0;
		}
	}for(int i=0;i<n;i++)printf("%s %d\n",u[i].name,u[i].money);
}
