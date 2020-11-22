#include <stdlib.h>
 
void linkGroup(int A[], int *a[], int *head[], int k)
{
    int i = -1, t;
    int **tmp[k];
    for (int i = 0; i < k; ++i)
    {
        tmp[i] = NULL;
    }
    do {
        i++;
        t = A[i]%k;
        if (head[t] == NULL)
        {
            head[t] = &A[i];
            tmp[t] = &a[i];
            continue;
        }
        *tmp[t] = &A[i];
        tmp[t] = &a[i];
    } while(a[i] != NULL);
    for (int i = 0; i < k; ++i)
    {
        if (tmp[i] != NULL)
        {
            *tmp[i] = NULL;
        }
    }
    return;
}
