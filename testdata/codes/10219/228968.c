#include <stdio.h>
void merge(int A[], int B[], int* a[], int* b[]){
    int id_a = 0, id_b = 0;
    int arrayA[1000] = {0};
    int arrayB[1000] = {0};
    int sizea = 1, sizeb = 1;
    for(int i = 0; a[i] != NULL; i++){
        sizea++;
    }
    for(int j = 0; b[j] != NULL; j++){
        sizeb++;
    }
    while(id_a < sizea && id_b < sizeb){
        if(A[id_a] < B[id_b]){
            if(A[id_a+1] < B[id_b]){
                a[id_a] = &A[id_a+1];
            }
            else{
                a[id_a] = &B[id_b];
            }
            id_a++;
        }
        else{
            if(B[id_b+1] < A[id_a]){
                b[id_b] = &B[id_b+1];
            }
            else{
                b[id_b] = &A[id_a];
            }
            id_b++;
        }
    }
    if (id_a == sizea){
        a[id_a - 1] = &B[id_b];
        for(int i = id_b; i < sizeb - 1; i++){
            b[i] = &B[i+1]; 
        }
        b[sizeb - 1]  = NULL;
    }
    else if(id_b == sizeb){
        b[id_b - 1] = &A[id_a];
        for(int i = id_a; i < sizea - 1; i++){
            a[i] = &A[i+1];
        }
        a[sizea- 1] = NULL;
    }
    return;
}
