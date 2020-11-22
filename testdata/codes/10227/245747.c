#include <stdio.h>
#include <string.h>
#define MAXS 100000
void string2int () {
	char input[MAXS];
	scanf("%s", input);
	int input_len = strlen(input); 
	long long int num = 0;
	for (int i = 0; i < input_len; ++i) {
		num |= input[i];
		if (i%8 == 7) {
			printf("%lld\n", num);
			num = 0;
		}
		else {
			num <<= 8;
		}
	}
	num <<= (8 - (input_len%8 + 1)) * 8;
	printf("%lld\n", num);
}

void int2string () {
	int N;
	long long int input;
	// long long int mask = ((long long int)1 << 9) - 1;
	scanf("%d", &N);
	while (N--) {
		scanf("%lld", &input);
		for (int i = 0; i < 8; ++i) {
			char c = input >> (7 - i)*8;
			if (c == 0) break;
			printf("%c", c);
		}
	}
	printf("\n");
}

int main () {
	int T;
	scanf("%d", &T);
	if (T) int2string();
	else string2int();
	return 0;	
}

