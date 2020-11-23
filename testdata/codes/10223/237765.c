#include <stdio.h>
#include <string.h>
char ans[10001][10001];
char s[10001];
char t[10001];
int num[10001] = {0};
int first = 0;
int main()
{
	int A;
	int B;
	char *start;
	int head;
	int Aindex;
	int length;
	while (scanf("%s", s) != EOF) {
		length = strlen(s);
		strcpy(t, s);
		t[length] = '\0';
		scanf("%d%d", &A, &B);
		start = s;
		head = 0;
		Aindex = 0;
		for (int i = 0; s[i] != '\0'; i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				strncpy(ans[Aindex], start, (i - head + 1));
				ans[Aindex][i - head + 1] = '\0';
				num[Aindex] = head;
				Aindex++;
				head = i + 1;
				start = &s[head];
			}
		}
		if (s[head] != '\0') {
			strcpy(ans[Aindex], start);
			ans[Aindex][strlen(start)] = '\0';
			Aindex++;
		}
		if (first != 0)
			printf("\n");
		first = 1;
		for (int j = 0; j < length; j++) {
				if (j == num[A])
					printf("%s", ans[A]);
				else if (j < num[A] || j >= num[A] + strlen(ans[A]))
					printf("+");
		}
		printf("\n");
		for (int j = 0; j < length; j++) {
				if (j == num[B])
					printf("%s", ans[B]);
				else if (j < num[B] || j >= num[B] +  strlen(ans[B]))
					printf("+");
		}
		printf("\n");
		for (int j = 0; j < length; j++) {
			if (j >= num[A] && j < num[A] + strlen(ans[A]))
				printf("+");
			else if (j >= num[B] && j < num[B] + strlen(ans[B]))
					printf("+");
			 else
				printf("%c", t[j]);
		}
	}
	return 0;
}

