#define MAXN 1024
int r[MAXN * MAXN], c[MAXN * MAXN];
void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N)
{
    int k, j, i;
    for ( i = 0; i < N; i++ ) {
        for ( j = 0; j < N; j++ ) {
            r[A[i][j]] = i;
            c[A[i][j]] = j;
        }
    }
 
    int s = 0;
    for ( i = 0; i < N; i++ ) {
        for ( j = 0; j < N; j++ ) {
            if ( A[i][j] == 0 ) {
                r[0] = i;
                c[0] = j;
                s = 1;
                break;
            }
        }
        if ( s == 1 )   break;
    }
 
    for ( i = 0; i < N*N-1; i++ ) {
        B[r[i]][c[i]] = &A[r[i+1]][c[i+1]];
    }
    B[r[N*N-1]][c[N*N-1]] = &A[r[0]][c[0]];
}
