#include <stdio.h>
#include <string.h>

char name[100][100];
int money[100];
char test[100][100]={"earns","spends","becomes","gives"};
char temp[100];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0 ; i<n ; i++){
		scanf("%s%d",name[i],&money[i]);
	}
	char delimeters[]=" ";
	while(gets(temp)){
		char instr[4][50];
		char *start=temp;
		start=strtok(start,delimeters);
		int a=0;
		while(start!=NULL){
			strcpy(instr[a],start);
			a++;
			start=strtok(NULL,delimeters);
		}
		if(a==4){
			int b=-1;
			for(int i=0 ; i<n ; i++){
				if(strcmp(name[i],instr[0])==0){
					b=i;
				}
			}
			if(b!=-1){
				if(strstr(instr[1],test[3])!=NULL){
					int c=-1;
					for(int i=0 ; i<n ; i++){
						if(strcmp(name[i],instr[2])==0)
							c=i;
					}
					//printf("%d\n",c);
					if(c!=-1){
						int d=strlen(instr[3]);
						int number=0;
						for(int i=0 ; i<d ; i++){
							number=(number+instr[3][i]-'0')*10;
						}
						number=number/10;
						if(number<=money[b]){
							money[b] -=number;
							money[c] +=number;
						}
					}
				}
			}
		}
		else{
			int b=-1;
			for(int i=0 ; i<n ; i++){
				if(strcmp(name[i],instr[0])==0){
					b=i;
				}
			}
			if(b!=-1){
				int c=3;
				for(int i=0 ; i<3 ; i++){
					if(strstr(instr[1],test[i])!=NULL)
						c=i;
				}
				if(c==0){
					int d=strlen(instr[2]);
					int number=0;;
					for(int i=0 ; i<d ; i++){
						number=(number+instr[2][i]-'0')*10;
					}
					number=number/10;
					//printf("%d\n",number);
					money[b]+=number;
				}
				if(c==1){
					int d=strlen(instr[2]);
					int number=0;
					for(int i=0 ; i<d ; i++){
						number=(number+instr[2][i]-'0')*10;
					}
					number=number/10;
					if(money[b]>=number){
						money[b]-=number;
					}
				}
				if(c==2){
					int d=strlen(instr[2]);
					int number=0;
					for(int i=0 ; i<d ; i++){
						number=(number+instr[2][i]-'0')*10;
					}
					number=number/10;
					money[b]=number;
				}
			}
		}
	}
	for(int i=0 ; i<n ; i++){
		printf("%s %d\n",name[i],money[i]);
	}
}
