#include <stdio.h>
#include <string.h>
#define STRLEN 100000
#define NMAX 12500
#define BYTENUM 8

void str2code()
{
	long long result[NMAX] = {};
	char str[STRLEN];
	int size = 0, j = 7;
	while (scanf("%s", str) != EOF) {
		int len = strlen(str);
		for (int k = 0; k < len; k++) {
			result[size] += ((long long)str[k] << (8 * j));
			if (j == 0) {
				j = 7;
				size++;
			} else {
				j--;
			}
		}
	}
	for (int i = 0; i <= size; i++) {
		printf("%lld\n", result[i]);
	}
	return;
}

void code2str()
{
	int N;
	scanf("%d", &N);
	long long code;
	char result[STRLEN];
	const int decode[8] = {56, 48, 40, 32, 24, 16, 8, 0};
	int len = -1;
	while (scanf("%lld", &code) != EOF) {
		char tmp[10];
		memset(tmp, '\0', 10);
		for (int i = 0; i < BYTENUM; i++) {
			tmp[i] = (code >> decode[i]) % (1 << BYTENUM);
		}
		strcat(result, tmp);
	}
	printf("%s\n", result);
	return;
}

int main()
{
	int T;
	scanf("%d", &T);
	if (T == 0) {
		str2code();
	} else if (T == 1) {
		code2str();
	}
}
