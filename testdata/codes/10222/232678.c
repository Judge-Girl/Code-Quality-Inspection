#include <stdio.h>
#include <stdlib.h>
void split(int A[], int *a[], int *head[], int k){
	int** next[k];
	for(int i = 0 ; i < k ; i++){
		next[i] = &head[i];
	}
	int n = 1;
	for(int i = 0 ; a[i] != NULL ; i++){
		n++;
	}

	int r;
	for(int i = 0 ; i < n ; i++){
		r = A[i]%k;
		*next[r] = &A[i];
		next[r] = &a[i];

	}

	/*
	for(int r = 0 ; r < k ; r++){
		for(int i = 0 ; i < n ; i++){
				if( (A[i]%k) == r){

					//ptr  = next[r];
					//*ptr = &A[i];
					*next[r] = &A[i];
					next[r] = &a[i]; 
				}

		}
	}
	*/
	for(int i = 0 ; i < k ; i++){
		*next[i] = NULL;
		//ptr = next[r];
		//*ptr = NULL;
	}

}
