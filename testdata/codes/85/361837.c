#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int year;
    int month;
    int date;
} DAY;

DAY arr[1000000], brr[1000000];
void radix_sort(DAY *arr, int size);
void counting_sort(DAY *arr, int size, int index);

void print_array(DAY *arr, int len) {
    for (int i = 0; i < len; i++)
        printf("%d %d %d\n", arr[i].year, arr[i].month, arr[i].date);
}

int main() {
    int SIZE;
    scanf("%d", &SIZE);
    //DAY *arr = (DAY *)malloc(sizeof(DAY)*SIZE);
    for (int i = 0; i < SIZE; i++) {
        scanf("%d %d %d", &arr[i].year, &arr[i].month, &arr[i].date);
    }
    radix_sort(arr, SIZE);
    print_array(arr, SIZE);
}

void radix_sort(DAY *arr, int size) {
    for (int i = 0; i < 3; i++)
        counting_sort(arr, size, i);
}

const int max_arr[] = {31, 12, 310000};   
void counting_sort(DAY *arr, int size, int index) {
    //DAY *brr = (DAY *)malloc(sizeof(DAY) * size);
    int MAX = max_arr[index];
    int *crr = (int *)calloc(MAX + 1, sizeof(int)); 
    switch (index) {
    case 0:
        for (int i = 0; i < size; i++)
            crr[arr[i].date]++;
        break;
    case 1:
        for (int i = 0; i < size; i++)
            crr[arr[i].month]++;
        break;
    case 2:
        for (int i = 0; i < size; i++)
            crr[arr[i].year]++;
        break;
    }
    for (int i = 1; i <= MAX; i++)
        crr[i] = crr[i] + crr[i - 1];
    switch (index) {
    case 0:
        for (int i = size - 1; i >= 0; i--) {
            brr[crr[arr[i].date] - 1] = arr[i]; // -1 since the index starts with 0
            crr[arr[i].date]--;
        }
        break;
    case 1:
        for (int i = size - 1; i >= 0; i--) {
            brr[crr[arr[i].month] - 1] = arr[i]; // -1 since the index starts with 0
            crr[arr[i].month]--;
        }
        break;
    case 2:
        for (int i = size - 1; i >= 0; i--) {
            brr[crr[arr[i].year] - 1] = arr[i]; // -1 since the index starts with 0
            crr[arr[i].year]--;
        }
        break;
    default:
        break;
    }

    for (int i = 0; i < size; i++)
        arr[i] = brr[i];
    // copies the sorted array to original orray
}

