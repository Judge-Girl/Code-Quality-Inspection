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
		char one[strlen(s)+1], two[strlen(s)+1];
		memset(one, 0, sizeof(one));
		memset(two, 0, sizeof(two));
		memset(one, '+', sizeof(char)*strlen(s));
		memset(two, '+', sizeof(char)*strlen(s));
		int tmp = 0, pre = 0, stop = 0;
		for (int i = 0; i < strlen(s); ++i) {
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
