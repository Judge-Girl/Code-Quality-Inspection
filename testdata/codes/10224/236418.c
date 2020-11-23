#include <stdio.h>
#include <string.h>

int main(void){
	char name[32][33];
	char instruction[100];
	char people[33], rest[33], to[33];
	int n, i, j, number, order;
	int money[32];

	scanf("%d", &n);

	for(i = 0; i < n; i++){
		scanf("%s %d", name[i], &money[i]);
	}
	i = 0;
	while(fgets(instruction, 100, stdin)){
		int whoa = -1, whob = -1, order = -1;
		sscanf(instruction, "%s %s", people, rest);
		for(i = 0; i < n; i++){
			if(strcmp(people, name[i]) == 0) {
				whoa = i;
				break;
			}
		}
		if(strstr(rest, "earns") != NULL) {
			order = 1;
		}
		else if(strstr(rest, "spends") != NULL){
			order = 2;
		}
		else if(strstr(rest, "gives") != NULL) {
			order = 3;
		}
		else if(strstr(rest, "becomes") != NULL) {
			order = 4;
		}
		if(order == -1) continue;
		if(order == 1 && whoa != -1){
			sscanf(instruction, "%s %s %d", people, rest, &number);
			money[whoa] += number;
		}
		else if(order == 2 && whoa != -1){
			sscanf(instruction, "%s %s %d", people, rest, &number);
			if(money[whoa] >= number) money[whoa] -= number;
		}
		else if(order == 3 && whoa != -1){
			sscanf(instruction, "%s %s %s %d", people, rest, to, &number);
			for(i = 0; i < n; i++){
				if(strcmp(to, name[i]) == 0) {
					whob = i;
					break;
				}
			}
			if(whob == -1) continue;
			if(money[whoa] >= number){
				money[whoa] -= number;
				money[whob] += number;
			}
		}
		else if(order == 4 && whoa != -1){
			sscanf(instruction, "%s %s %d", people, rest, &number);
			money[whoa] = number;
		}
	}

	for(i = 0; i < n; i++){
		printf("%s %d\n", name[i], money[i]);
	}
}
