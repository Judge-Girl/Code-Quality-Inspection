#include <stdio.h>
void split(int A[], int *a[], int *head[], int k)
{
    for(int i = 0; i < k;i++){
        head[i] = NULL;
    }
    int track[100000] = {0};
    int status[100000] = {0};
    int count = 0;
    for(int i = 0 ; a[i] != NULL;i++){
        count++;
    }
    for(int i = 0; i < count; i++){
        track[i] = -1;
    }
    count++;
    int divide;
    for(int i = 0; i < count;i++){
        divide = A[i] % k;
        if(status[divide] == 0){
            head[divide] = &A[i];
            status[divide] = -1;
            track[divide] = i;
        }
        else{
            a[track[divide]] = &A[i];
            track[divide] = i;
        }
    }
    /*for(int x = 0; x < k;x++){
            printf("track[%d] = %d\n",x,track[x]);
        }*/
    for(int i = 0; i < k;i++){
        a[track[i]] = NULL;
    }
}
