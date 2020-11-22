#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int N;
	scanf("%d", &N);
	char user[31][32];
	int account[31];
	for(int i = 0; i < N; i++){
		scanf("%s%d", &user[i][0], &account[i]);
	}
//	for(int i = 0; i < N; i++)
//		printf("%s %d\n", user[i], account[i]);
	char instru[100];
	char earns[] = "earns";
	char spends[] = "spends";
	char gives[] = "gives";
	char becomes[] = "becomes";
	int k;
	while(fgets(instru, 100, stdin) != NULL){
	//	printf("%s\n", instru);
		char a[31] = {0}, b[31] = {0};
		char *ptr;
		if((ptr = strstr(instru, earns)) != NULL){
			k = 0;
			while(instru[k] != ' ') k++;
			strncpy(a, instru, k);
			k += 2;
			while(instru[k] != ' ') k++;
			k += 1;
			for(int i = 0; i < N; i++){
				if(strcmp(&user[i][0], a) == 0){
					int num = atoi(&instru[k]);
					account[i] += num;
	//				printf("%d", account[i]);
				}
			}
		}else if((ptr = strstr(instru, spends)) != NULL){
			k = 0;
			while(instru[k] != ' ') k++;
			strncpy(a, instru, k);
			k += 2;
			while(instru[k] != ' ') k++;
			k += 1;
			for(int i = 0; i < N; i++){
				if(strcmp(&user[i][0], a) == 0){
					int num = atoi(&instru[k]);
					if(num <= account[i]) account[i] -= num;
	//				printf("%d", account[i]);
				}
			}
		}else if((ptr = strstr(instru, gives)) != NULL){
			k = 0;
			while(instru[k] != ' ') k++;
			strncpy(a, instru, k);
			k += 2;
			while(instru[k] != ' ') k++;
			k += 1;
			int temp = k;
			while(instru[temp] != ' ') temp++;
			strncpy(b, &instru[k], temp-k);
//			printf("%s %s<=\n", a, b);
			int in_a = -1, in_b = -1;
			for(int i = 0; i < N; i++)
				if(strcmp(&user[i][0], a) == 0) in_a = i;
			for(int i = 0; i < N; i++)
				if(strcmp(&user[i][0], b) == 0) in_b = i;
			if(in_a != -1 && in_b != -1){
				int num = atoi(&instru[temp+1]);
				if(num <= account[in_a]){
					account[in_a] -= num;
					account[in_b] += num;
	//				printf("%d %d", account[in_a], account[in_b]);
				}
			}
		}else if((ptr = strstr(instru, becomes)) != NULL){
			k = 0;
			while(instru[k] != ' ') k++;
			strncpy(a, instru, k);
			k += 2;
			while(instru[k] != ' ') k++;
			k += 1;
			for(int i = 0; i < N; i++){
				if(strcmp(&user[i][0], a) == 0){
					int num = atoi(&instru[k]);
					account[i] = num;
	//				printf("%d", account[i]);
				}
			}
		}
	}
	for(int i = 0; i < N; i++){
		printf("%s %d", &user[i][0], account[i]);
		if(i != N-1) printf("\n");
	}
	return 0;
}
