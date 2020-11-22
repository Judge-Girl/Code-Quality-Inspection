#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_N 50001

typedef struct vector {
    int x[MAX_N], y[MAX_N];
    int sz;
} Vector;

int main(void)
{
    int N = 0;
    scanf("%d", &N);

    Vector *A = malloc(sizeof(Vector)), *B = malloc(sizeof(Vector));
    A->sz = B->sz = 0;

    Vector *v = A, *w = B;
    for(int doubleN = 2 * N; doubleN--; ) {
        int x, y;
        scanf("%d %d", &x, &y);
        v->x[v->sz] = x, v->y[v->sz++] = y;

        int min = INT_MAX;
        for(int j = 0; j < w->sz; ++j) {
            int dist = abs(w->x[j] - x) + abs(w->y[j] - y);
            if(dist < min)
                min = dist;
        }
        if(min < INT_MAX)
            printf("%d\n", min);

        Vector *tmp = v;
        v = w, w = tmp; 
    }

    free(A);
    free(B);
    return 0;
}

