#include <stdio.h>

int main() {
    int a, b, h, c, d;
    scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
    printf("%d\n", h + (c * d * h) / (a * b - c* d) );
    return 0;
}

// water volume
// area
