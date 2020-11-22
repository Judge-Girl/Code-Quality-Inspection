#include<stdio.h>
#include<string.h>
#define maxs 100000
#define maxn 12500

int main()
{
    int T;
    scanf("%d", &T);
    if(!T)
    {
        char S[maxs];
        scanf("%s", S);
        int len = strlen(S) + 1, len2, i, coun = 0;
        len2 = len;
        unsigned long long W[maxn];
        while(len2 > 0)
        {
            W[coun] = 0;
            for(i = 0; i < 8; i++)
            {
                W[coun] += (unsigned long long)S[coun*8 + i]<<((7-i)*8);
            }
            coun++;
            len2 -=8;

        }
        for(i = 0; i < coun; i++)
            printf("%llu\n", W[i]);
    }
    else
    {
        int N, i, j;
        scanf("%d", &N);
        unsigned long long W[maxn];
        for(i = 0; i < N; i++)
            scanf("%llu", &W[i]);

        for(i = 0; i < N; i++)
        {
            char temp[8] = {0};


            for(j = 0; j < 8; j++)
            {
                temp[j] = (char)((W[i]>>((7-j)*8))%((unsigned long long)1<<8));
            }
            printf("%s", temp);


        }
    }
}


