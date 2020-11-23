#include <stdio.h>
#include <stdlib.h>
#define N_max 1000001

int com(const void *A, const void *B){
	int a = *(int *)A, b = *(int *)B;

	return a > b;
}

int main(){
	int N;
	long long int table[N_max], Y, M, D;
	scanf("%d", &N);

	for(int i = 0; i < N; i++){
		scanf("%lld %lld %lld", &Y, &M, &D);
		table[i] = 10000*Y + 100*M + D;
	}

	qsort(table, N, sizeof(long long int), com);

	for(int i = 0; i < N; i++)
		printf("%lld %lld %lld\n", table[i]/10000, (table[i]%10000)/100, table[i]%100);

}
