#include <stdio.h>
int table[1000000][13][32]  ={0};
int count_month[1000000][13]={0};
int count_year[1000000]     ={0};

int main(){
	int hm, years, month, days;
	scanf("%d", &hm);
	for(int i = 0 ; i < hm; ++i){
		scanf("%d %d %d", &years, &month, &days);
		count_year[years]=1;
		count_month[years][month]=1;
		table[years][month][days]=1;
	}
	for(int i = 0; i < 1000000; ++i) if(count_year[i] == 1) for(int j = 1 ; j < 13; ++j) if(count_month[i][j] == 1) for(int k = 1; k < 32; ++k) if(table[i][j][k] == 1)printf("%d %d %d\n", i, j, k);
}
