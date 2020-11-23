#include <stdio.h>
#include <stdlib.h>
#define doA 1
#define doB 2

void merge(int A[], int B[], int* a[], int* b[])
{
	int ASize = 1, BSize = 1;
	for (int i = 0; a[i] != NULL; i++) {
		ASize++;
	}
	for (int i = 0; b[i] != NULL; i++) {
		BSize++;
	}

	int indxA = 0, indxB = 0;
	int doAorB;

	while (indxA + indxB < ASize + BSize -1) {
		// printf("indxA = %d\n", indxA);
		// printf("indxB = %d\n", indxB);

		if (A[indxA] < B[indxB]) {
			doAorB = doA;
			//printf("a = %d, b = %d, do A \n", A[indxA], B[indxB]);
		} else {
			doAorB = doB;
			//printf("a = %d, b = %d, do B \n", A[indxA], B[indxB]);
		}
		
		//do the pointing
		if (doAorB == doA) {
			if (a[indxA] != NULL && B[indxB] < *a[indxA] && B[indxB] > A[indxA]) {
				a[indxA] = &B[indxB];
				// printf("indxA = %d\n", indxA);
				indxA++;
			} else if (a[indxA] == NULL){
				a[indxA] = &B[indxB];
				indxA++;
			}else {
				indxA++;
			}
		} else if (doAorB == doB){
			if (b[indxB] != NULL && A[indxA] < *b[indxB] && A[indxA] > B[indxB]) {
				b[indxB] = &A[indxA];
				// printf("%d", *b[indxB]);
				// printf("indxB = %d\n", indxB);
				indxB++;
				// exit(0);
			} else if (b[indxB] == NULL){
				b[indxB] = &A[indxA];
				indxB++;
			} else {
				indxB++;
			}
		}
	}
	return;

}
