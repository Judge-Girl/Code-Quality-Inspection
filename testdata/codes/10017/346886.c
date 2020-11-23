#include<stdio.h>
#define abs(a) (a) > 0 ? (a) : -(a)
typedef struct c
{
    long long int x, y;
} coo;
int distance(coo a,coo b)
{
    return (abs(a.x - b.x)) + (abs(a.y - b.y));
}
void scan_coo(coo *a)
{
    scanf("%d%d",&a->x,&(a->y));
}
int main()
{
    coo L[2][50000]={0};
    int N,x,y;
    scanf("%d", &N);
    scan_coo(&L[0][0]);
    scan_coo(&L[1][0]);
    printf("%d\n", distance(L[0][0], L[1][0]));
    for (int i = 1; i < N;i++)
    {
        scan_coo(&L[0][i]);
        int min = distance(L[0][i], L[1][0]);
        for (int j = 1; j <= i-1;j++)
        {
            if(distance(L[0][i],L[1][j])<min)
                min = distance(L[0][i], L[1][j]);
        }
        printf("%d\n", min);

        scan_coo(&L[1][i]);
        min = distance(L[1][i], L[0][0]);
        for (int j = 1; j <= i;j++)
        {
            if(distance(L[0][j],L[1][i])<min)
                min = distance(L[0][j], L[1][i]);
        }
        printf("%d\n", min);
        
    }
}
