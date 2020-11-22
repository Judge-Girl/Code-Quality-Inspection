#include <stdio.h>
#include <stdlib.h>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse","sse2","sse3","avx","sse4","ssse3","popcnt","abm","mmx","tune=native")

typedef struct date{
	int Y,M,D;
}Date;

int compare(const void *a,const void *b){
	if(((Date*)a)->Y!=((Date*)b)->Y){
		return ((Date*)a)->Y-((Date*)b)->Y;
	}
	else if(((Date*)a)->M!=((Date*)b)->M){
		return ((Date*)a)->M-((Date*)b)->M;
	}
	else{
		return ((Date*)a)->D-((Date*)b)->D;
	}
	
}

int main(){
	int n;
	scanf("%d",&n);

	Date *list=(Date*)malloc(sizeof(Date)*n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&list[i].Y,&list[i].M,&list[i].D);
	}

	qsort(list,n,sizeof(Date),compare);

	for(int i=0;i<n;i++){
		printf("%d %d %d\n",list[i].Y,list[i].M,list[i].D);
	}



}
