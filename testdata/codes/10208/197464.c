#include <stdio.h>

int main(){
    int a, b, h, c, d, depth;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &h);
    scanf("%d", &c);
    scanf("%d", &d);
    depth=a*b*h/(a*b-c*d);
    printf("%d", depth);
    return 0;
}

