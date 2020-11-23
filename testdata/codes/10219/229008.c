#include <stdio.h>
#include <stdlib.h>
void merge(int A[], int B[], int* a[], int* b[]){
    //index of a and A , b and B are the same
    int idxa=0;
    int idxb=0;
    int idxA=0;
    int idxB=0;
    int first=1;
    int prev=0; // 0 for A 1 for B
    //cari size
    int i=0;
    int counta=1;
    int countb=1;
    while(a[i]!=NULL){
        counta++;
        i++;
    }
    i=0;
    while(b[i]!=NULL){
        countb++;
        i++;
    }
    while(idxA<=counta && idxB<=countb){
         if(idxA== counta ){
            a[idxa]=&B[idxB];
                idxa++;
                idxA++;
                idxB++;
        }
        else if(idxB==countb){
            //printf("heyyo\n");
            b[idxb]=&A[idxA];
                idxb++;
                idxA++;
                idxB++;
        }
        else {
            if(A[idxA]<B[idxB]){
                if(first){
                    idxA++;
                    first=0;
                    prev=0;
                }
                else{
                    if(prev==1){
                        b[idxb]=&A[idxA];
                        idxA++;
                        idxb++;
                        prev=0;
                    }
                    else if(prev==0){
                        a[idxa]=&A[idxA];
                        idxa++;
                        idxA++;
                    }
                }
            }

            else {
                if(first) {
                    idxB++;
                    first=0;
                    prev=1;
                }
                else{
                    if(prev==0){
                        a[idxa]=&B[idxB];
                        idxa++;
                        idxB++;
                        prev=1;
                    }
                    else if(prev==1){
                        b[idxb]=&B[idxB];
                        idxb++;
                        idxB++;
                    }
                }
            }
        }
        //printf("A=%d B=%d counta=%d countb=%d\n",A[idxA],B[idxB],counta,countb);
    }

}
