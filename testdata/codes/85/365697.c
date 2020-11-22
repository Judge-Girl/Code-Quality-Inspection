#include <stdio.h>
#include <stdlib.h>

void counting_sort(unsigned int arr[], unsigned int new_arr[], unsigned int n,
                   int num, int digit, int redun)
{
    int *temp;
    temp = (int *)malloc((num + 1) * sizeof(int));
    for (int i = 0; i <= num; i++)
    {
        temp[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        temp[((arr[i] / digit) % redun)]++;
    }
    for (int i = 1; i <= num; i++)
    {
        temp[i] += temp[(i - 1)];
    }
    for (int i = (n - 1); i >= 0; i--)
    {
        new_arr[(temp[((arr[i] / digit) % redun)] - 1)] = arr[i];
        temp[((arr[i] / digit) % redun)]--;
    }
}

void radix(unsigned int arr[], unsigned int B[], unsigned int n)
{
    unsigned int *new_arr;
    new_arr = (unsigned int *)malloc(n * sizeof(int));
    counting_sort(arr, new_arr, n, 31, 1, 100);

    unsigned int *new_new_arr;
    new_new_arr = (unsigned int *)malloc(n * sizeof(int));
    counting_sort(new_arr, new_new_arr, n, 12, 100, 100);
    free(new_arr);

    new_arr = (unsigned int *)malloc(n * sizeof(int));
    counting_sort(new_new_arr, new_arr, n, 10, 10000, 10);
    free(new_new_arr);

    new_new_arr = (unsigned int *)malloc(n * sizeof(int));
    counting_sort(new_arr, new_new_arr, n, 10, 100000, 10);
    free(new_arr);

    new_arr = (unsigned int *)malloc(n * sizeof(int));
    counting_sort(new_new_arr, new_arr, n, 10, 1000000, 10);
    free(new_new_arr);

    new_new_arr = (unsigned int *)malloc(n * sizeof(int));
    counting_sort(new_arr, new_new_arr, n, 10, 10000000, 10);
    free(new_arr);

    new_arr = (unsigned int *)malloc(n * sizeof(int));
    counting_sort(new_new_arr, new_arr, n, 10, 100000000, 10);
    free(new_new_arr);

    counting_sort(new_arr, B, n, 10, 1000000000, 10);
}

main()
{
    unsigned int n, input;
    scanf("%u", &n);
    unsigned int *arr;
    arr = (unsigned int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%u", &input);
        arr[i] = input * 10000;
        scanf("%u", &input);
        arr[i] += input * 100;
        scanf("%u", &input);
        arr[i] += input;
    }
    unsigned int *new_arr;
    new_arr = (unsigned int *)malloc(n * sizeof(int));
    radix(arr, new_arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%u %u %u\n", (new_arr[i] / 10000), ((new_arr[i] / 100) % 100),
               (new_arr[i] % 100));
    }
}

