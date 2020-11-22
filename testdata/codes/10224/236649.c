#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int find_user(char user[32][32],int N,char target[]){
	for (int i =0;i<N;i++){
		if (strcmp(user[i],target) == 0){  //user found
			return i;
		}
	}
	return -1;
}

int str_to_int(char string[]){
	int result=0;
	for (int i =0;i<strlen(string);i++){
		result = result*10 + (string[i]-48);
	}
	return result;
}

int main(){
	char user[32][32];
	int balance[32];
	char input[32];
	int N;
	char *blank;
	char *amount;
	char *change;
	scanf("%d",&N);
	for (int i=0;i<N;i++){
		scanf("%s",&user[i]);
		scanf("%d",&balance[i]);
	}
	char A[32],B[32];
	char action[32];
	char *ptr;
	int number;
	int howmuch;
	int who,whom;
	while (scanf("%s",A) != EOF){	//who did 
		who = find_user(user,N,A);
		if (who == -1){	//user not found
			continue;
		}	
		scanf("%s",action);
		if (strstr(action,"earns") != NULL){
			scanf("%d",&howmuch);
			balance[who] += howmuch;
		}
		if (strstr(action,"spends")!=NULL){
			scanf("%d",&howmuch);
			if (balance[who]>=howmuch){
				balance[who]-=howmuch;
			}
		}
		if (strstr(action,"gives")!=NULL){
			scanf("%s",B);
			scanf("%d",&howmuch);
			whom = find_user(user,N,B);
			if (whom == -1){
				continue;
			}
			if (balance[who]>=howmuch){
				balance[who]-=howmuch;
				balance[whom]+=howmuch;
			}
		}
		if (strstr(action,"becomes")!=NULL){
			scanf("%d",&howmuch);
			balance[who] = howmuch;
		} 
	}
	for (int i = 0;i<N;i++){
		printf("%s %d\n",user[i],balance[i]);
	}
	return 0;
}
