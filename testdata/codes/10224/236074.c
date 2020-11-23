#include <stdio.h>
#include <string.h>

int main(){
	
	int n; scanf("%d", &n);
	char names[32][32];
	int balance[32];

	for (int i = 0; i < n; ++i)
		scanf("%s%d", names[i], &balance[i]);
	
	char iname[32];
	char instruction[32];
	int amount;
	while (scanf("%s", iname) != EOF){
		int i, j;
		for (i = 0; i < n && strcmp(names[i], iname) != 0; ++i);
		if (i == n) continue;
		scanf("%s", instruction);
		if (strstr(instruction, "earns") != NULL){
			scanf("%d", &amount);
			balance[i] += amount;
		}
		else if (strstr(instruction, "spends") != NULL){
			scanf("%d", &amount);
			if (balance[i] - amount >= 0)
				balance[i] -= amount;
		}
		else if (strstr(instruction, "gives") != NULL){
			scanf("%s", iname);
			for (j = 0; j < n && strcmp(names[j], iname) != 0; ++j);
			if (j == n) continue;
			scanf("%d", &amount);
			if (balance[i] - amount >= 0){
				balance[i] -= amount;	
				balance[j] += amount;				
			}				
		}
		else if (strstr(instruction, "becomes") != NULL){
			scanf("%d", &amount);
			balance[i] = amount;
		}		
	}

	for (int i = 0; i < n; ++i){
		printf("%s %d\n", names[i], balance[i]);
	}
	return 0;	
}
