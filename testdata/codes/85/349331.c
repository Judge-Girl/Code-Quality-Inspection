#include <stdio.h>
int table[1000000][13][32]  ={0}, count_month[1000000][13]={0}, count_year[1000000] ={0}, hm, years, month, days;
int max = -1;
int main(){
	scanf("%d", &hm);
	for(int i = 0 ; i < hm; ++i){
		scanf("%d %d %d", &years, &month, &days);
		count_year[years]= count_month[years][month] = table[years][month][days]=1;
		if(years > max) max = years;
	}
	for(int i = 0; i <= max; ++i) if(count_year[i] == 1) for(int j = 1 ; j < 13; ++j) if(count_month[i][j] == 1) for(int k = 1; k < 32; ++k) if(table[i][j][k] == 1)printf("%d %d %d\n", i, j, k);
}
