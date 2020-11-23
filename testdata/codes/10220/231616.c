#include<stdio.h>
	int locx[1024*1024]={0},locy[1024*1024]={0};

void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			locx[A[i][j]]=i;
			locy[A[i][j]]=j;
		}
	}
	#ifdef debug
	for(int i=0;i<N*N;i++)
		printf("i=%d x=%d y=%d\n",i,locx[i],locy[i]);
	#endif
	for(int i=0;i<N*N-1;i++){
		B[locx[i]][locy[i]]=&(A[locx[i+1]][locy[i+1]]);
	#ifdef debug
		printf("i=%d %d\n",i,*B[locx[i]][locy[i]]);
	#endif
	}
	B[locx[N*N-1]][locy[N*N-1]]=&(A[locx[0]][locy[0]]);
}
