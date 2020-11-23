#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void merge(int A[], int B[], int* a[], int* b[]){
    int con1,con2,con3,ta,tb,now,acon=0,bcon=0,alen,blen;
    for(con1=0;a[con1]!=NULL;con1++){
        con2=0;
    }
    alen=con1;
    alen++;
    for(con1=0;b[con1]!=NULL;con1++){
        con2=0;
    }
    blen=con1;
    blen++;
    if(A[0]<B[0]){
        ta=1;
        tb=0;
        now=0;
    }
    else{
        ta=0;
        tb=1;
        now=1;
    }
    while(ta<alen&&tb<blen){
        if(A[ta]<B[tb]){
            if(now==0){
                a[acon]=&A[ta];
                acon++;
                ta++;
            }
            else{
                b[bcon]=&A[ta];
                ta++;
                bcon++;
                now=0;
            }
        }
        else{
            if(now==0){
                a[acon]=&B[tb];
                tb++;
                acon++;
                now=1;
            }
            else{
                b[bcon]=&B[tb];
                bcon++;
                tb++;
            }
        }
    }
    if(ta==alen){
        if(a[acon]==NULL){
            a[acon]=&B[tb];
            tb++;
        }
        while(tb<blen-1){
            b[bcon]=&B[tb];
            bcon++;
            tb++;
        }
    }
    else{
        if(b[bcon]==NULL){
            b[bcon]=&A[ta];
            ta++;
        }
        while(ta<alen-1){
            a[acon]=&A[ta];
            acon++;
            ta++;
        }
    }
}
