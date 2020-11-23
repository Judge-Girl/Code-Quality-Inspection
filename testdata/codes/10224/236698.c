#include<stdio.h>
#include<string.h>
char username[32][32];
int balance[32];
char s1[32],s2[32];
int	type;

int main(){
	int N;
	scanf("%d\n",&N);
	for(int k=0;k<N;k++){
		scanf("%s %d",username[k],&balance[k]);
	}
	
	while(scanf("%s%s",s1,s2)!=EOF){
		type=-1;
		int len=strlen(s2);
		
		for(int k=0;k<len-4;k++){
			if(s2[k]=='e'&&s2[k+1]=='a'&&s2[k+2]=='r'&&s2[k+3]=='n'&&s2[k+4]=='s'){
				type=1;
			}
			
			if(s2[k]=='g'&&s2[k+1]=='i'&&s2[k+2]=='v'&&s2[k+3]=='e'&&s2[k+4]=='s'){
				type=3;
			}
		}
		for(int k=0;k<len-5;k++){
			if(s2[k]=='s'&&s2[k+1]=='p'&&s2[k+2]=='e'&&s2[k+3]=='n'&&s2[k+4]=='d'&&s2[k+5]=='s'){
				type=2;
			}
		}
		for(int k=0;k<len-6;k++){
			if(s2[k]=='b'&&s2[k+1]=='e'&&s2[k+2]=='c'&&s2[k+3]=='o'&&s2[k+4]=='m'&&s2[k+5]=='e'&&s2[k+6]=='s'){
				type=4;
			}
		}
		
		int id=-1,id2=-1;
		for(int k=0;k<N;k++){
			int j=strcmp(s1,username[k]);
			if(j==0){
				id=k;
				break;
			}	
		}
		if(id==-1)	type=0;
		
		int amount;
		if(type!=3)	scanf("%d",&amount);
		
		if(type==1)	balance[id]+=amount;
		
		if(type==2){
			if(amount<=balance[id])	balance[id]-=amount;
			else	type=0;
		}
		
		if(type==3){
			scanf("%s",s1);
			for(int k=0;k<N;k++){
				int g=strcmp(s1,username[k]);
				if(g==0){
					id2=k;
					break;
				}	
			}
			if(id2==-1){
				type=0;
				scanf("%d\n",&amount);
			}	
			else{
				scanf("%d\n",&amount);
				if(amount<=balance[id]){
					balance[id]-=amount;
					balance[id2]+=amount;
				}
				else	type=0;
			}
		}
		
		if(type==4)	balance[id]=amount;
		
		if(type==0)	continue;
	}
	
	for(int k=0;k<N;k++){
		printf("%s %d\n",username[k],balance[k]);
	}
}

