#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int N;
	scanf("%d", &N);
	int bal[32] = {};
	char user[32][32] = {};
	char name[32];
	int money, nomi;
	for(int i = 0; i < N; i++){
		scanf("%s%d", name, &money);
		strcat(user[i], name);
		bal[i] = money;
	}

	char in[200];
	while(gets(in) != NULL){
		int k = 0;
		int head = 0;
		char string[4][64] = {};
		for(int i = 0; i < strlen(in) && k < 4; i++){
			if(in[i] == ' '){
				k++;
				head = i + 1;
			}
			else string[k][i - head] = in[i];
		}
		int legal = 0;
		for(int i = 0; i < N; i++){
			if(strcmp(string[0], user[i]) == 0){
				legal = 1;
				nomi = i;
			}
		}
		if(legal){
			int mode = 0;
			for(int i = 0; i < strlen(string[1]); i++){
				if(string[1][i] == 'e' && string[1][i + 1] == 'a' && string[1][i + 2] == 'r' && string[1][i + 3] == 'n' && string[1][i + 4] == 's') mode = 1;
				if(string[1][i] == 's' && string[1][i + 1] == 'p' && string[1][i + 2] == 'e' && string[1][i + 3] == 'n' && string[1][i + 4] == 'd' && string[1][i + 5] == 's') mode = 2;
				if(string[1][i] == 'g' && string[1][i + 1] == 'i' && string[1][i + 2] == 'v' && string[1][i + 3] == 'e' && string[1][i + 4] == 's') mode = 3;
				if(string[1][i] == 'b' && string[1][i + 1] == 'e' && string[1][i + 2] == 'c' && string[1][i + 3] == 'o' && string[1][i + 4] == 'm' && string[1][i + 5] == 'e' && string[1][i + 6] == 's') mode = 4;
			}
			switch(mode){
				case 1:
					money = atoi(string[2]);
					bal[nomi] += money; 
					break;
				case 2:
					money = atoi(string[2]);
					if(money <= bal[nomi]) bal[nomi] -= money;
					break;
				case 3:
					money = atoi(string[3]);
					legal = 0;
					int snomi;
					for(int i = 0; i < N; i++){
						if(strcmp(string[2], user[i]) == 0){ 
							legal = 1;
							snomi = i;
						}
					}
					if(legal && money <= bal[nomi]){
						bal[nomi] -= money;
						bal[snomi] += money;
					}
					break;
				case 4:
					money = atoi(string[2]);
					bal[nomi] = money;
					break;
			}
		}
	}
	for(int i = 0; i < N; i++){
		if(i != 0) printf("\n");
		printf("%s %d", user[i], bal[i]);
	}
}
