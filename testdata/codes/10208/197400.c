#include<stdio.h>

int main(){
    int a, b, h, c, d;
    scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
    int water = a*b*h;
    int new_bottem_area = a*b - c*d;
    printf("%d", water/new_bottem_area);
    return 0;
}

