#include <stdio.h>
void merge(int A[], int B[], int* a[], int* b[]){
int i=0, j=0, sa, sb;
while(1){
    if(a[i]==NULL){
        break;
    }
    i++;
}
sa=i+1;
i=0;
while(b[i]!=NULL){
    i++;
}
sb=i+1;
i=0;
while(i<sa&&j<sb){
    if(A[i]<B[j]){
        if(A[i+1]>B[j]||i+1==sa){
            a[i]=&B[j];
            i++;
        }
        else{
            a[i]=&A[i+1];
            i++;
        }
    }
    else{
        if(B[j+1]>A[i]||j+1==sb){
            b[j]=&A[i];
            j++;
        }
        else{
            b[j]=&B[j+1];
            j++;
        }
    }
}
if(i==sa){
    for(j; j<sb-1; j++){
        b[j]=&B[j+1];
    }
}
else if(j==sb){
    for(i; i<sa-1; i++){
        a[i]=&A[i+1];
    }
}
}
