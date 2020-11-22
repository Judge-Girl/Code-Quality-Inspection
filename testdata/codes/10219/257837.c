#include <stdio.h>
void merge(int A[], int B[], int* a[], int* b[]){
     int i = 0, j = 0;
     int alen = 1, blen = 1;
     for(int q = 0; a[q]!=NULL;q++){
         alen++;
     }
     for(int p = 0; b[p]!=NULL;p++){
         blen++;
     }
     while ( i < alen  && j < blen ){
        if (A[i] < B[j]){
            if(i+1 < alen){
                if(A[i+1]>B[j]) a[i] = &B[j]; 
            }
            else{
                a[i] = &B[j];
            }
            i++;
        }
        else{
            if(j+1 < blen){
                if(B[j+1]>A[i]) b[j] = &A[i]; 
            }
            else{
                b[j] = &A[i];
            }
            j++;
        }
     }
 
}
