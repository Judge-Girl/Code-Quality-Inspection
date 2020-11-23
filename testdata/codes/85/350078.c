#include <stdio.h>
#include <stdlib.h>
typedef struct date{
    int y;int m;int d;
} Date;
int cmp(const void *x, const void *y) {
    Date *a = (Date*) x;
    Date *b = (Date*) y;
    if (a->y < b->y)    return -1;
    if (a->y > b->y)    return 1;
    if (a->m < b->m)    return -1;
    if (a->m > b->m)    return 1;
    if (a->d < b->d)    return -1;
    if (a->d > b->d)    return 1;
}
int gee[90000000]={0};
int main() {
    int n;
    Date *dts=(Date *)malloc(sizeof(Date)*1000001);
    scanf("%d",&n);
    //printf("%d\n",n);
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&dts[i].y,&dts[i].m,&dts[i].d);
      if(dts[0].y<300000)
        	gee[dts[i].y*10000+dts[i].m*100+dts[i].d]=1;
        //printf("%d %d %d\n",dts[i].y,dts[i].m,dts[i].d);
    }
  if(dts[0].y>300000)
  {
    qsort(dts,n,sizeof(Date),cmp);
        for (int i = 0; i < n; i++)
            printf("%d %d %d\n", dts[i].y, dts[i].m, dts[i].d);
  }
  else{
    for(int i=0;i<90000000;i++){
        if(gee[i]==0) continue;
        else{
            printf("%d %d %d\n",i/10000,(i/100)%100,i%100);
        }
    }
  }
}
