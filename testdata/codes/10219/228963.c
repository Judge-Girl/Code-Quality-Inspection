#include <stdio.h>
void merge(int A[], int B[], int* a[], int* b[]){

	int an = 0;
	int bn = 0;
	for(int i = 0 ; a[i] != NULL ; i++){
		an++;
	} an++;
	for(int i = 0 ; b[i] != NULL ; i++){
		bn++;
	} bn++;

	////////////////////////////////////

	int** next;
	int a_ind = 0;
	int b_ind = 0;

	
	int end = 0;

	if(A[a_ind] < B[b_ind]){
		next = &a[a_ind++]; 
		end = 0;
	}else{
		next = &b[b_ind++];
		end = 1;
	}


	for(int i = 1 ;  a_ind < an && b_ind < bn ; i++){
		

		if(A[a_ind] < B[b_ind]){
			*next = &A[a_ind];
			next = &a[a_ind++]; 
			if(a_ind == an)
				end = 0;
		}else{
			*next = &B[b_ind];
			next = &b[b_ind++];
			if(b_ind == bn)
				end = 1;
		}
	}

	if((a_ind+b_ind) == (an+bn))
		end = 10;
	else if( end == 0 )
		*next = &B[b_ind];
	else if(end == 1)
		*next = &A[a_ind];


	


}
