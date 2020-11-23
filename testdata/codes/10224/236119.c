#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	int N;
	scanf("%d", &N);
	char user[N][32];
	int balance[N];
	for (int i = 0; i < N; i++)
		scanf("%s %d", user[i], &balance[i]);
	char buf[128];
	char ins[4][32] = {0};
	char act[4][32] = {"earns", "spends", "becomes", "gives"};
	while (fgets (buf, 128, stdin) != NULL){
		int total = sscanf(buf, "%s %s %s %s", ins[0], ins[1], ins[2], ins[3]);
		if (total == 3){
			int amount = atoi(ins[2]);
			int find = -1;
			for (int i = 0; i < N; i++){
				if (strcmp(user[i], ins[0]) == 0)
					find = i;
			}
			if (find != -1){
				int action = -1;
				for (int j = 0; j < 3; j++){
					if (strstr(ins[1], act[j]) != NULL){
						action = j;
					}
				}
				switch (action){
					case 0:
						balance[find] += amount;
						break;
					case 1:
						if (amount <= balance[find])
							balance[find] -= amount;
						break;
					case 2:
						balance[find] = amount;
						break;
					default:
						break;
				}
			}
		}
		else if (total == 4){
			int amount = atoi(ins[3]);
			int find1 = -1, find2 = -1;
			for (int i = 0; i < N; i++){
				if (strcmp(user[i], ins[0]) == 0)
					find1 = i;
				if (strcmp(user[i], ins[2]) == 0)
					find2 = i;
			}
			if (find1 != -1 && find2 != -1 && find1 != find2){
				int action = -1;
				if (strstr(ins[1], act[3]) != NULL){
					action = 3;
				}
				if (action == 3){
					if (amount <= balance[find1]){
						balance[find1] -= amount;
						balance[find2] += amount;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++){
		printf("%s %d\n", user[i], balance[i]);
	}
	return 0;
}

