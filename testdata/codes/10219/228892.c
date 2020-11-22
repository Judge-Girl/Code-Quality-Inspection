#include <stdio.h>

void merge(int A[], int B[], int* a[], int* b[]){
	int totA = 0, totB = 0;
	while (a[totA] != NULL) totA ++;
	while (b[totB] != NULL) totB ++;
	totA ++; totB ++;

	int numA = 0, numB = 0, now = 0;
	int numa = 0, numb = 0;
	if (A[0] < B[0]){numA = 1; now = 0;}
	if (A[0] > B[0]){numB = 1; now = 1;}

	int flagA = 0, flagB = 0;
	while (flagA == 0 && flagB == 0){
		if (numA == totA) {
			// printf("giho\n");
			// a[numa] = &B[numB]; numa ++; numB ++; now = 1;
			flagA = 1;
			// b[numb] = &B[numB]; numb ++; numB ++; now = 1;
			if (now == 1){b[numb] = &B[numB]; numb ++; numB ++; now = 1; }
			if (now == 0){a[numa] = &B[numB]; numa ++; numB ++; now = 1;}
			continue;
		}
		else if (numB == totB) {
			// printf("hgohg\n");
			flagB = 1;
			// b[numb] = &B[numA]; numa ++; numA ++; now = 0;
			if (now == 0){a[numa] = &A[numA]; numa ++; numA ++; now = 0;}
			if (now == 1){b[numb] = &A[numA]; numa ++; numA ++; now = 0;}
			continue;
		}
		if (A[numA] > B[numB] && now == 0){a[numa] = &B[numB]; numa ++; numB ++; now = 1;}
		else if (A[numA] < B[numB] && now == 0){a[numa] = &A[numA]; numa ++; numA ++; now = 0;}
		else if (A[numA] > B[numB] && now == 1){b[numb] = &B[numB]; numb ++; numB ++; now = 1;}
		else if (A[numA] < B[numB] && now == 1){b[numb] = &A[numA]; numb ++; numA ++; now = 0;}
	}
	// if (now == 0) {
	// 	while (){
	// 		if (A[numA] > B[numB] && now == 0){a[numa] = &B[numB]; numa ++; numB ++; now = 1;}
	// 		if (A[numA] < B[numB] && now == 0){a[numa] = &A[numA]; numa ++; numA ++; now = 0;}
	// 	}
	// }
	// if (now == 1) {
	// 	while ()
	// }


	return;
}

