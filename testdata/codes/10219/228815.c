#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int B[], int* a[], int* b[]){
	int I = 0, J = 0, i = 0, j = 0, counta = 0, countb = 0;
	int *pa, *pb;
	while(a[counta] != NULL){
		counta++;
	}
	counta++;
	while(b[countb] != NULL){
		countb++;
	}
	countb++;
	int bigger = -1;
	int **last;
	if(A[0] < B[0]){
		last = a;
		I++;
	}else{
		last = b;
		J++;
	}
	while(I < counta && J < countb){
		if(A[I] < B[J]){
			*last = A+I;
			last = &a[I];
			I++;
			
		}else{
			*last = B+J;
			last = &b[J];
			J++;
		}
	}
	if(I == counta){
		a[counta - 1] = B + J;
		while(b[J] != NULL){
			b[J] = B + J + 1;
			J++;
		}
	}else if(J == countb){
		b[countb - 1] = A + I;
		while(a[I] != NULL){
			a[I] = A + I + 1;
			I++;
		}
	}
}
