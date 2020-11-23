#include <stdio.h>
#include <string.h>
#define MAXK 10005

void init(char output[2][MAXK], char str[]) {
	int length = strlen(str);
	
	memset(output[0], '+', length);
	memset(output[1], '+', length);
	output[0][length] = output[1][length] = '\0';
}

void findSyllable(char str[], int last, int buffer[]) {
	static const char vowel[] = "aeiou";
	char *visit = str;

	for (int i = 0; i <= last; i++) {
		int offset = strcspn(visit, vowel);
		buffer[i+1] = buffer[i] + offset + 1;
		visit += (offset + 1);
	}
}
int main () {
	char input[MAXK];
	char output[2][MAXK];
	int index[2];
	int position[MAXK] = {-1};

	while (scanf("%s%d%d", input, &index[0], &index[1]) != EOF) {
		init(output, input);
		findSyllable(input, index[0] > index[1] ? index[0] : index[1], position);
		for (int i = 0; i < 2; i++) {
			for (int j = position[index[i]] + 1; j <= position[index[i]+1]; j++) {
				output[i][j] = input[j];
				input[j] = '+';
			}
		}
		printf("%s\n%s\n%s\n", output[0], output[1], input);
	}
	return 0;
}

