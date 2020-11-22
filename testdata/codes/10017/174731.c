#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#pragma GCC optimize ("unroll-loops")

int original_abs(short a, short b)
{
	int k = a-b;
	return k>0?k:(-k);
}

void find_distance(short *compare1, short *compare2, short a, short b, int n)
{
	int min = INT_MAX;
	for (int i = 0; i < n; i++) {
		int k = original_abs(*(compare1+i), a) + original_abs(*(compare2+i), b);
		if (k < min)
			min = k;
	}
	printf("%d\n", min);
	return;
}

int main(int argc, char const *argv[])
{
	int N; scanf("%d", &N);
	short *step1 = malloc(N * sizeof(short));
	short *step2 = malloc(N * sizeof(short));
	short *step3 = malloc(N * sizeof(short));
	short *step4 = malloc(N * sizeof(short));


	scanf("%hu%hu%hu%hu", &step1[0], &step2[0], &step3[0], &step4[0]);
	find_distance(step1, step2, step3[0], step4[0], 1);
	for (int i = 1; i < N; i++) {
		scanf("%hu%hu", &step1[i], &step2[i]);
		find_distance(step3, step4, step1[i], step2[i], i);
		scanf("%hu%hu", &step3[i], &step4[i]);
		find_distance(step1, step2, step3[i], step4[i], i+1);
	}

	return 0;
}
