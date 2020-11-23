#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n , max=0;
int arr [100][100];
int find;
void f(int ans[100],int x,int now ,int usable[100],int num)
{
    if(find)
        return;
    if(max>x+num)
        return;
    if(x>max)//ok
    {
        max = x;
         //exit (0);
    }
    for(int i = 0; i < num; i++) 
    {
        if(num-i + x < max) return;
        int usb[100],usbnum=0;
        for (int j = i+1; j < num; ++j)
        {
            if(arr[usable[i]][usable[j]]) {
                usb[usbnum] = usable[j];
                usbnum++;
            }
        }
        ans[x] = usable[i];
        f(ans,x+1,usable[i],usb,usbnum);
    }
}
int main()
{
    int ans[100];
    int usable[100];
    
    while(scanf("%d",&n)!=EOF)
    {
        find=0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                {scanf("%d",&arr[i][j]);}
        for (int i = 1; i <=n; ++i)
        {
            usable[i-1]=i;
        }
        f(ans,0,0,usable,n);
        printf("%d\n",max);
    }
    return 0;
}
