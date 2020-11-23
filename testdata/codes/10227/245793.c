#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    if (T == 0) // str2arr
    {
        char str[100001] = "";
        scanf("%s", str);
        unsigned long long temp = 0;
        unsigned long long arr[12501] = {0};
        int count = 0;
        int len = 0;
        if (strlen(str) < 8)
        {
            for (int i = 0; i <= strlen(str); i++)
                arr[0] = arr[0] | (((unsigned long long)str[i]) << 8*(7-i));
            printf("%llu\n",arr[0]);
            exit(0);
        }
        for (int i = 0; i <= strlen(str); i++)  {
            if (count%8 == 0)
                len++;
            arr[count/8] = arr[count/8] | (((unsigned long long)str[i]) << 8*(7-i));
            count++;
            
        }
        for (int i = 0; i < len; i++)
            printf("%llu\n",arr[i]);
    }
    if (T == 1) // arr2str
    {
        int N;
        scanf("%d", &N);
        unsigned long long arr[12501] = {0};
        unsigned long long temp = 0;
        char one = 0;
        for (int i = 0; i < N; i++)  
            scanf("%llu", &arr[i]);
        for (int i = 0; i < N; i++)  {
            for (int j = 0; j < 8; j++)
            {
                one = (char)(arr[i] >> 8*(7-j));
                if (one == '\0')
                    exit(0);
                printf("%c", one);
                
            }
        }        


    }
    return 0;
}
