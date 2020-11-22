#include <stdio.h>
#include <stdlib.h>
int visited[100002];
void split(int A[], int *a[], int *head[], int k){
    int i = 0, j;
    int size = 1;
    while(a[i] != NULL){
        size ++;
        i++;
    }
    if(size == k){
        for(i=0; i<size; i++){
            head[A[i] % k] = &A[i];
            a[i] = NULL;
        }
        return;
    }
    for(i=0; i<size; i++){
        if(visited[i] == 0){
            int rem = A[i] % k;
            head[rem] = &A[i];
            visited[i] = 1;
            int id = i;
            int flag = 0;
            for(j=i+1; j<size; j++){
                if(visited[j] == 0){
                    if(A[j] % k == rem){
                        flag = 1;
                        a[id] = &A[j];
                        a[j] = NULL;
                        visited[j] = 1;
                        id=j;
                    }
                }
            }
            if(flag == 0)
                a[i] = NULL;
        }
    }
    return;
}
