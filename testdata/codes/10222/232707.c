#include <stdio.h>
#include <stdlib.h>

void split(int A[], int *a[], int *head[], int k){
    int alen,con1,con2,con3,yoo;
    for(con1=0;a[con1]!=NULL;con1++){
        con2=0;
    }
    alen=con1;
    alen++;
    int yo[100100]={0};
    int last[100100]={0};
    for(con1=0;con1<alen;con1++){
        yoo=A[con1]%k;
        if(yo[yoo]==0){
            yo[yoo]=1;
            head[yoo]=&A[con1];
            last[yoo]=con1;
        }
        else{
            a[last[yoo]]=&A[con1];
            last[yoo]=con1;
        }
    }
    yoo=A[0]%k;
    con2=0;
    for(con1=1;con1<alen;con1++){
        if(A[con1]%k==yoo)
            con2=1;
    }
    for(con1=0;con1<k;con1++){
        if(head[con1]!=NULL){
            a[last[con1]]=NULL;
        }
    }

}

