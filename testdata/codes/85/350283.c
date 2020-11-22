#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int64_t date[1000000];
int compare(const void *a, const void *b)
{
    return *(int64_t *)a-*(int64_t *)b;
}
int main(int argc, char const *argv[])
{
    int64_t year, month, day;
    int64_t num;
    scanf("%ld", &num);
    for (int i = 0; i < num; ++i)
    {
        scanf("%ld%ld%ld", &year, &month, &day);
        date[i] = year*10000 + month*100 + day;
    }
    qsort(date, num, sizeof(int64_t), compare);
    for (int i = 0; i < num; ++i)
    {
        year = date[i]/10000;
        month = date[i]/100 - year*100;
        day = date[i] - date[i]/100 * 100;
        printf("%d %d %d\n", year, month, day);
    }
    return 0;
}
