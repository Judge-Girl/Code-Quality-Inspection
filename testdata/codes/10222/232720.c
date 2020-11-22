#include <stdio.h>
#include <stdlib.h>

void split(int A[], int *a[], int *head[], int k){
	int n = 0;
	while(1){
		if(a[n] != NULL){
			n++;
		}else{
			break;
		}
	}
	n++;
	for(int i = 0; i < n; i++){
		a[i] = NULL;
	}
	int table[100000];
	for(int i = 0; i < 100000; i++){
		table[i] = -1;
	}
	int lastTable[k];
	int firstTable[k];
	for(int i = 0; i < k; i++){
		lastTable[i] = -1;
		firstTable[i] = -1;
	}
	for(int i = 0; i < n; i++){
		int tar = A[i] % k;
		if(lastTable[tar] == -1){
			head[tar] = &A[i];
			firstTable[tar] = i;
		}else{
			table[lastTable[tar]] = i;
		}
		lastTable[tar] = i;
	}
	for(int i = 0; i < n; i++){
		if(table[i] != -1){
			a[i] = &A[table[i]];
		}
		
	}/*
	for(int j = 0; j < k; j++){
		int **last = NULL;
		if(head[j] != NULL){
			last = &head[j];
			int tar = firstTable[j];
			while(table[tar] != -1){
				*last = &A[tar];
				tar = table[tar];
				last = &a[tar];
			}
		}
			
	}
	*/
}
