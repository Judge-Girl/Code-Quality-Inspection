#include <stdio.h>
#define MAXN 1024
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	int PA[N*N];
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			PA[A[i][j]]=10000*i+j;
	int k;
	for(k=0;k<N*N-1;k++)
		B[PA[k]/10000][PA[k]%10000]=&A[PA[k+1]/10000][PA[k+1]%10000];
	B[PA[N*N-1]/10000][PA[N*N-1]%10000]=&A[PA[0]/10000][PA[0]%10000];
}
