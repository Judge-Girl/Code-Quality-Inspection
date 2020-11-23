#include <stdio.h>
#include <stdlib.h>
int m(int a,int b,int c,int d)
{
    return abs(c-a)+abs(d-b);
}
int main(void)
{
    int n;
    int counta=1,countb=0;
    int ax[52000],ay[52000],bx[52000],by[52000];
    scanf("%d%d%d",&n,&ax[0],&ay[0]);
    int c,d,k,min=99999;
    for(int i=0;i<2*n-1;i++)
    {
        min=99999;
        if(i)   printf("\n");
        if(i%2==0)
        {
            scanf("%d%d",&bx[countb],&by[countb]);
            for(int j=0;j<counta;j++)
            {
                k=m(bx[countb],by[countb],ax[j],ay[j]);
                //printf("%d %d %d %d\n",bx[countb],by[countb],ax[j],ay[j]);
                if(k<min)   min=k;
            }
            countb++;
        }
        else
        {
            scanf("%d%d",&ax[counta],&ay[counta]);
            for(int j=0;j<countb;j++)
            {
                k=m(bx[j],by[j],ax[counta],ay[counta]);
                //printf("%d %d %d %d\n",bx[j],by[j],ax[counta],ay[counta]);
                if(k<min)   min=k;
            }
            counta++;
        }
        printf("%d",min);
    }
    return 0;
}

