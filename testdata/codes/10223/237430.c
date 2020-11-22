#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int first, second;
	char s[10001];
	// printf("%d\n", sizeof(s));
	memset(s, 0, sizeof(s));
	while (scanf("%s%d%d", s, &first, &second) != EOF) {
		int n = strlen(s);
		char one[n+1], two[n+1];
		memset(one, '+', n);
		memset(two, '+', n);
		one[n] = '\0';
		two[n] = '\0';
		int tmp = 0, pre = 0, stop = 0;
		for (int i = 0; i < n; ++i) {
			if (strchr("aeiou", s[i]) != NULL) {
				if (tmp == first) {
					strncpy(one+pre, s+pre, i-pre+1);
					memset(s+pre, '+', i-pre+1);
					stop++;
				}
				else if (tmp == second) {
					strncpy(two+pre, s+pre, i-pre+1);
					memset(s+pre, '+', i-pre+1);
					stop++;
				}
				tmp++;
				pre = i+1;
				if (stop == 2) break;
			}
		}
		printf("%s\n%s\n%s\n", one, two, s);
		memset(s, 0, sizeof(s));
	}
	return 0;
}
