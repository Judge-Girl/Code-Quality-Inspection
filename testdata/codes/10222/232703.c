#include <stdlib.h>
#define MAX 100000
int tail[MAX];
int count[MAX] = {0};
void foo(int i, int A[], int *a[], int *head[], int k)
{
    int rem = A[i] % k;
    if (count[rem] == 0)
    {
        head[rem] = &A[i];
        tail[rem] = i;
        count[rem]++;
    }
    else
    {
        a[tail[rem]] = &A[i];
        tail[rem] = i;
        count[rem]++;
    }
    return;
}
void split(int A[], int *a[], int *head[], int k)
{
    int i = 0;
    for ( ; a[i] != NULL; i++)
        foo(i, A, a, head, k);
    foo(i, A, a, head, k);
    for (int i = 0; i < k; i++)
    {
        if (count[i] == 0)
            head[i] = NULL;
        else
            a[tail[i]] = NULL;
    }
    return;
}

