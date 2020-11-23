#include<stdio.h>
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	int count=0;
	int pos[N*N];
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			pos[A[i][j]]=count;
			count++;
		};
	};
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int num;
			num=A[i][j];
			int ori=pos[num];
			int dir=pos[(num+1)%(N*N)];
			B[ori/N][ori%N]=&A[dir/N][dir%N];
		};
	};
}

