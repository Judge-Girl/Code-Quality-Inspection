#include <stdio.h>
#include <stdlib.h>

long long int array[1000010];
	
int compare(const void *data1, const void *data2){
	long long int *ptr1 = (long long int*)data1;
	long long int *ptr2 = (long long int*)data2;
	if(*ptr1 < *ptr2)
		return -1;
	else if(*ptr1 > *ptr2)
		return 1;
	else
		return 0;
}

int main(){
	int n;
	scanf("%d", &n);
	long long int year, month, day;
	for(int i = 0 ; i < n ; i++){
		array[i] = 0;
		scanf("%lld%lld%lld", &year, &month, &day);
		array[i] += year*10000;
		array[i] += month*100;
		array[i] += day;
	}
	qsort(array, n, sizeof(long long int), compare);
	for(int i = 0 ; i < n ; i++){
		long long int ans1 = array[i]/10000;
		long long int ans2 = (array[i]-ans1*10000)/100;
		long long int ans3 = (array[i]-ans1*10000-ans2*100);
		printf("%lld %lld %lld\n", ans1, ans2, ans3);
	}
	return 0; 
}
