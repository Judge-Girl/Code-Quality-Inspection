#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 32
typedef struct {
	char name[MAXLEN];
	int amount;
}Account;
Account all[MAXLEN];
int findid(char *tmp, int N){
	for(int i=0; i<N; i++){
		if(strcmp(tmp,all[i].name)==0)
			return i;
	}
	return -1;
}
int main(){
	int N;
	scanf("%d ",&N);
	char buf[MAXLEN*4];
	for(int i=0; i<N; i++){
		fgets(buf, MAXLEN*4, stdin);
		sscanf(buf,"%s%d",all[i].name,&all[i].amount);
	//	printf("i=%d %s %d\n", i,all[i].name,all[i].amount);
	}
	while(fgets(buf, MAXLEN*4, stdin)!=NULL){
		char s[5][MAXLEN];
		int num = sscanf(buf,"%s%s%s%s",s[0],s[1],s[2],s[3]);
		if(num==3){
			int id = findid(s[0],N);
			if(id<0)
				continue;
			int money = atoi(s[2]);
			char *earns = strstr(s[1],"earns");
			if(earns!=NULL){
				all[id].amount += money;
			}
			char *spends = strstr(s[1],"spends");
			if(spends!=NULL){
				if(all[id].amount>=money)
					all[id].amount -= money;
			}
			char *becomes = strstr(s[1],"becomes");
			if(becomes!=NULL){
				all[id].amount = money;
			}

		}
		else if(num==4){
			int first = findid(s[0],N);
			int second = findid(s[2],N);
			if(first<0||second<0)
				continue;
			char *gives=strstr(s[1],"gives");
			int money = atoi(s[3]);
			if(gives!=NULL){
				if(all[first].amount>=money){
					all[first].amount -= money;
					all[second].amount += money;
				}
			}
		}
		// char *ptr[5];
		// char *start = strtok(buf," ");
		// ptr[0] = start;
		// int num=0;
		// while(start != NULL){

		// }
	}
	for(int i=0; i<N; i++)
		printf("%s %d\n", all[i].name,all[i].amount);
	return 0;
}
