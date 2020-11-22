#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000
unsigned int arr[MAX];

int compare(const void *a, const void *b){
    return *((unsigned int*)a) - *((unsigned int*)b);
}
int input(){
    char cha;
    int x=0;
    while(cha=getchar())
        if(cha!=' '&&cha!='\n') break;
    x=cha-'0';
    while(cha=getchar()){
        if(cha==' '||cha=='\n') break;
        x=x*10+cha-'0';
    }
    return x;
}
int main(void){
    int N; scanf("%d", &N);
    int year, month, date;
    for(int i = 0; i < N; i++){
        year = input();
        month = input();
        date = input();
        arr[i] = year*10000 + month*100 + date;
    }
    qsort(arr,N,sizeof(unsigned int),compare);
    for(int i = 0; i < N; i++){
        date = arr[i]%100;
        arr[i] /= 100;
        month = arr[i]%100;
        arr[i] /= 100;
        printf("%d %d %d\n", arr[i], month, date);
    }
    return 0;
}
