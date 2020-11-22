#include <stdlib.h>
void split(int A[], int *a[], int *head[], int k) {
    int tail[k];
 
    for (int i = 0; i < k; i++)
            tail[i] = -1;
 
    int size = 1;
 
    for (int i = 0; a[i]; i++)
            size++;
 
    for (int i = 0; i < size; i++) {
        int index = A[i] % k;
        if (tail[index] < 0)
            head[index] = &A[i];
        else
            a[tail[index]] = &A[i];
        tail[index] = i;
    }
    for (int i = 0; i < k; i++)
            if (tail[i] >= 0)
                    a[tail[i]] = NULL;
}
