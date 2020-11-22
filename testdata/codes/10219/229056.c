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
		if (A[indxA] < B[indxB]) {
			doAorB = doA;
		} else {
			doAorB = doB;
		}
		
		//do the pointing
		if (doAorB == doA) {
			if (a[indxA] != NULL && B[indxB] < *a[indxA] && B[indxB] > A[indxA]) {
				a[indxA] = &B[indxB];
			} else if (a[indxA] == NULL){
				a[indxA] = &B[indxB];
			}
			indxA++;
		} else if (doAorB == doB){
			if (b[indxB] != NULL && A[indxA] < *b[indxB] && A[indxA] > B[indxB]) {
				b[indxB] = &A[indxA];
			} else if (b[indxB] == NULL){
				b[indxB] = &A[indxA];
			} 
			indxB++;
		}
	}
	return;
}
