#include <stdio.h>
 
void merge(int A[], int B[], int* a[], int* b[]){
	int a_count = 0;
	int b_count = 0;
	int a_finished = 0;
	int b_finished = 0;
	int a_size = 0;
	while(a[a_size]){
		a_size++;
	}
	int b_size = 0;
	while(b[b_size]){
		b_size++;
	}
	for(int i = 0; i <= a_size; i++){
		a[i] = 0;
	}
	for(int j = 0; j <= b_size; j++){
		b[j] = 0;
	}
	#ifdef DEBUG
	printf("A size: %d, B size: %d\n", a_size, b_size);
	#endif
	while(a_count <= a_size && b_count <= b_size){
		if(A[a_count] < B[b_count]){
			if(a_count < a_size && A[a_count + 1] < B[b_count]){
				a[a_count] = &A[a_count + 1];
				#ifdef DEBUG
				printf("link a[%d] to A[%d]\n", a_count, a_count + 1);
				#endif
			}else{
				a[a_count] = &B[b_count];
				#ifdef DEBUG
				printf("link a[%d] to B[%d]\n", a_count, b_count);
				#endif
			}
			a_count++;
		}else{
			if(b_count < b_size && B[b_count + 1] < A[a_count]){				
				b[b_count] = &B[b_count + 1];
				#ifdef DEBUG
				printf("link b[%d] to B[%d]\n", b_count, b_count + 1);
				#endif
			}else{
				b[b_count] = &A[a_count];
				#ifdef DEBUG
				printf("link b[%d] to A[%d]\n", b_count, a_count);
				#endif
			}
			b_count++;
		}
	}
	if(a_count < a_size){
		while(a_count < a_size){
			a[a_count] = &A[a_count+1];
			a_count++;
		}
	}
	if(b_count < b_size){
		while(b_count < b_size){
			b[b_count] = &B[b_count+1];
			b_count++;
		}
	}
}

