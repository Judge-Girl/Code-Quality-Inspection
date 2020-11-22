#include <stdio.h>

void merge(int A[], int B[], int* a[], int* b[]){
	int countA = 0,countB = 0,last,flag;
	if (A[0] < B[0]){
		countB = 0;
		countA = 1;
		flag = 0; 
		last = 0;
	}
	else{
		countA = 0;
		countB = 1;
		last = 0;
		flag = 1;
	}
	int numA = 0,numB = 0;
	while(a[numA] != NULL)
		numA++;
	while(b[numB] != NULL)
		numB++;
		
	int Bwin = 0,Awin = 0;
	for (int k = 0; k < numA + numB + 1; k++){
		if (countA > numA){
			if (flag == 1)
				b[last] = &B[countB];
			else
				a[last] = &B[countB];
			last = countB;
			countB++;
			flag = 1;
			Awin = 1;
			continue;
		}
		if (countB > numB){
			if (flag == 1)
				b[last] = &A[countA];
			else
				a[last] = &A[countA];
			last = countA;
			countA++;
			flag = 0;
			Bwin = 1;
			continue;
		}
		if (A[countA] < B[countB]){
			if (flag == 1)
				b[last] = &A[countA];
			else
				a[last] = &A[countA];
			last = countA;
			countA++;
			flag = 0;
		}
		else{
			if (flag == 1)
				b[last] = &B[countB];
			else
				a[last] = &B[countB];
			last = countB;
			countB++;
			flag = 1;
		}
	}
	if (Awin == 1)
		b[numB] = NULL;
	if (Bwin == 1)
		a[numA] = NULL;
}

