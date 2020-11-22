#include<stdio.h>

int main()
{
    int n;
    int i, j;
    int chess_x[100000], chess_y[100000];
    int md_sd = 65000, md_pl = 65000;

    while(scanf("%d",&n) != EOF)
    {
        for(i=0;i<(2*n);i++)
        {
            scanf("%d %d",&chess_x[i],&chess_y[i]);
        }
        for(i=0;i<(2*n);i++)
        {
            if(i%2 == 0)
            {
                int t;

                for(j=1;j<i;j+=2)
                {
                    t = abs(chess_x[i] - chess_x[j]) + abs(chess_y[i] - chess_y[j]);
                    if(t < md_sd)
                    {
                        md_sd = t;
                    }
                }
                if(md_sd != 65000)
                    printf("%d\n",md_sd);
                md_sd = 65000;
            }
            else
            {
                int t;

                for(j=0;j<i;j+=2)
                {
                    t = abs(chess_x[i] - chess_x[j]) + abs(chess_y[i] - chess_y[j]);
                    if(t < md_pl)
                    {
                        md_pl = t;
                    }
                }
                printf("%d\n",md_pl);
                md_pl = 65000;
            }
        }
    }

    return 0;
}

