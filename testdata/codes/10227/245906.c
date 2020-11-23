#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int type;
    scanf("%d", &type);
    if(type == 0)
    {
        char S[100000];
        scanf("%s", S);
        int pos = 0;
        int len = strlen(S);
        if((len+1) % 8 == 0)
        for(int j = 0; j < (len+1)/8;j++)
        {
            unsigned long long num = 0;
            for(int i = 0; i < 8; i++)
            {
                num += (unsigned long long)S[pos+i] << 56-8*i;
                
            }
            printf("%llu\n", num);
            pos += 8;
        }
        else
        {
            for(int j = 0; j < (len+1)/8+1;j++)
        {
            unsigned long long num = 0;
            for(int i = 0; i < 8; i++)
            {
                num += (unsigned long long)S[pos+i] << 56-8*i;
                
            }
            printf("%llu\n", num);
            pos += 8;
        }
        }
        
    }
    else if(type == 1)
    {
        unsigned long long num;
        while(scanf("%llu", &num) != EOF)
        {
            if(num <= 12500)
                continue;
            for(int i = 0; i < 8; i++)
            {
                if(((unsigned long long)num<<i*8)>>56 < 32||((unsigned long long)num<<i*8)>>56 >127)
                    continue;
                printf("%hhc", ((unsigned long long)num<<i*8)>>56);
                
            }
        }
    }
}
