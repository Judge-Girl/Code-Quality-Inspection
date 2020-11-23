#include <stdio.h> 
#include <stdlib.h>
void merge(int A[], int B[], int* a[], int* b[]){
	int i=0;
	int j=0;
	
	int lenA, lenB;
	for(lenA = 0; a[lenA]!=NULL; lenA++);
	for(lenB = 0; b[lenB]!=NULL; lenB++);
	lenA++;
	lenB++;
	
	int** pre;
	int flag = A[0]<B[0] ? 0:1;

	while(i<lenA && j<lenB){
		int new_flag = A[i]<B[j] ? 0:1;
		
		if(new_flag != flag)
			*pre = new_flag ? &B[j]:&A[i];
		
		flag = new_flag;
		pre = flag ? &b[j]:&a[i];
		
		if(new_flag)
			j++;
		else
			i++;
	}
	
	if(i>=lenA)
		*pre =  &B[j];
	else
		*pre =  &A[i];

}
