#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

typedef struct date{
    int year;
    int month;
    int date;
}Date;
Date arr[MAX];

int compare(const void *a, const void *b){
    Date *A = (Date*)a;
    Date *B = (Date*)b;
    int Y_A = A->year;
    int Y_B = B->year;
    int M_A = A->month;
    int M_B = B->month;
    int D_A = A->date;
    int D_B = B->date;
    if(Y_A != Y_B) return Y_A - Y_B;
    if(M_A != M_B) return M_A - M_B;
    return D_A - D_B;
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
    for(int i = 0; i < N; i++){
        arr[i].year = input();
        arr[i].month = input();
        arr[i].date = input();
    }
    qsort(arr,N,sizeof(Date),compare);
    for(int i = 0; i < N; i++){
        printf("%d %d %d\n", arr[i].year, arr[i].month, arr[i].date);
    }
    return 0;
}
