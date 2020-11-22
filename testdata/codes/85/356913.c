#include<stdio.h>
#define MAX 1000000
int y[MAX];
int m[MAX];
int d[MAX];
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
 
int std_id(int year[], int month[], int day[], int start, int end){
    int ahead = start - 1, j, stdy = year[end], stdm = month[end], stdd = day[end];
    for (j = start;j < end;j++){
        if (year[j] < stdy || (year[j] == stdy && (month[j] < stdm || (month[j] == stdm && day[j] < stdd)))){
            ahead += 1;
            swap(&year[j], &year[ahead]);
            swap(&month[j], &month[ahead]);
            swap(&day[j], &day[ahead]);
        }
    }
    ahead += 1;
    swap(&year[ahead], &year[end]);
    swap(&month[ahead], &month[end]);
    swap(&day[ahead], &day[end]);
    return ahead;
}
 
void quicksort(int year[], int month[], int day[], int start, int end){
    if (start < end){
        int stdid = std_id(year, month, day, start, end);
        quicksort(year, month, day, start, stdid - 1);
        quicksort(year, month, day, stdid + 1, end);
    }
}
 
void print(int year[], int month[], int day[], int num){
    for (int i = 0;i < num;i++)
        printf("%d %d %d\n", year[i], month[i], day[i]);
}
 
int main(){
    int num, i;
    scanf("%d", &num);
    for (i = 0;i < num;i++)
        scanf("%d%d%d", &y[i], &m[i], &d[i]);
    quicksort(y, m, d, 0, num - 1);
    print(y, m, d, num);
}
