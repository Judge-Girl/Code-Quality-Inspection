#include <stdio.h>
#include <stdlib.h>
typedef struct date{
    int Y;
    int M;
    int D;
}Date;
 
Date array[1000000];
int compare(const void *data1, const void *data2){
    Date *ptr1 = (Date *) data1;
    Date *ptr2 = (Date *) data2;
    if(ptr1->Y < ptr2->Y)    return -1;
    else if(ptr1->Y > ptr2->Y)    return 1;
    if((ptr1->M << 5) + ptr1->D < (ptr2->M << 5) + ptr2->D)    return -1;
    else if((ptr1->M << 5) + ptr1->D > (ptr2->M << 5) + ptr2->D)    return 1;
    return 0;
}
 
int main(void){
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)    scanf("%d%d%d", &(array[i].Y), &(array[i].M), &(array[i].D));
    qsort(array, num, sizeof(Date), compare);
    for(int i = 0; i < num; i++)    printf("%d %d %d\n", array[i].Y, array[i].M, array[i].D);
    return 0;
}
