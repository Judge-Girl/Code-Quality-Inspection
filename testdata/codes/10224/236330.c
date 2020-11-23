#include <stdio.h>
#include <string.h>

int main()	{
	int n;
	scanf("%d", &n);
	char names[32][32];
	int balance[32];
	for (int i = 0; i < n; i++)
		scanf("%s%d", names[i], &balance[i]);
	char user[32];
	while (scanf("%s", user) == 1)	{
		int index = -1;
		for (int i = 0; i < n; i++)	{
			if (strcmp(user, names[i]) == 0)	{
				index = i;
				break;
			}
		}
		if (index == -1)
			continue;
		char operation[32];
		scanf("%s", operation);
		if (strstr(operation, "becomes") != NULL)	{
			int amount;
			scanf("%d", &amount);
			balance[index] = amount;
		}
		else if (strstr(operation, "gives") != NULL)	{
			char user2[32];
			scanf("%s", user2);
			int amount;
			scanf("%d", &amount);
			int index2 = -1;
			for (int i = 0; i < n; i++)	{
				if (strcmp(user2, names[i]) == 0)
					index2 = i;
			}
			if (index2 == -1)
				continue;
			if (balance[index] >= amount)
				balance[index] -= amount, balance[index2] += amount;
		}
		else if (strstr(operation, "earns") != NULL)	{
			int amount;
			scanf("%d", &amount);
			balance[index] += amount;
		}
		else if (strstr(operation, "spends") != NULL)	{
			int amount;
			scanf("%d", &amount);
			if (balance[index] >= amount)
				balance[index] -= amount;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%s %d\n", names[i], balance[i]);
	return 0;
}
