#include <stdio.h>
#include <stdlib.h>

int row_of[1024*1024]; 	//index's range : 0~ N*N-1
int col_of[1024*1024];

void constructPointerArray(const int A[1024][1024],const *B[1024][1024],int N){
	
	int i,j;
	for (i=0;i<N;i++){
		for (j=0;j<N;j++){
			row_of[A[i][j]] = i;
			col_of[A[i][j]] = j;
		}
	}
	int index =0;
	for (i =0;i<N;i++){
		for (j=0;j<N;j++){
			if (index == N*N-1){
				B[row_of[index]][col_of[index]] = &A[row_of[0]][col_of[0]];
			}
			else{
				B[row_of[index]][col_of[index]] = &A[row_of[index+1]][col_of[index+1]];
			}
			index ++;
		}
	}
}
