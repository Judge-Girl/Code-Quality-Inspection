#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 1000000
typedef struct date{
	int y,m,d;
} Date;
Date di[MAX];
int compare(const void *a, const void *b) {
	Date *c = (Date *)a;
	Date *d = (Date *)b;
	if (c->y < d->y) return -1;
	if (c->y > d->y) return 1;
	if (c->m < d->m) return -1;
	if (c->m > d->m) return 1;
	if (c->d > d->d) return 1;
	return -1;
}
int main(void) {
    char tmp[10];
    gets(tmp);
    int n=0;
    char del[] = " ";
    int l = strlen(tmp);
    for (int i=0; i<l; ++i)
        n += (tmp[i]-'0')*pow(10,l-1-i);
    for (int i=0; i<n; ++i) {
        char year[100];
//        fgets(year,100,stdin);
        gets(year);
//        printf("%s\n",year);
        di[i].y = 0;
        di[i].m = 0;
        di[i].d = 0;
        int flag = 0;
        char *start = strtok(year,del);
        while (start != NULL) {
            l = strlen(start);
            if (flag == 0)
                di[i].y = atoi(start);
            else if (flag == 1)
                di[i].m = atoi(start);
            else if (flag == 2)
                di[i].d = atoi(start);
            flag++;
            start = strtok(NULL, del);
        }
//        printf("%d %d %d\n",di[i].y,di[i].m,di[i].d);
    }
	qsort(di,n,sizeof(Date),compare);
	for (int i=0; i<n; ++i)
		printf("%d %d %d\n",di[i].y,di[i].m,di[i].d);
	return 0;
}

