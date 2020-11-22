#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void task_0()
{
    long long int ans = 0;
    char s[100000];
    scanf("%s",s);
    int len = strlen(s) +1;
    int count = (len%8 == 0)? len/8 : len/8+1;
    count *= 8;
    int i;
    for(i = 0 ; i < count ; i++)
    {
        if(i < len-1)
            ans += s[i];
 
        if(i % 8 == 7)
        {
            printf("%lld\n",ans);
            ans = 0;
        }
        ans <<= 8;
    }
    return;
}
 
void task_1()
{
    int n,i;
    scanf("%d",&n);
    for(i = 0 ; i < n ; i++)
    {
        long long int number;
        scanf("%lld",&number);
        char c;
        int j;
        for(j = 1 ; j <= 8 ; j++)
            {
                long long int temp = number;
                temp >>= ((8-j)*8);
                c = (char)temp;
                if(c == '\0')
                    break;
                printf("%c",c);
            }
    }
    return;
 
}
 
int main()
{
    int task;
    scanf("%d",&task);
    if(task == 0)
        task_0();
    else
        task_1();
    return 0;
}
