#include<stdio.h>

int main(){
    int a,b,h,c,d,ans;
    scanf("%d%d%d%d%d",&a,&b,&h,&c,&d);
    ans=a*b*h/(a*b-c*d);
    printf("%d\n",ans);

}

