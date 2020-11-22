#include <stdio.h>
#include <string.h>
#include <ctype.h>

int chartonum(char s[]);
void earns(int balance[],int usr1idx,int nummoney);
void spends(int balance[],int usr1idx,int nummoney);
void gives(int balance[],int usr1idx, int usr2idx, int nummoney);
void becomes(int balance[],int usr1idx,int nummoney);


int main(){
	int n;
	scanf("%d", &n);
	
	char name[n][33];
	int balance[n];
	char move[4][33] = {"earns",
						"spends",
						"gives",
						"becomes"};
	
	int i;
	
	char ins[100];
	char insname[33];
	char insmove[33];
	char insmoney[33];
	
	
	for (i = 0; i < n; i++){
		scanf("%s%d", &name[i], &balance[i]);
	}
	/*for (i = 0; i < n; i++){
		printf("%s %d\n", name[i], balance[i]);
	}*/
	fgets(ins, 100, stdin);
	while (fgets(ins, 100, stdin) != NULL){
		//printf("%s", ins);
		char *ptr = strtok(ins, " ");
		strcpy(insname, ptr);
		
		int namevalid = 0;
		for (i = 0; i < n; i++){
			if (strcmp(insname, name[i]) == 0){
				namevalid = 1;
				break;
			}
		}
		if (namevalid == 0){//printf("namewrong\n");
			continue;
		}
		int usr1idx = i;
		
		ptr = strtok(NULL, " ");
		strcpy(insmove, ptr);
		
		int movevalid = 0;
		for (i = 0; i < 4; i++){
			if (strstr(insmove, move[i]) != NULL){
				movevalid = 1;
				break;
			}
		}
		if (movevalid == 0){//printf("movewrong\n");
			continue;
		}
		int moveindx = i;
		int usr2idx;
		if (moveindx == 2){
			char usr2[33];
			ptr = strtok(NULL, " ");
			strcpy(usr2, ptr);
			int usr2valid = 0;
			for (i = 0; i < n; i++){
				if (strcmp(usr2, name[i]) == 0){
					usr2valid = 1;
					break;
				}
			}
			if (usr2valid == 0){//printf("usr2wrong\n");
				continue;
			}
			usr2idx = i;
		}
		
		ptr = strtok(NULL, " ");
		strcpy(insmoney, ptr);
		int nummoney = chartonum(insmoney);//printf("%d\n", nummoney);
		if (nummoney == -1){//printf("moneywrong\n");
			continue;
		}
		
		switch(moveindx){
			case 0:
			earns(balance, usr1idx, nummoney);
			break;
			case 1:
			spends(balance, usr1idx, nummoney);
			break;
			case 2:
			gives(balance, usr1idx, usr2idx, nummoney);
			break;
			case 3:
			becomes(balance, usr1idx, nummoney);
			break;
		}
		/*for (i = 0; i < n; i++){
		printf("%s %d\n", name[i], balance[i]);
	}*/
	}
	
	for (i = 0; i < n; i++){
		printf("%s %d\n", name[i], balance[i]);
	}
	
	return 0;
}

int chartonum(char s[]){
	int i;
	int sum = 0;
	int mul = 1;
	int len = strlen(s);
	if (s[strlen(s) - 1] != '\n'){
		len++;
	}
	for (i = 0; i < len - 1; i++){
		if (isdigit(s[i]) == 0){
			return -1;
		}
	}
	
	for (i = len - 2; i >= 0; i--){
		sum += mul * (s[i] - '0');
		mul *= 10;
	}
	
	return sum;
}

void earns(int balance[],int usr1idx,int nummoney){
	balance[usr1idx] += nummoney;
}

void spends(int balance[],int usr1idx,int nummoney){
	if (nummoney <= balance[usr1idx]){
		balance[usr1idx] -= nummoney;
	}
}

void gives(int balance[],int usr1idx, int usr2idx, int nummoney){
	if (nummoney <= balance[usr1idx]){
		balance[usr2idx] += nummoney;
		balance[usr1idx] -= nummoney;
	}
}

void becomes(int balance[],int usr1idx,int nummoney){
	balance[usr1idx] = nummoney;
}
