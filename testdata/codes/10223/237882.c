#include <stdio.h>
#include <string.h>

int main()
{
	const char vowels[] = {"aeiou"};
	char word[10010];
	char result[3][10010];
	while (scanf("%s", word) != EOF) {
		for (int i = 0; i < 3; i++) {
			memset(result[i], '+', strlen(word));
			result[i][strlen(word)] = '\0';
		}
		int I, J;
		scanf("%d%d", &I, &J);
		int k = 0;
		char *start = word;
		while (start != NULL) {
			int skip = strcspn(start, vowels);
			if (k == I) {
				strncpy(result[0] + (start - word), start, skip + 1);
			}
			else if (k == J) {
				strncpy(result[1] + (start - word), start, skip + 1);
			}
			else {
				strncpy(result[2] + (start - word), start, skip + 1);
			}
			if (skip < strlen(start))
				start += (skip + 1);
			else break;
			k++;
		}

		printf("%s\n%s\n%s\n", result[0], result[1], result[2]);
	}
}
