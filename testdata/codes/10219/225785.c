#include <stdio.h>

void merge(int a[], int b[], int* ap[], int *bp[]) {
    int **prv = NULL;
    int n = 0, m = 0;
    for (int i = 0; ; ++i) if (ap[i] == NULL) {
        n = i + 1;
        break;
    }
    for (int i = 0; ; ++i) if (bp[i] == NULL) {
        m = i + 1;
        break;
    }
    int i = 0, j = 0;
    while (i < n || j < m) {
        if (i < n && j < m) {
            if (a[i] < b[j]) {
                if (prv) *prv = &a[i];
                prv = &ap[i];
                ++i;
            } else {
                if (prv) *prv = &b[j];
                prv = &bp[j];
                ++j;
            }
        } else if (i < n) {
            if (prv) *prv = &a[i];
            prv = &ap[i];
            ++i;
        } else {
            if (prv) *prv = &b[j];
            prv = &bp[j];
            ++j;
        }
    }
}
/* int main() */
/* { */
    /* int A[10], B[10]; */
    /* int *a[10], *b[10], *ans_a[10], *ans_b[10]; */
    /* int i, N, M; */

    /* scanf("%d%d", &N, &M); */
    /* for(i = 0; i < N; i++) */
        /* scanf("%d", &A[i]); */
    /* for(i = 0; i < M; i++) */
        /* scanf("%d", &B[i]); */
    /* for(i = 0; i < N-1; i++) */
        /* a[i] = &A[i+1]; */
    /* a[N-1] = NULL; */
    /* for(i = 0; i < M-1; i++) */
        /* b[i] = &B[i+1]; */
    /* b[M-1] = NULL; */

    /* merge(A, B, a, b); */

    /* ans_a[0] = &B[0]; ans_a[1] = &A[2]; ans_a[2] = &B[1]; ans_a[3] = &B[2]; */
    /* ans_b[0] = &A[1]; ans_b[1] = &A[3]; ans_b[2] = NULL; */

    /* for(i = 0; i < N; i++){ */
        /* if(a[i] != ans_a[i]) */
            /* printf("a[%d] is Wrong!\n", i); */
    /* } */
    /* for(i = 0; i < M; i++){ */
        /* if(b[i] != ans_b[i]) */
            /* printf("b[%d] is Wrong!\n", i); */
    /* } */
    /* printf("Finish!\n"); */
    /* return 0; */
/* } */

