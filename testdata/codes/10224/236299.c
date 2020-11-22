#include <stdio.h>
#include <string.h>

struct instructions {
	char name[20];
};

struct users{
	char name[33];
	int balance;
};	

struct users A[33];
struct instructions B[4];

int main(int argc, char const *argv[])
{
	int N;
	char temp[33];
	char user2[33];
	char ins[33];
	int amount;

	strcpy(B[0].name, "earns");
	strcpy(B[1].name, "spends");
	strcpy(B[2].name, "gives");
	strcpy(B[3].name, "becomes");

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s %d", &A[i].name, &A[i].balance);
	}

	while (scanf("%s %s", &temp, &ins) != EOF) {
		int i;
		for (i = 0; i < N; i++) {					//if the user is not there
			if (strcmp(temp, A[i].name) == 0)
				break;
		}
		if (i == N) {
			scanf("%d", &amount);
			continue;
		}

		int j;										//Valid instruction
		for (j = 0; j < 4; j++) {
			if (strstr(ins, B[j].name) != NULL)
				break;
		}
		// j--;
		// printf("%d %s\n", j, B[j].name); 
		if (j == 4) {
			// printf("xd\n");
			scanf("%d", &amount);
			continue;
		}

		if (j != 2) {
			scanf("%d", &amount);
			if (j == 0)
				A[i].balance += amount;
			if (j == 1) {
				if (A[i].balance < amount)
					continue;
				else
					A[i].balance -= amount;
			}
			if (j == 3) 
				A[i].balance = amount;
		}
		else {
			scanf("%s %d", &user2, &amount);
			int k;
			for (k = 0; k < N; k++) {
				if (strcmp(user2, A[k].name) == 0)
					break;
			}
			if (k == N || A[i].balance < amount)
				continue;

			A[i].balance -= amount;
			A[k].balance += amount;
		}
	}
	for (int i = 0; i < N; i++)
		printf("%s %d\n", A[i].name, A[i].balance);
	return 0;
}
