#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
	char name[32];
	int balance;
};

int main()
{
	struct Account account[32] = {};
	int numUsers;
	char instruction[256];

	scanf("%d", &numUsers);
	for (int i = 0; i < numUsers; i++)
		scanf("%s %d\n", account[i].name, &account[i].balance);

	while (fgets(instruction, 256, stdin) != NULL) {
		char *command;
		command = strtok(instruction, " \n");
		int indexA = -1;
		for (int i = 0; i < numUsers; i++)
			if (strcmp(command, account[i].name) == 0) {
				indexA = i;
				break;
			}		
		if (indexA == -1)
			continue;
		
		command = strtok(NULL, " \n");
		if (strstr(command, "earns") != NULL) {
			command = strtok(NULL, " \n");
			account[indexA].balance += atoi(command);
		}
		else if (strstr(command, "spends") != NULL) {
			command = strtok(NULL, " \n");
			if (atoi(command) <= account[indexA].balance)
				account[indexA].balance -= atoi(command);
		}
		else if (strstr(command, "gives") != NULL) {
			command = strtok(NULL, " \n");
			int indexB = -1;
			for (int i = 0; i < numUsers; i++)
				if (strcmp(command, account[i].name) == 0) {
					indexB = i;
					break;
				}
			if (indexB == -1)
				continue;
			command = strtok(NULL, " \n");
			int number = atoi(command);
			if (number > account[indexA].balance)
				continue;
			account[indexA].balance -= number;
			account[indexB].balance += number;
		}
		else if (strstr(command, "becomes") != NULL) {
			command = strtok(NULL, " \n");
			account[indexA].balance = atoi(command);
		}
	}

	for (int i = 0; i < numUsers; i++)
		printf("%s %d\n", account[i].name, account[i].balance);

	return 0;
}
