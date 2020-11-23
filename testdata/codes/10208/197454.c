#include <stdio.h>
int main(){
    int a,b,h;
    int c,d;
    int nh;
    scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
    int v = a*b*h;
    nh = (v)/(a*b-c*d);
    printf("%d\n",nh);
}

