#include<stdio.h>
#include<stdlib.h>

void merge(int A[], int B[], int* a[], int* b[]){
    int ai,bi;
    int which;
    ai=0;
    bi=0;
    if(A[0]>B[0]){
        bi++;
        which=0;
    }else{
        ai++;
        which=1;
    }
    int af=1,bf=1;
    while(af||bf){
        if(which){
            if(a[ai-1]==NULL){
                if(bf){
                    af=0;
                    ai--;
                    a[ai]=&B[bi];
                    which=0;
                    bi++;
                }else{af=0;}
            }else if(A[ai]>B[bi]&&bf){
                a[ai-1]=&B[bi];
                which=0;
                bi++;
            }else{
                a[ai-1]=&A[ai];
                ai++;
            }
        }else{
            if(b[bi-1]==NULL){
                if(af){
                    bf=0;
                    bi--;
                    b[bi]=&A[ai];
                    which=1;
                    ai++;
                }else{bf=0;}
            }else if(A[ai]<B[bi]&&af){
                b[bi-1]=&A[ai];
                which=1;
                ai++;
            }else{
                b[bi-1]=&B[bi];
                bi++;
            }
        }
    }
    return;
}

