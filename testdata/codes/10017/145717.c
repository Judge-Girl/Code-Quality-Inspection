#include <stdio.h>
#include <stdlib.h>
int a[2][50005][2];
int main(){
  int n;
  scanf("%d%d%d%d%d",&n,&a[0][0][0],&a[0][0][1],&a[1][0][0],&a[1][0][1]);
  printf("%d\n",abs(a[0][0][0]-a[1][0][0])+abs(a[0][0][1]-a[1][0][1]));
  for(int i=1;i<n;i++){
    scanf("%d%d",&a[0][i][0],&a[0][i][1]);
    int mi=100000;
    for(int j=0;j<i;j++){
      if(abs(a[0][i][0]-a[1][j][0])+abs(a[0][i][1]-a[1][j][1])<mi)
        mi=abs(a[0][i][0]-a[1][j][0])+abs(a[0][i][1]-a[1][j][1]);
    }
    printf("%d\n",mi);
    scanf("%d%d",&a[1][i][0],&a[1][i][1]);
    mi=100000;
    for(int j=0;j<=i;j++){
      if(abs(a[1][i][0]-a[0][j][0])+abs(a[1][i][1]-a[0][j][1])<mi)
        mi=abs(a[1][i][0]-a[0][j][0])+abs(a[1][i][1]-a[0][j][1]);
    }
    printf("%d\n",mi);
  }
  return 0;
}
