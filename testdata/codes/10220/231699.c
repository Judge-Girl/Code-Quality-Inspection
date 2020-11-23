#include <stdio.h>
int  r[1024*1024] , c[1024*1024] ;
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
	
	int index ,i ,j;
	for(i = 0 ; i < N ; i++){
		for(j = 0 ; j < N ; j++){
			index = A[i][j];
			r[index] = i;
			c[index] = j;
		}
	}
	int Bi = 0;
	while(Bi < N*N-1){
		B[r[Bi]][c[Bi]] = &A[r[Bi+1]][c[Bi+1]];
		Bi++;	
	}
	B[r[Bi]][c[Bi]] = &A[r[0]][c[0]];
	
}
