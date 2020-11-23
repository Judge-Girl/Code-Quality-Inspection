#include "constructPointerArray.h"
#include<stdio.h>

void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N)
{
	int c, d, pon[N*N];
	for(c=0;c<N;c++){
		for(d=0;d<N;d++)
			pon[A[c][d]]=c*N+d;
	}
	const int *tmp=(&A[pon[0]/N][pon[0]%N]);
	for(c=0;c<N*N-1;c++){
		B[pon[c]/N][pon[c]%N]=&A[pon[c+1]/N][pon[c+1]%N];
	}
	B[pon[N*N-1]/N][pon[N*N-1]%N]=tmp;
}
