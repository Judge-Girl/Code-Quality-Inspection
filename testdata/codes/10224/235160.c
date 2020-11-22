#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 32
int searchUser(char *user, char userList[][MAXLENGTH], int N) {
	for (int i = 0; i < N; i++)
		if (strcmp(user, userList[i]) == 0)
			return i;
	return -1;
}
int searchOp(char *op, char *opList[], int N) {
	for (int i = 0; i < N; i++)
		if (strstr(op, opList[i]) != NULL)
			return i;
	return -1;
}
int main() {
	char user[MAXLENGTH][MAXLENGTH];
	int balance[MAXLENGTH];
	char *operation[4] = {"earns", "spends", "gives", "becomes"};
	char instruction[128];
	int N;
	char inputUser1[MAXLENGTH], inputOperation[MAXLENGTH], inputUser2[MAXLENGTH];
	int ammount;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%s%d", user[i], &balance[i]);

	fgets(instruction, 128, stdin);
	while (fgets(instruction, 128, stdin) != NULL) {
		if (sscanf(instruction,"%s%s%d", inputUser1, inputOperation, &ammount) == 3) {
			int user1 = searchUser(inputUser1, user, N);
			int op = searchOp(inputOperation, operation, 4);
			if (user1 >= 0) {
				switch (op) {
				case 0:
					balance[user1] += ammount;
					break;
				case 1:
					balance[user1] = balance[user1] >= ammount ? balance[user1] - ammount: balance[user1];
					break;
				case 3:
					balance[user1] = ammount;
					break;
				default:
					break;
				}
			}
		}
		else if(sscanf(instruction,"%s%s%s%d", inputUser1, inputOperation, inputUser2, &ammount) == 4) {
			int op = searchOp(inputOperation, operation, 4);
			if (op == 2) {
				int user1 = searchUser(inputUser1, user, N);
				int user2 = searchUser(inputUser2, user, N);
				if (user1 >= 0 && user2 >= 0 && balance[user1] >= ammount ) {
					balance[user1] -= ammount;
					balance[user2] += ammount;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
		printf("%s %d\n", user[i], balance[i]);
	return 0;
}

