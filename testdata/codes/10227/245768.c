#include <stdio.h>
#include <string.h>
int main()
{
	int T;
	scanf("%d", &T);
	char string[100000];
	unsigned long long int ans = 0;
	unsigned long long int temp;
	unsigned char c;
	if (T == 0) {
		scanf("%s", string);
		int length = strlen(string);
		int k = (length + 1) / 8;
		int t = (length + 1) % 8;
		for (int i = 0; i < k; i++) {
			for (int j = 8 * i; j < 8 * i + 8; j++) {
				c = string[j];
				ans <<= 8;
				ans += c;
			}
			printf("%llu\n", ans);
			ans = 0;
		}
		if (t > 0) {
			for (int i = 0; i < t; i++) {
				ans <<= 8;
				ans += string[8 * k + i];
			}
			ans <<= (64 - t * 8);
			printf("%llu", ans);
		}
	}
	else {
		int n;
		scanf("%d", &n);
		int index = 0;
		for (int i = 0; i < n; i++) {
			scanf("%llu", &ans);
			for (int j = 0; j < 8; j++) {
				temp = ans;
				temp <<= j * 8;
				temp >>= 56;
				string[index] = temp;
				index++;
			}
		}
		printf("%s", string);
	}
	return 0;
}


