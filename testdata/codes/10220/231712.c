int record[1048576][2]; /** r=[0],c=[1] */
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N){
    
    for(int r=0;r<N;r++){
        for(int c=0;c<N;c++){
            record[A[r][c]][0]=r;
            record[A[r][c]][1]=c;
        }
    }
    for(int i=0;i<N*N-1;i++)
        B[record[i][0]][record[i][1]]=&A[record[i+1][0]][record[i+1][1]];
    B[record[N*N-1][0]][record[N*N-1][1]]=&A[record[0][0]][record[0][1]];
	return;
}
