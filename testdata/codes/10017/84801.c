#include<stdio.h>
#include<stdlib.h>

void cal(int *ptr,int x,int y,int len,int data){
  int min,i,tem;
  min = 65534;
  for(i = 0;i<data;i++){
    tem = abs(*(ptr+i*2+1)-x)+abs(*(ptr+i*2)-y);
    if(tem<min)
      min = tem;
  }
  printf("%d\n",min);
}

int main(){
  int n,i;
  scanf("%d",&n);
  int A[n][2],B[n][2];
  scanf("%d%d",&(A[0][0]),&(A[0][1]));
  scanf("%d%d",&(B[0][0]),&(B[0][1]));
  cal(A[0],B[0][1],B[0][0],1,1);
  for(i = 1;i<n;i++){
    scanf("%d%d",&(A[i][0]),&(A[i][1]));
    cal(B[0],A[i][1],A[i][0],1,i);
    scanf("%d%d",&(B[i][0]),&(B[i][1]));
    cal(A[0],B[i][1],B[i][0],1,i+1);
  }
  return 0;
}

