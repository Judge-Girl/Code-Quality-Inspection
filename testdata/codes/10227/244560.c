#include"stdio.h"
#include"string.h"
 
int main()
{
    int t;
    scanf("%d",&t);
    char str[8];
    if(t)
    {
        int n;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%lld",str);
            int i=8;
            while(i--&&str[i])
                putchar_unlocked(str[i]);
        }
        putchar_unlocked('\n');
    }
    else
    {
        char c=getchar_unlocked();
        int i=8;
        for(;;)
        {
            c=getchar();
            c=(c==10?0:c);
            str[--i]=c;
            if(i==0)
                printf("%lld\n",*(long long*)str),i=8;
            if(!c)
                break;
        }
        if(i<8)
        {
            memset(str,0,i);
            printf("%lld\n",*(long long*)str);
        }
    }
}
