#include <stdio.h>
#include <stdlib.h>
void merge(int A[], int B[], int* a[], int* b[]){
	int nowa = 0, nowb = 0;
	int asize = 0,bsize = 0;
	for(int i = 0; ;i++)
		if(a[i] == NULL ) {
			asize = i+1;
			break;
		}
	for(int i = 0; ;i++)
		if(b[i] == NULL ) {
			bsize = i+1;
			break;
		}
	while(nowa != asize && nowb != bsize){
		//printf("a %d b %d\n",A[nowa],B[nowb]);
		if(A[nowa] < B[nowb]){
			if(nowa+1 < asize){
				if(B[nowb] < A[nowa+1]){
					a[nowa] = &B[nowb];
				}
				else {
					a[nowa] = &A[nowa+1];
				} 
			}
			else a[nowa] = &B[nowb];
			nowa++;
		}
		else {
			if(nowb+1 < bsize){
				if(B[nowb+1] < A[nowa])
				{
					b[nowb] = &B[nowb+1];
				}
				else 
					b[nowb] = &A[nowa];
			}
			else b[nowb] = &A[nowa]; 
			nowb++;
		}
		//printf("nowa %d nowb %d\n", nowa, nowb);
	}
	if(nowa == asize){
		for(int i = nowb; i < bsize-1; i++)
			b[i] = &B[i+1];
		b[bsize-1] = NULL; 
	}
	else if(nowb == bsize){
		for(int i = nowa; i < asize-1; i++)
			a[i] = &A[i+1];
		a[asize-1] = NULL;
	}
}
