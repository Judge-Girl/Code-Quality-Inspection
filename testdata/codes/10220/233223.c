#include <stdio.h>
#define CONSTRUCT
#define MAXN 1024
 
int row[MAXN * MAXN + 2];
int col[MAXN * MAXN + 2];
 
void constructPointerArray(const int A[MAXN][MAXN], const int *B[MAXN][MAXN], int N) {
    int i, j;
    //int row[MAXN], col[MAXN];
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            row[A[i][j]] = i;
            col[A[i][j]] = j;    
        }
    }
    /*for (i = 0; i < N*N; i++)
        printf ("%d %d\n", row[i], col[i]);
    */
    int start_row = row[0];
    int start_col = col[0];
    int end_row = row[1];
    int end_col = col[1];
 
    for (i = 1 ; i <= N*N; i++) {
        B[start_row][start_col] = &A[end_row][end_col];
        //printf ("B[%d][%d] is %d\n", start_row, start_col, *B[start_row][start_col]);
 
        if (i != N*N) {
            start_row = end_row;
            start_col = end_col;
            end_row = row[i+1];
            end_col = col[i+1];
            //printf ("start is (%d,%d) , end is (%d, %d)\n", start_row, start_col, end_row, end_col);
        }
        else {
            //printf ("i is %d, start row %d, start col %d\n", i, start_row, start_col);
            //start_row = row[N*N-1];
            //start_col = col[N*N-1];
            end_row = row[0];
            end_col = col[0];
            B[start_row][start_col] = &A[end_row][end_col];
        }
    }
    //printf ("finished loop\n");
 
    //print
    /*for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf ("%d", *B[i][j]);
        printf ("\n");
    }*/
}
