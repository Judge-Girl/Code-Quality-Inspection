#include <stdio.h>

void merge(int A[], int B[], int* a[], int* b[]) {
	int len_a = 0, len_b = 0, N = 0;
	while (a[len_a] != NULL) {
		++len_a;
	}
	++len_a;
	while (b[len_b] != NULL) {
		++len_b;
	}
	++len_b;

	int iter_a = 0, iter_b = 0;
	while (iter_a < len_a && iter_b < len_b) {
		if (A[iter_a] < B[iter_b]) {
			if (iter_a < len_a - 1 && A[iter_a + 1] < B[iter_b]) {
				a[iter_a] = &A[iter_a + 1];
				#ifdef DEBUG
				printf("%d -> %d\n", A[iter_a], A[iter_a + 1]);
				#endif
			}
			else {
				a[iter_a] = &B[iter_b];
				#ifdef DEBUG
				printf("%d -> %d\n", A[iter_a], B[iter_b]);
				#endif
			}
			++iter_a;
		}
		else {
			if (iter_b < len_b - 1 && B[iter_b + 1] < A[iter_a]) {
				b[iter_b] = &B[iter_b + 1];
				#ifdef DEBUG
				printf("%d -> %d\n", B[iter_b], B[iter_b + 1]);
				#endif
			}
			else {
				b[iter_b] = &A[iter_a];
				#ifdef DEBUG
				printf("%d -> %d\n", B[iter_b], A[iter_a]);
				#endif

			}
			++iter_b;
		}
	}
	while (iter_a < len_a) {
		if (iter_a == len_a - 1) {
			a[iter_a] = NULL;
			break;
		}
		a[iter_a] = &A[iter_a + 1];
		#ifdef DEBUG
		printf("%d -> %d\n", A[iter_a], A[iter_a + 1]);
		#endif
		++iter_a;
	}
	while (iter_b < len_b) {
		if (iter_b == len_b - 1) {
			b[iter_b] = NULL;
			break;
		}
		b[iter_b] = &B[iter_b + 1];
		#ifdef DEBUG
		printf("%d -> %d\n", B[iter_b], B[iter_b + 1]);
		#endif
		++iter_b;
	}
	#ifdef DEBUG
	for (int i = 0; i < len_a; ++i) {
		if (a[i] == NULL) {
			printf("NULL");
			break;
		}
		printf("%d ", *a[i]);
	}
	printf("\n");
	for (int i = 0; i < len_b; ++i) {
		if (b[i] == NULL) {
			printf("NULL");
			break;
		}
		printf("%d ", *b[i]);
	}
	printf("\n");
	#endif
}

