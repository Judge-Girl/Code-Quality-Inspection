#include<stdio.h>
int main(){
    int a, b, h, c, d;//input
    int answer;
    scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
    answer = h + (c * d* h)/(a * b - c * d);
    printf("%d\n",answer);
}

