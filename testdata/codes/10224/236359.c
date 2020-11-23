#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[33];
	int money;
} Account;

Account bank[1000];
char s[1000];
char a[50], b[50], n[50], m[50], o[50];

int find(char a[], int n) {
	for (int i = 0; i < n; ++i) {
		if (strcmp(bank[i].name, a)==0)
			return i;
	}
	return -1;
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%s %d", bank[i].name, &(bank[i].money));
	int ammount;
	while (gets(s)!=NULL) {
		if (sscanf(s, "%s %s %d", a, o, &ammount)==3) {
			int id = find(a, N);
			if (id==-1)
				continue;
			if (strstr(o, "earns")!=NULL)
				bank[id].money += ammount;
				// puts("earns");
			else if (strstr(o, "spends")!=NULL) {
				if (bank[id].money >= ammount) {
					bank[id].money -= ammount;
				}
				// puts("spends");
			}
			else if (strstr(o, "becomes")!=NULL)
				bank[id].money = ammount;
				// puts("becomes");
		} else if (sscanf(s, "%s %s %s %d", a, o, b, &ammount)==4) {
			int id1 = find(a, N), id2 = find(b, N);
			if (id1==-1 || id2==-1)
				continue;
			if (strstr(o, "gives")!=NULL) {
				if (bank[id1].money >= ammount) {
					bank[id1].money -= ammount;
					bank[id2].money += ammount;
				}
			}
		}
		// for (int i = 0; i < N; ++i)
		// 	printf("%s %d\n", bank[i].name, bank[i].money);
	}
	for (int i = 0; i < N; ++i)
		printf("%s %d\n", bank[i].name, bank[i].money);
	return 0;
}
