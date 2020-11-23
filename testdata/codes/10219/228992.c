#include <stdio.h>
void merge(int A[], int B[], int* a[], int* b[]){
    int n=0,m=0;
    while(a[n++]!=NULL);
    while(b[m++]!=NULL);
    int i=1,j=1;
    int predeck,prenum=0;
    if(A[0]<B[0]){
        predeck=0;
        j=0;
    }
    else{
        predeck=1;
        i=0;
    }
    while(i<n && j<m){
        if(A[i]<B[j]){
            if(predeck==0){
                a[prenum]=&A[i];
                predeck=0;
                prenum=i;
                i++;
            }
            else if(predeck==1){
                b[prenum]=&A[i];
                predeck=0;
                prenum=i;
                i++;
            }
        }
        else{
            if(predeck==0){
                a[prenum]=&B[j];
                predeck=1;
                prenum=j;
                j++;
            }
            else if(predeck==1){
                b[prenum]=&B[j];
                predeck=1;
                prenum=j;
                j++;
            }
        }
    }
    if(j==m){
        if(predeck==0){
            a[prenum]=&A[i];
            predeck=0;
            prenum=i;
            i++;
        }
        else if(predeck==1){
            b[prenum]=&A[i];
            predeck=0;
            prenum=i;
            i++;
        }
        while(i<n){
            a[prenum]=&A[i];
            predeck=0;
            prenum=i;
            i++;
        }
        a[prenum]=NULL;
    }
    else if(i==n){
        if(predeck==0){
            a[prenum]=&B[j];
            predeck=1;
            prenum=j;
            j++;
        }
        else if(predeck==1){
            b[prenum]=&B[j];
            predeck=1;
            prenum=j;
            j++;
        }
        while(j<m){
            b[prenum]=&B[j];
            predeck=1;
            prenum=j;
            j++;
        }
        b[prenum]=NULL;
    }
}

