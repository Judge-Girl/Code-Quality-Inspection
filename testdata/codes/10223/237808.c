#include <stdio.h>
#include <string.h>

int main()
{
	const char vowels[] = {'a', 'e', 'i', 'o', 'u'};
	char word[10010];
	char result[3][10010];
	while (scanf("%s", word) != EOF) {
		for (int i = 0; i < strlen(word); i++) {
			result[0][i] = '+';
			result[1][i] = '+';
			result[2][i] = '+';
		}
		result[0][strlen(word)] = '\0';
		result[1][strlen(word)] = '\0';
		result[2][strlen(word)] = '\0';
		int I, J;
		scanf("%d%d", &I, &J);
		int k = 0;
		char *start = word;
		for (int i = 0; i <= strlen(word); i++) {
			if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || 
				word[i] == 'o' || word[i] == 'u' || i == strlen(word)) {
				if (k == I) {
					strncpy(result[0] + (start - word), start, i - (start - word) + 1);
				}
				else if (k == J) {
					strncpy(result[1] + (start - word), start, i - (start - word) + 1);
				}
				else {
					strncpy(result[2] + (start - word), start, i - (start - word) + 1);
				}
				start = word + i + 1;
				k++;
			}
		}

		printf("%s\n%s\n%s\n", result[0], result[1], result[2]);
	}
}
