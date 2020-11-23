#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int N;
	scanf("%d", &N);
	char user[32][32];
	int money[32];
	for(int i = 0; i < N; i++) {
		scanf("%s", user[i]);
		scanf("%d", &money[i]);
	}
	char ins[200];
	while(fgets(ins, 200, stdin) != NULL) {
		char del[] = " ";
		char file[40][40];
		int fc = 0;
		char *start = ins;
		start = strtok(start, del);
		while(start != NULL) {
			strcpy(file[fc], start);
			fc++;
			start = strtok(NULL, del);
		}
		int index;
		int index_two;
		int flag = 0;
		for(int i = 0; i < N; i++)
			if(strcmp(file[0], user[i]) == 0) {
				index = i;
				flag = 1;
			}
		if(flag == 0)
			continue;
		else {
			if (strstr(file[1], "earns")){
				money[index] += atoi(file[2]);
			}
			else if (strstr(file[1], "spends")){
				if(money[index] >= atoi(file[2]))
					money[index] -= atoi(file[2]);
			}
			else if (strstr(file[1], "gives")) {
				flag = 0;
				for(int i = 0; i < N; i++)
					if(strcmp(file[2], user[i]) == 0) {
						index_two = i;
						flag = 1;
					}
				if(flag == 0)
					continue;
				else {
					if(money[index] >= atoi(file[3])) {
						money[index] -= atoi(file[3]);
						money[index_two] += atoi(file[3]);
					}
				}
			}
			else if (strstr(file[1], "becomes")) {
				money[index] = atoi(file[2]);
			}
			else
				continue;
			}
	}
	for(int i = 0; i < N; i++) {
		printf("%s ", user[i]);
		printf("%d\n", money[i]);
	}
}
