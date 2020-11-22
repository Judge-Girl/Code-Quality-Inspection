#include<stdio.h>
#include<stdlib.h>
typedef struct da{
    int y,m,d;
}da;
da a[1000000];
int cmp(const void *d1,const void *d2){
    da *p1=(da*)d1;
    da *p2=(da*)d2;
    if(p1->y<p2->y)
        return -1;
    else if(p1->y>p2->y)
        return 1;
    else if(p1->m<p2->m)
        return -1;
    else if(p1->m>p2->m)
        return 1;
    else if(p1->d<p2->d)
        return -1;
    else if(p1->d>p2->d)
        return 1;
    else
        return 0;
}
int input()
{
  char cha;
  int x=0;
  while(cha=getchar())
     if(cha!=' '&&cha!='\n') break;
  x=cha-'0';
  while(cha=getchar())
    {
     if(cha==' '||cha=='\n') break;
      x=x*10+cha-'0';
    }
    return x;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        a[i].y=input();
        a[i].m=input();
        a[i].d=input();
    }
    qsort(a,n,sizeof(da),cmp);
    for(int i=0;i<n;i++)
        printf("%d %d %d\n",a[i].y,a[i].m,a[i].d);

}

