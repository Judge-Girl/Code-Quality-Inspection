#include <stdlib.h>
#define MAX 100000
void split(int A[], int *a[], int *head[], int k)
{
    int tail[MAX];
    int count[MAX] = {0};
    int i = 0;
    for ( ; a[i] != NULL; i++)
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
    }
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
    for (int i = 0; i < k; i++)
    {
        if (count[i] == 0)
            head[i] = NULL;
        else
            a[tail[i]] = NULL;
    }
    return;
}

