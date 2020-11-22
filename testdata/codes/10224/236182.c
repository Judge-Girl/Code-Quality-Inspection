#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
char ins[4][33] = {"earns", "spends", "gives", "becomes"};
typedef struct node
{
	char name[35];
	int balance;
} node;
int main()
{
	int n;
	scanf("%d", &n);
	node user[n];
	for (int i = 0; i < n; i++) {
		int money;
		scanf("%s%d", user[i].name, &money);
		user[i].balance = money;
	}
	char n1[35];
	while (scanf("%s", n1) != EOF) {
		int index1 = n + 1;
		for (int i = 0; i < n; i++) {
			if (!strcmp(n1, user[i].name)) {
				index1 = i;
				break;
			}
		}
		if (index1 == n + 1)
			continue;
		char s[33];
		scanf("%s", s);
		for (int i = 0; i < 4; i++) {
			if (strstr(s, ins[i]) != NULL) {
				if (i == 0) {
					scanf("%s", s);
					int money = atoi(s);
					user[index1].balance += money;
					break;
				}
				else if (i == 1) {
					scanf("%s", s);
					int money = atoi(s);
					if (user[index1].balance >= money)
						user[index1].balance -= money;
					break;
				}
				else if (i == 2) {
					char n2[35];
					scanf("%s%s", n2, s);
					int index2 = n + 1;
					for (int j = 0; j < n; j++) {
						if (!strcmp(n2, user[j].name)) {
							index2 = j;
							break;
						}
					}
					if (index2 == n + 1)
						break;
					int money = atoi(s);
					if (user[index1].balance >= money) {
						user[index1].balance -= money;
						user[index2].balance += money;
					}
					break;
				}
				else if (i == 3) {
					scanf("%s", s);
					int money = atoi(s);
					user[index1].balance = money;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%s %d\n", user[i].name, user[i].balance);
	}
	return 0;
}

