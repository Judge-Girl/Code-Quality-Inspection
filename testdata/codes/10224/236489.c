#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int find_user(char name[], char user[][32], int n)
{
	for(int i = 0; i < n; i++) if(strcmp(name, user[i]) == 0) return i;
	return -1;
}
int all_digits(char* amount)
{
	for(int i = 0; i < strlen(amount); i++)
	{
		if(!isdigit(amount[i])) return 0;
	}
	return 1;
}

int main()
{
	int N;
	char user[32][32];
	int balance[32];
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%s%d", user[i], &balance[i]);
	char instruction[200];
	fgets(instruction, 200, stdin);
	while(fgets(instruction, 200, stdin) != NULL)
	{
		char *p[5];
		p[0] = strtok(instruction, " \n");
		for(int i = 1; i < 5; i++)
			p[i] = strtok(NULL, " \n");
		int user1 = find_user(p[0], user, N);
		if(user1 != -1)
		{
			if(strstr(p[1], "earns") != NULL)
			{
				if(p[3] != NULL || (!all_digits(p[2]))) continue;
				int amount = atoi(p[2]);
				balance[user1] += amount;
			}
			else if(strstr(p[1], "spends") != NULL)
			{
				if(p[3] != NULL || (!all_digits(p[2]))) continue;
				int amount = atoi(p[2]);
				if(balance[user1] < amount) continue;
				else balance[user1] -= amount; 
			}
			else if(strstr(p[1], "gives") != NULL)
			{
				int user2 = find_user(p[2], user, N);
				if(user2 == -1 || (!all_digits(p[3])) || p[4] != NULL) continue;
				int amount = atoi(p[3]);
				if(balance[user1] < amount) continue;
				else
				{
					balance[user1] -= amount;
					balance[user2] += amount;
				}
			}
			else if(strstr(p[1], "becomes") != NULL)
			{
				if(!all_digits(p[2])) continue;
				int amount = atoi(p[2]);
				balance[user1] = amount;
			}
		}
	}
	for(int i = 0; i < N; i++)
		printf("%s %d\n", user[i], balance[i]);
}

