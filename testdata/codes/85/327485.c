#include <stdio.h>
#include <stdlib.h>

struct Date{
	int year;
	int month;
	int day;
	unsigned long long int value;
};

typedef struct Date data;
data date[1000000];

int hasEOF = 0;

int readchar(){
    static int N = 1 << 20;
    static char buf[1 << 20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf , 1 , N , stdin)) == buf) {
            hasEOF = 1;
            return EOF;   
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x){
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c - '0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c - '0';
    *x *= neg;
    return 1;
}

int cmp(const void* a , const void* b){
	return ( ((data *)a)->value - ((data *)b)->value );
}

int main(){
	int n; scanf("%d" , &n);

	for(int i = 0; i < n; i++){
		ReadInt(&date[i].year); ReadInt(&date[i].month) ; ReadInt(&date[i].day);
		date[i].value = date[i].day + 100 * date[i].month + 10000 * date[i].year;
	}

	//size of one unit is "sizeof(data)"
	qsort(date , n , sizeof(data) , cmp);

	for(int i = 0; i < n; i++)
		printf("%d %d %d\n", date[i].year , date[i].month , date[i].day);

	return 0;

}
