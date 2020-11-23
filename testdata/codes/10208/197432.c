#include<stdio.h>

int main(){
    int a, b, h, c, d;
    scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
    int A1 = a * b;
    int V = A1 * h;
    int A2 = c * d;
    printf("%d", V / (A1 - A2));
    return 0;
}
