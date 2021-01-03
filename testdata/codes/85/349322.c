#include<stdio.h>
#include<stdlib.h>
int date[1000000];
int compare(const void *data1, const void *data2)
{
  int *ptr1 = (int *)data1;
  int *ptr2 = (int *)data2;
  if (*ptr1 > *ptr2)
    return 1;
  else if (*ptr1 < *ptr2)
    return -1;
  else
    return 0;
}
int main()
{
  int num;
  scanf("%d", &num);
  int year, month, day;
  for (int i = 0; i < num; i++){
    scanf("%d%d%d", &year, &month, &day);
    date[i] = (year << 10) + (month << 5) + day;
  }
  qsort(date, num, sizeof(int), compare);
  for (int i = 0; i < num; i++){
    year = date[i] >> 10;
    month = (date[i] - (year << 10)) >> 5;
    day = date[i] - (year << 10) - (month << 5);
    printf("%d %d %d\n", year, month, day);
  }
  return 0;
}

