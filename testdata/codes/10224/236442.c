#include <stdio.h>
#include <string.h>

struct user{
	char name[33];
	int balance;
};

struct user users[33];

int main(void){
	int N;
	scanf("%d",&N);
	int i;
	for(i = 0; i < N; i++){
		scanf("%s%d",users[i].name,&users[i].balance);
	}
	char ins[33];
	char name1[33];
	char name2[33];
	while(scanf("%s%s",name1,ins) != EOF){
		int kind = -1;
		if(strstr(ins,"earns")!=NULL){
			kind = 1;
		}
		if(strstr(ins,"spends")!=NULL){
			kind = 2;
		}
		if(strstr(ins,"gives")!=NULL){
			scanf("%s",name2);
			kind = 3;
		}
		if(strstr(ins,"becomes")!=NULL){
			kind = 4;
		}
		int flag = 0;
		int num = -1;
		for(i = 0; i < N; i++){
			if(strcmp(users[i].name,name1) == 0){
				num = i;
				flag = 1;
				break;
			}
		}
		int money;
		scanf("%d",&money);
		if(flag){
			switch(kind){
				case 1:{
					users[num].balance += money;
					break;
				}
				case 2:{
					if(users[num].balance < money){
						break;
					}
					users[num].balance -= money;
					break;
				}
				case 3:{
					int num2 = -1;
					for(i = 0; i < N; i++){
						if(strcmp(users[i].name,name2) == 0){
							num2 = i;
							break;
						}
					}
					if(num2 == -1){
						break;
					}
					if(users[num].balance < money){
						break;
					}
					users[num].balance -= money;
					users[num2].balance += money;
					break;
				}
				case 4:{
					users[num].balance = money;
					break;
				}
				default:{
					break;
				}
			}
		}
	}
	for(i = 0; i < N; i++){
		printf("%s %d\n",users[i].name,users[i].balance);
	}
}
