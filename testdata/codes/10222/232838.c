#include <stdio.h>

void split(int A[], int *a[], int *head[], int k){
  int idx=0;
  for (int i=0;a[i]!=NULL;i++)idx++;
  idx++;
  int vis[100005],cnt[100005];
  for (int i=0;i<k+1;i++) vis[i]=0;
  for (int i=0;i<idx;i++){
    if (vis[(A[i]%k)]==0){
      head[(A[i]%k)]=&A[i];
      vis[(A[i]%k)]=1;
    }
  }
  for (int i=0;i<k;i++){
    if (vis[i]==0) head[i]=NULL;
  }

  for (int i=0;i<idx;i++) {vis[i]=0;cnt[(A[i]%k)]++;}
  for (int i=0;i<idx;i++){
    int ok=0;
    if (cnt[A[i]%k]==1){a[i]=NULL; continue;}
    for (int j=i+1;j<idx;j++){
      if (((A[j]%k)==(A[i]%k))&&(vis[j]==0)){
        a[i]=&A[j];
        vis[j]=1;
        ok=1;
        cnt[(A[j]%k)]--;
      }
      if (ok) break;
    }
    if (ok==0) a[i]=NULL;
  }

}

