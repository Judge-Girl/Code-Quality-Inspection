typedef struct {
    int row;
    int col;
} Point;

Point points[1024*1024];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N) {


for (int r = 0; r < N; r++)
    for (int c = 0; c < N; c++) {
        points[A[r][c]].row = r;
        points[A[r][c]].col = c;
    }

for (int i = 0; i < N*N ; i++) 
    B[points[i].row][points[i].col] = &(A[points[i+1].row][points[i+1].col]);

B[points[N*N-1].row][points[N*N-1].col] = &(A[points[0].row][points[0].col]);

}
