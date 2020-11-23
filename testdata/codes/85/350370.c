#include <stdio.h>
#define YEAR 350000
#define MONTH 13
#define DAY 32
int date[YEAR][MONTH][DAY] = {};
int year_confirm[YEAR] = {};

int main(){
    int numOfDate;
    scanf("%d", &numOfDate);
    int year, month, day;
    for(int i = 0; i < numOfDate; i++){
        scanf("%d %d %d", &year, &month, &day);
        year_confirm[year] = date[year][month][day] = 1;

    }
    for(int i = 0; i < YEAR; i++) if(year_confirm[i]) for(int j = 0; j < MONTH; j++) for(int k = 0; k < DAY; k++) if(date[i][j][k]) printf("%d %d %d\n", i, j, k);
}
