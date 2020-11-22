#include <stdio.h>
main(){ 
    int a , b , h , c , d ;
    scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
    printf("%d\n", h * a * b / (a * b - c * d));
} 

