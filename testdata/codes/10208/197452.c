#include <stdio.h>

int main(){
    int a,b,h,c,d;
    int k1,G;
    scanf("%d%d%d%d%d",&a,&b,&h,&c,&d);
    k1=a*b*h;
    G=k1/(a*b-c*d);
    printf("%d\n",G);
    
    return 0;
}
